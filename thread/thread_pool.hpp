//
// Created by yc_qian on 20-1-6.
//

#ifndef LIBYCQIAN_THREAD_POOL_HPP
#define LIBYCQIAN_THREAD_POOL_HPP

#include <mutex>
#include <condition_variable>
#include <functional>
#include <queue>
#include <thread>

namespace ycqian{
    class thread_pool{

    private:

        struct data{
            std::mutex mutex;
            std::condition_variable cv;
            std::queue<std::function<void ()>>tasks;
            bool shutdown = false;
        };
        std::shared_ptr<data> data_;

    public:

        explicit thread_pool(size_t size) : data_(std::make_shared<data>()) {
            for (size_t i = 0; i < size; ++i) {
                std::thread([data = data_]{
                    std::unique_lock<std::mutex> lk(data->mutex);
                    for (;;) {
                        if (data->tasks.size()>0) {
                            auto current = data->tasks.front();
                            data->tasks.pop();
                            lk.unlock();
                            current();
                            lk.lock();
                        } else if (data->shutdown) {
                            break;
                        } else {
                            data->cv.wait(lk);
                        }
                    }
                }).detach();
            }
        }

        void execute(std::function<void()> &&f) {
            {
                std::lock_guard<std::mutex> lg(data_->mutex);
                data_->tasks.push(f);
            }
            data_->cv.notify_one();
        }

        ~thread_pool(){
            if (data_) {
                {
                    std::lock_guard<std::mutex> lg(data_->mutex);
                    data_->shutdown = true;
                }
                data_->cv.notify_all();
            }
        }
    };
}

#endif //LIBYCQIAN_THREAD_POOL_HPP
