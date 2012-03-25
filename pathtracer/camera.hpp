//
//  camera.hpp
//  pathtracer
//
//  Created by Keunhong Park on 3/22/12.
//  Copyright (c) 2012 UIUC. All rights reserved.
//

#ifndef pathtracer_camera_hpp
#define pathtracer_camera_hpp

#include <iostream>
#include "vec3.hpp"

using std::cout;
using std::endl;

struct Camera{
    Vec3 optical_center;
    Vec3 focal_point;
    Vec3 lookat;
    double fovx;
    double fovy;
    double focal_length;
    
    Camera(Vec3 pos, Vec3 lookat, double fovx, double width, double height);
};

#endif
