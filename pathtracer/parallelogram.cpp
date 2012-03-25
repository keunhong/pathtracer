
//
//  parallelogram.cpp
//  pathtracer
//
//  Created by Keunhong Park on 3/24/12.
//  Copyright (c) 2012 UIUC. All rights reserved.
//

#include "parallelogram.hpp"

Parallelogram::Parallelogram() : Primitive(){}
Parallelogram::Parallelogram(Vec3 p0, Vec3 a, Vec3 b, Material *m){
    m_normal = a.cross(b).normalize();
    m_a = a;
    m_b = b;
    m_p0 = p0;
    m_p1 = p0 + a;
    m_p2 = p0 + a + b;
    m_p3 = p0 + b;
    m_center = m_p0 + (0.5*a) + (0.5*b);
    m_material = m;
}

Vec3 Parallelogram::get_pos(void) const{
    return m_center;
}

Vec3 Parallelogram::get_normal(Vec3 p) const{
    return m_normal;
}

double Parallelogram::get_area(void) const{
    return m_a.dot(m_b);
}

double Parallelogram::intersect(const Ray &ray){
    double vdotn = ray.d*m_normal;
    
    if(vdotn <= INTERSECT_EPSILON && vdotn >= -INTERSECT_EPSILON){
        return DBL_MAX;
    }
    
    double t = ((m_center-ray.o)*m_normal)/vdotn;
    Vec3 position = ray.o + ray.d*t;
    
    if(t > INTERSECT_EPSILON){
        bool c0 = (m_p1-m_p0).cross(position-m_p0).dot(m_normal) >= 0;
        bool c1 = (m_p2-m_p1).cross(position-m_p1).dot(m_normal) >= 0;
        bool c2 = (m_p3-m_p2).cross(position-m_p2).dot(m_normal) >= 0;
        bool c3 = (m_p0-m_p3).cross(position-m_p3).dot(m_normal) >= 0;
        
        if(c0 && c1 && c2 && c3){
            return t;
        }
    }

    
    return DBL_MAX;
}


