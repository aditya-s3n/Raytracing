#include "ray.h"

ray::ray() { }
ray::ray(const point3& origin, const vec3& direction) {
    orig = orig;
    direc = direction;
}

const point3& ray::origin() const {
    return orig;
}

const vec3& ray::direction() const {
    return direc;
}

point3 ray::at(double t) const {
    return orig + (t * direc);
}