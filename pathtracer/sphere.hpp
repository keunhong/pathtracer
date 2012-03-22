//
//  sphere.hpp
//  pathtracer
//
//  Created by Keunhong Park on 3/22/12.
//  Copyright (c) 2012 UIUC. All rights reserved.
//

#ifndef pathtracer_sphere_hpp
#define pathtracer_sphere_hpp

#include "primitive.hpp"

class Sphere : public Primitive{
private:
    Vec3 center;
    double radius;
    
public:
    Sphere();
    Sphere(Vec3 c, double r, Material *m);
    virtual double intersect(const Ray &ray);
};

#endif
