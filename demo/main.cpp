#include <stdio.h>
#include <inttypes.h>
#include <chrono>
#include "../lia/lia.h"
#include <stdlib.h>

#define VEC_SIZE    4
#define ITERATIONS  100000000


int main() {
    // Allocate the test vectors
    printf("Allocating vectors\n");
    lia::SVec<VEC_SIZE>* a = new lia::SVec<VEC_SIZE>[ITERATIONS];
    lia::SVec<VEC_SIZE>* b = new lia::SVec<VEC_SIZE>[ITERATIONS];
    double* results = new double[ITERATIONS];

    // Fill with random data
    printf("Filling vectors\n");
    for (int i = 0; i < ITERATIONS; i++) {
        a[i](0) = (double)rand() / (double)RAND_MAX;
        a[i](1) = (double)rand() / (double)RAND_MAX;
        a[i](2) = (double)rand() / (double)RAND_MAX;
        a[i](3) = (double)rand() / (double)RAND_MAX;
        b[i](0) = (double)rand() / (double)RAND_MAX;
        b[i](1) = (double)rand() / (double)RAND_MAX;
        b[i](2) = (double)rand() / (double)RAND_MAX;
        b[i](3) = (double)rand() / (double)RAND_MAX;
    }

    while (true) {
        printf("Benchmarking\n");
        auto begin = std::chrono::high_resolution_clock::now();
        for (uint64_t i = 0; i < ITERATIONS; i++) {
            results[i] = a[i] * b[i];
        }
        auto end = std::chrono::high_resolution_clock::now();

        double seconds = (end - begin).count() / 1e9;
        printf("Speed: %lf MDotProd/s\n", ((double)ITERATIONS / 1e6) / seconds);
    }

    const int TEST1 = sizeof(lia::Vec3);

    return 0;
}