#ifndef __COLOR_H__
#define __COLOR_H__

#include <iostream>
// #include <vec3.h>
#include <ray.h>

using color = Vector3f::Vec3f;

void write_color(std::ostream &out, color pixeelColor) {
    // Write the translated [0,255] value of each color component.
    out << static_cast<int>(255.999 * pixeelColor.x) << ' '
        << static_cast<int>(255.999 * pixeelColor.y) << ' '
        << static_cast<int>(255.999 * pixeelColor.z) << '\n';
}

// //t2^d⋅d−2td⋅(C−Q)+(C−Q)⋅(C−Q)−r^2=0
// bool hit_sphere(const Vector3f::point3f& center, double radius, Ray::ray& r) {
//     Vector3f::Vec3f oc = center - r.getOrigin();
//     auto a = dot(r.getDirection(), r.getDirection());
//     auto b = -2.0 * dot(r.getDirection(), oc);
//     auto c = dot(oc, oc) - radius*radius;
//     auto discriminant = b*b - 4*a*c;
//     return (discriminant >= 0);
// }

color ray_color(Ray::ray& r) {
    Vector3f::Vec3f unit_direction = Vector3f::normalize(r.getDirection());
    auto a = 0.5*(unit_direction.y + 1.0);
    return (1.0-a)*color(1.0, 1.0, 1.0) + a*color(0.2, 0.7, 0.6);
}

#endif
