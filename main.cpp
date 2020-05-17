#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "StreamOperator.h"
#include "CountTime.h"

using namespace std;

int main() {
    srand(time(0));

    StreamOperator *stream_operator = nullptr;
    auto start = 1;
    auto end = 100;
    auto min_operate_time = 1;
    auto max_operate_time = 1000;
    auto step_count = 10000;

    double **data = new double *[end - start];
    for (int i = 0; i < end - start; ++i)
        data[i] = new double[2];
    int p = 0;
    for (int i = start; i < end; i++) {
        int st = i - 1;
        if (st < 0) {
            st = 0;
        }
        stream_operator = new StreamOperator(min_operate_time, max_operate_time, st, i + 1);
        stream_operator->modeling_steps(step_count);
        data[p][0] = i;
        data[p][1] = stream_operator->processor.get_average_wait_time();
        cout << "x= " << data[p][0] << " y=" << +data[p][1] << endl;
        p++;
    }

    cout << endl;

    data = new double *[end - start + 1];
    for (int i = 0; i < end - start; ++i)
        data[i] = new double[2];
    p = 0;
    for (int i = start; i < end; i++) {
        stream_operator = new StreamOperator(min_operate_time, max_operate_time, i - 1, i + 1);
        stream_operator->modeling_steps(step_count);
        data[p][0] = i;
        data[p][1] = stream_operator->processor.get_free_processor_percent();
        cout << "x= " << data[p][0] << " y=" << +data[p][1] << endl;
        p++;
    }

    cout << endl;

    data = new double *[end - start + 1];
    for (int i = 0; i < end - start; ++i)
        data[i] = new double[2];
    p = 0;
    stream_operator = new StreamOperator(min_operate_time, max_operate_time, start, end);

    vector<CountTime> result;


    for (int i = 0; i < step_count; i++) {
        stream_operator->modeling_steps(1);
        result.emplace_back(stream_operator->processor.request_count_wait_time());
//        cout << res[i].to_string() << endl;
    }

    vector<CountTime> count_key;
    for (int i = 0; i < result.size(); i++) {
        CountTime curr_count_time = result[i];
        bool is_in_list = false;
        for (int j = 0; j < count_key.size(); j++) {
            if (count_key.at(j).size == curr_count_time.size) {
                count_key.at(j).wait_time = (count_key.at(j).wait_time + curr_count_time.wait_time) / 2;
                is_in_list = true;
                break;
            }
        }
        if (!is_in_list) {
            count_key.emplace_back(result[i]);
        }
    }


    data = new double *[count_key.size()];
    for (int i = 0; i < end - start; ++i)
        data[i] = new double[2];

    for (int i = 0; i < count_key.size(); i++) {
        data[i][0] = count_key.at(i).wait_time;
        data[i][1] = count_key.at(i).size;
        cout << "x= " << data[p][0] << " y=" << +data[p][1] << endl;
    }

    return 0;
}
