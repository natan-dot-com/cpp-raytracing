#include "Color.h"

namespace color {   
    void write(std::ostream& os, const Color& pixel) {
        os << static_cast<int>(255.999 * pixel.x) << " "
           << static_cast<int>(255.999 * pixel.y) << " "
           << static_cast<int>(255.999 * pixel.z) << "\n";
    }
}
