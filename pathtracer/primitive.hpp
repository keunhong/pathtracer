//
//  primitive.hpp
//  pathtracer
//
//  Created by Keunhong Park on 3/22/12.
//  Copyright (c) 2012 UIUC. All rights reserved.
//

#ifndef pathtracer_primitive_hpp
#define pathtracer_primitive_hpp

#include "material.hpp"
#include "ray.hpp"
#include "vec3.hpp"

#define INTERSECT_EPSILON 1e-4
class Primitive{
    static int counter;
    int key;
    
  protected:
    const Material *m_material;
    
  public:
    Primitive();
    Primitive(Material *m); 
    virtual double intersect(const Ray &ray) = 0;
    Color get_color(void) const;
    virtual Vec3 get_pos(void) const = 0;
    const Material *get_mat(void) const;
    Color get_exitance(void) const;
    virtual Vec3 get_normal(Vec3 p) const = 0;
    virtual double get_area(void) const = 0;
};

#endif
