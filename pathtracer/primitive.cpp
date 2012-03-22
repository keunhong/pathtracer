//
//  primitive.cpp
//  pathtracer
//
//  Created by Keunhong Park on 3/22/12.
//  Copyright (c) 2012 UIUC. All rights reserved.
//

#include "primitive.hpp"

int Primitive::counter = 0;

Primitive::Primitive(){
    key = ++counter;
    m_exitance = Vec3(0,0,0);
}

Primitive::Primitive(Material *m){
    key = ++counter;
    m_exitance = Vec3(0,0,0);
    m_material = m;
}