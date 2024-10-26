#pragma once
#include <initializer_list>
#include "../force_inline.h"

namespace lia {
    /**
     * Statically allocated dense matrix.
    */
    template <int ls, int cs, typename DT>
    class SMat {
    public:
        // Default constructor
        constexpr LIA_FORCE_INLINE SMat() {}

        /**
         * Create a matrix or vector and set all its elements to a value.
         * @param value Value to set all the elements to.
        */
        constexpr LIA_FORCE_INLINE SMat(DT value) {
            // Set all element to the same value
            for (int i = 0; i < ls*cs; i++) { data[i] = value; }
        }

        /**
         * Create a matrix or vector and set its elemements
         * @param value Value to set all the elements to.
        */
        constexpr LIA_FORCE_INLINE SMat(DT v1, DT v2) {
            static_assert(ls == 2 && cs == 1, "The size of the matrix/vector is not 2x1");
            data[0] = v1;
            data[1] = v2;
        }

        /**
         * Create a matrix or vector and set its elemements
         * @param value Value to set all the elements to.
        */
        constexpr LIA_FORCE_INLINE SMat(DT v1, DT v2, DT v3) {
            static_assert(ls == 3 && cs == 1, "The size of the matrix/vector is not 3x1");
            data[0] = v1;
            data[1] = v2;
            data[2] = v3;
        }

        /**
         * Create a matrix or vector and set its elemements
         * @param value Value to set all the elements to.
        */
        constexpr LIA_FORCE_INLINE SMat(DT v1, DT v2, DT v3, DT v4) {
            static_assert(ls == 4 && cs == 1, "The size of the matrix/vector is not 4x1");
            data[0] = v1;
            data[1] = v2;
            data[2] = v3;
            data[3] = v4;
        }

        /**
         * Create a matrix or vector and set its elements.
         * @param values Values for each of its elements.
        */
        constexpr LIA_FORCE_INLINE SMat(std::initializer_list<DT> values) {
            // Set all element to their given value
            for (int i = 0; i < ls*cs; i++) { data[i] = values[i]; }
        }

        // Function operator to access elements
        constexpr LIA_FORCE_INLINE DT& operator()(int line, int column = 0) { return data[line*cs + column]; }
        constexpr LIA_FORCE_INLINE const DT& operator()(int line, int column = 0) const { return data[line*cs + column]; }

        // Array operator to access the data
        constexpr LIA_FORCE_INLINE DT& operator[](int id) { return data[id]; }
        constexpr LIA_FORCE_INLINE const DT& operator[](int id) const { return data[id]; }

        // In-place addition operator
        constexpr LIA_FORCE_INLINE void operator+=(const SMat<ls, cs, DT>& right) {
            add(*this, *this, right);
        }

        // In-place subtraction operator
        constexpr LIA_FORCE_INLINE void operator-=(const SMat<ls, cs, DT>& right) {
            sub(*this, *this, right);
        }

        // In-place scalar multiplication operator
        template <typename TS>
        constexpr LIA_FORCE_INLINE void operator*=(const TS& right) {
            mul(*this, *this, (DT)right);
        }

        // In-place scalar division operator
        template <typename TS>
        constexpr LIA_FORCE_INLINE void operator/=(const TS& right) {
            div(*this, *this, (DT)right);
        }

        // In-place cross product operator
        constexpr LIA_FORCE_INLINE void operator^=(const SMat<ls, cs, DT>& right) {
            static_assert(ls == 3 && cs == 1, "The cross product operator can only be used on 3 element column vectors");
            cross(*this, *this, right);
        }

        /**
         * Transpose a matrix or vector.
         * @param result Matrix or vector to write the result to.
         * @param left Matrix or vector to transpose.
        */
        constexpr LIA_FORCE_INLINE SMat<cs, ls, DT> T() {
            SMat<cs, ls, DT> result;
            transpose(result, *this);
            return result;
        }

        /**
         * Compute the euclidian norm of a vector.
         * @param value Vector to take the euclidian norm of.
         * @return Euclidian norm of the vector.
        */
        LIA_FORCE_INLINE DT norm() {
            static_assert(cs == 1, "Can only take the norm of a vector");
            return lia::norm(*this);
        }

        // Raw matrix data
        DT data[ls*cs];
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

    // =============================== TRANSPOSE ===============================

    /**
     * Transpose a matrix or vector.
     * @param result Matrix or vector to write the result to.
     * @param left Matrix or vector to transpose.
    */

