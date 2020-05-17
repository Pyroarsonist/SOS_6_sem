#ifndef LAB_3_COUNTTIME_H
#define LAB_3_COUNTTIME_H


#include "string"


class CountTime {

public:
    CountTime(int, int);
    std::string to_string();
    int size;
    int wait_time;
};


#endif //LAB_3_COUNTTIME_H
