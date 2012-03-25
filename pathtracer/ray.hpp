//
//  ray.h
//  pathtracer
//
//  Created by Keunhong Park on 3/22/12.
//  Copyright (c) 2012 UIUC. All rights reserved.
//

#ifndef pathtracer_ray_h
#define pathtracer_ray_h

#include "vec3.hpp"

struct Ray{
    Vec3 o,d;
    Ray(Vec3 o_, Vec3 d_) : o(o_), d(d_){}
    friend std::ostream& operator<<(std::ostream& os, const Ray& r){
        os << "Ray( " << r.o << " + t * " << r.d << " )";
        return os;
    }
};

#endif
