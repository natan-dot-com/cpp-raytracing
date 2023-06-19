#include "Vec3.hpp"
#include "Ray.hpp"
#include "Color.h"
#include "Utils.h"

#include <iostream>

/*
* This function solves a quadratic equation to determine whether a ray
*    of light collided with a sphere on the screen or not.
*
* Let 'A' be the origin of the ray, 'b' be the direction vector of the 
*    ray, 'C' be the center of the sphere and 'r' be its radius Also con-
*    consider that '.' is the dot product between vectors. This function
*    is solving for t on:
*
*    (b.b)t^2 + 2[b.(A-C)]t + [(A-C).(A-C)-r^2] = 0
*
* [Ref: https://raytracing.github.io/books/RayTracingInOneWeekend.html#addingasphere]
*/
template<Numeric T>
double hit_sphere(const Point3& center, const T radius, const Ray& r) {
    const auto oc = r.origin() - center;

    const auto a = r.direction().dot(r.direction());
    const auto b = 2.0 * oc.dot(r.direction());
    const auto c = oc.dot(oc) - radius*radius;

    const auto discriminant = b*b - 4*a*c;
    if (discriminant < 0) {
        return -1.0;
    }
    else {
        return (-b-std::sqrt(discriminant)) / 2.0*a;
    }
}

/*
* Linearly blends two colors from top to bottom as a vertical gradient.
*    
*    blendedValue = (1-t)*startValue + t*endValue
*
* [Ref: https://raytracing.github.io/books/RayTracingInOneWeekend.html
*    #rays,asimplecamera,andbackground/sendingraysintothescene]
*/
color::Color ray_color(const color::Color bottom, 
                       const color::Color upper,
                       const Ray& r) 
{
    const auto sphere_center = Point3(0, 0, -1);
    const auto sphere_radius = 0.5;

    auto t = hit_sphere(sphere_center, sphere_radius, r);
    if (t > 0.0) {
        auto N = (r.at(t) - sphere_center).versor();
        std::cerr << N << std::endl;
        return (color::Color(N.x, N.y, N.z) + 1)/2;
    }
    const Vec3 direction = r.direction().versor();
    t = (direction.y + 1)/2;
    return bottom*(1.0-t) + upper*t;
}

int main() {
    // Image definition
    const double aspect_ratio = 16.0 / 9.0;
    const int width = 400;
    const int height = static_cast<int>(width / aspect_ratio);

    // Camera definition
    const double viewport_height = 2.0;
    const double viewport_width = aspect_ratio * viewport_height;
    const double focal_length = 1.0;

    const auto origin = Point3(0, 0, 0);
    const auto horizontal = Vec3(viewport_width, 0, 0);
    const auto vertical = Vec3(0, viewport_height, 0);

    // Lower-left corner
    const auto llc = origin - horizontal/2 - vertical/2 - Vec3(0, 0, focal_length);
    
    // Render 
    std::cout << "P3\n" << width << " " << height << "\n255\n";
    for (int i = height-1; i >= 0; --i) {
        for (int j = 0; j < width; ++j) {
            const auto u = double(j) / (width-1);
            const auto v = double(i) / (height-1);

            const Ray r(origin, llc + horizontal*u + vertical*v - origin);
            const auto pixel = ray_color(color::White, color::Black, r);
            color::write(std::cout, pixel);
        }
    }

    return 0;
}
