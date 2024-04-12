
#include <iostream>
#include "color.h"
#include "parser.h"

// TODO
// fucntion that creats ppmfile
// ppmFileFunc()

/// @brief
/// @param camera
/// @param i : image_heig
/// @param j : nx
/// @return
Ray::ray generateRay(const Scene::camera &camera, int i, int j)
{
    // near plane values
    float left = camera.getLeft();
    float right = camera.getRight();
    float bottom = camera.getBottom();
    float top = camera.getTop();

    // normalize the gaze vector
    Vector3f::Vec3f gaze = Vector3f::normalize(camera.getGaze());

    float su = (right - left) * (j + 0.5) / camera.getNx();
    float sv = (top - bottom) * (i + 0.5) / camera.getNy();

    Vector3f::Vec3f u, v;
    Vector3f::point3f m, q, s;
    m = camera.getEyePoint() + (camera.getGaze() * camera.getDistance()); // m = e + -w*distance

    u = Vector3f::cross(gaze, camera.getUp());
    u = Vector3f::normalize(u);

    v = Vector3f::cross(u, gaze);

    q = m + u * left + v * top; // q = m + l*u + t*v

    s = q + u * su - v * sv; // s = q + u*su - v*sv

    Ray::ray ray;
    // iki nokta arasına vektör çizmek içi bitiş noktasından başlangıç noktası çıkarılır
    ray.setOrigin(camera.getEyePoint());
    ray.setDirection(Vector3f::normalize(s - camera.getEyePoint()));
    return ray;
}

<<<<<<< HEAD


using namespace parser;
=======
>>>>>>> parent of f6f17f2 (1-parser eklendi ama tam bitmedi. ona bakılacak ve test edilecek. 2-sphere çizmee eklendi ama spherede bi saçmalık var. tam sphere şeklinde değil ona bakılması lazım)
int main()
{

    // Scene::camera camera;

    parser::Scene scene;

    scene.loadFromXml("simple.xml");
    // camera = new Scene::camera(new);

    // // her pixel için dönecek. her bir pixele bir ray oluşturacak
    // for (size_t k = 0; k < camera.getNy(); ++k)
    // {
    //     for (size_t i = 0; i < camera.getNx(); ++i)
    //     {
    //         generateRay(camera, i, k);
    //     }
    // }

    // // Image
    // double e[3];

    int image_width = scene.cameras[0].image_width;// camera.getNx();
    int image_height = scene.cameras[0].image_height;// camera.getNx();

    // Scene::camera cam = new Scene::camera(scene.cameras[0].position,scene.cameras[0].up,scene.cameras[0].gaze
    // ,scene.cameras[0].image_width, scene.cameras[0].image_height, scene.cameras[0].)

    // int image_height = camera.getNy();

    // Render

    // std::cout << "P3\n"
    //           << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; ++j)
    {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i)
        {

            // auto pixel_color = color(double(i)/(image_width-1), double(j)/(image_height-1), 0);
            Ray::ray r = generateRay(scene.cameras[0], j, i);
            color pixel_color = ray_color(r);
            write_color(std::cout, pixel_color);

            // std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
    std::clog << "\rDone.                 \n";
}








Ray::ray generateRay(const parser::Camera &camera, int i, int j)
{
    // near plane values
    float left = camera.near_plane.x;
    float right = camera.near_plane.y;
    float bottom = camera.near_plane.z;
    float top = camera.near_plane.w;

    // normalize the gaze vector
    Vector3f::Vec3f gaze = (camera.gaze);

    float su = (right - left) * (j + 0.5) / camera.getNx();
    float sv = (top - bottom) * (i + 0.5) / camera.getNy();

    Vector3f::Vec3f u, v;
    Vector3f::point3f m, q, s;
    m = camera.getEyePoint() + (camera.getGaze() * camera.getDistance()); // m = e + -w*distance

    u = Vector3f::cross(gaze, camera.getUp());
    u = Vector3f::normalize(u);

    v = Vector3f::cross(u, gaze);

    q = m + u * left + v * top; // q = m + l*u + t*v

    s = q + u * su - v * sv; // s = q + u*su - v*sv

    Ray::ray ray;
    // iki nokta arasına vektör çizmek içi bitiş noktasından başlangıç noktası çıkarılır
    ray.setOrigin(camera.getEyePoint());
    ray.setDirection(Vector3f::normalize(s - camera.getEyePoint()));
    return ray;
}