//
//  camera.cpp
//  pathtracer
//
//  Created by Keunhong Park on 3/22/12.
//  Copyright (c) 2012 UIUC. All rights reserved.
//

#include <iostream>
#include "camera.hpp"

Camera::Camera(Vec3 pos, Vec3 lookat, double fovx, double width, double height){
    m_optical_center = pos;
    m_lookat = lookat;
    m_fovx = fovx;
    m_fovy = height/width * fovx;
    m_focal_length = height / (2*std::tan(fovx/2));
    m_focal_point = m_optical_center;
    m_focal_point.z -= m_focal_length;
}