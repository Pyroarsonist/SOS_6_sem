#ifndef LAB_3_REQUEST_H
#define LAB_3_REQUEST_H

#include <string>
//using namespace std;



class Request {
private:
    int operate_time;
    int time_adding_to_queue;
    int start_operate_time;
    int time_removed_from_queue;
    int worked_time;
    bool is_on_processor;

public:
    Request(int operate_time);
    void start_operate_at_time(int);
    int get_operate_time();
    void set_operate_time(int);
    int get_time_adding_to_queue();
    void set_time_adding_to_queue(int);
    int get_time_removed_from_queue();
    void set_time_removed_from_queue(int);
    bool get_is_on_processor();
    void set_on_processor(bool);
    int get_worked_time();
    void set_worked_time(int);
    std::string to_string();




};


#endif //LAB_3_REQUEST_H