    template <typename T>
    static constexpr LIA_FORCE_INLINE void transpose(SMat<1, 2, T>& result, const SVec<2, T>& value) {
        const T* v = value.data;
        T* r = result.data;
        r[0] = data[0];
        r[1] = data[1];
    }

    template <typename T>
    static constexpr LIA_FORCE_INLINE void transpose(SMat<1, 3, T>& result, const SVec<3, T>& value) {
        const T* v = value.data;
        T* r = result.data;
        r[0] = data[0];
        r[1] = data[1];
        r[2] = data[2];
    }

    template <typename T>
    static constexpr LIA_FORCE_INLINE void transpose(SMat<1, 4, T>& result, const SVec<4, T>& value) {
        const T* v = value.data;
        T* r = result.data;
        r[0] = data[0];
        r[1] = data[1];
        r[2] = data[2];
        r[3] = data[3];
    }

    template <int d, typename T>
    static constexpr LIA_FORCE_INLINE void transpose(SMat<1, d, T>& result, const SVec<d, T>& value) {
        memcpy(result.data, value.data);
    }

    template <typename T>
    static constexpr LIA_FORCE_INLINE void transpose(SMat<2, 2, T>& result, const SMat<2, 2, T>& value) {
        const T* v = value.data;
        T* r = result.data;
        r[0] = data[0]; r[1] = data[2];
        r[2] = data[1]; r[3] = data[3];
    }

    template <typename T>
    static constexpr LIA_FORCE_INLINE void transpose(SMat<3, 3, T>& result, const SMat<3, 3, T>& value) {
        const T* v = value.data;
        T* r = result.data;
        r[0] = data[0]; r[1] = data[3]; r[2] = data[6];
        r[3] = data[1]; r[4] = data[4]; r[5] = data[7];
        r[6] = data[2]; r[7] = data[5]; r[8] = data[8];
    }

    template <typename T>
    static constexpr LIA_FORCE_INLINE void transpose(SMat<4, 4, T>& result, const SMat<4, 4, T>& value) {
        const T* v = value.data;
        T* r = result.data;
        r[0] = data[0]; r[1] = data[4]; r[2] = data[8]; r[3] = data[12];
        r[4] = data[1]; r[5] = data[5]; r[6] = data[9]; r[7] = data[13];
        r[8] = data[2]; r[9] = data[6]; r[10] = data[10]; r[11] = data[14];
        r[12] = data[3]; r[13] = data[7]; r[14] = data[11]; r[15] = data[15];
    }

    template <int ls, int cs, typename T>
    static constexpr LIA_FORCE_INLINE void transpose(SMat<cs, ls, T>& result, const SMat<ls, cs, T>& value) {
        const T* v = value.data;
        T* r = result.data;
        for (int i = 0; i < ls; i++) {
            const T* line = &v[i*cs];
            for (int j = 0; j < cs; j++) {
                r[j*ls + i] = line[j];
            }
        }
    }

    // ================================= NORM =================================

    /**
     * Compute the euclidian norm of a vector.
     * @param value Vector to take the euclidian norm of.
     * @return Euclidian norm of the vector.
    */

    template <typename T>
    static LIA_FORCE_INLINE T norm(const SVec<2, T>& value) {
        const T* v = value.data;
        if constexpr (std::is_same_v<T, float>) {
            return sqrtf(v[0]*v[0] + v[1]*v[1]);
        }
        else {
            return sqrt(v[0]*v[0] + v[1]*v[1]);
        }
    }

    template <typename T>
    static LIA_FORCE_INLINE T norm(const SVec<3, T>& value) {
        const T* v = value.data;
        if constexpr (std::is_same_v<T, float>) {
            return sqrtf(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
        }
        else {
            return sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
        }
    }

    template <typename T>
    static LIA_FORCE_INLINE T norm(const SVec<3, T>& value) {
        const T* v = value.data;
        if constexpr (std::is_same_v<T, float>) {
            return sqrtf(v[0]*v[0] + v[1]*v[1] + v[2]*v[2] + v[3]*v[3]);
        }
        else {
            return sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2] + v[3]*v[3]);
        }
    }

    template <int d, typename T>
    static LIA_FORCE_INLINE T norm(const SVec<3, T>& value) {
        const T* v = value.data;
        T sum = 0.0;
        for (int i = 0; i < d; i++) {
            sum += v[i]*v[i];
        }
        if constexpr (std::is_same_v<T, float>) {
            return sqrtf(sum);
        }
        else {
            return sqrt(sum);
        }
    }

