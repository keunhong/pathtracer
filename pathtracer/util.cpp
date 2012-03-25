//
//  util.cpp
//  pathtracer
//
//  Created by Keunhong Park on 3/23/12.
//  Copyright (c) 2012 UIUC. All rights reserved.
//

#include "util.hpp"

namespace util
{
    
    double drand(void){
        return (double)rand()/(RAND_MAX+1);
    }

}