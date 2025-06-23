#pragma once
#include <Maths/vectors.hpp>

using namespace Raytracing::Maths;

struct Image {
	double aspectRatio;
	int width;
	int height;

	Image(int w = 400, double ar = 16.0 / 9.0)
		: aspectRatio(ar), width(w) {
		height = (int(width / aspectRatio) < 1) ? 1 : int(width / aspectRatio);
	}
};

class Viewport {
public:
	Viewport()
	{
		_image = Image();
		_height = 2.0;
		_width = _height * (double(_image.width) / _image.height);
		computeViewportVectors();
	};

	Viewport(double width, double height, Image image) : _width(width), _height(height), _image(image)
	{
		computeViewportVectors();
		getUpperLeftPointCoordinates();
	}

	double getWidth() const { return _width; }
	double getHeight() const { return _height; }
	Vec3<double> getHorizontalVector() const { return _horizontalVector; }
	Vec3<double> getVerticalVector() const { return _verticalVector; }
	Image getImage() const { return _image; }

	inline void computeViewportVectors() {
		_horizontalVector = Vec3<double>(_width, 0, 0);
		_verticalVector = Vec3<double>(0, -(_height), 0); // -height, since the y-axis is inverted in the image plane
	}

	inline Vec3<double> getUpperLeftPointCoordinates() {
		_upperLeftPoint = Vec3<double>(0, 0, 0) -
			Vec3<double>(0, 0, 1) - (_horizontalVector / 2) - 
			(_verticalVector / 2);
		return _upperLeftPoint;
	}

private:
	double _width;
	double _height;

	Vec3<double> _horizontalVector;
	Vec3<double> _verticalVector;
	Vec3<double> _upperLeftPoint;

	Image _image;
};

class Camera {
public:
	Camera() = default;
	Camera(double focalLength, const Vec3<double>& center)
		: _focalLength(focalLength), _center(center) {
	}

	Camera& operator=(const Camera& other) {
		if (this != &other) {
			_focalLength = other._focalLength;
			_center = other._center;
		}
		return *this;
	}
	
	// Perfect copy
	Camera& operator=(Camera&& other) noexcept {
		if (this != &other) {
			_focalLength = std::move(other._focalLength);
			_center = std::move(other._center);
		}
		return *this;
	};

	Vec3<double> getCamCenter() const { return _center; }
	double getFocalLength() const { return _focalLength; }

private:
	double _focalLength = 1.0; // The distance from the camera to the viewport/image plane
	Vec3<double> _center = Vec3<double>(0, 0, 0);
};