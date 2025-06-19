#pragma once
#include <Maths/vectors.hpp>

using Raytracing::Maths;

class Ray {
    public:
        Ray() = default;

        Ray(const Vec3<int>& origin, const Vec3<int>& direction) : 
            _origin(origin), _direction(direction) {}

        const Vec3<int>& origin() const { return _origin; }
        const vec3<int>& direction() const { return _direction; }
        
        // A ray being a line in a cartesian plane,
		// t being the parameter that scales the direction,
	    // the point at time t is given by P(t) = at + b
        Vec3<int> at(double t) const {
            return (_direction * t) + _origin;
        }

    private:
        Vec3<int> _origin;
        vec3<int> _direction;       
};