    // =============================== ADDITION ===============================

    /**
     * Add two matrices or vectors.
     * @param result Matrix or vector to write the result to.
     * @param left Left-hand matrix or vector.
     * @param right Right-hand matrix or vector.
    */

    template <typename T>
    static constexpr LIA_FORCE_INLINE void add(SVec<2, T>& result, const SVec<2, T>& left, const SVec<2, T>& right) {
        const T* a = left.data;
        const T* b = right.data;
        T* r = result.data;
        r[0] = a[0] + b[0];
        r[1] = a[1] + b[1];
    }

    template <typename T>
    static constexpr LIA_FORCE_INLINE void add(SVec<3, T>& result, const SVec<3, T>& left, const SVec<3, T>& right) {
        const T* a = left.data;
        const T* b = right.data;
        T* r = result.data;
        r[0] = a[0] + b[0];
        r[1] = a[1] + b[1];
        r[2] = a[2] + b[2];
    }

    template <typename T>
    static constexpr LIA_FORCE_INLINE void add(SVec<4, T>& result, const SVec<4, T>& left, const SVec<4, T>& right) {
        const T* a = left.data;
        const T* b = right.data;
        T* r = result.data;
        r[0] = a[0] + b[0];
        r[1] = a[1] + b[1];
        r[2] = a[2] + b[2];
        r[3] = a[3] + b[3];
    }

    template <int d, typename T>
    static constexpr LIA_FORCE_INLINE void add(SVec<d, T>& result, const SVec<d, T>& left, const SVec<d, T>& right) {
        const T* a = left.data;
        const T* b = right.data;
        T* r = result.data;
        for (int i = 0; i < d; i++) {
            r[i] = a[i] + b[i];
        }
    }

    template <typename T>
    static constexpr LIA_FORCE_INLINE void add(SMat<2, 2, T>& result, const SMat<2, 2, T>& left, const SMat<2, 2, T>& right) {
        const T* a = left.data;
        const T* b = right.data;
        T* r = result.data;
        r[0] = a[0] + b[0]; r[1] = a[1] + b[1];
        r[2] = a[2] + b[2]; r[3] = a[3] + b[3];
    }

    template <typename T>
    static constexpr LIA_FORCE_INLINE void add(SMat<3, 3, T>& result, const SMat<3, 3, T>& left, const SMat<3, 3, T>& right) {
        const T* a = left.data;
        const T* b = right.data;
        T* r = result.data;
        r[0] = a[0] + b[0]; r[1] = a[1] + b[1]; r[2] = a[2] + b[2];
        r[3] = a[3] + b[3]; r[4] = a[4] + b[4]; r[5] = a[5] + b[5];
        r[6] = a[6] + b[6]; r[7] = a[7] + b[7]; r[8] = a[8] + b[8];
    }

    template <typename T>
    static constexpr LIA_FORCE_INLINE void add(SMat<4, 4, T>& result, const SMat<4, 4, T>& left, const SMat<4, 4, T>& right) {
        const T* a = left.data;
        const T* b = right.data;
        T* r = result.data;
        r[0] = a[0] + b[0]; r[1] = a[1] + b[1]; r[2] = a[2] + b[2]; r[3] = a[3] + b[3];
        r[4] = a[4] + b[4]; r[5] = a[5] + b[5]; r[6] = a[6] + b[6]; r[7] = a[7] + b[7];
        r[8] = a[8] + b[8]; r[9] = a[9] + b[9]; r[10] = a[10] + b[10]; r[11] = a[11] + b[11];
        r[12] = a[12] + b[12]; r[13] = a[13] + b[13]; r[14] = a[14] + b[14]; r[15] = a[15] + b[15];
    }

    template <int ls, int cs, typename T>
    static constexpr LIA_FORCE_INLINE void add(SMat<cs, ls, T>& result, const SMat<cs, ls, T>& left, const SMat<cs, ls, T>& right) {
        const T* a = left.data;
        const T* b = right.data;
        T* r = result.data;
        for (int i = 0; i < ls*cs; i++) {
            r[i] = a[i] + b[i];
        }
    }

    // Addition operator for static matrices and vectors
    template <int ls, int cs, typename T>
    static constexpr LIA_FORCE_INLINE SMat<ls, cs, T> operator+(const SMat<ls, cs, T>& left, const SMat<ls, cs, T>& right) {
        SMat<ls, cs, T> result;
        add(result, left, right);
        return result;
    }

    // ============================== SUBTRACTION ==============================

