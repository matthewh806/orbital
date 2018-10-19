//
//  main.cpp
//  orbital
//
//  Created by Matthew Harris on 18/10/2018.
//  Copyright © 2018 Matthew Harris. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "data_structures.h"
#include "OrbitalMechanics.hpp"

static void print_state(std::vector<body>& bodies) {
    std::cout << " ------------------------ RUN " << "---------------------" << std::endl;
    
    for(auto body_iter = bodies.begin(); body_iter != bodies.end(); *body_iter++) {
        std::cout << body_iter->name << " : (x, y, z) :"
        << " ( " << body_iter->location.x << ", " << body_iter->location.y << ", "
        << body_iter->location.z << " )"
        << std::endl;
    }
}

static void write_state(std::vector<body>& bodies) {
    for(auto body_iter = bodies.begin(); body_iter != bodies.end(); *body_iter++) {
        body_iter->locations.push_back(body_iter->location);
    }
}

static void output_states(const std::vector<body>& bodies) {
    for(auto body_iter = bodies.begin(); body_iter != bodies.end(); *body_iter++) {
        std::ofstream f;
        f.open(body_iter->name + ".dat");
        f << body_iter->name << std::endl;
        f.close();
    }
    
    for(auto body_iter = bodies.begin(); body_iter != bodies.end(); *body_iter++) {
        std::ofstream f;
        f.open(body_iter->name + ".dat", std::ofstream::out | std::ofstream::app);
        for(auto location = body_iter->locations.begin(); location < body_iter->locations.end(); *location++) {
            f << location->x << "," << location->y << "," << location->z << std::endl;
        }
        f.close();
    }
}

template <typename Integrator>
void run_simulation(Integrator integrator, int iterations, int data_frequency) {
    for(auto i=0; i < iterations; i++) {
        if(i % data_frequency == 0) {
//            print_state(integrator.get_bodies());
            write_state(integrator.get_bodies());
        }
        
        integrator.compute_gravity_for_step();
    }
    
    output_states(integrator.get_bodies());
}

int main(int argc, const char * argv[]) {
    std::vector<body> bodies;
    
    // TODO: Make some test cases with simpler systems.
    bodies.push_back(solar_system::sun);
    bodies.push_back(solar_system::mercury);
    bodies.push_back(solar_system::venus);
    bodies.push_back(solar_system::earth);
    bodies.push_back(solar_system::mars);
//    bodies.push_back(solar_system::saturn);
//    bodies.push_back(solar_system::jupiter);
//    bodies.push_back(solar_system::uranus);
//    bodies.push_back(solar_system::neptune);
//    bodies.push_back(solar_system::pluto);
    
    // 1 day in seconds: 86400
    OrbitalMechanics::Euler orbit(bodies, 10);
    
    std::cout << " Beginning of simulation! " << std::endl;
    run_simulation(orbit, (int)((365 * 86400) / 10), 1e3);
    
    std::cout << " End of simulation! " << std::endl;
    std::cin;
    
    return 0;
}
