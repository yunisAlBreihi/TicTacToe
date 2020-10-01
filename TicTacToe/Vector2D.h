#pragma once

struct Vector2D 
{
	int x;
	int y;

	bool operator==(const Vector2D other)
	{
		if (other.x == x && other.y == y)
		{
			return true;
		}
		return false;
	}
};