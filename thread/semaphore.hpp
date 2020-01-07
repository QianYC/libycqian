//
// Created by yc_qian on 20-1-6.
//

#ifndef LIBYCQIAN_SEMAPHORE_HPP
#define LIBYCQIAN_SEMAPHORE_HPP

#include <shared_mutex>
#include <condition_variable>
#include <thread>
#include <mutex>

namespace ycqian {
    class semaphore {
    private:
        std::mutex mutex;
        int count;//bug-1:设置成了unsigned
        std::condition_variable cond;

    public:
        semaphore(int count) : count(count) {}

        semaphore(semaphore &) = delete;

        semaphore(const semaphore &) = delete;

        semaphore(semaphore &&) = delete;

        semaphore &operator=(semaphore &) = delete;

        semaphore &operator=(semaphore &&) = delete;

        void p() {
            std::unique_lock<std::mutex> lk(mutex);
            count--;
            if (count < 0) {
                cond.wait(lk);
            }
        }

        void v() {
            std::lock_guard<std::mutex> lg(mutex);
            count++;
            if (count <= 0) {//bug-2:方向搞反
                cond.notify_one();
            }
        }
    };
}

#endif //LIBYCQIAN_SEMAPHORE_HPP
