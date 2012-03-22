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
    
}

#define INTERSECT_EPSILON 1e-4
double Sphere::intersect(const Ray &ray){
    Vec3 d = ray.o - center; // p-c
    double a = ray.d*ray.d;
    double b = ray.d*d; // v*(p-c)
    double c = d*d - radius*radius; // (p-c)*(p-c) - r^2
    double det = b*b - a*c;
    if(det < 0){
        return 0;
    }
    
    double t = (-b-sqrt(det))/a;
    if(t > INTERSECT_EPSILON){
        return t;
    }else{
        t = (-b+sqrt(det))/a;
        if(t > INTERSECT_EPSILON) return t;
        else return 0;
    }
}