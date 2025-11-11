#include "camera.h"

color camera::ray_color(const ray& r, int depth, const actor& world) const {
    if (depth <= 0) return color(0, 0, 0);


    hit_record rec;
    if (world.hit(r, interval(0.001, infinity), rec)) {
        ray scattered;
        color attenuation;

        if (rec.mat->scatter(r, rec, attenuation, scattered)) {
            return attenuation * ray_color(scattered, depth - 1, world);
        }

        return color(0, 0, 0);

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

    pixel_samples_scale = 1.0 / samples_per_pixel;

    center = lookfrom;

    // CAMERA
    auto focal_len = (lookfrom - lookat).length();
    auto theta = degrees_to_radians(vfov);
    auto h = std::tan(theta / 2);
    auto viewport_height = 2.0 * h * focal_len;
    auto viewport_width = viewport_height * (double(img_width)/img_height);
    

    // u, w, v basis vectors for camera coordinate frame
    w = unit_vector(lookfrom - lookat);
    u = unit_vector(cross(vup, w));
    v = cross(w, u);

    // viewport vectors
    auto viewport_u = viewport_width * u;
    auto viewport_v = viewport_height * -v;

    // horizontal and vertical delta
    pixel_delta_u = viewport_u / img_width;
    pixel_delta_v = viewport_v / img_height;

    // location of top left pixel
    auto viewport_upper_left = center - (focal_len * w) - viewport_u/2 - viewport_v/2;
    pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);
}

void camera::render(const actor& world) {
    initialize();

    
    std::cout << "P3\n" << img_width << ' ' << img_height << "\n255\n";

    for (int j = 0; j < img_height; j++) {
        
        std::clog << "\rScanlines Remaining: " << (img_height - j) << ' ' << std::flush;

        for (int i = 0; i < img_width; i++) {

            color pixel_color(0, 0, 0);
            for (int sample = 0; sample < samples_per_pixel; sample++) {
                ray r = get_ray(i, j);
                pixel_color += ray_color(r, max_depth,world);
            }

            write_color(std::cout, pixel_samples_scale * pixel_color);

        }

    }


    std::clog << "\rDone.\n";
}

ray camera::get_ray(int i, int j) const {
    // construct ray from origin, and sample randomly around it
    auto offest = sample_square();
    auto pixel_sample = pixel00_loc 
                        + ((i + offest.x()) * pixel_delta_u)
                        + ((j + offest.y()) * pixel_delta_v);
                        
    auto ray_orig = center;
    auto ray_direc = pixel_sample - ray_orig;

    return ray(ray_orig, ray_direc);
}

vec3 camera::sample_square() const {
    // return random vector to a random point unit square [-0.5, -0.5] - [0.5, 0.5]
    return vec3(random_double() - 0.5, random_double() - 0.5, 0);
}