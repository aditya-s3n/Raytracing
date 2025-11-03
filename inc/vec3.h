#pragma once

#include <cmath>
#include <iostream>

class vec3 {
    public:
        double e[3];

        vec3();
        vec3(double e0, double e1, double e2);

        double x() const { return e[0]; }
        double y() const { return e[1]; }
        double z() const { return e[2]; }

        vec3 operator-();
        double operator[](int i);
        // double& operator[](int i);

        vec3& operator+=(const vec3& v);
        vec3& operator*=(double t);
        vec3& operator/=(double t);

        double length() const;

        double lenght_sqr() const;
};


using point3 = vec3;

inline std::ostream& operator<<(std::ostream& out, const vec3& v);

inline vec3 operator+(const vec3& u, const vec3& v);
inline vec3 operator-(const vec3& u, const vec3& v);
inline vec3 operator*(const vec3& u, const vec3& v);
inline vec3 operator*(const vec3& u, double t);
inline vec3 operator*(double t, const vec3& v);
inline vec3 operator/(const vec3& u, double t);

inline double dot(const vec3& u, const vec3& v);
inline vec3 cross(const vec3& u, const vec3& v);
inline vec3 unit_vector(const vec3& v);