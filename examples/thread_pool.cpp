//
// Created by yc_qian on 20-1-6.
//
#include "thread_pool.hpp"
#include <iostream>
#include <chrono>
#include <future>

class A {};
void foo();
int bar();
A var();

int main(int argc, char **argv){
    ycqian::thread_pool pool(8);

    for (int i = 0; i < 10; ++i) {
        pool.execute([] {
            std::cout << std::this_thread::get_id() << " do sth...\n";
        });
    }

    pool.execute(foo);
    pool.execute(bar);
    pool.execute(var);

    /**
     * passing parameters
     */
    for (int j = 0; j < 4; ++j) {
        pool.execute([j] {
            std::cout << "task-" << j << std::endl;
        });
    }
    /**
     * wait some time to see the output
     */
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    /**
     * getting return value
     */
    std::promise<int>add_promise;
    std::future<int> add_future = add_promise.get_future();
    pool.execute([&add_promise] {
        //do some task
        add_promise.set_value(10);
    });
    std::cout << "the result = " << add_future.get() << std::endl;
}

void foo(){
    std::cout << "foo\n";
}

int bar(){
    std::cout << "bar\n";
    return -1;
}

A var(){
    A a;
    std::cout << "var\n";
    return a;
}