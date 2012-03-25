//
//  sphere.cpp
//  pathtracer
//
//  Created by Keunhong Park on 3/22/12.
//  Copyright (c) 2012 UIUC. All rights reserved.
//

#include <iostream>
#include "sphere.hpp"

Sphere::Sphere(){
    
}
Sphere::Sphere(Vec3 c, double r, Material *m) : Primitive(){
    m_center = c;
    m_radius = r;
    m_material = m;
}

Vec3 Sphere::get_pos() const{
    return m_center;
}

Vec3 Sphere::get_normal(Vec3 p) const{
    return (p-m_center).normalize();
}

double Sphere::get_area(void) const{
    return 4*M_PI*m_radius*m_radius;
}

double Sphere::intersect(const Ray &ray){
    Vec3 d = ray.o - m_center; // p-c
    double a = ray.d*ray.d; // v*v
    double b = ray.d*d; // v*(p-c)
    double c = d*d - m_radius*m_radius; // (p-c)*(p-c) - r^2
    double det = b*b - a*c; // determinant
    
    // No root
    if(det < 0){
        return DBL_MAX;
    }
    
    // Check smaller solution
    double t = (-b-sqrt(det))/a;
    if(t > INTERSECT_EPSILON){
        return t;
    }else{
        // Check larger solution
        t = (-b+sqrt(det))/a;
        if(t > INTERSECT_EPSILON) return t;
        else return DBL_MAX;
    }
}