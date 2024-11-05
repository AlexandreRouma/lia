#include "../utt/utt.h"
#include "../../lia/dense/static.h"

template <int ls, int cs>
static inline lia::SMatd<ls, cs> randMat() {
    lia::SMatd<ls, cs> mat;
    for (int i = 0; i < ls; i++) {
        for (int j = 0; j < cs; j++) {
            mat(i, j) = (double)rand() / (double)RAND_MAX;
        }
    }
    return mat;
}

template <int ls, int cs>
static inline void testClear() {
    lia::SMatd<ls, cs> a;
    double b = (double)rand() / (double)RAND_MAX;
    lia::clear(a, b);
    for (int i = 0; i < ls*cs; i++) {
        if (a[i] != b) { throw std::runtime_error(""); }
    }
}

UT("Static Clear 2x1", { testClear<2, 1>(); })
UT("Static Clear 3x1", { testClear<3, 1>(); })
UT("Static Clear 4x1", { testClear<4, 1>(); })
UT("Static Clear 5x1", { testClear<5, 1>(); })
UT("Static Clear 2x2", { testClear<2, 2>(); })
UT("Static Clear 3x3", { testClear<3, 3>(); })
UT("Static Clear 4x4", { testClear<4, 4>(); })
UT("Static Clear 5x5", { testClear<5, 5>(); })

template <int ls, int cs>
static inline void testTranspose() {
    lia::SMatd<ls, cs> a = randMat<ls, cs>();
    lia::SMatd<cs, ls> b = a.T();
    for (int i = 0; i < ls; i++) {
        for (int j = 0; j < cs; j++) {
            if (a(i,j) != b(j,i)) { throw std::runtime_error(""); }
        }
    }
}

UT("Static Transpose 2x1", { testTranspose<2, 1>(); })
UT("Static Transpose 3x1", { testTranspose<3, 1>(); })
UT("Static Transpose 4x1", { testTranspose<4, 1>(); })
UT("Static Transpose 5x1", { testTranspose<5, 1>(); })
UT("Static Transpose 2x2", { testTranspose<2, 2>(); })
UT("Static Transpose 3x3", { testTranspose<3, 3>(); })
UT("Static Transpose 4x4", { testTranspose<4, 4>(); })
UT("Static Transpose 5x5", { testTranspose<5, 5>(); })

template <int d>
static inline void testNorm() {
    lia::SVecd<d> a = randMat<d, 1>();
    double norm = a.N();
    double sum = 0.0;
    for (int i = 0; i < d; i++) {
        sum += a[i]*a[i];
    }
    if (sqrt(sum) != norm) { throw std::runtime_error(""); }
}

UT("Static Norm 2x1", { testNorm<2>(); })
UT("Static Norm 3x1", { testNorm<3>(); })
UT("Static Norm 4x1", { testNorm<4>(); })
UT("Static Norm 5x1", { testNorm<5>(); })

template <int ls, int cs>
static inline void testAdd() {
    lia::SMatd<ls, cs> a = randMat<ls, cs>();
    lia::SMatd<ls, cs> b = randMat<ls, cs>();
    lia::SMatd<ls, cs> c = a + b;
    for (int i = 0; i < ls*cs; i++) {
        if (c[i] != a[i] + b[i]) { throw std::runtime_error(""); }
    }
}

UT("Static Add 2x1", { testAdd<2, 1>(); })
UT("Static Add 3x1", { testAdd<3, 1>(); })
UT("Static Add 4x1", { testAdd<4, 1>(); })
UT("Static Add 5x1", { testAdd<5, 1>(); })
UT("Static Add 2x2", { testAdd<2, 2>(); })
UT("Static Add 3x3", { testAdd<3, 3>(); })
UT("Static Add 4x4", { testAdd<4, 4>(); })
UT("Static Add 5x5", { testAdd<5, 5>(); })

template <int ls, int cs>
static inline void testSub() {
    lia::SMatd<ls, cs> a = randMat<ls, cs>();
    lia::SMatd<ls, cs> b = randMat<ls, cs>();
    lia::SMatd<ls, cs> c = a - b;
    for (int i = 0; i < ls*cs; i++) {
        if (c[i] != a[i] - b[i]) { throw std::runtime_error(""); }
    }
}

UT("Static Sub 2x1", { testSub<2, 1>(); })
UT("Static Sub 3x1", { testSub<3, 1>(); })
UT("Static Sub 4x1", { testSub<4, 1>(); })
UT("Static Sub 5x1", { testSub<5, 1>(); })
UT("Static Sub 2x2", { testSub<2, 2>(); })
UT("Static Sub 3x3", { testSub<3, 3>(); })
UT("Static Sub 4x4", { testSub<4, 4>(); })
UT("Static Sub 5x5", { testSub<5, 5>(); })

