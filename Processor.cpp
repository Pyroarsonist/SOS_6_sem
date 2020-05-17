#include "Processor.h"

Processor::Processor() {
    free_processor_time = 0;
    operated_request_count = 0;
    sum_wait_time = 0;
}

void Processor::add_request(Request *request) {
    if (request == nullptr) {
        throw "No request";
    }
    request->set_time_adding_to_queue(current_time);
    queue.emplace_back(request);
}

void Processor::step(int count) {
    current_time += count;
    if (queue.size() == 0) {
        free_processor_time += count;
        return;
    }
    Request *current_request = queue.at(0);
    if (!current_request->get_is_on_processor()) {
        current_request->start_operate_at_time(current_time);
    }
    int dt = current_time - current_request->get_time_removed_from_queue();
    if (dt >= 0) {
        queue.erase(queue.begin());
        operated_request_count++;
        sum_wait_time += current_request->get_time_removed_from_queue() - current_request->get_time_adding_to_queue();
    } else {
        current_request->set_worked_time(current_request->get_worked_time() + count);
    }
    if (dt > 0) {
        step(dt);
    }
}

CountTime Processor::request_count_wait_time() {
    if (queue.size() == 0) {
        return CountTime(0, 0);
    }
    int summary_wait_time = 0;
    int current_wait_time = 0;
    for (int i = queue.size() - 1; i >= 0; i--) {
        current_wait_time += (queue).at(i)->get_operate_time();
        summary_wait_time += current_wait_time;
    }
    return CountTime(queue.size(), summary_wait_time);
}

double Processor::get_average_wait_time() {
//    if (sum_wait_time == 0) return 0;
    return ((double) sum_wait_time) / operated_request_count;
}

double Processor::get_free_processor_percent() {
    //    if (free_processor_time == 0) return 0;
    return ((double) free_processor_time) / current_time;
}

int Processor::get_processor_time() {
    return current_time;
}

std::vector<std::string> Processor::requests_to_text() {
    std::vector<std::string> text;
    if (queue.size() == 0) {
        return text;
    }

    int p = 0;
    for (int i = queue.size() - 1; i >= 0; i--) {
        text[i] = (queue).at(i)->to_string();
        p++;
    }
    return text;
}
