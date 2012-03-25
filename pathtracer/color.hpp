//
//  color.hpp
//  pathtracer
//
//  Created by Keunhong Park on 3/22/12.
//  Copyright (c) 2012 UIUC. All rights reserved.
//

#ifndef pathtracer_color_hpp
#define pathtracer_color_hpp

#include <iostream>
#include <cmath>

#include "util.hpp"

class Color{
public:
    double r, g, b;
    Color();
    Color(double x_, double y_, double z_);
    Color(double xyz);
    
    Color to_int() const;
    
    Color& normalize();
    Color norm();
    double length() const;
    
    double operator*(const Color& r) const;
    
    Color dotmult(const Color& c) const;
    double max(void) const;
    
    // Scalar operators
    Color operator*(double s) const;
    Color operator+(double s) const;
    Color operator-(double s) const;
    Color operator/(double s) const;
    friend Color operator*(double s, const Color &v);
    friend Color operator+(double s, const Color &v);
    friend Color operator-(double s, const Color &v);
    Color& operator+=(const double& c);
    Color& operator-=(const double& c);
    Color& operator*=(const double& c);
    Color& operator/=(const double& c);
    
    // Vector operators
    Color operator+(const Color& r) const;
    Color operator-(const Color& r) const;
    Color operator-() const;
    Color& operator+=(const Color& c);
    Color& operator-=(const Color& c);
    Color& operator*=(const Color& c);
    Color& operator/=(const Color& c);
    
    bool operator==(const Color& c) const;
    bool operator!=(const Color& c) const;
    
    friend std::ostream& operator<<(std::ostream& os, const Color& v);

    static const Color RED;
    static const Color GREEN;
    static const Color BLUE;
    static const Color WHITE;
    static const Color BLACK;
    static const Color CYAN;
    static const Color MAGENTA;
    static const Color YELLOW;
};

#endif
