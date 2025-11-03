#include "vec3.h"
#include "ray.h"
#include "color.h"

#include <iostream>


color ray_color(const ray& r) {
    vec3 unit_direction = unit_vector(r.direction());

    auto a = 0.5 * (unit_direction.y() + 1.0);

    auto linear_interpolation = (1.0 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);

    return linear_interpolation;
}

int main() {
    // IMAGE
    auto aspect_ratio = 16.0 / 9.0;
    int img_width = 400;
    int img_height = int(img_width / aspect_ratio);

    if (img_height < 1) {
        img_height = 1;
    }


    // CAMERA
    auto focal_len = 1.0;
    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * (double(img_width)/img_height);
    auto camera_center = point3(0, 0, 0);

    // viewport vectors
    auto viewport_u = vec3(viewport_width, 0, 0);
    auto viewport_v = vec3(0, -viewport_height, 0);

    // horizontal and vertical delta
    auto pixel_delta_u = viewport_u / img_width;
    auto pixel_delta_v = viewport_v / img_height;

    // location of top left pixel
    auto viewport_upper_left = camera_center - vec3(0, 0, focal_len) - viewport_u/2 - viewport_v/2;
    auto pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);


    // RENDER
    std::cout << "P3\n" << img_width << ' ' << img_height << "\n255\n";

    for (int j = 0; j < img_height; j++) {
        
        std::clog << "\rScanlines Remaining: " << (img_height - j) << ' ' << std::flush;

        for (int i = 0; i < img_width; i++) {

            auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v); // pixel to render
            auto ray_direction = pixel_center - camera_center;
            ray r(camera_center, ray_direction);

            color pixel_color = ray_color(r);

            write_color(std::cout, pixel_color);

        }

    }


    std::clog << "\rDone.\n";

    return 0;
}