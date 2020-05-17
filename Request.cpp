#include "Request.h"

Request::Request(int operate_time) {
    is_on_processor = false;
    this->operate_time = operate_time;
    worked_time = 0;
}

void Request::start_operate_at_time(int processor_time) {
    is_on_processor = true;
    start_operate_time = processor_time;
    time_removed_from_queue = processor_time + operate_time;
}

int Request::get_operate_time() {
    return operate_time;
}

void Request::set_operate_time(int x) {
    operate_time = x;
}

int Request::get_time_adding_to_queue() {
    return time_adding_to_queue;
}

void Request::set_time_adding_to_queue(int x) {
    time_adding_to_queue = x;
}

int Request::get_time_removed_from_queue() {
    return time_removed_from_queue;
}

void Request::set_time_removed_from_queue(int x) {
    time_removed_from_queue = x;
}

bool Request::get_is_on_processor() {
    return is_on_processor;
}

void Request::set_on_processor(bool x) {
    is_on_processor = x;
}

int Request::get_worked_time() {
    return worked_time;
}

void Request::set_worked_time(int x) {
    worked_time = x;
}

std::string Request::to_string() {
    return "Time adding=" + std::to_string(time_adding_to_queue) + " operate time=" + std::to_string(operate_time) +
           " worked time=" +
           std::to_string(worked_time);
}








