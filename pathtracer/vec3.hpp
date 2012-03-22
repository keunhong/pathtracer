#ifndef KP_VEC3_H
#define KP_VEC3_H

#include <iostream>
#include <cmath>

class Vec3{
  public:
    double x, y, z;
    Vec3();
    Vec3(double x_, double y_, double z_);
    Vec3& normalize();
    Vec3 cross(const Vec3& v) const;
    double dot(const Vec3& r) const;
    double operator*(const Vec3& r) const;
    double length() const;
    Vec3 operator*(double s) const;
    Vec3 operator+(double s) const;
    Vec3 operator-(double s) const;
    Vec3 operator/(double s) const;
    friend Vec3 operator*(double s, const Vec3 &v);
    friend Vec3 operator+(double s, const Vec3 &v);
    friend Vec3 operator-(double s, const Vec3 &v);
    Vec3 operator+(const Vec3& r) const;
    Vec3 operator-(const Vec3& r) const;
    Vec3 operator-() const;
    Vec3& operator+=(const Vec3& c);
    Vec3& operator-=(const Vec3& c);
    Vec3& operator*=(const Vec3& c);
    Vec3& operator/=(const Vec3& c);

    friend std::ostream& operator<<(std::ostream& os, const Vec3& v);
};


#endif 