    /**
     * Subtract two matrices or vectors.
     * @param result Matrix or vector to write the result to.
     * @param left Left-hand matrix or vector.
     * @param right Right-hand matrix or vector.
    */

    template <typename T>
    static constexpr LIA_FORCE_INLINE void sub(SVec<2, T>& result, const SVec<2, T>& left, const SVec<2, T>& right) {
        const T* a = left.data;
        const T* b = right.data;
        T* r = result.data;
        r[0] = a[0] - b[0];
        r[1] = a[1] - b[1];
    }

    template <typename T>
    static constexpr LIA_FORCE_INLINE void sub(SVec<3, T>& result, const SVec<3, T>& left, const SVec<3, T>& right) {
        const T* a = left.data;
        const T* b = right.data;
        T* r = result.data;
        r[0] = a[0] - b[0];
        r[1] = a[1] - b[1];
        r[2] = a[2] - b[2];
    }

    template <typename T>
    static constexpr LIA_FORCE_INLINE void sub(SVec<4, T>& result, const SVec<4, T>& left, const SVec<4, T>& right) {
        const T* a = left.data;
        const T* b = right.data;
        T* r = result.data;
        r[0] = a[0] - b[0];
        r[1] = a[1] - b[1];
        r[2] = a[2] - b[2];
        r[3] = a[3] - b[3];
    }

    template <int d, typename T>
    static constexpr LIA_FORCE_INLINE void sub(SVec<d, T>& result, const SVec<d, T>& left, const SVec<d, T>& right) {
        const T* a = left.data;
        const T* b = right.data;
        T* r = result.data;
        for (int i = 0; i < d; i++) {
            r[i] = a[i] - b[i];
        }
    }

    template <typename T>
    static constexpr LIA_FORCE_INLINE void sub(SMat<2, 2, T>& result, const SMat<2, 2, T>& left, const SMat<2, 2, T>& right) {
        const T* a = left.data;
        const T* b = right.data;
        T* r = result.data;
        r[0] = a[0] - b[0]; r[1] = a[1] - b[1];
        r[2] = a[2] - b[2]; r[3] = a[3] - b[3];
    }

    template <typename T>
    static constexpr LIA_FORCE_INLINE void sub(SMat<3, 3, T>& result, const SMat<3, 3, T>& left, const SMat<3, 3, T>& right) {
        const T* a = left.data;
        const T* b = right.data;
        T* r = result.data;
        r[0] = a[0] - b[0]; r[1] = a[1] - b[1]; r[2] = a[2] - b[2];
        r[3] = a[3] - b[3]; r[4] = a[4] - b[4]; r[5] = a[5] - b[5];
        r[6] = a[6] - b[6]; r[7] = a[7] - b[7]; r[8] = a[8] - b[8];
    }

    template <typename T>
    static constexpr LIA_FORCE_INLINE void sub(SMat<4, 4, T>& result, const SMat<4, 4, T>& left, const SMat<4, 4, T>& right) {
        const T* a = left.data;
        const T* b = right.data;
        T* r = result.data;
        r[0] = a[0] - b[0]; r[1] = a[1] - b[1]; r[2] = a[2] - b[2]; r[3] = a[3] - b[3];
        r[4] = a[4] - b[4]; r[5] = a[5] - b[5]; r[6] = a[6] - b[6]; r[7] = a[7] - b[7];
        r[8] = a[8] - b[8]; r[9] = a[9] - b[9]; r[10] = a[10] - b[10]; r[11] = a[11] - b[11];
        r[12] = a[12] - b[12]; r[13] = a[13] - b[13]; r[14] = a[14] - b[14]; r[15] = a[15] - b[15];
    }

    template <int ls, int cs, typename T>
    static constexpr LIA_FORCE_INLINE void sub(SMat<cs, ls, T>& result, const SMat<cs, ls, T>& left, const SMat<cs, ls, T>& right) {
        const T* a = left.data;
        const T* b = right.data;
        T* r = result.data;
        for (int i = 0; i < ls*cs; i++) {
            r[i] = a[i] - b[i];
        }
    }

    // Addition operator for static matrices and vectors
    template <int ls, int cs, typename T>
    static constexpr LIA_FORCE_INLINE SMat<ls, cs, T> operator-(const SMat<ls, cs, T>& left, const SMat<ls, cs, T>& right) {
        SMat<ls, cs, T> result;
        sub(result, left, right);
        return result;
    }

    // ============================ MULTIPLICATION ============================

