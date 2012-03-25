//
//  plane.cpp
//  pathtracer
//
//  Created by Keunhong Park on 3/24/12.
//  Copyright (c) 2012 UIUC. All rights reserved.
//

#include "plane.hpp"

Plane::Plane() : Primitive(){}
Plane::Plane(Vec3 n, Vec3 r0, Material *m){
    m_normal = n;
    m_r0 = r0;
    m_material = m;
}

Vec3 Plane::get_pos(void) const{
    return m_r0;
}

Vec3 Plane::get_normal(Vec3 p) const{
    return m_normal;
}

double Plane::intersect(const Ray &ray){
    double vdotn = ray.d*m_normal;
    
    if(vdotn <= INTERSECT_EPSILON && vdotn >= -INTERSECT_EPSILON){
        return DBL_MAX;
    }
    
    double t = ((m_r0-ray.o)*m_normal)/vdotn;
    if(t > INTERSECT_EPSILON){
        return t;
    }
    
    return DBL_MAX;
}

double Plane::get_area(void) const{
    return 1;
}