template <int ls, int cs>
static inline void testMul() {
    lia::SMatd<ls, cs> a = randMat<ls, cs>();
    double b = (double)rand() / (double)RAND_MAX;
    lia::SMatd<ls, cs> c = a * b;
    for (int i = 0; i < ls*cs; i++) {
        if (c[i] != a[i] * b) { throw std::runtime_error(""); }
    }
}

UT("Static Mul 2x1", { testMul<2, 1>(); })
UT("Static Mul 3x1", { testMul<3, 1>(); })
UT("Static Mul 4x1", { testMul<4, 1>(); })
UT("Static Mul 5x1", { testMul<5, 1>(); })
UT("Static Mul 2x2", { testMul<2, 2>(); })
UT("Static Mul 3x3", { testMul<3, 3>(); })
UT("Static Mul 4x4", { testMul<4, 4>(); })
UT("Static Mul 5x5", { testMul<5, 5>(); })

template <int ls, int cs>
static inline void testDiv() {
    lia::SMatd<ls, cs> a = randMat<ls, cs>();
    double b = (double)rand() / (double)RAND_MAX;
    lia::SMatd<ls, cs> c = a / b;
    for (int i = 0; i < ls*cs; i++) {
        if (c[i] != a[i] / b) { throw std::runtime_error(""); }
    }
}

UT("Static Div 2x1", { testDiv<2, 1>(); })
UT("Static Div 3x1", { testDiv<3, 1>(); })
UT("Static Div 4x1", { testDiv<4, 1>(); })
UT("Static Div 5x1", { testDiv<5, 1>(); })
UT("Static Div 2x2", { testDiv<2, 2>(); })
UT("Static Div 3x3", { testDiv<3, 3>(); })
UT("Static Div 4x4", { testDiv<4, 4>(); })
UT("Static Div 5x5", { testDiv<5, 5>(); })

template <int a, int b, int c, int d>
static inline void testDot() {
    lia::SMatd<a, b> ma = randMat<a, b>();
    lia::SMatd<c, d> mb = randMat<c, d>();
    if constexpr (b == 1 && d == 1) {
        double o = ma * mb;
        double sum = 0.0;
        for (int k = 0; k < a; k++) {
            sum += ma[k] * mb[k];
        }
        if (o != sum) {
            throw std::runtime_error("");
        }
    }
    else {
        lia::SMatd<a, d> o = ma * mb;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < d; j++) {
                double sum = 0.0;
                for (int k = 0; k < b; k++) {
                    sum += ma(i, k) * mb(k, j);
                }
                if (o(i, j) != sum) {
                    throw std::runtime_error("");
                }
            }
        }
    }
}

UT("Static Dot 2x1 * 2x1", { testDot<2, 1, 2, 1>(); })
UT("Static Dot 3x1 * 3x1", { testDot<3, 1, 3, 1>(); })
UT("Static Dot 4x1 * 4x1", { testDot<4, 1, 4, 1>(); })
UT("Static Dot 5x1 * 5x1", { testDot<5, 1, 5, 1>(); })
UT("Static Dot 2x2 * 2x1", { testDot<2, 2, 2, 1>(); })
UT("Static Dot 3x3 * 3x1", { testDot<3, 3, 3, 1>(); })
UT("Static Dot 4x4 * 4x1", { testDot<4, 4, 4, 1>(); })
UT("Static Dot 5x5 * 5x1", { testDot<5, 5, 5, 1>(); })
UT("Static Dot 2x2 * 2x2", { testDot<2, 2, 2, 2>(); })
UT("Static Dot 3x3 * 3x3", { testDot<3, 3, 3, 3>(); })
UT("Static Dot 4x4 * 4x4", { testDot<4, 4, 4, 4>(); })
UT("Static Dot 5x5 * 5x5", { testDot<5, 5, 5, 5>(); })
UT("Static Dot 6x5 * 5x3", { testDot<6, 5, 5, 3>(); })

UT("Static Cross 3x3", {
    lia::Vec3d a = randMat<3, 1>();
    lia::Vec3d b = randMat<3, 1>();
    lia::Vec3d c = a ^ b;
    double s1 = a[1]*b[2] - a[2]*b[1];
    double s2 = a[2]*b[0] - a[0]*b[2];
    double s3 = a[0]*b[1] - a[1]*b[0];
    if (s1 != c[0] || s2 != c[1] || s3 != c[2]) {
        throw std::runtime_error("");
    }
})