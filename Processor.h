#ifndef LAB_3_PROCESSOR_H
#define LAB_3_PROCESSOR_H

#include <string>
#include <vector>
#include "Request.h"
#include "CountTime.h"


class Processor {
private:
    int operated_request_count;
 int sum_wait_time;
 int current_time;
 int free_processor_time;
 std::vector<Request*> queue;

public:
    Processor();
    void add_request(Request*);
    void step(int);
    CountTime request_count_wait_time();
    double get_average_wait_time();
    double get_free_processor_percent();
    int get_processor_time();
    std::vector<std::string> requests_to_text();

};


#endif //LAB_3_PROCESSOR_H
