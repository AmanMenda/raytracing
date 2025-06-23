#pragma once
#include <Maths/vectors.hpp>

using namespace Raytracing::Maths;

using pixel = Vec3<double>;

void paint(pixel p) {
	int rbyte = int(255.999 * p.x);
	int gbyte = int(255.999 * p.y);
	int bbyte = int(255.999 * p.z);

	std::cout << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}