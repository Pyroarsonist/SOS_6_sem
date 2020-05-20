#include <iostream>
#include <chrono>

using namespace std;

void initial_func() {

    int *C = new int[2];

    for (int j = 500000000; j > 0; j--) {
        C[0]++;
        C[0]++;
    }

    C[1] = C[0];

    cout << C[0];
}

void optimized_func() {

    int *C = new int[2];

    C[0] += 2 * 500000000;

    C[1] = C[0];

    cout << C[0];
}


int main() {

    auto t_start = std::chrono::high_resolution_clock::now();

    initial_func();

    auto t_end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(t_end - t_start).count();

    cout << endl << "Old function execution time in nanoseconds: " << duration << endl;


    t_start = std::chrono::high_resolution_clock::now();

    optimized_func();

    t_end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::nanoseconds>(t_end - t_start).count();

    cout << endl << "Optimized function execution time in nanoseconds: " << duration << endl;

    return 0;
}