    /**
     * Do scalar multiplication between a matrix or vector and a scalar.
     * @param result Matrix, vector or scalar to write the result to.
     * @param value Matrix or vector to multiply.
     * @param right Scalar to multiply the matrix or vector by.
    */

    template <typename T>
    static constexpr LIA_FORCE_INLINE void mul(SVec<2, T>& result, const SVec<2, T>& value, const T& scalar) {
        const T* v = value.data;
        T* r = result.data;
        r[0] = v[0] * scalar;
        r[1] = v[1] * scalar;
    }

    template <typename T>
    static constexpr LIA_FORCE_INLINE void mul(SVec<3, T>& result, const SVec<3, T>& value, const T& scalar) {
        const T* v = value.data;
        T* r = result.data;
        r[0] = v[0] * scalar;
        r[1] = v[1] * scalar;
        r[2] = v[2] * scalar;
    }

    template <typename T>
    static constexpr LIA_FORCE_INLINE void mul(SVec<4, T>& result, const SVec<4, T>& value, const T& scalar) {
        const T* v = value.data;
        T* r = result.data;
        r[0] = v[0] * scalar;
        r[1] = v[1] * scalar;
        r[2] = v[2] * scalar;
        r[3] = v[3] * scalar;
    }

    template <int d, typename T>
    static constexpr LIA_FORCE_INLINE void mul(SVec<d, T>& result, const SVec<d, T>& value, const T& scalar) {
        const T* v = value.data;
        T* r = result.data;
        for (int i = 0; i < d; i++) {
            r[i] = v[i] * scalar;
        }
    }

    template <typename T>
    static constexpr LIA_FORCE_INLINE void mul(SMat<2, 2, T>& result, const SMat<2, 2, T>& value, const T& scalar) {
        const T* m = value.data;
        T* r = result.data;
        r[0] = m[0] * scalar; r[1] = m[1] * scalar;
        r[2] = m[2] * scalar; r[3] = m[3] * scalar;
    }

    template <typename T>
    static constexpr LIA_FORCE_INLINE void mul(SMat<3, 3, T>& result, const SMat<3, 3, T>& value, const T& scalar) {
        const T* m = value.data;
        T* r = result.data;
        r[0] = m[0] * scalar; r[1] = m[1] * scalar; r[2] = m[2] * scalar;
        r[3] = m[3] * scalar; r[4] = m[4] * scalar; r[5] = m[5] * scalar;
        r[6] = m[6] * scalar; r[7] = m[7] * scalar; r[8] = m[8] * scalar;
    }

    template <typename T>
    static constexpr LIA_FORCE_INLINE void mul(SMat<4, 4, T>& result, const SMat<4, 4, T>& value, const T& scalar) {
        const T* m = value.data;
        T* r = result.data;
        r[0] = m[0] * scalar; r[1] = m[1] * scalar; r[2] = m[2] * scalar; r[3] = m[3] * scalar;
        r[4] = m[4] * scalar; r[5] = m[5] * scalar; r[6] = m[6] * scalar; r[7] = m[7] * scalar;
        r[8] = m[8] * scalar; r[9] = m[9] * scalar; r[10] = m[10] * scalar; r[11] = m[11] * scalar;
        r[12] = m[12] * scalar; r[13] = m[13] * scalar; r[14] = m[14] * scalar; r[15] = m[15] * scalar;
    }

    template <int ls, int cs, typename T>
    static constexpr LIA_FORCE_INLINE void mul(SMat<ls, cs, T>& result, const SMat<ls, cs, T>& value, const T& scalar) {
        const T* m = value.data;
        T* r = result.data;
        for (int i = 0; i < ls*cs; i++) {
            r[i] = m[i] * scalar;
        }
    }

    // Scalar multiplication operator (scalar on the right)
    template <int ls, int cs, typename T>
    static constexpr LIA_FORCE_INLINE SMat<ls, cs, T> operator*(const SMat<ls, cs, T>& left, const T& right) {
        SMat<ls, cs, T> result;
        mul(result, left, right);
        return result;
    }

    // Scalar multiplication operator (scalar on the left)
    template <int ls, int cs, typename T>
    static constexpr LIA_FORCE_INLINE SMat<ls, cs, T> operator*(const T& left, const SMat<ls, cs, T>& right) {
        SMat<ls, cs, T> result;
        mul(result, right, left);
        return result;
    }

    // =============================== DIVISION ===============================

