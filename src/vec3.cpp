#include "vec3.h"

vec3::vec3() {
    this->e[0] = 0;
    this->e[1] = 0;
    this->e[2] = 0;
}

vec3::vec3(double e0, double e1, double e2) {
    this->e[0] = e0;
    this->e[1] = e1;
    this->e[2] = e2;
}

vec3 vec3::operator-() {
    return vec3(-e[0], -e[1], -e[2]);
}

double vec3::operator[](int i) {
    if (i >= 0 && i <= 2) return e[i];

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

bool vec3::near_zero() const {
    // see if all vectors are close to zero

    auto s = 1e-8;
    return (std::fabs(e[0]) < s) && (std::fabs(e[1]) < s) && (std::fabs(e[2]) < s);
}