#pragma once

#include "actor.h"
#include "rt_utility.h"

class sphere : public actor {
    private:
        point3 center;
        double radius;
        shared_ptr<material> mat;

    public:
        sphere(const point3& cntr, double rad, shared_ptr<material> mat);

        bool hit(const ray& r, interval ray_t, hit_record& rec) const override;
};