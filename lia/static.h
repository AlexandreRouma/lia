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

        // TODO: Initializer list

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

    // =============================== ADDITION ===============================

    // Addition operator for static column vectors of size 2
    template <typename T>
    inline SVec<2, T> operator+(const SVec<2, T>& left, const SVec<2, T>& right) {
        SVec<2, T> out;
        const T* a = left.data;
        const T* b = right.data;
        T* o = out.data;
        o[0] = a[0] + b[0];
        o[1] = a[1] + b[1];
        return out;
    }

    // Addition operator for static column vectors of size 3
    template <typename T>
    inline SVec<3, T> operator+(const SVec<3, T>& left, const SVec<3, T>& right) {
        SVec<3, T> out;
        const T* a = left.data;
        const T* b = right.data;
        T* o = out.data;
        o[0] = a[0] + b[0];
        o[1] = a[1] + b[1];
        o[2] = a[2] + b[2];
        return out;
    }

    // Addition operator for static column vectors of size 4
    template <typename T>
    inline SVec<4, T> operator+(const SVec<4, T>& left, const SVec<4, T>& right) {
        SVec<4, T> out;
        const T* a = left.data;
        const T* b = right.data;
        T* o = out.data;
        o[0] = a[0] + b[0];
        o[1] = a[1] + b[1];
        o[2] = a[2] + b[2];
        o[3] = a[3] + b[3];
        return out;
    }

    // Addition operator for static column vectors of sany size
    template <int d, typename T>
    inline SVec<d, T> operator+(const SVec<d, T>& left, const SVec<d, T>& right) {
        SVec<d, T> out;
        const T* a = left.data;
        const T* b = right.data;
        T* o = out.data;
        for (int i = 0; i < d; i++) {
            o[i] = a[i] + b[i];
        }
        return out;
    }

    // Addition operator for static square matrices of size 2
    template <typename T>
    inline SMat<2, 2, T> operator+(const SMat<2, 2, T>& left, const SMat<2, 2, T>& right) {
        SMat<2, 2, T> out;
        const T* a = left.data;
        const T* b = right.data;
        T* o = out.data;
        o[0] = a[0] + b[0]; o[1] = a[1] + b[1];
        o[2] = a[2] + b[2]; o[3] = a[3] + b[3];
        return out;
    }

    // Addition operator for static square matrices of size 3
    template <typename T>
    inline SMat<3, 3, T> operator+(const SMat<3, 3, T>& left, const SMat<3, 3, T>& right) {
        SMat<3, 3, T> out;
        const T* a = left.data;
        const T* b = right.data;
        T* o = out.data;
        o[0] = a[0] + b[0]; o[1] = a[1] + b[1]; o[2] = a[2] + b[2];
        o[3] = a[3] + b[3]; o[4] = a[4] + b[4]; o[5] = a[5] + b[5];
        o[6] = a[6] + b[6]; o[7] = a[7] + b[7]; o[8] = a[8] + b[8];
        return out;
    }

    // Addition operator for static square matrices of size 4
    template <typename T>
    inline SMat<4, 4, T> operator+(const SMat<4, 4, T>& left, const SMat<4, 4, T>& right) {
        SMat<4, 4, T> out;
        const T* a = left.data;
        const T* b = right.data;
        T* o = out.data;
        o[0] = a[0] + b[0]; o[1] = a[1] + b[1]; o[2] = a[2] + b[2]; o[3] = a[3] + b[3];
        o[4] = a[4] + b[4]; o[5] = a[5] + b[5]; o[6] = a[6] + b[6]; o[7] = a[7] + b[7];
        o[8] = a[8] + b[8]; o[9] = a[9] + b[9]; o[10] = a[10] + b[10]; o[11] = a[11] + b[11];
        o[12] = a[12] + b[12]; o[13] = a[13] + b[13]; o[14] = a[14] + b[14]; o[15] = a[15] + b[15];
        return out;
    }

    // Addition operator for static matrices of sany size
    template <int ls, int cs, typename T>
    inline SMat<ls, cs, T> operator+(const SMat<ls, cs, T>& left, const SMat<ls, cs, T>& right) {
        SMat<ls, cs, T> out;
        const T* a = left.data;
        const T* b = right.data;
        T* o = out.data;
        for (int i = 0; i < ls*cs; i++) {
            o[i] = a[i] + b[i];
        }
        return out;
    }

    // ============================== SUBTRACTION ==============================

    // Addition operator for static column vectors of size 2
    template <typename T>
    inline SVec<2, T> operator-(const SVec<2, T>& left, const SVec<2, T>& right) {
        SVec<2, T> out;
        const T* a = left.data;
        const T* b = right.data;
        T* o = out.data;
        o[0] = a[0] - b[0];
        o[1] = a[1] - b[1];
        return out;
    }

    // Addition operator for static column vectors of size 3
    template <typename T>
    inline SVec<3, T> operator-(const SVec<3, T>& left, const SVec<3, T>& right) {
        SVec<3, T> out;
        const T* a = left.data;
        const T* b = right.data;
        T* o = out.data;
        o[0] = a[0] - b[0];
        o[1] = a[1] - b[1];
        o[2] = a[2] - b[2];
        return out;
    }

    // Addition operator for static column vectors of size 4
    template <typename T>
    inline SVec<4, T> operator-(const SVec<4, T>& left, const SVec<4, T>& right) {
        SVec<4, T> out;
        const T* a = left.data;
        const T* b = right.data;
        T* o = out.data;
        o[0] = a[0] - b[0];
        o[1] = a[1] - b[1];
        o[2] = a[2] - b[2];
        o[3] = a[3] - b[3];
        return out;
    }

    // Addition operator for static column vectors of sany size
    template <int d, typename T>
    inline SVec<d, T> operator-(const SVec<d, T>& left, const SVec<d, T>& right) {
        SVec<d, T> out;
        const T* a = left.data;
        const T* b = right.data;
        T* o = out.data;
        for (int i = 0; i < d; i++) {
            o[i] = a[i] - b[i];
        }
        return out;
    }

    // Addition operator for static square matrices of size 2
    template <typename T>
    inline SMat<2, 2, T> operator-(const SMat<2, 2, T>& left, const SMat<2, 2, T>& right) {
        SMat<2, 2, T> out;
        const T* a = left.data;
        const T* b = right.data;
        T* o = out.data;
        o[0] = a[0] - b[0]; o[1] = a[1] - b[1];
        o[2] = a[2] - b[2]; o[3] = a[3] - b[3];
        return out;
    }

    // Addition operator for static square matrices of size 3
    template <typename T>
    inline SMat<3, 3, T> operator-(const SMat<3, 3, T>& left, const SMat<3, 3, T>& right) {
        SMat<3, 3, T> out;
        const T* a = left.data;
        const T* b = right.data;
        T* o = out.data;
        o[0] = a[0] - b[0]; o[1] = a[1] - b[1]; o[2] = a[2] - b[2];
        o[3] = a[3] - b[3]; o[4] = a[4] - b[4]; o[5] = a[5] - b[5];
        o[6] = a[6] - b[6]; o[7] = a[7] - b[7]; o[8] = a[8] - b[8];
        return out;
    }

    // Addition operator for static square matrices of size 4
    template <typename T>
    inline SMat<4, 4, T> operator-(const SMat<4, 4, T>& left, const SMat<4, 4, T>& right) {
        SMat<4, 4, T> out;
        const T* a = left.data;
        const T* b = right.data;
        T* o = out.data;
        o[0] = a[0] - b[0]; o[1] = a[1] - b[1]; o[2] = a[2] - b[2]; o[3] = a[3] - b[3];
        o[4] = a[4] - b[4]; o[5] = a[5] - b[5]; o[6] = a[6] - b[6]; o[7] = a[7] - b[7];
        o[8] = a[8] - b[8]; o[9] = a[9] - b[9]; o[10] = a[10] - b[10]; o[11] = a[11] - b[11];
        o[12] = a[12] - b[12]; o[13] = a[13] - b[13]; o[14] = a[14] - b[14]; o[15] = a[15] - b[15];
        return out;
    }

    // Addition operator for static matrices of sany size
    template <int ls, int cs, typename T>
    inline SMat<ls, cs, T> operator-(const SMat<ls, cs, T>& left, const SMat<ls, cs, T>& right) {
        SMat<ls, cs, T> out;
        const T* a = left.data;
        const T* b = right.data;
        T* o = out.data;
        for (int i = 0; i < ls*cs; i++) {
            o[i] = a[i] - b[i];
        }
        return out;
    }

    // ============================ MULTIPLICATION ============================

    // Multiplication operator for static column vectors of size 2 (scalar on the right)
    template <typename TV, typename TS>
    inline SVec<2, TV> operator*(const SVec<2, TV>& left, const TS& right) {
        SVec<2, TV> out;
        const TV* a = left.data;
        TV* o = out.data;
        o[0] = a[0] * (TV)right;
        o[1] = a[1] * (TV)right;
        return out;
    }

    // Multiplication operator for static column vectors of size 2 (scalar on the left)
    template <typename TV, typename TS>
    inline SVec<2, TV> operator*(const TS& left, const SVec<2, TV>& right) {
        SVec<2, TV> out;
        const TV* b = right.data;
        TV* o = out.data;
        o[0] = b[0] * (TV)left;
        o[1] = b[1] * (TV)left;
        return out;
    }

    // Multiplication operator for static column vectors of size 3 (scalar on the right)
    template <typename TV, typename TS>
    inline SVec<3, TV> operator*(const SVec<3, TV>& left, const TS& right) {
        SVec<3, TV> out;
        const TV* a = left.data;
        TV* o = out.data;
        o[0] = a[0] * (TV)right;
        o[1] = a[1] * (TV)right;
        o[2] = a[2] * (TV)right;
        return out;
    }

    // Multiplication operator for static column vectors of size 3 (scalar on the left)
    template <typename TV, typename TS>
    inline SVec<3, TV> operator*(const TS& left, const SVec<3, TV>& right) {
        SVec<3, TV> out;
        const TV* b = right.data;
        TV* o = out.data;
        o[0] = b[0] * (TV)left;
        o[1] = b[1] * (TV)left;
        o[2] = b[2] * (TV)left;
        return out;
    }

    // Multiplication operator for static column vectors of size 4 (scalar on the right)
    template <typename TV, typename TS>
    inline SVec<4, TV> operator*(const SVec<4, TV>& left, const TS& right) {
        SVec<4, TV> out;
        const TV* a = left.data;
        TV* o = out.data;
        o[0] = a[0] * (TV)right;
        o[1] = a[1] * (TV)right;
        o[2] = a[2] * (TV)right;
        o[3] = a[3] * (TV)right;
        return out;
    }

    // Multiplication operator for static column vectors of size 4 (scalar on the left)
    template <typename TV, typename TS>
    inline SVec<4, TV> operator*(const TS& left, const SVec<4, TV>& right) {
        SVec<4, TV> out;
        const TV* b = right.data;
        TV* o = out.data;
        o[0] = b[0] * (TV)left;
        o[1] = b[1] * (TV)left;
        o[2] = b[2] * (TV)left;
        o[3] = b[3] * (TV)left;
        return out;
    }

    // Multiplication operator for static column vectors of any size (scalar on the right)
    template <int d, typename TV, typename TS>
    inline SVec<d, TV> operator*(const SVec<d, TV>& left, const TS& right) {
        SVec<d, TV> out;
        const TV* a = left.data;
        TV* o = out.data;
        for (int i = 0; i < d; i++) {
            o[i] = a[i] * (TV)right;
        }
        return out;
    }

    // Multiplication operator for static column vectors of any size (scalar on the left)
    template <int d, typename TV, typename TS>
    inline SVec<d, TV> operator*(const TS& left, const SVec<d, TV>& right) {
        SVec<d, TV> out;
        const TV* b = right.data;
        TV* o = out.data;
        for (int i = 0; i < d; i++) {
            o[i] = b[i] * (TV)left;
        }
        return out;
    }

    // Multiplication operator for static square matrices of size 2 (scalar on the right)
    template <typename TV, typename TS>
    inline SMat<2, 2, TV> operator*(const SMat<2, 2, TV>& left, const TS& right) {
        SMat<2, 2, TV> out;
        const TV* a = left.data;
        TV* o = out.data;
        o[0] = a[0] * (TV)right; o[1] = a[1] * (TV)right;
        o[2] = a[2] * (TV)right; o[3] = a[3] * (TV)right;
        return out;
    }

    // Multiplication operator for static square matrices of size 2 (scalar on the left)
    template <typename TV, typename TS>
    inline SMat<2, 2, TV> operator*(const TS& left, const SMat<2, 2, TV>& right) {
        SMat<2, 2, TV> out;
        const TV* b = right.data;
        TV* o = out.data;
        o[0] = b[0] * (TV)left; o[1] = b[1] * (TV)left;
        o[2] = b[2] * (TV)left; o[3] = b[3] * (TV)left;
        return out;
    }

    // Multiplication operator for static square matrices of size 3 (scalar on the right)
    template <typename TV, typename TS>
    inline SMat<3, 3, TV> operator*(const SMat<3, 3, TV>& left, const TS& right) {
        SMat<3, 3, TV> out;
        const TV* a = left.data;
        TV* o = out.data;
        o[0] = a[0] * (TV)right; o[1] = a[1] * (TV)right; o[2] = a[2] * (TV)right;
        o[3] = a[3] * (TV)right; o[4] = a[4] * (TV)right; o[5] = a[5] * (TV)right;
        o[6] = a[6] * (TV)right; o[7] = a[7] * (TV)right; o[8] = a[8] * (TV)right;
        return out;
    }

    // Multiplication operator for static square matrices of size 3 (scalar on the left)
    template <typename TV, typename TS>
    inline SMat<3, 3, TV> operator*(const TS& left, const SMat<3, 3, TV>& right) {
        SMat<3, 3, TV> out;
        const TV* b = right.data;
        TV* o = out.data;
        o[0] = b[0] * (TV)left; o[1] = b[1] * (TV)left; o[2] = b[2] * (TV)left;
        o[3] = b[3] * (TV)left; o[4] = b[4] * (TV)left; o[5] = b[5] * (TV)left;
        o[6] = b[6] * (TV)left; o[7] = b[7] * (TV)left; o[8] = b[8] * (TV)left;
        return out;
    }

    // Multiplication operator for static square matrices of size 4 (scalar on the right)
    template <typename TV, typename TS>
    inline SMat<4, 4, TV> operator*(const SMat<4, 4, TV>& left, const TS& right) {
        SMat<4, 4, TV> out;
        const TV* a = left.data;
        TV* o = out.data;
        o[0] = a[0] * (TV)right; o[1] = a[1] * (TV)right; o[2] = a[2] * (TV)right; o[3] = a[3] * (TV)right;
        o[4] = a[4] * (TV)right; o[5] = a[5] * (TV)right; o[6] = a[6] * (TV)right; o[7] = a[7] * (TV)right;
        o[8] = a[8] * (TV)right; o[9] = a[9] * (TV)right; o[10] = a[10] * (TV)right; o[11] = a[11] * (TV)right;
        o[12] = a[12] * (TV)right; o[13] = a[13] * (TV)right; o[14] = a[14] * (TV)right; o[15] = a[15] * (TV)right;
        return out;
    }

    // Multiplication operator for static square matrices of size 4 (scalar on the left)
    template <typename TV, typename TS>
    inline SMat<4, 4, TV> operator*(const TS& left, const SMat<4, 4, TV>& right) {
        SMat<4, 4, TV> out;
        const TV* b = right.data;
        TV* o = out.data;
        o[0] = b[0] * (TV)left; o[1] = b[1] * (TV)left; o[2] = b[2] * (TV)left; o[3] = b[3] * (TV)left;
        o[4] = b[4] * (TV)left; o[5] = b[5] * (TV)left; o[6] = b[6] * (TV)left; o[7] = b[7] * (TV)left;
        o[8] = b[8] * (TV)left; o[9] = b[9] * (TV)left; o[10] = b[10] * (TV)left; o[11] = b[11] * (TV)left;
        o[12] = b[12] * (TV)left; o[13] = b[13] * (TV)left; o[14] = b[14] * (TV)left; o[15] = b[15] * (TV)left;
        return out;
    }

    // Multiplication operator for static column vectors of any size (scalar on the right)
    template <int ls, int cs, typename TV, typename TS>
    inline SMat<ls, cs, TV> operator*(const SMat<ls, cs, TV>& left, const TS& right) {
        SMat<ls, cs, TV> out;
        const TV* a = left.data;
        TV* o = out.data;
        for (int i = 0; i < ls*cs; i++) {
            o[i] = a[i] * (TV)right;
        }
        return out;
    }

    // Multiplication operator for static column vectors of any size (scalar on the left)
    template <int ls, int cs, typename TV, typename TS>
    inline SMat<ls, cs, TV> operator*(const TS& left, const SMat<ls, cs, TV>& right) {
        SMat<ls, cs, TV> out;
        const TV* b = right.data;
        TV* o = out.data;
        for (int i = 0; i < ls*cs; i++) {
            o[i] = b[i] * (TV)left;
        }
        return out;
    }

    // =============================== DIVISION ===============================

    // Multiplication operator for static column vectors of size 2
    template <typename TV, typename TS>
    inline SVec<2, TV> operator/(const SVec<2, TV>& left, const TS& right) {
        SVec<2, TV> out;
        const TV* a = left.data;
        TV* o = out.data;
        o[0] = a[0] / (TV)right;
        o[1] = a[1] / (TV)right;
        return out;
    }

    // Multiplication operator for static column vectors of size 3
    template <typename TV, typename TS>
    inline SVec<3, TV> operator/(const SVec<3, TV>& left, const TS& right) {
        SVec<3, TV> out;
        const TV* a = left.data;
        TV* o = out.data;
        o[0] = a[0] / (TV)right;
        o[1] = a[1] / (TV)right;
        o[2] = a[2] / (TV)right;
        return out;
    }

    // Multiplication operator for static column vectors of size 4
    template <typename TV, typename TS>
    inline SVec<4, TV> operator/(const SVec<4, TV>& left, const TS& right) {
        SVec<4, TV> out;
        const TV* a = left.data;
        TV* o = out.data;
        o[0] = a[0] / (TV)right;
        o[1] = a[1] / (TV)right;
        o[2] = a[2] / (TV)right;
        o[3] = a[3] / (TV)right;
        return out;
    }

    // Multiplication operator for static column vectors of any size
    template <int d, typename TV, typename TS>
    inline SVec<d, TV> operator/(const SVec<d, TV>& left, const TS& right) {
        SVec<d, TV> out;
        const TV* a = left.data;
        TV* o = out.data;
        for (int i = 0; i < d; i++) {
            o[i] = a[i] / (TV)right;
        }
        return out;
    }

    // Multiplication operator for static square matrices of size 2
    template <typename TV, typename TS>
    inline SMat<2, 2, TV> operator/(const SMat<2, 2, TV>& left, const TS& right) {
        SMat<2, 2, TV> out;
        const TV* a = left.data;
        TV* o = out.data;
        o[0] = a[0] / (TV)right; o[1] = a[1] / (TV)right;
        o[2] = a[2] / (TV)right; o[3] = a[3] / (TV)right;
        return out;
    }

    // Multiplication operator for static square matrices of size 3
    template <typename TV, typename TS>
    inline SMat<3, 3, TV> operator/(const SMat<3, 3, TV>& left, const TS& right) {
        SMat<3, 3, TV> out;
        const TV* a = left.data;
        TV* o = out.data;
        o[0] = a[0] / (TV)right; o[1] = a[1] / (TV)right; o[2] = a[2] / (TV)right;
        o[3] = a[3] / (TV)right; o[4] = a[4] / (TV)right; o[5] = a[5] / (TV)right;
        o[6] = a[6] / (TV)right; o[7] = a[7] / (TV)right; o[8] = a[8] / (TV)right;
        return out;
    }

    // Multiplication operator for static square matrices of size 4
    template <typename TV, typename TS>
    inline SMat<4, 4, TV> operator/(const SMat<4, 4, TV>& left, const TS& right) {
        SMat<4, 4, TV> out;
        const TV* a = left.data;
        TV* o = out.data;
        o[0] = a[0] / (TV)right; o[1] = a[1] / (TV)right; o[2] = a[2] / (TV)right; o[3] = a[3] / (TV)right;
        o[4] = a[4] / (TV)right; o[5] = a[5] / (TV)right; o[6] = a[6] / (TV)right; o[7] = a[7] / (TV)right;
        o[8] = a[8] / (TV)right; o[9] = a[9] / (TV)right; o[10] = a[10] / (TV)right; o[11] = a[11] / (TV)right;
        o[12] = a[12] / (TV)right; o[13] = a[13] / (TV)right; o[14] = a[14] / (TV)right; o[15] = a[15] / (TV)right;
        return out;
    }

    // Multiplication operator for static column vectors of any size
    template <int ls, int cs, typename TV, typename TS>
    inline SMat<ls, cs, TV> operator/(const SMat<ls, cs, TV>& left, const TS& right) {
        SMat<ls, cs, TV> out;
        const TV* a = left.data;
        TV* o = out.data;
        for (int i = 0; i < ls*cs; i++) {
            o[i] = a[i] / (TV)right;
        }
        return out;
    }

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

    // Dot product between static square matrix and column vectors of size 4
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

    // Dot product between square static matrices and vector of any size
    template <int d, typename T>
    inline SVec<d, T> operator*(const SMat<d, d, T>& left, const SVec<d, T>& right) {
        SVec<d, T> out;
        const T* da = left.data;
        const T* db = right.data;
        T* o = out.data;
        for (int i = 0; i < d; i++) {
            const T* line = &da[i*d];
            T* const sum = &o[i];
            *sum = 0;
            for (int j = 0; j < d; j++) {
                *sum += line[j]*db[j];
            }
        }
        return out;
    }

    // TODO: Dot product between square small matrices

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

    template <typename T>
    inline SVec<3, T> operator^(const SVec<3, T>& left, const SVec<3, T>& right) {
        SVec<3, T> out;
        const T* a = left.data;
        const T* b = right.data;
        T* o = out.data;
        o[0] = a[1]*b[2] - a[2]*b[1];
        o[1] = a[2]*b[0] - a[0]*b[2];
        o[2] = a[0]*b[1] - a[1]*b[0];
        return out;
    }

    // ============================= FUNCTION API =============================

    // TODO: Maybe, maybe not
}