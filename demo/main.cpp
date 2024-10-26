#include <stdio.h>
#include <inttypes.h>
#include <chrono>
#include "../lia/dense/static.h"
#include "../lia/dense/dynamic.h"
#include <stdlib.h>
#include <complex>
#include "tests.h"

#define VEC_SIZE    2
#define ITERATIONS  10000000
#define TEST_COUNT  100

int main() {
    try {
        // Small vector addition
        testAdd<2, 1>();
        testAdd<3, 1>();
        testAdd<4, 1>();

        // Large vector addition
        testAdd<5, 1>();

        // Small matrix addition
        testAdd<2, 2>();
        testAdd<3, 3>();
        testAdd<4, 4>();

        // Large matrix addition
        testAdd<5, 5>();

        // Small vector subtraction
        testSub<2, 1>();
        testSub<3, 1>();
        testSub<4, 1>();

        // Large vector subtraction
        testSub<5, 1>();

        // Small matrix subtraction
        testSub<2, 2>();
        testSub<3, 3>();
        testSub<4, 4>();

        // Large matrix subtraction
        testSub<5, 5>();

        // Small vector scalar multiplication
        testMulL<2, 1>();
        testMulR<2, 1>();
        testMulL<3, 1>();
        testMulR<3, 1>();
        testMulL<4, 1>();
        testMulR<4, 1>();

        // Large vector scalar multiplication
        testMulL<5, 1>();
        testMulR<5, 1>();

        // Small matrix scalar multiplication
        testMulL<2, 2>();
        testMulR<2, 2>();
        testMulL<3, 3>();
        testMulR<3, 3>();
        testMulL<4, 4>();
        testMulR<4, 4>();

        // Large matrix scalar multiplication
        testMulL<5, 5>();
        testMulR<5, 5>();

        // Small vector scalar division
        testDiv<2, 1>();
        testDiv<3, 1>();
        testDiv<4, 1>();

        // Large vector scalar division
        testDiv<5, 1>();

        // Small matrix scalar division
        testDiv<2, 2>();
        testDiv<3, 3>();
        testDiv<4, 4>();

        // Large matrix scalar division
        testDiv<5, 5>();

        // Small column vector dot product
        testDot<2, 1, 2, 1>();
        testDot<3, 1, 3, 1>();
        testDot<4, 1, 4, 1>();

        // Large column vector dot product
        testDot<5, 1, 5, 1>();

        // Small square matrix vector dot product
        testDot<2, 2, 2, 1>();
        testDot<3, 3, 3, 1>();
        testDot<4, 4, 4, 1>();

        // Large square matrix vector dot product
        testDot<5, 5, 5, 1>();

        // Small square matrix dot product
        testDot<2, 2, 2, 2>();
        testDot<3, 3, 3, 3>();
        testDot<4, 4, 4, 4>();

        // Large arbitrary matrix dot product
        testDot<6, 5, 5, 3>();

        // Cross product
        testCross();

        // ============= DONE =============
        printf("All tests passed successfully!\n");
        return 0;
    }
    catch ([[maybe_unused]] const std::runtime_error& e) {
        return -1;
    }

    lia::SMatd<4, 3> testMat;

    auto test = testMat.T() * testMat;

    lia::Vec3f a;
    lia::Vec3f b;
    lia::Vec3f c;

    lia::norm(a);

    lia::cross(c, a, b);

    // // Allocate the test vectors
    // printf("Allocating vectors\n");
    // lia::SMatd<VEC_SIZE, VEC_SIZE>* a = new lia::SMatd<VEC_SIZE, VEC_SIZE>[ITERATIONS];
    // lia::SMatd<VEC_SIZE, VEC_SIZE>* b = new lia::SMatd<VEC_SIZE, VEC_SIZE>[ITERATIONS];
    // lia::SMatd<VEC_SIZE, VEC_SIZE>* c = new lia::SMatd<VEC_SIZE, VEC_SIZE>[ITERATIONS];

    // // Fill with random data
    // printf("Filling vectors\n");
    // for (int i = 0; i < ITERATIONS; i++) {
    //     a[i](0, 0) = (double)rand() / (double)RAND_MAX;
    //     a[i](1, 0) = (double)rand() / (double)RAND_MAX;
    //     a[i](2, 0) = (double)rand() / (double)RAND_MAX;
    //     a[i](3, 0) = (double)rand() / (double)RAND_MAX;
    //     a[i](0, 1) = (double)rand() / (double)RAND_MAX;
    //     a[i](1, 1) = (double)rand() / (double)RAND_MAX;
    //     a[i](2, 1) = (double)rand() / (double)RAND_MAX;
    //     a[i](3, 1) = (double)rand() / (double)RAND_MAX;
    //     a[i](0, 2) = (double)rand() / (double)RAND_MAX;
    //     a[i](1, 2) = (double)rand() / (double)RAND_MAX;
    //     a[i](2, 2) = (double)rand() / (double)RAND_MAX;
    //     a[i](3, 2) = (double)rand() / (double)RAND_MAX;
    //     a[i](0, 3) = (double)rand() / (double)RAND_MAX;
    //     a[i](1, 3) = (double)rand() / (double)RAND_MAX;
    //     a[i](2, 3) = (double)rand() / (double)RAND_MAX;
    //     a[i](3, 3) = (double)rand() / (double)RAND_MAX;

    //     b[i](0, 0) = (double)rand() / (double)RAND_MAX;
    //     b[i](1, 0) = (double)rand() / (double)RAND_MAX;
    //     b[i](2, 0) = (double)rand() / (double)RAND_MAX;
    //     b[i](3, 0) = (double)rand() / (double)RAND_MAX;
    //     b[i](0, 1) = (double)rand() / (double)RAND_MAX;
    //     b[i](1, 1) = (double)rand() / (double)RAND_MAX;
    //     b[i](2, 1) = (double)rand() / (double)RAND_MAX;
    //     b[i](3, 1) = (double)rand() / (double)RAND_MAX;
    //     b[i](0, 2) = (double)rand() / (double)RAND_MAX;
    //     b[i](1, 2) = (double)rand() / (double)RAND_MAX;
    //     b[i](2, 2) = (double)rand() / (double)RAND_MAX;
    //     b[i](3, 2) = (double)rand() / (double)RAND_MAX;
    //     b[i](0, 3) = (double)rand() / (double)RAND_MAX;
    //     b[i](1, 3) = (double)rand() / (double)RAND_MAX;
    //     b[i](2, 3) = (double)rand() / (double)RAND_MAX;
    //     b[i](3, 3) = (double)rand() / (double)RAND_MAX;
    // }

    // double avg = 0.0;
    // for (int i = 0; i < TEST_COUNT; i++) {
    //     printf("Benchmarking\n");
    //     auto begin = std::chrono::high_resolution_clock::now();
    //     for (uint64_t i = 0; i < ITERATIONS; i++) {
    //         c[i] = a[i] * b[i];
    //     }
    //     auto end = std::chrono::high_resolution_clock::now();

    //     double seconds = (end - begin).count() / 1e9;

    //     avg += ((double)ITERATIONS / 1e6) / seconds;
    // }

    // auto test = b[0] * 4.0;

    // printf("Speed: %lf MDotProd/s\n", avg / (double)TEST_COUNT);

    return 0;
}