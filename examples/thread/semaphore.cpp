//
// Created by yc_qian on 20-1-6.
//
#include <iostream>
#include <chrono>
#include "../../thread/semaphore.hpp"
#include "../../thread/thread_pool.hpp"

int main(int argc, char **argv){
    ycqian::thread_pool pool(4);
    ycqian::semaphore semaphore(2);

    for (int i = 0; i < 4; ++i) {
        pool.execute([&semaphore, i] {
            std::cout << i << "-thread before enter\n";
            semaphore.p();
            std::cout << i << "-thread do something\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            semaphore.v();
            std::cout << i << "-thread exit\n";
        });
    }
    std::this_thread::sleep_for(std::chrono::seconds(5));
}