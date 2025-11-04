#pragma once

#include "rt_utility.h"
#include "actor.h"
#include <vector>


class actor_list : public actor {
    public:
        std::vector<shared_ptr<actor>> objects;

        actor_list() {}
        actor_list(shared_ptr<actor> object);

        void clear();

        void add(shared_ptr<actor> object);

        bool hit(const ray& r, interval ray_t, hit_record& rec) const override;
};