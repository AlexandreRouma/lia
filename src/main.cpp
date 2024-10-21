#include <stdio.h>
#include <inttypes.h>
#include <chrono>
#include "../lia/lia.h"

void testFunc(const lia::Mat& a, const lia::Mat& b) {
    printf("A: %dx%d\n", a.lines(), a.columns());
    printf("B: %dx%d\n", b.lines(), b.columns());
}

int main() {
    lia::Vec3 testVec;
    lia::Mat3 testMat;

    lia::Vec3 test = testMat * testVec;

    lia::Vec3 out;
    lia::cross(out, testVec, test);

    testFunc(testVec, testMat);

    return 0;
}