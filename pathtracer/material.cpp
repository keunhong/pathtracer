//
//  material.cpp
//  pathtracer
//
//  Created by Keunhong Park on 3/22/12.
//  Copyright (c) 2012 UIUC. All rights reserved.
//

#include "material.hpp"

Material::Material(){
    std::cout << "Default constructor for material called. This will do NOTHING." << std::endl;
}
Material::Material(Color e, Color c, double n_): exitance(e), color(c), n(n_){}

/*
 * Rejection sampling of hemisphere oriented to normal n
 */
Vec3 Material::sample_hemisphere(Vec3 n) const{
    // Uniformly sample cube and reject if not in radius of sphere
    Vec3 random_dir;
    do{
        random_dir = Vec3(drand48()*2.0 - 1.0, drand48()*2.0 - 1.0, drand48()*2.0 - 1.0);
    }while(random_dir*random_dir > 1.0);
    
    random_dir.normalize();
    
    // Flip if point is on the wrong hemisphere
    if(random_dir*n < 0) random_dir = -random_dir;
    
    return random_dir;
}

Vec3 Material::brdf_direction(Vec3 n) const{
    return sample_hemisphere(n);
}