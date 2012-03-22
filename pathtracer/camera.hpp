//
//  camera.hpp
//  pathtracer
//
//  Created by Keunhong Park on 3/22/12.
//  Copyright (c) 2012 UIUC. All rights reserved.
//

#ifndef pathtracer_camera_hpp
#define pathtracer_camera_hpp

#include "vec3.hpp"

struct Camera{
    Vec3 m_optical_center;
    Vec3 m_focal_point;
    Vec3 m_lookat;
    double m_fovx;
    double m_fovy;
    double m_focal_length;
    
    Camera(Vec3 pos, Vec3 lookat, double fovx, double width, double height);
};

#endif
