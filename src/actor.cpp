#include "actor.h"

void hit_record::set_face_normal(const ray& r, const vec3& outward_normal) {
    // sets hit record to normal vector
    // outward normal assumed to be unit vector

    front_face = dot(r.direction(), outward_normal) < 0;

    if (front_face) {
        normal = outward_normal;
    } else {
        normal = outward_normal * -1;
    }
}