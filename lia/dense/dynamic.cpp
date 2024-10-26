#include "dynamic.h"

namespace lia {
    template <typename DT>
    DMat<DT>::DMat() : ls(0), cs(0) {}

    template class DMat<double>;
    template class DMat<float>;
    template class DMat<int>;
}