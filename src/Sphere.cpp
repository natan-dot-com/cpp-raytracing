#include "Sphere.h"

/*
* This function solves a quadratic equation to determine whether a ray
*    of light collided with a sphere on the screen or not.
*
* Let 'A' be the origin of the ray, 'b' be the direction vector of the 
*    ray, 'C' be the center of the sphere and 'r' be its radius Also con-
*    consider that '.' is the dot product between vectors. This function
*    is solving, with some simplifications, for t on:
*
*    (b.b)t^2 + 2[b.(A-C)]t + [(A-C).(A-C)-r^2] = 0
*
* Refs: 
*   - https://raytracing.github.io/books/RayTracingInOneWeekend.html#addingasphere
*   - https://raytracing.github.io/books/RayTracingInOneWeekend.html#
*       surfacenormalsandmultipleobjects/simplifyingtheray-sphereintersectioncode
*/
std::optional<hitRecord> Sphere::hit(const Ray& r, const double t_min, const double t_max) const {
    auto check_interval = [&t_min, &t_max](double root) 
                            -> bool{ return root >= t_min || root <= t_max; };
    
    const auto oc = r.origin() - _center;

    const auto a = r.direction().squared_norm();
    const auto half_b = oc.dot(r.direction());
    const auto c = oc.squared_norm() - _radius*_radius;

    const auto discriminant = half_b*half_b - a*c;
    if (discriminant < 0) { 
        return std::nullopt; 
    }

    // See whether any of the roots lie in the proposed interval
    auto root = (-half_b - std::sqrt(discriminant)) / a;
    if (!check_interval(root)) { 
        if (discriminant == 0) {
            return std::nullopt;
        }
        root = (-half_b + std::sqrt(discriminant)) / a;
        if (!check_interval(root)) {
            return std::nullopt;
        }
    }

    return std::optional<hitRecord>{
        (hitRecord) {
            .point = r.at(root),
            .normal = (r.at(root) - _center) / _radius,
            .t = root
        }
    };
}
