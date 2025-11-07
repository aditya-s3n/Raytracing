#pragma once

#include "actor.h"

class camera {
    public:
        double aspect_ratio = 1.0;  // Ratio of image width over height
        int img_width = 100;  // Rendered image width in pixel count
        int samples_per_pixel = 10; // random samples for anti-aliasing
        int max_depth = 10; // max ray bounces
    
        void render(const actor& world);

    private:
        int img_height;
        point3 center;
        point3 pixel00_loc;
        vec3 pixel_delta_u;
        vec3 pixel_delta_v;
        double pixel_samples_scale; 

        void initialize();

        ray get_ray(int i, int j) const;

        vec3 sample_square() const;

        color ray_color(const ray& r, int depth, const actor& world) const;
};