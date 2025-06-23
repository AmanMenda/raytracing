#pragma once
#include <Maths/vectors.hpp>

using namespace Raytracing::Maths;

class Ray {
    public:
        Ray() = default;

        Ray(const Vec3<double>& origin, const Vec3<double>& direction) : 
            _origin(origin), _direction(direction) {}

        const Vec3<double>& origin() const { return _origin; }
        const Vec3<double>& direction() const { return _direction; }
        const Vec3<double>& color() const { return _color; }
        
        // A ray being a line in a cartesian plane,
		// t being the parameter that scales the direction,
	    // the point at time t is given by P(t) = at + b
        Vec3<double> at(double t) const {
            return (_direction * t) + _origin;
        }
        
        // blendedColor = ((1−a)baseGradientColor) + (a * maxGradientColor),
		// a being the blending factor (real number between 0 and 1)
		void computeColor() {
			double a = 0.5 * (_direction.normalize().y + 1.0);
			Vec3<double> startValue = Vec3<double>(1.0, 1.0, 1.0); // white
			Vec3<double> endValue = Vec3<double>(0.5, 0.7, 1.0); // light blue
 
            _color = startValue * (1.0 - a) +  endValue * a;
		}

    private:
        Vec3<double> _color;
        Vec3<double> _origin;
        Vec3<double> _direction;       
};