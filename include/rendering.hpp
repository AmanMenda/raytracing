#pragma once
#include <Maths/vectors.hpp>

using Raytracing::Maths;

struct Image {
	int width = 400;
	// this ensure the image height respects the AR;
	int height = (int(image_width / aspect_ratio) < 1)
		? 1
		: int(image_width / aspect_ratio)
};

class Viewport {
public:
	Viewport()
	{
		computeViewportVectors();
	};

	Viewport(int width, int height) : _width(width), _height(height)
	{
		computeViewportVectors();
	}

	int getWidth() const { return _width; }
	int getHeight() const { return _height; }
	Vec3<int> getHorizontalVector() const { return _horizontalVector; }
	Vec3<int> getVerticalVector() const { return _verticalVector; }

	inline void computeViewportVectors() {
		_horizontalVector = Vec3<int>(_width, 0, 0);
		_verticalVector = Vec3<int>(0, -(_height), 0); // -height, since the y-axis is inverted in the image plane
	}

	inline void getUpperLeftPointCoordinates(const Camera& camera) {
		_upperLeftPoint = camera.center - Vec3<int>(0, 0, camera.focalLength) - (_horizontalVector / 2) - (_verticalVector / 2);
	}

private:
	double _aspectRatio = 16 / 9;
	int _width = height * (double(originalImage.width) / originalImage.height);
	int _height = 2.0;

	Vec3<int> _horizontalVector;
	Vec3<int> _verticalVector;
	Vec3<int> _upperLeftPoint;

	Image originalImage = Image();
};

class Camera {
public:
	Camera() = default;
	Camera(double focalLength, const Vec3<int>& center)
		: focalLength(focalLength), center(center) {
	}

	Camera& operator=(const Camera& other) {
		if (*this != other) {
			focalLength = other.focalLength;
			center = other.center;
		}
		return *this;
	}
	
	// Perfect copy
	Camera& operator=(Camera&& other) noexcept {
		if (*this != other) {
			focalLength = std::move(other.focalLength);
			center = std::move(other.center);
		}
		return *this;
	};

private:
	double focalLength = 1.0; // The distance from the camera to the viewport/image plane
	Vec3<int> center = Vec3<int>(0, 0, 0);
	Viewport viewport = Viewport();
};