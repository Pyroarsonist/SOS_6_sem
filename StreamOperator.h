#ifndef LAB_3_STREAMOPERATOR_H
#define LAB_3_STREAMOPERATOR_H


#include <queue>
#include <string>
#include <vector>
#include "Request.h"
#include "Processor.h"
#include <stdlib.h>
#include <time.h>


class StreamOperator {

private:
    int min_operate_time;
    int max_operate_time;
    int min_time_between_request;
    int max_time_between_request;
    int time_to_next_request;

    int generate_random(int, int);

public:
    void modeling_steps(int);

    Processor processor;

    StreamOperator(int, int, int, int);

    int get_min_operate_time();

    void set_min_operate_time(int);

    int get_max_operate_time();

    void set_max_operate_time(int);

    int get_min_time_between_request();

    void set_min_time_between_request(int);

    int get_max_time_between_request();

    void set_max_time_between_request(int);


};


#endif //LAB_3_STREAMOPERATOR_H
