//
//  material.hpp
//  pathtracer
//
//  Created by Keunhong Park on 3/22/12.
//  Copyright (c) 2012 UIUC. All rights reserved.
//

#ifndef pathtracer_material_hpp
#define pathtracer_material_hpp

#include "vec3.hpp"

class Material{
private:
    Vec3 color;
    double rho_d;
    double rho_r;
    double rho_t;
    double n;
    
public:
    Material();
    Material(const Vec3 &c, double rd, double rr, double rt, double n);
};

#endif
