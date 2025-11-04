#pragma once

#include "actor.h"
#include "rt_utility.h"

class sphere : public actor {
    private:
        point3 center;
        double radius;

    public:
        sphere(const point3& cntr, double rad);

        bool hit(const ray& r, interval ray_t, hit_record& rec) const override;
};