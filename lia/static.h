#pragma once
#include <complex>

namespace lia {
    /**
     * Statically allocated dense matrix.
    */
    template <int ls, int cs, typename T>
    class SMat {
    public:
        // Default constructor
        inline SMat() {}

        /**
         * Create a matrix and set all its elements to a value.
         * @param value Value to set all the elements to.
        */
        inline SMat(T value) {
            // Set all element to the same value
            for (int i = 0; i < ls*cs; i++) { data[i] = value; }
        }

        // Function operator to access elements
        inline T& operator()(int line, int column = 0) { return data[line*cs + column]; }
        inline const T& operator()(int line, int column = 0) const { return data[line*cs + column]; }

        // Array operator to access the data
        inline T& operator[](int id) { return data[id]; }
        inline const T& operator[](int id) const { return data[id]; }

        // Raw matrix data
        T data[ls*cs];
    };

    /**
     * Statically allocated vector. Equivalent to a statically allocated matrix with a single column.
    */
    template <int ls, typename T>
    using SVec = SMat<ls, 1, T>;

    // Common static vector and matrix types
    template <int ls>
    using SVecd = SVec<ls, double>;
    template <int ls>
    using SVecf = SVec<ls, float>;
    template <int ls>
    using SVeci = SVec<ls, int>;
    template <int ls, int cs>
    using SMatd = SMat<ls, cs, double>;
    template <int ls, int cs>
    using SMatf = SMat<ls, cs, float>;
    template <int ls, int cs>
    using SMati = SMat<ls, cs, int>;
    template <int ls>
    using SVeccd = SVec<ls, std::complex<double>>;
    template <int ls>
    using SVeccf = SVec<ls, std::complex<float>>;
    template <int ls>
    using SVecci = SVec<ls, std::complex<int>>;
    template <int ls, int cs>
    using SMatcd = SMat<ls, cs, std::complex<double>>;
    template <int ls, int cs>
    using SMatcf = SMat<ls, cs, std::complex<float>>;
    template <int ls, int cs>
    using SMatci = SMat<ls, cs, std::complex<int>>;

    // Common static vector and matrix sizes
    using Vec2d = SVecd<2>;
    using Vec3d = SVecd<3>;
    using Vec4d = SVecd<4>;
    using Mat2d = SMatd<2, 2>;
    using Mat3d = SMatd<3, 3>;
    using Mat4d = SMatd<4, 4>;
    using Vec2f = SVecf<2>;
    using Vec3f = SVecf<3>;
    using Vec4f = SVecf<4>;
    using Mat2f = SMatf<2, 2>;
    using Mat3f = SMatf<3, 3>;
    using Mat4f = SMatf<4, 4>;
    using Vec2i = SVeci<2>;
    using Vec3i = SVeci<3>;
    using Vec4i = SVeci<4>;
    using Mat2i = SMati<2, 2>;
    using Mat3i = SMati<3, 3>;
    using Mat4i = SMati<4, 4>;
    using Vec2cd = SVeccd<2>;
    using Vec3cd = SVeccd<3>;
    using Vec4cd = SVeccd<4>;
    using Mat2cd = SMatcd<2, 2>;
    using Mat3cd = SMatcd<3, 3>;
    using Mat4cd = SMatcd<4, 4>;
    using Vec2cf = SVeccf<2>;
    using Vec3cf = SVeccf<3>;
    using Vec4cf = SVeccf<4>;
    using Mat2cf = SMatcf<2, 2>;
    using Mat3cf = SMatcf<3, 3>;
    using Mat4cf = SMatcf<4, 4>;
    using Vec2ci = SVecci<2>;
    using Vec3ci = SVecci<3>;
    using Vec4ci = SVecci<4>;
    using Mat2ci = SMatci<2, 2>;
    using Mat3ci = SMatci<3, 3>;
    using Mat4ci = SMatci<4, 4>;

    // =============================== ADDITION ===============================

    // ============================== SUBTRACTION ==============================

    // ============================ MULTIPLICATION ============================

    // =============================== DIVISION ===============================

    // ============================== DOT PRODUCT ==============================

    // Dot product between static column vectors of size 2
    template <typename T>
    inline T operator*(const SVec<2, T>& left, const SVec<2, T>& right) {
        const T* a = left.data;
        const T* b = right.data;
        return a[0]*b[0] + a[1]*b[1];
    }

