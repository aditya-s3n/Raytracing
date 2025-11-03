#include "vec3.h"

vec3::vec3() {
    e[0] = 0;
    e[1] = 0;
    e[2] = 0;
}

vec3::vec3(double e0, double e1, double e2) {
    e[0] = e0;
    e[1] = e1;
    e[2] = e2;
}

vec3 vec3::operator-() {
    return vec3(-e[0], -e[1], -e[2]);
}

double vec3::operator[](int i) {
    if (0 <= i <= 2) {
        return e[i];
    }
    
    return 0.0;
}

vec3& vec3::operator+=(const vec3& v) {
    e[0] += v.e[0];
    e[1] += v.e[1];
    e[2] += v.e[2];

    return *this;
}
vec3& vec3::operator*=(double t) {
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;

    return *this;
}
vec3& vec3::operator/=(double t) {
    return *this *= 1/t;
}

double vec3::length() const {
    return std::sqrt(lenght_sqr());
}

double vec3::lenght_sqr() const {
    return e[0]*e[0] + e[1]*e[1] + e[2]*e[2]; 
}

inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline vec3 operator+(const vec3& u, const vec3& v) { 
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline vec3 operator-(const vec3& u, const vec3& v) {
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

inline vec3 operator*(const vec3& u, const vec3& v) {
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

inline vec3 operator*(const vec3& u, double t) {
    return vec3(u.e[0] * t, u.e[1] * t, u.e[2] * t);
}

inline vec3 operator*(double t, const vec3& v) {
    return vec3(v.e[0] * t, v.e[1] * t, v.e[2] * t);
}

inline vec3 operator/(const vec3& u, double t) {
    return u * (1/t);
}

inline double dot(const vec3& u, const vec3& v) {
    return u.e[0] * v.e[0]
        + u.e[1] * v.e[1]
        + u.e[2] * v.e[2];
}

inline vec3 cross(const vec3& u, const vec3& v) {
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline vec3 unit_vector(const vec3& v) {
    return v / v.length();
}