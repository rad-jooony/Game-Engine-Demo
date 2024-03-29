#pragma once
#include "Vector2.h"
class Rectangle
{
private:

public:
	int left;
	int top;
	int right;
	int bottom;
	Rectangle() : left(0), right(0), top(0), bottom(0) {}
	Rectangle(int l, int r, int t, int b) : left(l), right(r), top(t), bottom(b) {}

	void Translate(Vector2 position)
	{
		left += position.x;
		right += position.x;
		top += position.y;
		bottom += position.y;
	}
	void ClipTo(const Rectangle& other)
	{

		//right = std::min(right, other.right);

		if (right > other.right)
			right = other.right;
		if (bottom > other.bottom)
			bottom = other.bottom;
		if (left < other.left)
			left = other.left;
		if (top < other.top)
			top = other.top;
	}

	int Width() const { return right - left; }
	int Height() const { return bottom - top; }
};

