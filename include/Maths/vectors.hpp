#pragma once

#include <cmath>
#include <cassert>

namespace Raytracing::Maths {
    template <typename T, size_t N, typename = std::enable_if_t<std::is_arithmetic_v<T> && (N >= 1)>>
    struct Vec
    {
        T x, y, z;

        static bool isEqual(const T& a, const T& b)
        {
            return a == b;
        }

        static bool isEqual(const Vec& a, const Vec& b)
        {
            for (size_t i = 0; i < N; ++i)
            {
                if (!isEqual(a[i], b[i]))
                {
                    return false;
                }
            }
            return true;
        }
    };

    template <typename T>
    struct Vec2 : public Vec<T, 2>
    {

        using Vec<T, 2>::x;
        using Vec<T, 2>::y;

        Vec2() = default;

        Vec2(T x_value, T y_value)
        {
            x = x_value;
            y = y_value;
        }

        bool operator==(const Vec2& other) const
        {
            return  Vec<T, 2>::isEqual(x, other.x) &&
                    Vec<T, 2>::isEqual(y, other.y);
        }

        bool operator!=(const Vec2& other) const
        {
            return (*this != other);
        }

        Vec2 operator+(const Vec2& other) const
        {
            return Vec2(x + other.x, y + other.y);
        }

        Vec2 operator-(const Vec2& other) const
        {
            return Vec2(x - other.x, y - other.y);
        }

        Vec2 operator*(T scalar) const
        {
            return Vec2(x * scalar, y * scalar);
        }

        Vec2 operator/(T scalar) const
        {
            assert(scalar != 0 && "Division by zero in vector division");
            return Vec2(x / scalar, y / scalar);
        }

        Vec2& operator+=(const Vec2& other)
        {
            x += other.x;
            y += other.y;

            return *this;
        }

        Vec2& operator-=(const Vec2& other)
        {
            x -= other.x;
            y -= other.y;

            return *this;
        }

        Vec2& operator*=(T scalar)
        {
            x *= scalar;
            y *= scalar;

            return *this;
        }
        Vec2& operator/=(T scalar)
        {
            x /= scalar;
            y /= scalar;

            return *this;
        }

        T magnitude() const
        {
            return std::sqrt(x*x + y*y);
        }

		// Returns a normalized vector (unit vector)
        Vec2 normalize() const
        {
            T vectorLength = magnitude();
            assert(vectorLength != 0 && "Cannot normalize zero vector");
            return *this / vectorLength;
        }
    };

    template <typename T>
    struct Vec3 : public Vec<T, 3>
    {
        using Vec<T, 3>::x;
        using Vec<T, 3>::y;
        using Vec<T, 3>::z;

        Vec3() = default;

        Vec3(T x_value, T y_value, T z_value)
        {
            x = x_value;
            y = y_value;
            z = z_value;
        }

        bool operator==(const Vec3& other) const
        {
            
            return 
                Vec<T, 3>::isEqual(x, other.x) &&
                Vec<T, 3>::isEqual(y, other.y) &&
                Vec<T, 3>::isEqual(z, other.z);
        }

        bool operator!=(const Vec3& other) const
        {
            return *this != other;
        }

        inline Vec3 operator+(const Vec3& other) const
        {
            return Vec3(x + other.x, y + other.y, z + other.z);
        }

        inline Vec3 operator-(const Vec3& other) const
        {
            return Vec3(x - other.x, y - other.y, z - other.z);
        }

        inline Vec3 operator*(T scalar) const
        {
            return Vec3(x * scalar, y * scalar, z * scalar);
        }

        inline Vec3 operator/(T scalar) const
        {
            return Vec3(x / scalar, y / scalar, z / scalar);
        }

		inline Vec3 operator*(const Vec3& other) const
		{
			return Vec3(x * other.x, y * other.y, z * other.z);
		}

        inline Vec3& operator+=(const Vec3& other)
        {
            x += other.x;
            y += other.y;
            z += other.z;

            return *this;
        }

        inline Vec3& operator-=(const Vec3& other)
        {
            x -= other.x;
            y -= other.y;
            z -= other.z;

            return *this;
        }

        inline Vec3& operator*=(T scalar)
        {
            x *= scalar;
            y *= scalar;
            z *= scalar;

            return *this;
        }

        inline Vec3& operator/=(T scalar)
        {
            x /= scalar;
            y /= scalar;
            z /= scalar;

            return *this;
        }

        inline T magnitude() const
        {
            return std::sqrt(x*x + y*y + z*z);
        }
        
		inline T magnitude(const Vec3& v) const
		{
			return std::sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
		}

        Vec3<T> normalize() const
        {
            T vectorLength = magnitude();
            assert(vectorLength != 0 && "Cannot normalize zero vector");
            return *this / vectorLength;
        }

        inline std::ostream& operator<<(std::ostream& out) {
            return out << x << ' ' << y << ' ' << z;
        }

        inline T dot(const Vec3& v) {
            return (x*v.x + y*v.y + z*v.z);
        }
    };
}