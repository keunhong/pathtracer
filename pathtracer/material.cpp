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
Material::Material(const Vec3& c, double rd, double rr, double rt, double n_): color(c), rho_d(rd), rho_r(rr), rho_t(rt), n(n_){}