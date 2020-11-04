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
        e[0]+=v[0];
        e[1]+=v[1];
        e[2]+=v[2];
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

// vec3 Utility Functions
using std::ostream;
inline ostream& operator<<(ostream& out, const vec3& v) {
    return out<<v[0]<<" "<<v[1]<<" "<<v[2];
}

inline vec3 operator+(const vec3& u, const vec3& v) {
    return vec3(u[0]+v[0], u[1]+v[1], u[2]+v[2]);
}

inline vec3 operator-(const vec3& u, const vec3& v) {
    return vec3(u[0]-v[0], u[1]-v[1], u[2]-v[2]);
}

inline vec3 operator*(const vec3& u, const vec3& v) {
    return vec3(u[0]*v[0], u[1]*v[1], u[2]*v[2]);
}

inline vec3 operator*(double t, const vec3& u) {
    return vec3(u[0]*t, u[1]*t, u[2]*t);
}

inline vec3 operator*(const vec3& u, double t) {
    return t*u;
}

inline vec3 operator/(const vec3& u, double t) {
    return (1/t)*u;
}

//向量点乘
inline double dot(const vec3& u, const vec3& v) {
    return u[0]*v[0]+u[1]*v[1]+u[2]*v[2];
}

//向量叉乘
inline vec3 cross(const vec3& u, const vec3& v) {
    return vec3(u[1]*v[2]-u[2]*v[1], u[2]*v[0]-u[0]*v[2], u[0]*v[1]-u[1]*v[0]);
}

inline vec3 unite_vector(const vec3& v) {
    return v/v.length();
}

#endif //end of head file