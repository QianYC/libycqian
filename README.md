# libycqian -- 一个轻量级 c++ 库
## 作者: ycqian

## 安装
- 不安装：对于只有头文件的库，你可以直接复制头文件至项目里使用
- cmake安装
    ```
    git clone https://github.com/QianYC/libycqian.git
    cd libycqian
    mkdir build && cd build
    cmake ..
    make
    sudo make install
    ```
## 使用
1. 引入头文件
2. 链接pthread库
    ```
    1. 使用cmake：target_link_libraries([target name] pthread)
    2. 直接使用编译选项：-lpthread
    ```

## 模块列表

|模块|描述|
|---|---|
|thread|提供了多线程编程的工具类|

## 1.0 thread 模块

|类|描述|
|---|---|
|thread_pool|固定线程数的线程池|
|semaphore|信号量，可用于pv操作|
|barrier|相当于可重复使用的latch|
|latch|可用于在一个线程中等待其他线程完成任务|

### 1.1 thread_pool
|方法|描述|
|---|---|
|thread_pool(size_t size)|创建大小为size的线程池|
|void execute(std::function<void()> &&f)|提交一个任务给线程池执行，传递参数、获得返回值详情参考thread_pool.cpp|

### 1.2 semaphore
|方法|描述|
|---|---|
|semaphore(int count)|创建一个信号量|
|void p()|递减信号量|
|void v()|递增信号量|
**PS:semaphore不可复制与移动！**

### 1.3 barrier
|方法|描述|
|---|---|
|barrier(unsigned int count)|创建等待count个线程的barrier|
|void wait()|阻塞当前线程，当有count个线程调用wait时，唤醒所有线程|
**PS:barrier不可复制与移动！**

### 1.4 latch
|方法|描述|
|---|---|
|latch(unsigned int count)|创建等待count个线程的latch|
|void count_down()|在工作线程中调用，递减计数器|
|void wait()|阻塞当前线程，直到count个工作线程调用count_down|
**PS:latch不可复制与移动！**