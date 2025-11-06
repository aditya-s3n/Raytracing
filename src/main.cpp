#include "rt_utility.h"

#include "actor.h"
#include "actor_list.h"
#include "sphere.h"
#include "camera.h"

int main() {
    // WORLD
    actor_list world;
    world.add(make_shared<sphere>(point3(0, 0, -1), 0.5));
    world.add(make_shared<sphere>(point3(0, -100.5, -1), 100));

    // RENDER
    camera cam;
    cam.aspect_ratio = 16.0 / 9.0;
    cam.img_width = 400;
    cam.samples_per_pixel = 100;

    cam.render(world);
    

    return 0;
}