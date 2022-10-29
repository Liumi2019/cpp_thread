#include <iostream>
#include <thread>

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