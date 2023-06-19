#pragma once

#include <cmath>
#include <iostream>
#include "Utils.h"

class Vec3 {
public:
    double x, y, z;

    Vec3() noexcept 
        : x(0.0), y(0.0), z(0.0)
    {}

    template<Numeric _Tx, Numeric _Ty, Numeric _Tz>
    Vec3(_Tx _x, _Ty _y, _Tz _z) noexcept
        : x(static_cast<double>(_x))
        , y(static_cast<double>(_y))
        , z(static_cast<double>(_z))
    {}

    Vec3& operator=(Vec3& other) {
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }

    inline Vec3 operator+(const Vec3& rhs) const {
        return Vec3(x + rhs.x, y + rhs.y, z + rhs.z);
    }

    template<Numeric T>
    inline Vec3 operator+(const T rhs) const {
        return Vec3(x + rhs, y + rhs, z + rhs);
    }

    inline Vec3 operator-() const {
        return Vec3(-x, -y, -z);
    }

    inline Vec3 operator-(const Vec3& rhs) const {
        return *this + (-rhs);
    }

    template<Numeric T>
    inline Vec3 operator-(const T rhs) const {
        return *this + (-1.0)*rhs;
    }

    inline Vec3 operator*(const Vec3& rhs) const {
        return Vec3(x * rhs.x, y * rhs.y, z * rhs.z);
    }

    template<Numeric T>
    inline Vec3 operator*(const T rhs) const {
        return Vec3(x * rhs, y * rhs, z * rhs);
    }

    template<Numeric T>
    inline Vec3 operator/(const T rhs) const {
        return *this * (1.0/rhs);
    }
    
    Vec3& operator+=(const Vec3& rhs) {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        return *this;
    }

    template<Numeric T>
    Vec3& operator+=(const T rhs) {
        x += rhs;
        y += rhs;
        z += rhs;
        return *this;
    }
    
    Vec3& operator-=(const Vec3& rhs) {
        *this += -rhs;
        return *this;
    }

    template<Numeric T>
    Vec3& operator-=(const T rhs) {
        *this += (-1.0)*rhs;
        return *this;
    }

    Vec3& operator*=(const Vec3& rhs) {
        x *= rhs.x;
        y *= rhs.y;
        z *= rhs.z;
        return *this;
    }

    template<Numeric T>
    Vec3& operator*=(const T rhs) {
        x *= rhs;
        y *= rhs;
        z *= rhs;
        return *this;
    }

    template<Numeric T>
    Vec3& operator/=(const T rhs) {
        *this *= (1.0/rhs);
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Vec3& rhs) {
        os << "Vec3([" << rhs.x << ", " << rhs.y << ", " << rhs.z << "])";
        return os;
    }

    inline double norm() const {
        return std::sqrt(x*x + y*y + z*z);
    }

    inline constexpr double dot(const Vec3& other) const {
        return x*other.x + y*other.y + z*other.z;
    }

    inline Vec3 cross(const Vec3& other) const {
        return Vec3(y*other.z - z*other.y,
                    z*other.x - x*other.z,
                    x*other.y - y*other.x);
    }

    inline Vec3 versor() const {
        return *this / (*this).norm();
    }    
};
