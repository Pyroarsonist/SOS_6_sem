#include "StreamOperator.h"

StreamOperator::StreamOperator(int min_operate_time,
                               int max_operate_time, int min_time_between_request,
                               int max_time_between_request) {
    time_to_next_request = 0;
    this->processor = Processor();
    this->min_operate_time = min_operate_time;
    this->max_operate_time = max_operate_time;
    this->min_time_between_request = min_time_between_request;
    this->max_time_between_request = max_time_between_request;
}

int StreamOperator::generate_random(int min, int max) {
    double r = std::rand() % (max - min);
    return (int) (min + r);
}

void StreamOperator::modeling_steps(int time) {
    if (time < 1) {
        throw "Invalid time";
    }
    Request *request = nullptr;
    int operate_time;
    for (int i = 0; i < time; i++) {
        if (time_to_next_request < 0) {
            operate_time = generate_random(min_operate_time, max_operate_time);
            request = new Request(operate_time);
            processor.add_request(request);
            time_to_next_request = generate_random(min_time_between_request, max_time_between_request);
        } else {
            time_to_next_request--;
        }
        processor.step(1);
    }
}

int StreamOperator::get_min_operate_time() {
    return min_operate_time;
}

void StreamOperator::set_min_operate_time(int x) {
    min_operate_time = x;
}

void StreamOperator::set_max_time_between_request(int x) {
    max_time_between_request = x;
}

int StreamOperator::get_max_operate_time() {
    return max_operate_time;
}

void StreamOperator::set_max_operate_time(int x) {
    max_operate_time = x;
}

int StreamOperator::get_min_time_between_request() {
    return min_time_between_request;
}

void StreamOperator::set_min_time_between_request(int x) {
    min_time_between_request = x;
}

int StreamOperator::get_max_time_between_request() {
    return max_time_between_request;
}


