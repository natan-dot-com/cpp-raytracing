#pragma once

#include "Vec3.hpp"
#include "Utils.h"

using Point3 = Vec3;

/*
* A ray is a function P(t) = A + tB, where P is a 3D position
*    along a line in 3D. 'A' is the ray origin point and 'b' 
*    is the ray direction vector.
*/
class Ray {
private:
    Point3 _origin;
    Vec3 _direction;

public:
    Ray() = default;
    Ray(const Point3& origin, const Vec3& direction) noexcept
        : _origin(origin)
        , _direction(direction)
    {}

    inline Point3 origin() const { return _origin; }
    inline Vec3 direction() const { return _direction; };

    template<Numeric T>
    inline constexpr Point3 at(const T t) const {
        return _origin + (_direction * t);
    }
};
