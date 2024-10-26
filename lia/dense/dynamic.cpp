#include "dynamic.h"
#include <string.h>

namespace lia {
    template <typename DT>
    DMat<DT>::DMat() : ls(0), cs(0) {
        // Null out the buffer pointer
        _data = NULL;
    }

    template <typename DT>
    DMat<DT>::DMat(int lines, int columns) : ls(lines), cs(columns) {
        // Allocate the data buffer
        _data = new DT[ls*cs];
    }

    template <typename DT>
    DMat<DT>::~DMat() {
        // Free the data buffer if it was allocated
        if (_data) { delete[] _data; }
    }

    template class DMat<double>;
    template class DMat<float>;
    template class DMat<int>;

    template <typename DT>
    DVec<DT>::DVec() {}

    template <typename DT>
    DVec<DT>::DVec(int lines) : DMat<DT>(lines, 1) {}

    template class DVec<double>;
    template class DVec<float>;
    template class DVec<int>;
    
    template <typename T>
    void transpose(DMat<T>& result, const DVec<T>& value) {
        memcpy(result.data(), value.data(), value.ls * sizeof(T));
    }
    template void transpose<double>(DMat<double>& result, const DVec<double>& value);
    template void transpose<float>(DMat<float>& result, const DVec<float>& value);
    template void transpose<int>(DMat<int>& result, const DVec<int>& value);

    template <typename T>
    void transpose(DMat<T>& result, const DMat<T>& value) {
        const T* v = value.data();
        T* r = result.data();
        const int ls = value.ls;
        const int cs = value.cs;
        for (int i = 0; i < ls; i++) {
            const T* line = &v[i*cs];
            for (int j = 0; j < cs; j++) {
                r[j*ls + i] = line[j];
            }
        }
    }
    template void transpose<double>(DMat<double>& result, const DMat<double>& value);
    template void transpose<float>(DMat<float>& result, const DMat<float>& value);
    template void transpose<int>(DMat<int>& result, const DMat<int>& value);

    template <typename T>
    T norm(const DVec<T>& value) {
        const T* v = value.data();
        const int ls = value.ls;
        T sum = 0.0;
        for (int i = 0; i < ls; i++) {
            sum += v[i]*v[i];
        }
        if constexpr (std::is_same_v<T, float>) {
            return sqrtf(sum);
        }
        else {
            return sqrt(sum);
        }
    }
    template double norm<double>(const DVec<double>& value);
    template float norm<float>(const DVec<float>& value);
    template int norm<int>(const DVec<int>& value);

    template <typename T>
    void add(DVec<T>& result, const DVec<T>& left, const DVec<T>& right) {
        const T* a = left.data();
        const T* b = right.data();
        const int d = right.ls;
        T* r = result.data();
        for (int i = 0; i < d; i++) {
            r[i] = a[i] + b[i];
        }
    }
    template void add(DVec<double>& result, const DVec<double>& left, const DVec<double>& right);
    template void add(DVec<float>& result, const DVec<float>& left, const DVec<float>& right);
    template void add(DVec<int>& result, const DVec<int>& left, const DVec<int>& right);

    template <typename T>
    void add(DMat<T>& result, const DMat<T>& left, const DMat<T>& right) {
        const T* a = left.data();
        const T* b = right.data();
        const int d = right.ls * right.cs;
        T* r = result.data();
        for (int i = 0; i < d; i++) {
            r[i] = a[i] + b[i];
        }
    }
    template void add(DMat<double>& result, const DMat<double>& left, const DMat<double>& right);
    template void add(DMat<float>& result, const DMat<float>& left, const DMat<float>& right);
    template void add(DMat<int>& result, const DMat<int>& left, const DMat<int>& right);

    template <typename T>
    void sub(DVec<T>& result, const DVec<T>& left, const DVec<T>& right) {
        const T* a = left.data();
        const T* b = right.data();
        const int d = right.ls;
        T* r = result.data();
        for (int i = 0; i < d; i++) {
            r[i] = a[i] - b[i];
        }
    }
    template void sub(DVec<double>& result, const DVec<double>& left, const DVec<double>& right);
    template void sub(DVec<float>& result, const DVec<float>& left, const DVec<float>& right);
    template void sub(DVec<int>& result, const DVec<int>& left, const DVec<int>& right);

