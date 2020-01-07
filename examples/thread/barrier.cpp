//
// Created by yc_qian on 20-1-6.
//
#include <iostream>
#include <chrono>
#include "../../thread/barrier.hpp"
#include "../../thread/thread_pool.hpp"

int main(int argc, char **argv){
    ycqian::thread_pool pool(4);
    ycqian::barrier barrier(4);

    for (int i = 0; i < 4; ++i) {
        pool.execute([&barrier, i] {
            for (int j = 0; j < 10; ++j) {
                std::cout << i << "-thread do sth...\n";
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                barrier.wait();
            }
        });
    }

    std::this_thread::sleep_for(std::chrono::seconds(5));

    std::cout << "===============\n";

    ycqian::latch latch(4);

    for (int k = 0; k < 4; ++k) {
        pool.execute([&latch,k] {
            std::cout << k << "-thread do sth...\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            latch.count_down();
        });
    }

    latch.wait();
    std::cout << "main wait until other thread finish\n";
}