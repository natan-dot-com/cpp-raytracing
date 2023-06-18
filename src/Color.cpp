#include "Color.h"

namespace Color {   
    void write(std::ostream& os, Color& pixel) {
        os << static_cast<int>(255.999 * pixel.x) << " "
           << static_cast<int>(255.999 * pixel.y) << " "
           << static_cast<int>(255.999 * pixel.z) << "\n";
    }
}
