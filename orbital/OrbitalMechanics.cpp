//
//  OrbitalMechanics.cpp
//  orbital
//
//  Created by Matthew Harris on 18/10/2018.
//  Copyright © 2018 Matthew Harris. All rights reserved.
//

#include "OrbitalMechanics.hpp"
#include <math.h>

void OrbitalMechanics::Euler::compute_gravity_for_step() {
    compute_velocity();
    update_location();
}

point OrbitalMechanics::Euler::calculate_single_body_acceleration(int index) {
    double GRAV = 6.67408e-11; // TODO: Move to constants file
    point acceleration{0, 0, 0};
    body b = m_bodies[index];
    
    int idx = 0;
    for(auto external_body = m_bodies.begin(); external_body != m_bodies.end(); *external_body++, idx++)
    {
        if(idx == index) continue;
        
        // TODO: Try to avoid powers
        double r = pow((b.location.x - external_body->location.x), 2) + pow((b.location.y - external_body->location.y), 2) + pow((b.location.z - external_body->location.z), 2);
        r = sqrt(r);
        auto tmp = (GRAV * external_body->mass) / (r*r*r);
        acceleration = acceleration + (external_body->location - b.location) * tmp;
    }
    
    return acceleration;
}

void OrbitalMechanics::Euler::compute_velocity() {
    for(int i = 0; i < m_bodies.size(); i++) {
        m_bodies[i].velocity += calculate_single_body_acceleration(i) * m_time_step;
    }
}

void OrbitalMechanics::Euler::update_location() {
    for(auto target_body = m_bodies.begin(); target_body != m_bodies.end(); *target_body++) {
        target_body->location += target_body->velocity * m_time_step;
    }
}
