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

class Primitive{
    static int counter;
    int key;
    
  protected:
    const Material *m_material;
    Vec3 m_exitance;
    
  public:
    Primitive();
    Primitive(Material *m); 
    virtual double intersect(const Ray &ray) = 0;
};

#endif
