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
#include "util.hpp"
#include "primitive.hpp"

using std::vector;

class Scene{
    vector<Primitive*> primitives;
    vector<Primitive*> luminaires;
    
public:
    Scene();
    ~Scene();
    void add_primitive(Primitive *p);
    bool nearest_primitive(const Ray &ray, double &t, Primitive *&obj);
    Vec3 sample_hemisphere(Vec3 p) const;
    Color radiance(const Ray &ray, int depth);

};

#endif
