#include "vec3.hpp"

Vec3::Vec3() : x(0), y(0), z(0){}
Vec3::Vec3(double x_, double y_, double z_) : x(x_), y(y_), z(z_){}
Vec3::Vec3(double xyz) : x(xyz), y(xyz), z(xyz){}

Vec3& Vec3::normalize(){
    double length = sqrt(x*x+y*y+z*z);
    x /= length;
    y /= length;
    z /= length;

    return *this;
}

Vec3 Vec3::norm(){
    double length = sqrt(x*x+y*y+z*z);
    return Vec3(x/length, y/length, z/length);
}

double Vec3::length() const{
    return sqrt(x*x+y*y+z*z);
}

Vec3 Vec3::cross(const Vec3& v) const{
    return Vec3(y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x);
}

double Vec3::dot(const Vec3& r) const{
    return x*r.x + y*r.y + z*r.z;
}

double Vec3::operator*(const Vec3& r) const{
    return dot(r);
}

// Scalar operators
Vec3 Vec3::operator*(double s) const{
    return Vec3(s*x, s*y, s*z);
}
Vec3 operator*(double s, const Vec3& v){
    return Vec3(s*v.x, s*v.y, s*v.z);
}

Vec3 Vec3::operator+(double s) const{
    return Vec3(s+x, s+y, s+z);
}
Vec3 operator+(double s, const Vec3& v){
    return Vec3(s+v.x, s+v.y, s+v.z);
}

Vec3 Vec3::operator-(double s) const{
    return Vec3(x-s, y-s, z-s);
}

Vec3 Vec3::operator/(double s) const{
    return Vec3(x/s, y/s, z/s);
}

Vec3& Vec3::operator+=(const double& c){
    x += c;
    y += c;
    z += c;
    return *this;
}
Vec3& Vec3::operator-=(const double& c){
    x /= c;
    y /= c;
    z /= c;
    return *this;
}
Vec3& Vec3::operator*=(const double& c){
    x /= c;
    y /= c;
    z /= c;
    return *this;
}
Vec3& Vec3::operator/=(const double& c){
    x /= c;
    y /= c;
    z /= c;
    return *this;
}




// Vector operators
Vec3 Vec3::operator+(const Vec3& r) const{
    return Vec3(x+r.x, y+r.y, z+r.z);
}

Vec3 Vec3::operator-(const Vec3& r) const{
    return Vec3(x-r.x, y-r.y, z-r.z);
}

Vec3 Vec3::operator-() const{
    return Vec3(-x, -y, -z);
}
Vec3& Vec3::operator+=(const Vec3& c){
    x += c.x;
    y += c.y;
    z += c.z;
    return *this;
}
Vec3& Vec3::operator-=(const Vec3& c){
    x /= c.x;
    y /= c.y;
    z /= c.z;
    return *this;
}
Vec3& Vec3::operator*=(const Vec3& c){
    x /= c.x;
    y /= c.y;
    z /= c.z;
    return *this;
}
Vec3& Vec3::operator/=(const Vec3& c){
    x /= c.x;
    y /= c.y;
    z /= c.z;
    return *this;
}





std::ostream& operator<<(std::ostream& os, const Vec3& v){
    os << "Vec3(" <<  v.x << ", " << v.y <<", " << v.z << ")";
    return os;
}



