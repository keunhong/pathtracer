//
//  scene.hpp
//  pathtracer
//
//  Created by Keunhong Park on 3/22/12.
//  Copyright (c) 2012 UIUC. All rights reserved.
//

#ifndef pathtracer_scene_hpp
#define pathtracer_scene_hpp

#include <vector>
#include "definitions.hpp"
#include "primitive.hpp"

class Scene{
    std::vector<Primitive*> primitives;
    
public:
    void add_primitive(Primitive *p);
    bool nearest_primitive(const Ray &ray, double &t, Primitive *&obj);
};

#endif
