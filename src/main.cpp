#include "Vec3.hpp"
#include "Ray.hpp"

int main() {
    // - This will come in handy later on
    // const int width = 256;
    // const int height = 256;

    // std::cout << "P3\n" << width << " " << height << "\n255\n";
    // for (int i = height-1; i >= 0; --i) {
    //     std::cerr << "\rScanlines remaining: " << i << " " << std::flush;
    //     for (int j = 0; j < width; ++j) {
    //         Color::Color pixel(double(i) / width, double(i) / height, 0.25);
    //         Color::write(std::cout, pixel);
    //     }
    // }

    auto r = Ray(Point3(1, 2, 2), Vec3(0, 1, 0));
    std::cout << r.at(0) << std::endl;
    std::cout << r.at(2) << std::endl;
    std::cout << r.at(4) << std::endl;

    return 0;
}
