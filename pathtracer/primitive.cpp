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
}

Primitive::Primitive(Material *m){
    key = ++counter;
    m_material = m;
}

Color Primitive::get_color(void) const{
    return m_material->color;
}

const Material *Primitive::get_mat(void) const{
    return m_material;
}

Color Primitive::get_exitance(void) const{
    return m_material->exitance;
}