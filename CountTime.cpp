#include "CountTime.h"

CountTime::CountTime(int size, int wait_time) {
    this->size = size;
    this->wait_time = wait_time;
}

std::string CountTime::to_string() {
    return "Size of queue=" + std::to_string(size) + " wait time=" + std::to_string(wait_time);
}
