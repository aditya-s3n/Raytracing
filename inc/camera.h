#pragma once

#include "actor.h"
#include "material.h"

class camera {
    public:
        double aspect_ratio = 1.0;  // Ratio of image width over height
        int img_width = 100;  // Rendered image width in pixel count
        int samples_per_pixel = 10; // random samples for anti-aliasing
        int max_depth = 10; // max ray bounces

        double vfov = 90; // vertical view angle
        point3 lookfrom = point3(0, 0, 0); // point from camera lens
        point3 lookat = point3(0, 0, -1); // look at point
        vec3 vup = vec3(0, 1, 0); // camera-relative up direction

        double defocus_angle = 0;
        double focus_dist = 10;
    
        void render(const actor& world);

    private:
        int img_height;
        point3 center;
        point3 pixel00_loc;
        vec3 pixel_delta_u;
        vec3 pixel_delta_v;
        double pixel_samples_scale; 
        vec3 u, v, w; // camera frame basis vectors
        vec3 defocus_disk_u;
        vec3 defocus_disk_v;


        void initialize();

        ray get_ray(int i, int j) const;

        vec3 sample_square() const;

        point3 defocus_disk_sample() const;

        color ray_color(const ray& r, int depth, const actor& world) const;
};