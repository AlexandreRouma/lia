#pragma once

namespace lia {
    template <typename DT>
    class DMat {
    public:
        // Default constructor
        DMat();

        /**
         * Create a matrix.
         * @param lines Number of lines.
         * @param columns Number of columns.
        */
        DMat(int lines, int columns);

        // Destructor
        ~DMat();

        // Number of lines
        const int ls;

        // Number of columns
        const int cs;

    private:
        DT* data = NULL;
    };

    template <typename DT>
    class DVec : public DMat<DT> {
    public:
        // Default constructor
        DVec();
        
        /**
         * Create a vector.
         * @param lines Number of lines.
        */
        DVec(int lines);
    };

    // Common dynamic vector and matrix types
    using DVecd = DVec<double>;
    using DVecf = DVec<float>;
    using DVeci = DVec<int>;
    using DMatd = DMat<double>;
    using DMatf = DMat<float>;
    using DMati = DMat<int>;

    // =============================== TRANSPOSE ===============================

    /**
     * Transpose a matrix or vector.
     * @param result Matrix or vector to write the result to.
     * @param value Matrix or vector to transpose.
    */
    template <typename T>
    void transpose(DMat<T>& result, const DVec<T>& value);
    template <typename T>
    void transpose(DMat<T>& result, const DMat<T>& value);

    // ================================= NORM =================================

    /**
     * Compute the euclidian norm of a vector.
     * @param value Vector to take the euclidian norm of.
     * @return Euclidian norm of the vector.
    */
    template <typename T>
    T norm(const DVec<T>& value);

    // =============================== ADDITION ===============================

    /**
     * Add two matrices or vectors.
     * @param result Matrix or vector to write the result to.
     * @param left Left-hand matrix or vector.
     * @param right Right-hand matrix or vector.
    */
    template <typename T>
    void add(DVec<T>& result, const DVec<T>& left, const DVec<T>& right);
    template <typename T>
    void add(DMat<T>& result, const DMat<T>& left, const DMat<T>& right);

    // ============================== SUBTRACTION ==============================

    /**
     * Subtract two matrices or vectors.
     * @param result Matrix or vector to write the result to.
     * @param left Left-hand matrix or vector.
     * @param right Right-hand matrix or vector.
    */
    template <typename T>
    void sub(DVec<T>& result, const DVec<T>& left, const DVec<T>& right);
    template <typename T>
    void sub(DMat<T>& result, const DMat<T>& left, const DMat<T>& right);

    // ============================ MULTIPLICATION ============================

    /**
     * Do scalar multiplication between a matrix or vector and a scalar.
     * @param result Matrix, vector or scalar to write the result to.
     * @param left Matrix or vector to multiply.
     * @param right Scalar to multiply the matrix or vector by.
    */
    template <typename T>
    void mul(DVec<T>& result, const DVec<T>& left, T right);
    template <typename T>
    void mul(DMat<T>& result, const DMat<T>& left, T right);

    // =============================== DIVISION ===============================

    /**
     * Do scalar divison between a matrix or vector and a scalar.
     * @param result Matrix, vector or scalar to write the result to.
     * @param left Matrix or vector to divide.
     * @param right Scalar to divide the matrix or vector by.
    */
    template <typename T>
    void div(DVec<T>& result, const DVec<T>& left, T right);
    template <typename T>
    void div(DMat<T>& result, const DMat<T>& left, T right);

    // ============================== DOT PRODUCT ==============================

    /**
     * Take the dot product between two vector or matrices.
     * @param result Matrix, vector or scalar to write the result to.
     * @param left Left-hand matrix or vector.
     * @param right Right-hand matrix or vector.
    */

    // ============================= CROSS PRODUCT =============================

    /**
     * Take the cross product between two 3D vectors.
     * @param result Vector to write the result to.
     * @param left Left-hand side vector.
     * @param right Right-hand side vector.
    */
    template <typename T>
    void cross(DVec<T>& result, const DVec<T>& left, const DVec<T>& right);
}