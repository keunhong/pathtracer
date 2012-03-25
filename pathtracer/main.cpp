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
#include <fstream>
#include <ctime>

#include "vec3.hpp"
#include "ray.hpp"
#include "primitive.hpp"
#include "sphere.hpp"
#include "plane.hpp"
#include "parallelogram.hpp"
#include "material.hpp"
#include "scene.hpp"
#include "camera.hpp"

using std::cout;
using std::endl; 

int main (int argc, const char * argv[])
{   
    cout << "Path Tracer" << endl;
    
    long int seed = (long int)time(NULL);
    cout << "Seeding with seed = " << seed << endl;
    srand48(seed);
    
    
    int width = 640;
    int height = 480;
    int num_passes = 10;
    
    cout << "Initializing environment" << endl;
    
    Material mats[] = {
        Material(Color(1.0), Color(0.9), 1), //light
        Material(Color(0.0), Color(0.9, 0.5, 0.5), 1),
        Material(Color(0.0), Color(0.5, 0.9, 0.5), 1),
        Material(Color(0.0), Color(0.5, 0.5, 0.9), 1),
        Material(Color(0.0), Color(0.9)          , 1),
        Material(Color(1.5), Color(0)            , 1)
    };
    
    Scene scene;
    //scene.add_primitive( new Parallelogram(Vec3(-320,520,500), Vec3(0,0,-1000), Vec3(640,0,0), &mats[5]) ); // ceiling
    
    scene.add_primitive( new Sphere(Vec3(-300,-420,-400), 100, &mats[4]) );
    scene.add_primitive( new Sphere(Vec3(0,-420,-400), 100, &mats[3]) );
    scene.add_primitive( new Sphere(Vec3(300,-420,-400), 100, &mats[4]) );
    scene.add_primitive( new Plane(Vec3(-1,0,0), Vec3(520,0,0), &mats[1]) ); // right wall
    scene.add_primitive( new Plane(Vec3(1,0,0), Vec3(-520,0,0), &mats[2]) ); // left wall
    scene.add_primitive( new Plane(Vec3(0,-1,0), Vec3(0,520,0), &mats[5]) ); // ceiling
    scene.add_primitive( new Plane(Vec3(0,1,0), Vec3(0,-520,0), &mats[4]) ); // floor
    scene.add_primitive( new Plane(Vec3(0,0,1), Vec3(0,0,-700), &mats[4]) ); // front wall
    scene.add_primitive( new Plane(Vec3(0,0,-1), Vec3(0,0,700), &mats[4]) ); // back wall
    
    Camera cam(Vec3(0,0,500), Vec3(0,0,-1), M_PI/2, width, height);
    
    double image[width][height][3];
        
    // Trace scene
    cout << "Tracing scene" << endl;
    for(int pass = 1; pass <= num_passes; pass++){
        // Display progress
        cout << "Pass " << pass << " of " << num_passes << endl;
        for(int x = 0; x < width; x++){
            // Trace scene
            for(int y = 0; y < height; y++){
                double u = (double)x - width/2.0;
                double v = (double)y - height/2.0;
                
                static const int num_samples = 1;
                for(int i = 0; i < num_samples; i++){
                    double xs = 0;
                    double ys = 0;
                    Vec3 image_point(cam.optical_center.x+u+xs
                                    ,cam.optical_center.y+v+ys
                                    ,cam.optical_center.z);
                    Ray ray(image_point, cam.focal_point-image_point);
                    ray.d.normalize();
                    
                    Color c = scene.radiance(ray, 0).to_int();
                    
                    image[x][y][0] += c.r/(num_samples*num_passes);
                    image[x][y][1] += c.g/(num_samples*num_passes);
                    image[x][y][2] += c.b/(num_samples*num_passes);
                }
            }
        }
    }

    // Write to file
    cout << "Writing to file" << endl;
    std::ofstream file;
    file.open("image.ppm");
    file << "P3" << endl
         << width << " " << height << endl
         << 255 << endl;
    
    for(int y = 0; y < height; y++){
        for(int x = 0; x < width; x++){
            file << (int)image[width-1-x][y][0] << " "
                 << (int)image[width-1-x][y][1] << " "
                 << (int)image[width-1-x][y][2] << " ";
        }
    }
    file.close();
    cout << "Done" << endl;
    return 0;
}

