#pragma once
#include <complex>
#include <stddef.h>

namespace lia {
    /**
     * Dynamically allocated dense matrix.
    */
    template <typename T>
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

    // Type shortcuts
    using DMatd = DMat<double>;
    using DMatf = DMat<float>;
    using DMati = DMat<int>;

    template <typename T>
    void dot(DMat<T>& result, const DMat<T>& left, const DMat<T>& right);
}