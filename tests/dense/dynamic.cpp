#include "../utt/utt.h"
#include "../../lia/dense/dynamic.h"

template <int d>
static inline lia::DVecd randVec() {
    lia::DVecd mat(d);
    for (int i = 0; i < d; i++) {
        mat[i] = (double)rand() / (double)RAND_MAX;
    }
    return mat;
}

template <int ls, int cs>
static inline lia::DMatd randMat() {
    lia::DMatd mat(ls, cs);
    for (int i = 0; i < ls; i++) {
        for (int j = 0; j < cs; j++) {
            mat(i, j) = (double)rand() / (double)RAND_MAX;
        }
    }
    return mat;
}

UT("Dynamic Clear(Vec)", {
    lia::DVecd a(42);
    double b = (double)rand() / (double)RAND_MAX;
    lia::clear(a, b);
    for (int i = 0; i < 42; i++) {
        if (a[i] != b) { throw std::runtime_error(""); }
    }
})

UT("Dynamic Clear(Mat)", {
    lia::DMatd a(69, 42);
    double b = (double)rand() / (double)RAND_MAX;
    lia::clear(a, b);
    for (int i = 0; i < 69*42; i++) {
        if (a[i] != b) { throw std::runtime_error(""); }
    }
})

UT("Dynamic Transpose(Vec -> Mat)", {
    lia::DVecd a = randVec<42>();
    lia::DMatd b(1, 42);
    lia::transpose(b, a);
    for (int i = 0; i < 42; i++) {
        if (a[i] != b[i]) { throw std::runtime_error(""); }
    }
})

UT("Dynamic Transpose(Mat -> Vec)", {
    lia::DMatd a = randMat<1, 42>();
    lia::DVecd b(42);
    lia::transpose(b, a);
    for (int i = 0; i < 42; i++) {
        if (a[i] != b[i]) { throw std::runtime_error(""); }
    }
})

UT("Dynamic Transpose(Mat -> Mat)", {
    lia::DMatd a = randMat<69, 42>();
    lia::DMatd b(42, 69);
    lia::transpose(b, a);
    for (int i = 0; i < 69; i++) {
        for (int j = 0; j < 42; j++) {
            if (a(i, j) != b(j, i)) { throw std::runtime_error(""); }
        }
    }
})

UT("Dynamic Norm", {
    lia::DVecd a = randVec<42>();
    double b = lia::norm(a);
    double sum = 0.0;
    for (int i = 0; i < 42; i++) {
        sum += a[i]*a[i];
    }
    if (sqrt(sum) != b) { throw std::runtime_error(""); }
})

UT("Dynamic Add(Vec)", {
    lia::DVecd a = randVec<42>();
    lia::DVecd b = randVec<42>();
    lia::DVecd c(42);
    lia::add(c, a, b);
    for (int i = 0; i < 42; i++) {
        if (c[i] != a[i] + b[i]) { throw std::runtime_error(""); }
    }
})


UT("Dynamic Add(Mat)", {
    lia::DMatd a = randMat<69, 42>();
    lia::DMatd b = randMat<69, 42>();
    lia::DMatd c(69, 42);
    lia::add(c, a, b);
    for (int i = 0; i < 69*42; i++) {
        if (c[i] != a[i] + b[i]) { throw std::runtime_error(""); }
    }
})

UT("Dynamic Sub(Vec)", {
    lia::DVecd a = randVec<42>();
    lia::DVecd b = randVec<42>();
    lia::DVecd c(42);
    lia::sub(c, a, b);
    for (int i = 0; i < 42; i++) {
        if (c[i] != a[i] - b[i]) { throw std::runtime_error(""); }
    }
})


UT("Dynamic Sub(Mat)", {
    lia::DMatd a = randMat<69, 42>();
    lia::DMatd b = randMat<69, 42>();
    lia::DMatd c(69, 42);
    lia::sub(c, a, b);
    for (int i = 0; i < 69*42; i++) {
        if (c[i] != a[i] - b[i]) { throw std::runtime_error(""); }
    }
})

UT("Dynamic Mul(Vec)", {
    lia::DVecd a = randVec<42>();
    double b = (double)rand() / (double)RAND_MAX;
    lia::DVecd c(42);
    lia::mul(c, a, b);
    for (int i = 0; i < 42; i++) {
        if (c[i] != a[i] * b) { throw std::runtime_error(""); }
    }
})


UT("Dynamic Mul(Mat)", {
    lia::DMatd a = randMat<69, 42>();
    double b = (double)rand() / (double)RAND_MAX;
    lia::DMatd c(69, 42);
    lia::mul(c, a, b);
    for (int i = 0; i < 69*42; i++) {
        if (c[i] != a[i] * b) { throw std::runtime_error(""); }
    }
})

UT("Dynamic Div(Vec)", {
    lia::DVecd a = randVec<42>();
    double b = (double)rand() / (double)RAND_MAX;
    lia::DVecd c(42);
    lia::div(c, a, b);
    for (int i = 0; i < 42; i++) {
        if (c[i] != a[i] / b) { throw std::runtime_error(""); }
    }
})


UT("Dynamic Div(Mat)", {
    lia::DMatd a = randMat<69, 42>();
    double b = (double)rand() / (double)RAND_MAX;
    lia::DMatd c(69, 42);
    lia::div(c, a, b);
    for (int i = 0; i < 69*42; i++) {
        if (c[i] != a[i] / b) { throw std::runtime_error(""); }
    }
})


UT("Dynamic Dot(Vec * Vec)", {
    lia::DVecd a = randVec<42>();
    lia::DVecd b = randVec<42>();
    double c;
    lia::dot(c, a, b);
    double sum = 0.0;
    for (int k = 0; k < 42; k++) {
        sum += a[k] * b[k];
    }
    if (c != sum) {
        throw std::runtime_error("");
    }
})

UT("Dynamic Dot(Mat * Vec)", {
    lia::DMatd a = randMat<69, 42>();
    lia::DVecd b = randVec<42>();
    lia::DVecd c(69);
    lia::dot(c, a, b);
    double sum = 0.0;
    for (int i = 0; i < 69; i++) {
        for (int j = 0; j < 1; j++) {
            double sum = 0.0;
            for (int k = 0; k < 42; k++) {
                sum += a(i, k) * b(k, j);
            }
            if (c(i, j) != sum) {
                throw std::runtime_error("");
            }
        }
    }
})

UT("Dynamic Dot(Mat * Mat)", {
    lia::DMatd a = randMat<69, 42>();
    lia::DMatd b = randMat<42, 52>();
    lia::DMatd c(69, 52);
    lia::dot(c, a, b);
    double sum = 0.0;
    for (int i = 0; i < 69; i++) {
        for (int j = 0; j < 52; j++) {
            double sum = 0.0;
            for (int k = 0; k < 42; k++) {
                sum += a(i, k) * b(k, j);
            }
            if (c(i, j) != sum) {
                throw std::runtime_error("");
            }
        }
    }
})

UT("Dynamic Cross", {
    lia::DVecd a = randVec<3>();
    lia::DVecd b = randVec<3>();
    lia::DVecd c(3);
    lia::cross(c, a, b);
    double s1 = a[1]*b[2] - a[2]*b[1];
    double s2 = a[2]*b[0] - a[0]*b[2];
    double s3 = a[0]*b[1] - a[1]*b[0];
    if (s1 != c[0] || s2 != c[1] || s3 != c[2]) {
        throw std::runtime_error("");
    }
})
