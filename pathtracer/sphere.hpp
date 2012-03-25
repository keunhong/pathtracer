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
#include <cfloat>

class Sphere : public Primitive{
private:
    Vec3 m_center;
    double m_radius;
    
public:
    Sphere();
    Sphere(Vec3 c, double r, Material *m);
    virtual double intersect(const Ray &ray);
    virtual Vec3 get_pos() const;
    virtual Vec3 get_normal(Vec3 p) const;
    virtual double get_area(void) const;

};

#endif