    /**
     * Do scalar divison between a matrix or vector and a scalar.
     * @param result Matrix, vector or scalar to write the result to.
     * @param left Matrix or vector to divide.
     * @param right Scalar to divide the matrix or vector by.
    */

    template <typename T>
    static constexpr LIA_FORCE_INLINE void div(SVec<2, T>& result, const SVec<2, T>& left, const T& right) {
        const T* a = left.data;
        T* r = result.data;
        r[0] = a[0] / (T)right;
        r[1] = a[1] / (T)right;
    }

    template <typename T>
    static constexpr LIA_FORCE_INLINE void div(SVec<3, T>& result, const SVec<3, T>& left, const T& right) {
        const T* a = left.data;
        T* r = result.data;
        r[0] = a[0] / (T)right;
        r[1] = a[1] / (T)right;
        r[2] = a[2] / (T)right;
    }

    template <typename T>
    static constexpr LIA_FORCE_INLINE void div(SVec<4, T>& result, const SVec<4, T>& left, const T& right) {
        const T* a = left.data;
        T* r = result.data;
        r[0] = a[0] / (T)right;
        r[1] = a[1] / (T)right;
        r[2] = a[2] / (T)right;
        r[3] = a[3] / (T)right;
    }

    template <int d, typename T>
    static constexpr LIA_FORCE_INLINE void div(SVec<d, T>& result, const SVec<d, T>& left, const T& right) {
        const T* a = left.data;
        T* r = result.data;
        for (int i = 0; i < d; i++) {
            r[i] = a[i] / (T)right;
        }
    }

    template <typename T>
    static constexpr LIA_FORCE_INLINE void div(SMat<2, 2, T>& result, const SMat<2, 2, T>& left, const T& right) {
        const T* a = left.data;
        T* r = result.data;
        r[0] = a[0] / (T)right; r[1] = a[1] / (T)right;
        r[2] = a[2] / (T)right; r[3] = a[3] / (T)right;
    }

    template <typename T>
    static constexpr LIA_FORCE_INLINE void div(SMat<3, 3, T>& result, const SMat<3, 3, T>& left, const T& right) {
        const T* a = left.data;
        T* r = result.data;
        r[0] = a[0] / (T)right; r[1] = a[1] / (T)right; r[2] = a[2] / (T)right;
        r[3] = a[3] / (T)right; r[4] = a[4] / (T)right; r[5] = a[5] / (T)right;
        r[6] = a[6] / (T)right; r[7] = a[7] / (T)right; r[8] = a[8] / (T)right;
    }

    template <typename T>
    static constexpr LIA_FORCE_INLINE void div(SMat<4, 4, T>& result, const SMat<4, 4, T>& left, const T& right) {
        const T* a = left.data;
        T* r = result.data;
        r[0] = a[0] / (T)right; r[1] = a[1] / (T)right; r[2] = a[2] / (T)right; r[3] = a[3] / (T)right;
        r[4] = a[4] / (T)right; r[5] = a[5] / (T)right; r[6] = a[6] / (T)right; r[7] = a[7] / (T)right;
        r[8] = a[8] / (T)right; r[9] = a[9] / (T)right; r[10] = a[10] / (T)right; r[11] = a[11] / (T)right;
        r[12] = a[12] / (T)right; r[13] = a[13] / (T)right; r[14] = a[14] / (T)right; r[15] = a[15] / (T)right;
    }

    template <int ls, int cs, typename T>
    static constexpr LIA_FORCE_INLINE void div(SMat<ls, cs, T>& result, const SMat<ls, cs, T>& left, const T& right) {
        const T* a = left.data;
        T* r = result.data;
        for (int i = 0; i < ls*cs; i++) {
            r[i] = a[i] / (T)right;
        }
    }

    // Scalar division operator
    template <int ls, int cs, typename T>
    static constexpr LIA_FORCE_INLINE SMat<ls, cs, T> operator/(const SMat<ls, cs, T>& left, const T& right) {
        SMat<ls, cs, T> result;
        div(result, left, right);
        return result;
    }

    // ============================== DOT PRODUCT ==============================

    /**
     * Take the dot product between two vector or matrices.
     * @param result Matrix, vector or scalar to write the result to.
     * @param left Left-hand matrix or vector.
     * @param right Right-hand matrix or vector.
    */

    template <typename T>
    static constexpr LIA_FORCE_INLINE void dot(double& result, const SVec<2, T>& left, const SVec<2, T>& right) {
        const T* a = left.data;
        const T* b = right.data;
        result = a[0]*b[0] + a[1]*b[1];
    }

