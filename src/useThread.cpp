#include "useThread.h"

#include <unistd.h>

#include <iostream>
#include <mutex>
#include <thread>

void printA(int a) {
  for (int i = 0; i < 100; i++) {
    std::cout << "a = " << a << " ";
  }
  std::cout << std::endl;
}

void test_Thread() {
  std::thread t1(printA, 50);
  std::thread t2(printA, 100);
  t1.join();
  t2.join();
}

void MemoryQue::insertInfo() {
  for (int info = 0; info < MAX_INFO_NUM; info++) {
    usleep(1000 * 1);
    mtex.lock();
    {
      infoList.push_back(info);
      std::cout << "insert info = " << info << std::endl;
    }
    mtex.unlock();
  }
  isEnd = true;
  std::cout << "insert end" << std::endl;
}

void MemoryQue::printInfo() {
  while (!isEnd) {
    while (!infoList.empty()) {
      mtex.lock();
      {
        std::cout << " --- doing info = " << infoList.front() << std::endl;
        infoList.pop_front();
      }
      mtex.unlock();
    }
  }
}

void test_MemoryQue() {
  MemoryQue memoryQue;
  std::thread consurmer(&MemoryQue::printInfo, &memoryQue);
  std::thread creater(&MemoryQue::insertInfo, &memoryQue);
  creater.join();
  consurmer.join();
}
