#ifndef __VECS_H_DI38SKCJ83MIUD83JLSLINAK__
#define __VECS_H_DI38SKCJ83MIUD83JLSLINAK__

#include <cmath>
#include <iostream>

using std::sqrt;

class vec3 {
public:
    vec3() : e{0, 0, 0} {}
    vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}
    ~vec3() {}

public:
    double x() const {return e[0];}
    double y() const {return e[1];}
    double z() const {return e[2];}

    vec3 operator-() const {return vec3(-e[0], -e[1], -e[2]);}
    double operator[](int i) const {return e[i];}
    double& operator[](int i) {return e[i];}

    vec3& operator+=(const vec3& v) {
        e[0]+=v.e[0];
        e[1]+=v.e[1];
        e[2]+=v.e[2];
        return *this;
    }

    vec3& operator*=(const double t) {
        e[0]*=t;
        e[1]*=t;
        e[2]*=t;
        return *this;
    }

    vec3& operator/=(const double t) {
        return *this *= 1/t;
    }

    double length() const {
        return sqrt(length_squared());
    }

    double length_squared() const {
        return e[0]*e[0]+e[1]*e[1]+e[2]*e[2];
    }

private:
    double e[3];//x, y, z

}; //end of class vec3

// Type aliases for vec3
using point3 = vec3; // 3D point
using color  = vec3; // RGB color

#endif //end of head file