    // Dot product between static column vectors of size 3
    template <typename T>
    inline T operator*(const SVec<3, T>& left, const SVec<3, T>& right) {
        const T* a = left.data;
        const T* b = right.data;
        return a[0]*b[0] + a[1]*b[1] + a[2]*b[2];
    }

    // Dot product between static column vectors of size 4
    template <typename T>
    inline T operator*(const SVec<4, T>& left, const SVec<4, T>& right) {
        const T* a = left.data;
        const T* b = right.data;
        return a[0]*b[0] + a[1]*b[1] + a[2]*b[2] + a[3]*b[3];
    }

    // Dot product for static column vectors larger than size 4
    template <int d, typename T>
    inline T operator*(const SVec<d, T>& left, const SVec<d, T>& right) {
        const T* a = left.data;
        const T* b = right.data;
        T result = 0.0;
        for (int i = 0; i < d; i++) {
            result += a[i]*b[i];
        }
        return result;
    }

    // Dot product between static square matrix and column vectors of size 2
    template <typename T>
    inline SVec<2, T> operator*(const SMat<2, 2, T>& left, const SVec<2, T>& right) {
        SVec<2, T> out;
        const T* a = left.data;
        const T* b = right.data;
        T* o = out.data;
        o[0] = a[0]*b[0] + a[1]*b[1];
        o[1] = a[2]*b[0] + a[3]*b[1];
        return out;
    }

    // Dot product between static square matrix and column vectors of size 3
    template <typename T>
    inline SVec<3, T> operator*(const SMat<3, 3, T>& left, const SVec<3, T>& right) {
        SVec<3, T> out;
        const T* a = left.data;
        const T* b = right.data;
        T* o = out.data;
        o[0] = a[0]*b[0] + a[1]*b[1] + a[2]*b[2];
        o[1] = a[3]*b[0] + a[4]*b[1] + a[5]*b[2];
        o[2] = a[6]*b[0] + a[7]*b[1] + a[8]*b[2];
        return out;
    }

    // Dot product between static square matrix and column vectors of size 3
    template <typename T>
    inline SVec<4, T> operator*(const SMat<4, 4, T>& left, const SVec<4, T>& right) {
        SVec<4, T> out;
        const T* a = left.data;
        const T* b = right.data;
        T* o = out.data;
        o[0] = a[0]*b[0] + a[1]*b[1] + a[2]*b[2] + a[3]*b[3];
        o[1] = a[4]*b[0] + a[5]*b[1] + a[6]*b[2] + a[7]*b[3];
        o[2] = a[8]*b[0] + a[9]*b[1] + a[10]*b[2] + a[11]*b[3];
        o[3] = a[12]*b[0] + a[13]*b[1] + a[14]*b[2] + a[15]*b[3];
        return out;
    }

    // Dot product between static matrices of any size
    template <int a, int b, int c, typename T>
    inline SMat<a, c, T> operator*(const SMat<a, b, T>& left, const SMat<b, c, T>& right) {
        SMat<a, c, T> out;
        const T* da = left.data;
        const T* db = right.data;
        T* o = out.data;
        for (int i = 0; i < a; i++) {
            const T* line = &da[i*b];
            for (int j = 0; j < c; j++) {
                const T* col = &db[j];
                T* const sum = &o[i*c + j];
                *sum = 0;
                for (int k = 0; k < b; k++) {
                    *sum += line[k] * (*col);
                    col += c;
                }
            }
        }
        return out;
    }

    // ============================= CROSS PRODUCT =============================

    // ============================= FUNCTION API =============================

    /**
     * Take the dot product between two matrices or vectors.
     * @param result Matrix, vector or scalar to write the result to.
     * @param left Left hand matrix or vector.
     * @param right Right hand matrix or vector.
    */
    template <int d, typename T>
    inline void dot(T& result, const SVec<d, T>& left, const SVec<d, T>& right) {
        result = left * right;
    }
    template <int a, int b, int c, typename T>
    inline void dot(SMat<a, c, T>& result, const SMat<a, b, T>& left, const SMat<b, c, T>& right) {
        result = left * right;
    }
}