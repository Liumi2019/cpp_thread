#ifndef USE_THREAD_H
#define USE_THREAD_H

#include <list>
#include <mutex>

void printA(int a);

void test_Thread();

// 生产者 —— 消费者 模型
class MemoryQue
{
public:
    MemoryQue() = default;
    ~MemoryQue() = default;

    void insertInfo();
    void printInfo();

private:
    std::list<int> infoList;
    static const int MAX_INFO_NUM = 100000;
    std::mutex mtex;
};

void test_MemoryQue();

#endif