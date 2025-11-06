#pragma once

#include "actor.h"

class camera {
    public:
        double aspect_ratio = 1.0;  // Ratio of image width over height
        int img_width = 100;  // Rendered image width in pixel count
    
        void render(const actor& world);

    private:
        int img_height;
        point3 center;
        point3 pixel00_loc;
        vec3 pixel_delta_u;
        vec3 pixel_delta_v;

        void initialize();

        color ray_color(const ray& r, const actor& world);
};