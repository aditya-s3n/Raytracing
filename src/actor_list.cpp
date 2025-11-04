#include "actor_list.h"

actor_list::actor_list(shared_ptr<actor> object) {
    add(object);
}

void actor_list::clear() {
    objects.clear();
}

void actor_list::add(shared_ptr<actor> object) {
    objects.push_back(object);
}

bool actor_list::hit(const ray& r, interval ray_t, hit_record& rec) const {
    hit_record temp_rec;
    bool hit_obj = false;
    auto closest_to_cam = ray_t.max;


    for (const auto& object : objects) {
        if (object->hit(r, interval(ray_t.min, closest_to_cam), temp_rec)) {
            hit_obj = true;
            closest_to_cam = rec.t;
            rec = temp_rec;
        }
    }

    return hit_obj;
}