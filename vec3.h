#ifndef __Vec3f_H__
#define __Vec3f_H__

#include <cmath>
#include <iostream>

// using std::sqrt;

namespace Vector3f
{

    class Vec3f
    {
    public:
        float x;
        float y;
        float z;
        Vec3f() : x(0.0f), y(0.0f), z(0.0f) {}
        Vec3f(float xf, float yf, float zf) : x(xf), y(yf), z(zf) {}

        // float x() const { return this->x; }
        // float y() const { return this->y; }
        // float z() const { return (*this).z; }

        Vec3f operator-() const { return Vec3f(-x, -y, -z); }
        // float operator[](int i) const { return e[i]; }
        // float &operator[](int i) {
        //     if(i<0) throw std::runtime_error("index 0'dan küçük olamaz");
        //     if(i==0)
        // }

        Vec3f &operator+=(const Vec3f &v)
        {
            x += v.x;
            y += v.y;
            z += v.z;
            return *this;
        }

        Vec3f operator=(const Vec3f &v)
        {
            x = v.x;
            y = v.y;
            z = v.z;
            return *this;
        }

        // Vec3f operator-(const Vec3f &other) const
        // {
        //     return Vec3f(x - other.x, y - other.y, z - other.z);
        // }
        // Vec3f operator+(const Vec3f &other) const
        // {
        //     return Vec3f(x + other.x, y + other.y, z + other.z);
        // }

        Vec3f &operator*=(double t)
        {
            x *= t;
            y *= t;
            z *= t;
            return *this;
        }

        Vec3f &operator/=(float t)
        {
            return *this *= 1 / t;
        }

        double length() const
        {
            return sqrt(length_squared());
        }

        double length_squared() const
        {
            return x * x + y * y + z * z;
        }

    }; // point3 is just an alias for Vec3f, but useful for geometric clarity in the code.
    using point3f = Vec3f;

    // Vector Utility Functions

    inline std::ostream &operator<<(std::ostream &out, const Vec3f &v)
    {
        return out << v.x << ' ' << v.y << ' ' << v.z;
    }

    inline Vec3f operator+(const Vec3f &u, const Vec3f &v)
    {
        return Vec3f(u.x + v.x, u.y + v.y, u.z + v.z);
    }

    inline Vec3f operator-(const Vec3f &u, const Vec3f &v)
    {
        return Vec3f(u.x - v.x, u.y - v.y, u.z - v.z);
    }

    inline Vec3f operator*(const Vec3f &u, const Vec3f &v)
    {
        return Vec3f(u.x * v.x, u.y * v.y, u.z * v.z);
    }

    inline Vec3f operator*(double t, const Vec3f &v)
    {
        return Vec3f(t * v.x, t * v.y, t * v.z);
    }

    inline Vec3f operator*(const Vec3f &v, double t)
    {
        return t * v;
    }

    inline Vec3f operator/(Vec3f v, double t)
    {
        return (1 / t) * v;
    }

    inline double dot(const Vec3f &u, const Vec3f &v)
    {
        return u.x * v.x + u.y * v.y + u.z * v.z;
    }

    inline Vec3f cross(const Vec3f &u, const Vec3f &v)
    {
        return Vec3f(u.y * v.z - u.z * v.y,
                     u.z * v.x - u.x * v.z,
                     u.x * v.y - u.y * v.x);
    }

    inline Vec3f normalize(Vec3f v)
    {
        return v / v.length();
    }
    // inline Vec3f normalize(Vec3f v)
    // {
    //     return v / v.length();
    // }

}

#endif
