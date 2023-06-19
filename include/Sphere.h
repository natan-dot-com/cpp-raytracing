#pragma once

#include "Hittable.h"

class Sphere : public isHittable {
private:
    Point3 _center;
    double _radius;

public:
    Sphere() = default;
    Sphere(Point3 center, double radius)
        : _center(center)
        , _radius(radius)
    {}
    
    virtual std::optional<hitRecord> hit(const Ray&, const double, const double) const override;
};