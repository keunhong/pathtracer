//
//  main.cpp
//  pathtracer
//
//  Created by Keunhong Park on 3/14/12.
//  Copyright (c) 2012 UIUC. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>

#include "vec3.hpp"
#include "ray.hpp"
#include "primitive.hpp"
#include "sphere.hpp"
#include "material.hpp"
#include "scene.hpp"
#include "camera.hpp"

using std::cout;
using std::endl;

int main (int argc, const char * argv[])
{   
    cout << "Path Tracer" << endl;
    
    int width = 640;
    int height = 480;
    int samples = 2;
    
    Material mats[] = {
        Material(Vec3(1.0,0,0), 1.0, 0, 0, 0)
    };
    
    Scene scene;
    scene.add_primitive( new Sphere(Vec3(0,0,0), 100, &mats[0]) );
    
    Camera cam(Vec3(0,0,500), Vec3(0,0,-1), M_PI/2, width, height);
    

    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

