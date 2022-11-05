#include <iostream>
#include <thread>
#include <mutex>

#include "useThread.h"

void printA(int a)
{
    for (int i = 0; i < 100; i++)
    {
        std::cout << "a = " << a << " ";
    }
    std::cout << std::endl;
}

void test_Thread()
{
    std::thread t1(printA, 50);
    std::thread t2(printA, 100);
    t1.join();
    t2.join();
}

void MemoryQue::insertInfo()
{
    std::lock_guard lock_gd(mtex);
    for (int info = 0; info < MAX_INFO_NUM; info++)
    {
        infoList.push_back(info);
        std::cout << "insert info = " << info << std::endl;
    }
}

void MemoryQue::printInfo()
{
    std::lock_guard lock_gd(mtex);

    for (int info = 0; info < MAX_INFO_NUM; info++)
    {
        if (infoList.empty())
        {
            std::cout << "infoList is null, please wait!" << std::endl;
        }
        else
        {
            std::cout << "doing info = " << infoList.front() << std::endl;
            infoList.pop_front();
        }
    }
    std::cout << "print info end." << std::endl;
}

void test_MemoryQue()
{
    MemoryQue memoryQue;
    std::thread consurmer(&MemoryQue::printInfo, &memoryQue);
    std::thread creater(&MemoryQue::insertInfo, &memoryQue);

    creater.join();
    consurmer.join();
}
