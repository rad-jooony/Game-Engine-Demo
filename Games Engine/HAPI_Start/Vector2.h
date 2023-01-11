// 2D Vector class

#pragma once

// Required for sqrt:
#include <cmath>

class Vector2
{

private:

public:
	float x{ 0 };
	float y{ 0 };
	// Constructors
	Vector2() = default;
	Vector2(float newX, float newY) : x(newX), y(newY) {}

	// + operator. Returns the result of adding the rhs to this
	Vector2 operator + (const Vector2& other) const
	{
		return Vector2(x + other.x, y + other.y);
	}

	Vector2& operator+=(const Vector2& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}

	Vector2 operator-(const Vector2& other) const
	{
		return Vector2(-x, -y);
	}

	Vector2 operator-() const
	{
		return Vector2(-x, -y);
	}

	Vector2& operator-=(const Vector2& other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}

	Vector2 operator*(float val) const
	{
		return Vector2(val * x, val * y);
	}


	Vector2& operator*=(float val)
	{
		x *= val;
		y *= val;
		return *this;
	}

	float Length() const
	{
		return sqrt(x * x + y * y);
	}

	// return value of 1, a unit vector
	void NormaliseInPlace()
	{
		float len = Length();

		if (len == 0)
			return;

		x /= len;
		y /= len;
	}

	//The dot product can be used to calculate the angle between 2 vectors.
	float Dot(const Vector2& other) const
	{
		return x * other.x + y * other.y;
	}

	/*
	The cross product gives a value which is 2 times the area of the triangle.
	Can also be used to find which rotation direction a vector is, relative to another (+-)
	*/
	float Cross(const Vector2& other) const
	{
		return x * other.y - y * other.x;
	}
};