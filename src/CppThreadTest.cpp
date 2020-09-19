#include <iostream>
#include <thread>
#include<mutex>
#include <unistd.h>
#include<memory>
#include "container.h"
#include "Producer.h"
#include "consumer.h"


std::mutex m_mutex;
void func(std::thread::id id)
{
    static int count = 0;
    while (1)
    {
        m_mutex.lock();
        std::cout << id<<":"<<std::this_thread::get_id() << ":"<<count++ << std::endl;
        m_mutex.unlock();
        sleep(1);     
    }
}

void runThreads()
{
    std::shared_ptr<container> sls(new container(15));
    Producer pdr(sls);
    consumer csm(sls);

    std::thread pdrthread(&Producer::conduct,pdr);
    std::thread csmthread(&consumer::consume,csm);
    pdrthread.join();
    csmthread.join();


//     std::thread t1(func,std::this_thread::get_id());
//     std::thread t2(func,std::this_thread::get_id());
//     std::thread t3(func,std::this_thread::get_id());

//     t1.join();
//     t2.join();
//     t3.join();
}

int main()
{
    runThreads();
    // std::shared_ptr< int[15]> a;
    // std::cout<<sizeof(int[20])/sizeof(int)<<std::endl;
    // std::cout<<sizeof(a.get())/sizeof(int)<<std::endl;
    return 0;
}