//
//  camera.cpp
//  pathtracer
//
//  Created by Keunhong Park on 3/22/12.
//  Copyright (c) 2012 UIUC. All rights reserved.
//

#include <iostream>
#include "camera.hpp"

Camera::Camera(Vec3 pos, Vec3 lookat_, double fovx_, double width, double height){
    optical_center = pos;
    lookat = lookat_;
    fovx = fovx_;
    fovy = height/width * fovx;
    focal_length = height / (2*std::tan(fovx/2));
    focal_point = optical_center;
    focal_point.z -= focal_length;
    
    cout << "optical center : " << optical_center << endl
         << "focal point : " << focal_point << endl
         << "focal length : " << focal_length << endl;
}