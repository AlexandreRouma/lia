#include "dynamic.h"

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
}