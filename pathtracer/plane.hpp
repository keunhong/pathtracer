//
//  plane.hpp
//  pathtracer
//
//  Created by Keunhong Park on 3/24/12.
//  Copyright (c) 2012 UIUC. All rights reserved.
//

#ifndef pathtracer_plane_hpp
#define pathtracer_plane_hpp


#include "primitive.hpp"

class Plane : public Primitive{
private:
    Vec3 m_normal;
    Vec3 m_r0;
    
public:
    Plane();
    Plane(Vec3 n, Vec3 r0, Material *m);
    virtual double intersect(const Ray &ray);
    virtual Vec3 get_pos(void) const;
    virtual Vec3 get_normal(Vec3 p) const;
    virtual double get_area(void) const;
};

#endif
