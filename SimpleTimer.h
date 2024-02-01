#ifndef TEST_SIMPLETIMER_H
#define TEST_SIMPLETIMER_H

#include <chrono>
#include <iostream>

class SimpleTimer{
public:
    SimpleTimer();
    ~SimpleTimer();

private:
    std::chrono::time_point<std::chrono::steady_clock> start, end;
    std::chrono::duration<float>duration;
};

#endif //TEST_SIMPLETIMER_H
