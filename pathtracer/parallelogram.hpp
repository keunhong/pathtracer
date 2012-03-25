//
//  parallelogram.hpp
//  pathtracer
//
//  Created by Keunhong Park on 3/24/12.
//  Copyright (c) 2012 UIUC. All rights reserved.
//

#ifndef pathtracer_parallelogram_hpp
#define pathtracer_parallelogram_hpp

#include "primitive.hpp"

class Parallelogram : public Primitive{
    Vec3 m_a;
    Vec3 m_b;
    Vec3 m_p0;
    Vec3 m_p1;
    Vec3 m_p2;
    Vec3 m_p3;
    Vec3 m_normal;
    Vec3 m_center;
    double m_width;
    double m_height;
    
public:
    Parallelogram();
    Parallelogram(Vec3 p0, Vec3 a, Vec3 b, Material *m);
    virtual double intersect(const Ray &ray);
    virtual Vec3 get_pos(void) const;
    virtual Vec3 get_normal(Vec3 p) const;
    virtual double get_area(void) const;
};

#endif
