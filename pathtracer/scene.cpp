//
//  scene.cpp
//  pathtracer
//
//  Created by Keunhong Park on 3/22/12.
//  Copyright (c) 2012 UIUC. All rights reserved.
//

#include "scene.hpp"


bool Scene::nearest_primitive(const Ray &ray, double &t, Primitive *&obj){
    t = DBL_MAX;
    obj = NULL;
    for(std::vector<Primitive*>::iterator it = primitives.begin(); it != primitives.end(); it++){
        double tcur = (*it)->intersect(ray);
        if(tcur < t) {
            t = tcur;
            obj = *it;
        }
    }
    
    return t < DBL_MAX;
}

void Scene::add_primitive(Primitive *p){
    primitives.push_back(p);
}