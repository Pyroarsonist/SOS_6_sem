//
// Created by dan on 09.03.20.
//

#ifndef LAB_2_TESTER_H
#define LAB_2_TESTER_H

#include "Allocator.h"

class Tester {

public:
    explicit Tester(Allocator *allocator);

    void test(size_t iteration_counter, void **pointers, size_t *pointers_count);

private:
    Allocator *allocator;

};

#endif //LAB_2_TESTER_H
