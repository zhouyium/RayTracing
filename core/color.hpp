#ifndef __COLOR_H_DI39SJIOUF923JK4IOOSUIJH3842XQ__
#define __COLOR_H_DI39SJIOUF923JK4IOOSUIJH3842XQ__

#include "vec3.hpp"
#include <iostream>

using std::ostream;

void write_color(ostream& out, color pixel_color) {
    //Write the translated [0, 255] value of each color component.
    out << static_cast<int>(255.999 * pixel_color.x()) << ' '
        << static_cast<int>(255.999 * pixel_color.y()) << ' '
        << static_cast<int>(255.999 * pixel_color.z()) << '\n';
}

#endif //end of head file