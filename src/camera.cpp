#include "camera.h"

color camera::ray_color(const ray& r, const actor& world) {
    hit_record rec;
    if (world.hit(r, interval(0, infinity), rec)) {
        return 0.5 * (rec.normal + color(1, 1, 1));
    }

    vec3 unit_direction = unit_vector(r.direction());

    auto a = 0.5 * (unit_direction.y() + 1.0);

    auto linear_interpolation = (1.0 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);

    return linear_interpolation;
}

void camera::initialize() {
    img_height = int(img_width / aspect_ratio);

    if (img_height < 1) {
        img_height = 1;
    }

    // CAMERA
    auto focal_len = 1.0;
    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * (double(img_width)/img_height);
    center = point3(0, 0, 0);

    // viewport vectors
    auto viewport_u = vec3(viewport_width, 0, 0);
    auto viewport_v = vec3(0, -viewport_height, 0);

    // horizontal and vertical delta
    pixel_delta_u = viewport_u / img_width;
    pixel_delta_v = viewport_v / img_height;

    // location of top left pixel
    auto viewport_upper_left = center - vec3(0, 0, focal_len) - viewport_u/2 - viewport_v/2;
    pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);
}

void camera::render(const actor& world) {
    initialize();

    
    std::cout << "P3\n" << img_width << ' ' << img_height << "\n255\n";

    for (int j = 0; j < img_height; j++) {
        
        std::clog << "\rScanlines Remaining: " << (img_height - j) << ' ' << std::flush;

        for (int i = 0; i < img_width; i++) {

            auto pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v); // pixel to render
            auto ray_direction = pixel_center - center;
            ray r(center, ray_direction);

            color pixel_color = ray_color(r, world);

            write_color(std::cout, pixel_color);

        }

    }


    std::clog << "\rDone.\n";
}