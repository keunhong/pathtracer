//
//  util.hpp
//  pathtracer
//
//  Created by Keunhong Park on 3/23/12.
//  Copyright (c) 2012 UIUC. All rights reserved.
//

#ifndef pathtracer_util_hpp
#define pathtracer_util_hpp

#include <cfloat>
#include <cstdlib>

namespace util{
    template <typename T> T clamp(const T& value, const T& low, const T& high){
        return (value < low) ? low : ((value > high) ? high : value); 
    }
    
    double drand(void);
}
    

#endif