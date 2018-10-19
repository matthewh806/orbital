//
//  data_structures.h
//  orbital
//
//  Created by Matthew Harris on 18/10/2018.
//  Copyright © 2018 Matthew Harris. All rights reserved.
//

#ifndef data_structures_h
#define data_structures_h

#import <vector>
#import <string>

struct point {
    double x;
    double y;
    double z;
    // TODO: tests for these operators
    point operator+(point a) {
        return point{x+a.x, y+a.y, z+a.z};
    }
    
    point operator+(double a) {
        return point{x + a, y + a, z + a};
    }
    
    point operator-(point a) {
        return point{x-a.x, y-a.y, z-a.z};
    }
    
    point operator-(double a) {
        return point {x-a, y-a, z-a};
    }
    
    point operator*(point a) {
        return point{ x*a.x, y*a.y, z*a.z};
    }
    
    point operator*(double a) {
        return point{x*a, y*a, z*a};
    }
    
    point operator/(point a) {
        return point{x/a.x, y/a.y, z/a.z};
    }
    
    point operator/(double a) {
        return point{x / a, y / a, z / a };
    }
    
    point operator+=(point a) {
        x += a.x;
        y += a.y;
        z += a.z;
        
        return point{x, y, z };
    }
    
};

struct body {
    point location;
    point velocity;
    double mass;
    std::string name;
    std::vector<point> locations;
};

#endif /* data_structures_h */
