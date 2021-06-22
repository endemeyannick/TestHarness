#pragma once
#include "Test.h"
#include <mutex>
#include <memory>



class ThreadTest :
    public Test
{
protected:
    ThreadTest* self;
    int _threadDuration;
    int _displayThread;

public:
    ThreadTest();
    ThreadTest(string n, int s);
    int getThreadDuration();
    void run();
};

