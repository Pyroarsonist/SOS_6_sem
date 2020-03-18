//
// Created by dan on 09.03.20.
//
#ifndef LAB_1_ALLOCATOR_H
#define LAB_1_ALLOCATOR_H

#include <cstddef>
#include <iostream>

using namespace std;


struct header {
    bool is_busy;
    size_t size;
    size_t prev_size;
};

class Allocator {
public:
    explicit Allocator(size_t memory_size);

    ~Allocator();

    void mem_dump();

    void *mem_alloc(size_t size);

    void *mem_realloc(void *ptr, size_t size);

    void mem_free(void *ptr);

private:
    size_t memory_size;
    void *memory;
};

#endif //LAB_1_ALLOCATOR_H
