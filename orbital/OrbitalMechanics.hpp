//
//  OrbitalMechanics.hpp
//  orbital
//
//  Created by Matthew Harris on 18/10/2018.
//  Copyright © 2018 Matthew Harris. All rights reserved.
//

#ifndef OrbitalMechanics_hpp
#define OrbitalMechanics_hpp

#include <stdio.h>
#include <vector>
#include "data_structures.h"

namespace OrbitalMechanics {
    class Integrator {
    public:
        virtual void compute_gravity_for_step() = 0;
        virtual std::vector<body>& get_bodies() = 0;
    };
    
    class Euler : Integrator  {
    public:
        Euler(std::vector<body> bodies, double time_step=1) :
            m_bodies(bodies),
            m_time_step(time_step)
        {};
        
        std::vector<body>& get_bodies() { return m_bodies; }
        void compute_gravity_for_step();
        
    protected:
        point calculate_single_body_acceleration(int);
        void compute_velocity();
        void update_location();
    
    private:
        std::vector<body> m_bodies;
        double m_time_step;
    };
}

// location(x, y, z), velocity (m/s), mass (kg), name
namespace solar_system {
    static body sun{{0, 0, 0}, {0, 0, 0}, 2e30, "sun"};
    static body mercury{{0, 5.0e10, 0}, {47000, 0, 0}, 3.285e23,"mercury"};
    static body venus{ { 0, 1.1e11, 0 }, { 35000, 0, 0 }, 4.8e24, "venus" };
    static body earth{ { 0, 1.5e11, 0 },{ 30000,0,0 }, 6e24, "earth" };
    static body mars{ { 0, 2.2e11, 0 },{ 24000,0,0 }, 2.4e24, "mars" };
    static body jupiter{ { 7.7e11,0,0 }, { 0,13000,0 }, 1e28, "jupiter" };
    static body saturn{ { 0, 1.4e12, 0 },{ 9000,0,0 }, 5.7e26, "saturn" };
    static body uranus = { { 0, 2.8e12, 0 },{ 6835, 0, 0 }, 8.7e25, "uranus" };
    static body neptune = { { 0, 4.5e12, 0 }, { 5477,0,0 }, 1e26, "neptune" };
    static body pluto = { { 0, 7.3e12, 0 }, { 4748,0,0 }, 1.3e22,"pluto" };
}

#endif /* OrbitalMechanics_hpp */
