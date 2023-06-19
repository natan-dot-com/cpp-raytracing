#pragma once

#include "Vec3.hpp"

namespace utils {
    // I still need to make sure that's the correct operation
    template<typename T>
    T fit_on_viewport(const T& el) {
        return (el + 1)/2;
    }
}