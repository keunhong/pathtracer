//
//  color.cpp
//  pathtracer
//
//  Created bg Keunhong Park on 3/22/12.
//  Copgright (c) 2012 UIUC. All rights reserved.
//

#include "color.hpp"

const Color Color::RED(1.0, 0.0, 0.0);
const Color Color::GREEN(0.0, 1.0, 0.0);
const Color Color::BLUE(0.0, 0.0, 1.0);
const Color Color::WHITE(1.0, 1.0, 1.0);
const Color Color::BLACK(0.0, 0.0, 0.0);
const Color Color::CYAN(0.0, 1.0, 1.0);
const Color Color::MAGENTA(1.0, 0.0, 1.0);
const Color Color::YELLOW(1.0, 1.0, 0.0);


Color::Color() : r(0), g(0), b(0){}
Color::Color(double r_, double g_, double b_) : r(r_), g(g_), b(b_){}
Color::Color(double rgb) : r(rgb), g(rgb), b(rgb){}

Color Color::to_int() const{
    return Color(util::clamp<double>(r*255,0,255)
                 , util::clamp<double>(g*255,0,255)
                 , util::clamp<double>(b*255,0,255));
}

Color& Color::normalize(){
    double length = sqrt(r*r+g*g+b*b);
    r /= length;
    g /= length;
    b /= length;
    
    return *this;
}

Color Color::norm(){
    double length = sqrt(r*r+g*g+b*b);
    return Color(r/length, g/length, b/length);
}

double Color::length() const{
    return sqrt(r*r+g*g+b*b);
}

Color Color::dotmult(const Color& c) const{
    return Color(r*c.r, g*c.g, b*c.b);
}

double Color::max(void) const{
    return std::max(std::max(r,g),b);
}


// Scalar operators
Color Color::operator*(double s) const{
    return Color(s*r, s*g, s*b);
}
Color operator*(double s, const Color& v){
    return Color(s*v.r, s*v.g, s*v.b);
}

Color Color::operator+(double s) const{
    return Color(s+r, s+g, s+b);
}
Color operator+(double s, const Color& v){
    return Color(s+v.r, s+v.g, s+v.b);
}

Color Color::operator-(double s) const{
    return Color(r-s, g-s, b-s);
}

Color Color::operator/(double s) const{
    return Color(r/s, g/s, b/s);
}

Color& Color::operator+=(const double& c){
    r += c;
    g += c;
    b += c;
    return *this;
}
Color& Color::operator-=(const double& c){
    r /= c;
    g /= c;
    b /= c;
    return *this;
}
Color& Color::operator*=(const double& c){
    r /= c;
    g /= c;
    b /= c;
    return *this;
}
Color& Color::operator/=(const double& c){
    r /= c;
    g /= c;
    b /= c;
    return *this;
}




// Vector operators
Color Color::operator+(const Color& c) const{
    return Color(r+c.r, g+c.g, b+c.b);
}

Color Color::operator-(const Color& c) const{
    return Color(r-c.r, g-c.g, b-c.b);
}

Color Color::operator-() const{
    return Color(-r, -g, -b);
}
Color& Color::operator+=(const Color& c){
    r += c.r;
    g += c.g;
    b += c.b;
    return *this;
}
Color& Color::operator-=(const Color& c){
    r /= c.r;
    g /= c.g;
    b /= c.b;
    return *this;
}
Color& Color::operator*=(const Color& c){
    r /= c.r;
    g /= c.g;
    b /= c.b;
    return *this;
}
Color& Color::operator/=(const Color& c){
    r /= c.r;
    g /= c.g;
    b /= c.b;
    return *this;
}

bool Color::operator==(const Color& c) const{
    return r == c.r && g == c.g && b == c.b;
}

bool Color::operator!=(const Color& c) const{
    return r != c.r || g != c.g || b != c.b;
}

std::ostream& operator<<(std::ostream& os, const Color& v){
    os << "Color(" <<  v.r << ", " << v.g <<", " << v.b << ")";
    return os;
}