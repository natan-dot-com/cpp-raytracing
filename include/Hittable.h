#pragma once

#include "Ray.hpp"
#include <optional>

struct hitRecord {
    Point3 point;
    Vec3 normal;
    double t;
};

class isHittable {
    virtual std::optional<hitRecord> hit(const Ray& r, const double t_min, const double t_max) const = 0;
};