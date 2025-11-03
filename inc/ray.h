#pragma once

#include "vec3.h"

class ray {
    private:
        point3 orig;
        vec3 direc;

    public:
        ray();
        ray(const point3& origin, const vec3& direction);

        const point3& origin() const;
        const vec3& direction() const;

        point3 at(double t) const;
};