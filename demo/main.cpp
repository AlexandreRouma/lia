#include <stdio.h>
#include <inttypes.h>
#include <chrono>
#include "../lia/static.h"
#include <stdlib.h>
#include <complex>
#include "tests.h"

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

        // TODO: Dot product between square small matrices

        // Large arbitrary matrix dot product
        testDot<6, 5, 5, 3>();

        // Cross product
        testCross();

        // ============= DONE =============
        printf("All tests passed successfully!\n");
        return 0;
    }
    catch (const std::runtime_error& e) {
        return -1;
    }
}