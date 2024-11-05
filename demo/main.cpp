#include <stdio.h>
#include <inttypes.h>
#include <chrono>
#include "../lia/dense/static.h"
#include "../lia/dense/dynamic.h"
#include <stdlib.h>

#define VEC_SIZE    2
#define ITERATIONS  10000000
#define TEST_COUNT  100

int main() {
    // Allocate the test vectors
    printf("Allocating vectors\n");
    lia::SMatd<VEC_SIZE, VEC_SIZE>* a = new lia::SMatd<VEC_SIZE, VEC_SIZE>[ITERATIONS];
    lia::SMatd<VEC_SIZE, VEC_SIZE>* b = new lia::SMatd<VEC_SIZE, VEC_SIZE>[ITERATIONS];
    lia::SMatd<VEC_SIZE, VEC_SIZE>* c = new lia::SMatd<VEC_SIZE, VEC_SIZE>[ITERATIONS];

    // Fill with random data
    printf("Filling vectors\n");
    for (int i = 0; i < ITERATIONS; i++) {
        a[i](0, 0) = (double)rand() / (double)RAND_MAX;
        a[i](1, 0) = (double)rand() / (double)RAND_MAX;
        a[i](2, 0) = (double)rand() / (double)RAND_MAX;
        a[i](3, 0) = (double)rand() / (double)RAND_MAX;
        a[i](0, 1) = (double)rand() / (double)RAND_MAX;
        a[i](1, 1) = (double)rand() / (double)RAND_MAX;
        a[i](2, 1) = (double)rand() / (double)RAND_MAX;
        a[i](3, 1) = (double)rand() / (double)RAND_MAX;
        a[i](0, 2) = (double)rand() / (double)RAND_MAX;
        a[i](1, 2) = (double)rand() / (double)RAND_MAX;
        a[i](2, 2) = (double)rand() / (double)RAND_MAX;
        a[i](3, 2) = (double)rand() / (double)RAND_MAX;
        a[i](0, 3) = (double)rand() / (double)RAND_MAX;
        a[i](1, 3) = (double)rand() / (double)RAND_MAX;
        a[i](2, 3) = (double)rand() / (double)RAND_MAX;
        a[i](3, 3) = (double)rand() / (double)RAND_MAX;

        b[i](0, 0) = (double)rand() / (double)RAND_MAX;
        b[i](1, 0) = (double)rand() / (double)RAND_MAX;
        b[i](2, 0) = (double)rand() / (double)RAND_MAX;
        b[i](3, 0) = (double)rand() / (double)RAND_MAX;
        b[i](0, 1) = (double)rand() / (double)RAND_MAX;
        b[i](1, 1) = (double)rand() / (double)RAND_MAX;
        b[i](2, 1) = (double)rand() / (double)RAND_MAX;
        b[i](3, 1) = (double)rand() / (double)RAND_MAX;
        b[i](0, 2) = (double)rand() / (double)RAND_MAX;
        b[i](1, 2) = (double)rand() / (double)RAND_MAX;
        b[i](2, 2) = (double)rand() / (double)RAND_MAX;
        b[i](3, 2) = (double)rand() / (double)RAND_MAX;
        b[i](0, 3) = (double)rand() / (double)RAND_MAX;
        b[i](1, 3) = (double)rand() / (double)RAND_MAX;
        b[i](2, 3) = (double)rand() / (double)RAND_MAX;
        b[i](3, 3) = (double)rand() / (double)RAND_MAX;
    }

    double avg = 0.0;
    for (int i = 0; i < TEST_COUNT; i++) {
        printf("Benchmarking\n");
        auto begin = std::chrono::high_resolution_clock::now();
        for (uint64_t i = 0; i < ITERATIONS; i++) {
            c[i] = a[i] * b[i];
        }
        auto end = std::chrono::high_resolution_clock::now();

        double seconds = (end - begin).count() / 1e9;

        avg += ((double)ITERATIONS / 1e6) / seconds;
    }

    lia::Vec3f test({ 1.0f, 2.0f, 3.0f });

    printf("Speed: %lf MDotProd/s\n", avg / (double)TEST_COUNT);

    return 0;
}