#include "sphere.h"

sphere::sphere(const point3& cntr, double rad) {
    this->center = cntr;
    this->radius = rad;
}

bool sphere::hit(const ray& r, interval ray_t, hit_record& rec) const {
    vec3 oc = center - r.origin();
    
    //quadratic formula
    auto a = r.direction().lenght_sqr();
    auto h = dot(r.direction(), oc);
    auto c = oc.lenght_sqr() - (radius * radius);

    auto discriminant = (h * h) - (a * c);

    if (discriminant < 0) {
        return false;
    }

    auto sqrtd = std::sqrt(discriminant);


    // find the root in the range of t
    auto root = (h - sqrtd) / a;
    if (!ray_t.surrounds(root)) {
        root = (h + sqrtd) / a;

        if (!ray_t.surrounds(root)) return false;
    }

    rec.t = root;
    rec.p = r.at(rec.t);
    rec.normal = (rec.p - center) / radius;


    return true;
}

