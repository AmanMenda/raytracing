#include <Maths/vectors.hpp>

namespace Raytracing {
	class Pixel {
		public:
			Pixel() : color(0.0, 0.0, 0.0) {}

			Pixel(const Maths::Vec3<double>& col) : color(col) {}

			Pixel(float r, float g, float b) : color(r, g, b) {}

			Maths::Vec3<double> getColor() const { return color; }

			void setColor(const Maths::Vec3<double>& col) { color = col; }

			void setColor(double r, double g, double b) { color = Maths::Vec3<double>(r, g, b); }

			void paint() {
				int rbyte = int(255.999 * color.x);
				int gbyte = int(255.999 * color.y);
				int bbyte = int(255.999 * color.z);

				std::cout << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
			}

		private:
			Maths::Vec3<double> color;
	};
}