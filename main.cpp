#include <iostream>
#include <string>
#include <unistd.h>
#include <chrono>

using namespace std;

void draw_cat() {
    for (int i = 0; i < 1000000000; i++) {
        printf("\nDrawing cat\n");
        //process of drawing
        usleep(1000);
    }

}

static void draw_dog() {
    printf("\nDrawing dog\n");
    for (int i = 0; i < 1000000000; i++) {
        //process of drawing
        usleep(1000);
    }
}

int main() {
    printf("Inside main()\nEnter type of shape:\n");
    string type_of_shape(100, '\0');;
    scanf("%s", type_of_shape.c_str());

    auto t_start = chrono::high_resolution_clock::now();



    for (int i = 0; i < 0xffffff; ++i) {
        if (type_of_shape == "dog")
            draw_dog();
        if (type_of_shape == "cat")
            draw_cat();
    }

    auto t_end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::milliseconds>(t_end - t_start).count();

    cout << endl << "Optimized function execution time in milliseconds: " << duration << endl;


    return 0;
}