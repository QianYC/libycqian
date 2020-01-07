//
// Created by yc_qian on 20-1-6.
//

#ifndef LIBYCQIAN_BARRIER_HPP
#define LIBYCQIAN_BARRIER_HPP

#include <condition_variable>
#include <mutex>

namespace ycqian {

    class barrier {
    private:
        const unsigned int count;
        unsigned int current;
        std::condition_variable cv;
        std::mutex mutex;

    public:
        barrier(unsigned int count) : count(count), current(count) {
            if (count == 0) {
                throw std::runtime_error("count must be greater than 0!");
            }
        }

        /**
         * not copyable, not moveable
         */
        barrier(const barrier &) = delete;

        barrier(barrier &&) = delete;

        barrier &operator=(const barrier &) = delete;

        barrier &operator=(barrier &&) = delete;

        void wait(){
            std::unique_lock<std::mutex> lk(mutex);
            if (current == 1) {
                current = count;//reset
                cv.notify_all();
            } else {
                current--;
                cv.wait(lk);
            }
        }
    };

    class latch {
    private:
        unsigned int count;
        std::mutex mutex;
        std::condition_variable cv;

    public:
        latch(const latch &) = delete;

        latch(latch &&) = delete;

        latch &operator=(const latch &) = delete;

        latch &operator=(latch &&) = delete;

        latch(unsigned int count) : count(count) {
            if (count == 0) {
                throw std::runtime_error("count must be greater than 0!");
            }
        }

        void count_down() {
            std::lock_guard<std::mutex> lg(mutex);
            count--;
            if (count == 0) {
                cv.notify_all();
            }
        }

        void wait(){
            std::unique_lock<std::mutex> lk(mutex);
            cv.wait(lk);
        }
    };
}

#endif //LIBYCQIAN_BARRIER_HPP
