//
//  scene.cpp
//  pathtracer
//
//  Created by Keunhong Park on 3/22/12.
//  Copyright (c) 2012 UIUC. All rights reserved.
//

#include "scene.hpp"

Scene::Scene(){
    
}

Scene::~Scene(){
    for(vector<Primitive*>::iterator it = primitives.begin(); it != primitives.end(); it++){
        delete *it;
    }
}

/*
 * Returns the nearest primitive and intersection along a ray
 */
bool Scene::nearest_primitive(const Ray &ray, double &t, Primitive *&obj){
    t = DBL_MAX;
    obj = NULL;
    for(vector<Primitive*>::iterator it = primitives.begin(); it != primitives.end(); it++){
        double tcur = (*it)->intersect(ray);
        if(tcur < t) {
            t = tcur;
            obj = *it;
        }
    }
    
    return t < DBL_MAX;
}

/*
 * Adds a primitive to the scene
 */
void Scene::add_primitive(Primitive *p){
    primitives.push_back(p);
    if(p->get_mat()->exitance != Color::BLACK){
        luminaires.push_back(p);
    }
}

/*
 * Returns a radiance estimate at intersection point along ray
 */
Color Scene::radiance(const Ray &ray, int depth){
    double t;
    Primitive *prim = NULL;
    if(!nearest_primitive(ray, t, prim)){
        std::cout << "No intersection" << std::endl;
        return Color::MAGENTA;
    }
    
    Vec3 p = ray.o + t*ray.d; // intersection point
    Vec3 n = prim->get_normal(p); // normal at intersection point
    Vec3 n_orient = (n*ray.d < 0) ? n : -n; // orient intersection point
    
    // Russian Roulette
    double q = prim->get_color().max();
    if(drand48() > q){
        return prim->get_exitance();
    }
    
    Color brdf = prim->get_color() / M_PI;
    Ray irradiance_ray(p, prim->get_mat()->brdf_direction(n));
    
    return prim->get_exitance() + M_PI*radiance(irradiance_ray,depth+1).dotmult(brdf);
}