    template <typename T>
    void sub(DMat<T>& result, const DMat<T>& left, const DMat<T>& right) {
        const T* a = left.data();
        const T* b = right.data();
        const int d = right.ls * right.cs;
        T* r = result.data();
        for (int i = 0; i < d; i++) {
            r[i] = a[i] - b[i];
        }
    }
    template void sub(DMat<double>& result, const DMat<double>& left, const DMat<double>& right);
    template void sub(DMat<float>& result, const DMat<float>& left, const DMat<float>& right);
    template void sub(DMat<int>& result, const DMat<int>& left, const DMat<int>& right);

    template <typename T>
    void mul(DVec<T>& result, const DVec<T>& left, T right) {
        const T* v = left.data();
        const int d = left.ls;
        T* r = result.data();
        for (int i = 0; i < d; i++) {
            r[i] = v[i] * right;
        }
    }
    template void mul(DVec<double>& result, const DVec<double>& left, double right);
    template void mul(DVec<float>& result, const DVec<float>& left, float right);
    template void mul(DVec<int>& result, const DVec<int>& left, int right);

    template <typename T>
    void mul(DMat<T>& result, const DMat<T>& left, T right) {
        const T* m = left.data();
        const int d = right.ls * right.cs;
        T* r = result.data();
        for (int i = 0; i < d; i++) {
            r[i] = m[i] * right;
        }
    }
    template void mul(DMat<double>& result, const DMat<double>& left, double right);
    template void mul(DMat<float>& result, const DMat<float>& left, float right);
    template void mul(DMat<int>& result, const DMat<int>& left, int right);

    template <typename T>
    void div(DVec<T>& result, const DVec<T>& left, T right) {
        const T* v = left.data();
        const int d = left.ls;
        T* r = result.data();
        for (int i = 0; i < d; i++) {
            r[i] = v[i] / right;
        }
    }
    template void div(DVec<double>& result, const DVec<double>& left, double right);
    template void div(DVec<float>& result, const DVec<float>& left, float right);
    template void div(DVec<int>& result, const DVec<int>& left, int right);

    template <typename T>
    void div(DMat<T>& result, const DMat<T>& left, T right) {
        const T* m = left.data();
        const int d = right.ls * right.cs;
        T* r = result.data();
        for (int i = 0; i < d; i++) {
            r[i] = m[i] / right;
        }
    }
    template void div(DMat<double>& result, const DMat<double>& left, double right);
    template void div(DMat<float>& result, const DMat<float>& left, float right);
    template void div(DMat<int>& result, const DMat<int>& left, int right);

    template <typename T>
    void dot(T& result, const DVec<T>& left, const DVec<T>& right) {
        const T* a = left.data();
        const T* b = right.data();
        const int d = right.ls;
        result = 0.0;
        for (int i = 0; i < d; i++) {
            result += a[i]*b[i];
        }
    }
    template void dot(double& result, const DVec<double>& left, const DVec<double>& right);
    template void dot(float& result, const DVec<float>& left, const DVec<float>& right);
    template void dot(int& result, const DVec<int>& left, const DVec<int>& right);
    
    template <typename T>
    void dot(DVec<T>& result, const DMat<T>& left, const DVec<T>& right) {
        const T* da = left.data();
        const T* db = right.data();
        T* r = result.data();
        // TODO
    }
    template void dot(DVec<double>& result, const DMat<double>& left, const DVec<double>& right);
    template void dot(DVec<float>& result, const DMat<float>& left, const DVec<float>& right);
    template void dot(DVec<int>& result, const DMat<int>& left, const DVec<int>& right);

    
    template <typename T>
    void dot(DMat<T>& result, const DMat<T>& left, const DMat<T>& right) {
        const T* da = left.data();
        const T* db = right.data();
        T* r = result.data();
        // TODO
    }
    template void dot(DMat<double>& result, const DMat<double>& left, const DMat<double>& right);
    template void dot(DMat<float>& result, const DMat<float>& left, const DMat<float>& right);
    template void dot(DMat<int>& result, const DMat<int>& left, const DMat<int>& right);
}