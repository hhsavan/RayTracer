#ifndef __RAY_H__
#define __RAY_H__

#include "vec3.h"

namespace Ray
{

    // A ray is the function: P(t) = A + t*d
    // A: origin, d: direction, t: positif float values
    class ray
    {

    public:
        ray() {}
        ray(const Vector3f::point3f &origin, const Vector3f::Vec3f &direction) : origin(origin), dir(direction) {}

        Vector3f::point3f getOrigin() { return origin; }
        Vector3f::Vec3f getDirection() { return dir; }

        void setOrigin(const Vector3f::point3f &org){ origin = org;}
        void setDirection(const Vector3f::Vec3f &direction){ dir = direction;}

        // Vector3f::point3f getOriginV() { return origin; }
        // Vector3f::point3f getOriginV() { return origin; }
        Vector3f::point3f at(double t) const
        {
            return origin + t * dir;
        }

    private:
        Vector3f::point3f origin;
        Vector3f::Vec3f dir;
    };

}

#endif
