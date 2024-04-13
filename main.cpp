
#include <iostream>
// #include "color.h"
#include "ray.h"
#include "parser.h"
Ray::ray generateRay(const parser::Camera &camera, int i, int j);

// using namespace parser;
int main()
{

    parser::Scene scene;
    scene.loadFromXml("simple.xml");
    parser::Camera cam = scene.cameras[0];
    int imgWidth = cam.image_width;
    int imgHeigth = cam.image_height;


    //main loop
    for(int i=0; i<imgHeigth; i++){

        for(int j=0; j<imgWidth; j++){
            Ray::ray _ray = generateRay(cam,i,j);




        }
    }

}

Ray::ray generateRay(const parser::Camera &camera, int i, int j)
{
    // near plane values
    float left = camera.near_plane.x;
    float right = camera.near_plane.y;
    float bottom = camera.near_plane.z;
    float top = camera.near_plane.w;

    // normalize the gaze vector
    Vector3f::Vec3f gaze = Vector3f::normalize(camera.gaze);

    float su = (right - left) * (j + 0.5) / camera.image_width;
    float sv = (top - bottom) * (i + 0.5) / camera.image_height;

    Vector3f::Vec3f u, v;
    Vector3f::point3f m, q, s;
    m = camera.position + (camera.gaze * camera.near_distance); // m = e + -w*distance

    u = Vector3f::cross(gaze, camera.up);
    u = Vector3f::normalize(u);

    v = Vector3f::cross(u, gaze);

    q = m + u * left + v * top; // q = m + l*u + t*v

    s = q + u * su - v * sv; // s = q + u*su - v*sv

    Ray::ray ray;
    // iki nokta arasına vektör çizmek içi bitiş noktasından başlangıç noktası çıkarılır
    ray.setOrigin(camera.position);
    ray.setDirection(Vector3f::normalize(s - camera.position));
    return ray;
}