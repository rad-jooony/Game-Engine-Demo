#pragma once
class Rectangle
{
private:
	int left;
	int top;
	int right;
	int bottom;
public:
	Rectangle() : left(0), right(0), top(0), bottom(0) {}
	Rectangle(int l, int r, int t, int b) : left(l), right(r), top(t), bottom(b) {}
};

