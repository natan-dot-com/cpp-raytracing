#pragma once

#include "Vec3.hpp"

namespace color {
    using Color = Vec3;

    const auto Red = Color(1, 0, 0);
    const auto Green = Color(0, 1, 0);
    const auto Blue = Color(0, 0, 1);
    const auto White = Color(1, 1, 1);
    const auto Black = Color(0, 0, 0);
    const auto Gray = Color(0.5, 0.5, 0.5);

    void write(std::ostream&, const Color&);
}
