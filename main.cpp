#include "Vec3.hpp"
#include "Ray.hpp"
#include "Color.h"
#include "Utils.hpp"
#include "Sphere.h"

#include <iostream>

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
    const Sphere sphere(Point3(0, 0, -1), 0.5);

    const auto record = sphere.hit(r, 0, 1);
    if (record && record->t > 0.0) {
        return utils::fit_on_viewport(record->normal);
    }
    const Vec3 direction = r.direction().versor();
    const auto t = utils::fit_on_viewport(direction.y);
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
