#pragma once
#include <string.h>

namespace lia {
    /**
     * Generic matrix of any size.
    */
    class Mat {
    public:
        // Destructor
        virtual ~Mat() {}

        /**
         * Get the number of lines in the matrix.
         * @return Number of lines in the matrix.
        */
        virtual int lines() const = 0;

        /**
         * Get the number of columns in the matrix.
         * @return Number of columns in the matrix.
        */
        virtual int columns() const = 0;

        /**
         * Get a pointer to the data of the matrix.
         * @return Pointer to the data of the matrix.
        */
        virtual double* data() = 0;
        virtual const double* data() const = 0;
    };

    /**
     * Statically allocated matrix.
    */
    template <int ls, int cs>
    class SMat : public Mat {
    public:
        SMat() {}

        /**
         * Create a matrix and set all its elements to a value.
         * @param value Value to set all the elements to.
        */
        SMat(double value) {
            // Set all element to the same value
            for (int i = 0; i < ls*cs; i++) { _data[i] = value; }
        }

        /**
         * Get the number of lines in the matrix.
         * @return Number of lines in the matrix.
        */
        int lines() const { return ls; }

        /**
         * Get the number of columns in the matrix.
         * @return Number of columns in the matrix.
        */
        int columns() const { return cs; }

        /**
         * Get a pointer to the data of the matrix.
         * @return Pointer to the data of the matrix.
        */
        double* data() { return _data; }
        const double* data() const { return _data; }

    private:
        double _data[ls*cs];
    };

    /**
     * Statically allocated vector. Equivalent to a statically allocated matrix with a single column.
    */
    template <int ls>
    using SVec = SMat<ls, 1>;

    // Common static vector and matrix sizes
    using Vec2 = SVec<2>;
    using Vec3 = SVec<3>;
    using Mat2 = SMat<2, 2>;
    using Mat3 = SMat<3, 3>;

    /**
     * Take the dot product of two matrices or vectors.
     * @param result Matrix, vector or scalar to write the result to.
     * @param a Left hand matrix or vector.
     * @param b Right hand matrix or vector.
    */
    void dot(Mat& result, const Mat& a, const Mat& b);

    /**
     * Take the cross product of two three element vectors.
     * @param result Vector to write the result to.
     * @param a Left hand vector.
     * @param b Right hand vector.
    */
    void cross(Mat& result, const Mat& a, const Mat& b);

    // Dot product operator for generic matrices
    Mat operator*(const Mat& left, const Mat& right);

    // Dot product operator for static matrices and vectors
    template <int a, int b, int c>
    SMat<a, c> operator*(const SMat<a, b>& left, const SMat<b, c>& right) {
        SMat<a, c> result;
        dot(result, left, right);
        return result;
    }

    // Cross product for generic vectors
    Mat operator^(const Mat& left, const Mat& right);

    // Cross product operator for static vectors
    Vec3 operator^(const Vec3& left, const Vec3& right);
}
