//
//  material.hpp
//  pathtracer
//
//  Created by Keunhong Park on 3/22/12.
//  Copyright (c) 2012 UIUC. All rights reserved.
//

#ifndef pathtracer_material_hpp
#define pathtracer_material_hpp

#include "color.hpp"
#include "vec3.hpp"
#include "ray.hpp"

class Material{
public:
    Color color;
    double n;
    Color exitance;
    
    Material();
    Material(Color e, Color c, double n);
    
    Vec3 sample_hemisphere(Vec3 n) const;
    virtual Vec3 brdf_direction(Vec3 n) const;
};

#endif