    template <typename T>
    static constexpr LIA_FORCE_INLINE void dot(double& result, const SVec<3, T>& left, const SVec<3, T>& right) {
        const T* a = left.data;
        const T* b = right.data;
        result = a[0]*b[0] + a[1]*b[1] + a[2]*b[2];
    }

    template <typename T>
    static constexpr LIA_FORCE_INLINE void dot(double& result, const SVec<4, T>& left, const SVec<4, T>& right) {
        const T* a = left.data;
        const T* b = right.data;
        result = a[0]*b[0] + a[1]*b[1] + a[2]*b[2] + a[3]*b[3];
    }

    template <int d, typename T>
    static constexpr LIA_FORCE_INLINE void dot(double& result, const SVec<d, T>& left, const SVec<d, T>& right) {
        const T* a = left.data;
        const T* b = right.data;
        result = 0.0;
        for (int i = 0; i < d; i++) {
            result += a[i]*b[i];
        }
    }

    template <typename T>
    static constexpr LIA_FORCE_INLINE void dot(SVec<2, T>& result, const SMat<2, 2, T>& left, const SVec<2, T>& right) {
        const T* a = left.data;
        const T* b = right.data;
        T* r = result.data;
        r[0] = a[0]*b[0] + a[1]*b[1];
        r[1] = a[2]*b[0] + a[3]*b[1];
    }

    template <typename T>
    static constexpr LIA_FORCE_INLINE void dot(SVec<3, T>& result, const SMat<3, 3, T>& left, const SVec<3, T>& right) {
        const T* a = left.data;
        const T* b = right.data;
        T* r = result.data;
        r[0] = a[0]*b[0] + a[1]*b[1] + a[2]*b[2];
        r[1] = a[3]*b[0] + a[4]*b[1] + a[5]*b[2];
        r[2] = a[6]*b[0] + a[7]*b[1] + a[8]*b[2];
    }

    template <typename T>
    static constexpr LIA_FORCE_INLINE void dot(SVec<4, T>& result, const SMat<4, 4, T>& left, const SVec<4, T>& right) {
        const T* a = left.data;
        const T* b = right.data;
        T* r = result.data;
        r[0] = a[0]*b[0] + a[1]*b[1] + a[2]*b[2] + a[3]*b[3];
        r[1] = a[4]*b[0] + a[5]*b[1] + a[6]*b[2] + a[7]*b[3];
        r[2] = a[8]*b[0] + a[9]*b[1] + a[10]*b[2] + a[11]*b[3];
        r[3] = a[12]*b[0] + a[13]*b[1] + a[14]*b[2] + a[15]*b[3];
    }

    template <int d, typename T>
    static constexpr LIA_FORCE_INLINE void dot(SVec<d, T>& result, const SMat<d, d, T>& left, const SVec<d, T>& right) {
        const T* da = left.data;
        const T* db = right.data;
        T* r = result.data;
        for (int i = 0; i < d; i++) {
            const T* line = &da[i*d];
            T* const sum = &r[i];
            *sum = 0;
            for (int j = 0; j < d; j++) {
                *sum += line[j]*db[j];
            }
        }
    }

    template <typename T>
    static constexpr LIA_FORCE_INLINE void dot(SMat<2, 2, T>& result, const SMat<2, 2, T>& left, const SMat<2, 2, T>& right) {
        const T* a = left.data;
        const T* b = right.data;
        T* r = result.data;
        r[0] = a[0]*b[0] + a[1]*b[2]; r[1] = a[0]*b[1] + a[1]*b[3];
        r[2] = a[2]*b[0] + a[3]*b[2]; r[3] = a[2]*b[1] + a[3]*b[3];
    }

    template <typename T>
    static constexpr LIA_FORCE_INLINE void dot(SMat<3, 3, T>& result, const SMat<3, 3, T>& left, const SMat<3, 3, T>& right) {
        const T* a = left.data;
        const T* b = right.data;
        T* r = result.data;
        r[0] = a[0]*b[0] + a[1]*b[3] + a[2]*b[6]; r[1] = a[0]*b[1] + a[1]*b[4] + a[2]*b[7]; r[2] = a[0]*b[2] + a[1]*b[5] + a[2]*b[8];
        r[3] = a[3]*b[0] + a[4]*b[3] + a[5]*b[6]; r[4] = a[3]*b[1] + a[4]*b[4] + a[5]*b[7]; r[5] = a[3]*b[2] + a[4]*b[5] + a[5]*b[8];
        r[6] = a[6]*b[0] + a[7]*b[3] + a[8]*b[6]; r[7] = a[6]*b[1] + a[7]*b[4] + a[8]*b[7]; r[8] = a[6]*b[2] + a[7]*b[5] + a[8]*b[8];
    }

