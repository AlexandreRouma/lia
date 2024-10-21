#pragma once
#include <string.h>

namespace lia {
    /**
     * Statically allocated matrix.
    */
    template <int ls, int cs>
    class SMat {
    public:
        // Default constructor
        inline SMat() {}

        /**
         * Create a matrix and set all its elements to a value.
         * @param value Value to set all the elements to.
        */
        inline SMat(double value) {
            // Set all element to the same value
            for (int i = 0; i < ls*cs; i++) { _data[i] = value; }
        }

        // Function operator to access elements
        double& operator()(int line, int column = 0) { return _data[line*cs + column]; }
        const double& operator()(int line, int column = 0) const { return _data[line*cs + column]; }

        // Array operator to access the data
        double& operator[](int id) { return _data[id]; }
        const double& operator[](int id) const { return _data[id]; }

        // Raw matrix data
        double data[ls*cs];
    };

    /**
     * Dynamically allocated matrix.
    */
    class DMat {
    public:
        // Default constructor
        inline DMat() : lines(0), columns(0) {}

        /**
         * Create a dynamic matrix.
         * @param lines Number of lines of the matrix.
         * @param columns Number of columns of the matrix.
        */
        inline DMat(int lines, int columns) : lines(lines), columns(columns) {
            // Allocate the data buffer
            data = new double[lines*columns];
        }

        // Destructor
        inline ~DMat() {
            // Delete the data buffer if it was allocated
            if (data) { delete[] data; }
        }

        // Function operator to access elements
        inline double& operator()(int line, int column = 0) { return data[line*columns + column]; }
        inline const double& operator()(int line, int column = 0) const { return data[line*columns + column]; }

        const int lines;
        const int columns;
        double* data = NULL;
    };

    /**
     * Statically allocated vector. Equivalent to a statically allocated matrix with a single column.
    */
    template <int ls>
    using SVec = SMat<ls, 1>;

    // Common static vector and matrix sizes
    using Vec2 = SVec<2>;
    using Vec3 = SVec<3>;
    using Vec4 = SVec<4>;
    using Mat2 = SMat<2, 2>;
    using Mat3 = SMat<3, 3>;
    using Mat4 = SMat<4, 4>;

    // =============================== ADDITION ===============================

    // ============================== SUBTRACTION ==============================

    // ============================== DOT PRODUCT ==============================

    // Dot product between static column vectors of size 2
    inline double operator*(const Vec2& left, const Vec2& right) {
        const double* a = left.data;
        const double* b = right.data;
        return a[0]*b[0] + a[1]*b[1];
    }

    // Dot product between static column vectors of size 3
    inline double operator*(const Vec3& left, const Vec3& right) {
        const double* a = left.data;
        const double* b = right.data;
        return a[0]*b[0] + a[1]*b[1] + a[2]*b[2];
    }

    // Dot product between static column vectors of size 4
    inline double operator*(const Vec4& left, const Vec4& right) {
        const double* a = left.data;
        const double* b = right.data;
        return a[0]*b[0] + a[1]*b[1] + a[2]*b[2] + a[3]*b[3];
    }

    // Dot product for static column vectors larger than size 4
    template <int d>
    inline double operator*(const SVec<d>& left, const SVec<d>& right) {
        const double* a = left.data;
        const double* b = right.data;
        double result = 0.0;
        for (int i = 0; i < d; i++) {
            result += a[i]*b[i];
        }
        return result;
    }

    // Dot product between static square matrix and column vectors of size 2
    inline Vec2 operator*(const Mat2& left, const Vec2& right) {
        Vec2 out;
        const double* a = left.data;
        const double* b = right.data;
        double* o = out.data;
        o[0] = a[0]*b[0] + a[1]*b[1];
        o[1] = a[2]*b[0] + a[3]*b[1];
        return out;
    }

    // Dot product between static square matrix and column vectors of size 3
    inline Vec3 operator*(const Mat3& left, const Vec3& right) {
        Vec3 out;
        const double* a = left.data;
        const double* b = right.data;
        double* o = out.data;
        o[0] = a[0]*b[0] + a[1]*b[1] + a[2]*b[2];
        o[1] = a[3]*b[0] + a[4]*b[1] + a[5]*b[2];
        o[2] = a[6]*b[0] + a[7]*b[1] + a[8]*b[2];
        return out;
    }

    // Dot product between static square matrix and column vectors of size 3
    inline Vec4 operator*(const Mat4& left, const Vec4& right) {
        Vec4 out;
        const double* a = left.data;
        const double* b = right.data;
        double* o = out.data;
        o[0] = a[0]*b[0] + a[1]*b[1] + a[2]*b[2] + a[3]*b[3];
        o[1] = a[4]*b[0] + a[5]*b[1] + a[6]*b[2] + a[7]*b[3];
        o[2] = a[8]*b[0] + a[9]*b[1] + a[10]*b[2] + a[11]*b[3];
        o[3] = a[12]*b[0] + a[13]*b[1] + a[14]*b[2] + a[15]*b[3];
        return out;
    }
}
