#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>
#include "../lia/dense/static.h"

template <int ls, int cs>
void testAdd() {
    // Print test info
    printf("add %dx%d: ", ls, cs);

    // Fill up the matrices with random shit
    lia::SMatd<ls, cs> a;
    lia::SMatd<ls, cs> b;
    for (int i = 0; i < ls; i++) {
        for (int j = 0; j < cs; j++) {
            a(i, j) = (double)rand() / (double)RAND_MAX;
            b(i, j) = (double)rand() / (double)RAND_MAX;
        }
    }

    // Run operation
    lia::SMatd<ls, cs> o = a + b;

    // Verify
    for (int i = 0; i < ls; i++) {
        for (int j = 0; j < cs; j++) {
            if (o(i, j) != a(i, j) + b(i, j)) {
                printf("FAIL\n");
                throw std::runtime_error("Test failed");
            }
        }
    }
    printf("PASS\n");
}

template <int ls, int cs>
void testSub() {
    // Print test info
    printf("sub %dx%d: ", ls, cs);

    // Fill up the matrices with random shit
    lia::SMatd<ls, cs> a;
    lia::SMatd<ls, cs> b;
    for (int i = 0; i < ls; i++) {
        for (int j = 0; j < cs; j++) {
            a(i, j) = (double)rand() / (double)RAND_MAX;
            b(i, j) = (double)rand() / (double)RAND_MAX;
        }
    }

    // Run operation
    lia::SMatd<ls, cs> o = a - b;

    // Verify
    for (int i = 0; i < ls; i++) {
        for (int j = 0; j < cs; j++) {
            if (o(i, j) != a(i, j) - b(i, j)) {
                printf("FAIL\n");
                throw std::runtime_error("Test failed");
            }
        }
    }
    printf("PASS\n");
}

template <int ls, int cs>
void testMulL() {
    // Print test info
    printf("mul(L) %dx%d: ", ls, cs);

    // Fill up the matrices with random shit
    double a = (double)rand() / (double)RAND_MAX;
    lia::SMatd<ls, cs> b;
    for (int i = 0; i < ls; i++) {
        for (int j = 0; j < cs; j++) {
            b(i, j) = (double)rand() / (double)RAND_MAX;
        }
    }

    // Run operation
    lia::SMatd<ls, cs> o = a * b;

    // Verify
    for (int i = 0; i < ls; i++) {
        for (int j = 0; j < cs; j++) {
            if (o(i, j) != a * b(i, j)) {
                printf("FAIL\n");
                throw std::runtime_error("Test failed");
            }
        }
    }
    printf("PASS\n");
}

template <int ls, int cs>
void testMulR() {
    // Print test info
    printf("mul(R) %dx%d: ", ls, cs);

    // Fill up the matrices with random shit
    lia::SMatd<ls, cs> a;
    double b = (double)rand() / (double)RAND_MAX;
    for (int i = 0; i < ls; i++) {
        for (int j = 0; j < cs; j++) {
            a(i, j) = (double)rand() / (double)RAND_MAX;
        }
    }

    // Run operation
    lia::SMatd<ls, cs> o = a * b;

    // Verify
    for (int i = 0; i < ls; i++) {
        for (int j = 0; j < cs; j++) {
            if (o(i, j) != a(i, j) * b) {
                printf("FAIL\n");
                throw std::runtime_error("Test failed");
            }
        }
    }
    printf("PASS\n");
}

template <int ls, int cs>
void testDiv() {
    // Print test info
    printf("div %dx%d: ", ls, cs);

    // Fill up the matrices with random shit
    lia::SMatd<ls, cs> a;
    double b = (double)rand() / (double)RAND_MAX;
    for (int i = 0; i < ls; i++) {
        for (int j = 0; j < cs; j++) {
            a(i, j) = (double)rand() / (double)RAND_MAX;
        }
    }

    // Run operation
    lia::SMatd<ls, cs> o = a / b;

    // Verify
    for (int i = 0; i < ls; i++) {
        for (int j = 0; j < cs; j++) {
            if (o(i, j) != a(i, j) / b) {
                printf("FAIL\n");
                throw std::runtime_error("Test failed");
            }
        }
    }
    printf("PASS\n");
}

template <int a, int b, int c, int d>
void testDot() {
    // Print test info
    printf("dot %dx%d * %dx%d: ", a, b, c, d);

    // Fill up the matrices with random shit
    lia::SMatd<a, b> ma;
    lia::SMatd<c, d> mb;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            ma(i, j) = (double)rand() / (double)RAND_MAX;
        }
    }
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < d; j++) {
            mb(i, j) = (double)rand() / (double)RAND_MAX;
        }
    }

    if constexpr (b == 1 && d == 1) {
        // Run operation
        double o = ma * mb;

        // Verify
        double sum = 0.0;
        for (int k = 0; k < a; k++) {
            sum += ma[k] * mb[k];
        }
        if (o != sum) {
            printf("FAIL\n");
            throw std::runtime_error("Test failed");
        }
    }
    else {
        // Run operation
        lia::SMatd<a, d> o = ma * mb;

        // Verify
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < d; j++) {
                double sum = 0.0;
                for (int k = 0; k < b; k++) {
                    sum += ma(i, k) * mb(k, j);
                }
                if (o(i, j) != sum) {
                    printf("FAIL\n");
                    throw std::runtime_error("Test failed");
                }
            }
        }
    }
    
    printf("PASS\n");
}

void testCross() {
    // Print test info
    printf("cross: ");

    // Fill up the matrices with random shit
    lia::Vec3d a;
    lia::Vec3d b;
    for (int i = 0; i < 3; i++) {
        a[i] = (double)rand() / (double)RAND_MAX;
        b[i] = (double)rand() / (double)RAND_MAX;
    }

    // Run operation
    lia::Vec3d o = a ^ b;

    // Verify
    double s1 = a[1]*b[2] - a[2]*b[1];
    double s2 = a[2]*b[0] - a[0]*b[2];
    double s3 = a[0]*b[1] - a[1]*b[0];
    if (s1 != o[0] || s2 != o[1] || s3 != o[2]) {
        printf("FAIL\n");
        throw std::runtime_error("Test failed");
    }
    
    printf("PASS\n");
}