    template <typename T>
    static constexpr LIA_FORCE_INLINE void dot(SMat<4, 4, T>& result, const SMat<4, 4, T>& left, const SMat<4, 4, T>& right) {
        const T* a = left.data;
        const T* b = right.data;
        T* r = result.data;
        r[0] = a[0]*b[0] + a[1]*b[4] + a[2]*b[8] + a[3]*b[12]; r[1] = a[0]*b[1] + a[1]*b[5] + a[2]*b[9] + a[3]*b[13]; r[2] = a[0]*b[2] + a[1]*b[6] + a[2]*b[10] + a[3]*b[14]; r[3] = a[0]*b[3] + a[1]*b[7] + a[2]*b[11] + a[3]*b[15]; 
        r[4] = a[4]*b[0] + a[5]*b[4] + a[6]*b[8] + a[7]*b[12]; r[5] = a[4]*b[1] + a[5]*b[5] + a[6]*b[9] + a[7]*b[13]; r[6] = a[4]*b[2] + a[5]*b[6] + a[6]*b[10] + a[7]*b[14]; r[7] = a[4]*b[3] + a[5]*b[7] + a[6]*b[11] + a[7]*b[15]; 
        r[8] = a[8]*b[0] + a[9]*b[4] + a[10]*b[8] + a[11]*b[12]; r[9] = a[8]*b[1] + a[9]*b[5] + a[10]*b[9] + a[11]*b[13]; r[10] = a[8]*b[2] + a[9]*b[6] + a[10]*b[10] + a[11]*b[14]; r[11] = a[8]*b[3] + a[9]*b[7] + a[10]*b[11] + a[11]*b[15];
        r[12] = a[12]*b[0] + a[13]*b[4] + a[14]*b[8] + a[15]*b[12]; r[13] = a[12]*b[1] + a[13]*b[5] + a[14]*b[9] + a[15]*b[13]; r[14] = a[12]*b[2] + a[13]*b[6] + a[14]*b[10] + a[15]*b[14]; r[15] = a[12]*b[3] + a[13]*b[7] + a[14]*b[11] + a[15]*b[15];
    }

    template <int a, int b, int c, typename T>
    static constexpr LIA_FORCE_INLINE void dot(SMat<a, c, T>& result, const SMat<a, b, T>& left, const SMat<b, c, T>& right) {
        const T* da = left.data;
        const T* db = right.data;
        T* r = result.data;
        for (int i = 0; i < a; i++) {
            const T* line = &da[i*b];
            for (int j = 0; j < c; j++) {
                const T* col = &db[j];
                T* const sum = &r[i*c + j];
                *sum = 0;
                for (int k = 0; k < b; k++) {
                    *sum += line[k] * (*col);
                    col += c;
                }
            }
        }
    }

    // Vector dot product operator
    template <int d, typename T>
    static constexpr LIA_FORCE_INLINE T operator*(const SVec<d, T>& left, const SVec<d, T>& right) {
        T result;
        dot(result, left, right);
        return result;
    }

    // Matrix dot product operator
    template <int a, int b, int c, typename T>
    static constexpr LIA_FORCE_INLINE SMat<a, c, T> operator*(const SMat<a, b, T>& left, const SMat<b, c, T>& right) {
        SMat<a, c, T> result;
        dot(result, left, right);
        return result;
    }

    // ============================= CROSS PRODUCT =============================

    /**
     * Take the cross product between two 3D vectors.
     * @param result Vector to write the result to.
     * @param left Left-hand side vector.
     * @param right Right-hand side vector.
    */
    template <typename T>
    static constexpr LIA_FORCE_INLINE void cross(SVec<3, T>& result, const SVec<3, T>& left, const SVec<3, T>& right) {
        const T* a = left.data;
        const T* b = right.data;
        T* r = result.data;
        r[0] = a[1]*b[2] - a[2]*b[1];
        r[1] = a[2]*b[0] - a[0]*b[2];
        r[2] = a[0]*b[1] - a[1]*b[0];
    }

    template <typename T>
    static constexpr LIA_FORCE_INLINE SVec<3, T> operator^(const SVec<3, T>& left, const SVec<3, T>& right) {
        SVec<3, T> result;
        cross(result, left, right);
        return result;
    }
}