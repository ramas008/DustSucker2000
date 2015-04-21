#ifndef VEC2_H
#define VEC2_H

#include <iostream>

// Vector class that will contain the cardinal direction as a char and the x and y value 
// as a int. If the vector does not contain the cardinal direction it will create a
// vector with only the x and y value.
class Vec2
{
	public:
		// Constructors.
		Vec2() : direction(' '), xPosition(0), yPosition(0) {}
		Vec2(int x, int y) : direction(' '), xPosition(x), yPosition(y) {}
		Vec2(char d, int x, int y) : direction(d), xPosition(x), yPosition(y) {}

		// Operator overloading of "<<" to print the vector.
		friend std::ostream& operator<<(std::ostream& os, const Vec2& pos)
		{
			if (pos.Direction() == ' ')
				os << pos.X() << " " << pos.Y();
			else
				os << pos.Direction() << " " << pos.X() << " " << pos.Y();
			return os;
		}

		// Operator overloading of "=".
		Vec2 operator = (Vec2 pos)
		{
			direction = pos.Direction();
			xPosition = pos.X();
			yPosition = pos.Y();
			return *this;
		}

		// Change the x value of the vector.
		Vec2 SetX(int xPos)
		{
			xPosition = xPos;
			return *this;
		}

		// Change the y value of the vector.
		Vec2 SetY(int yPos)
		{
			yPosition = yPos;
			return *this;
		}

		// Change the cardinal direction of the vector.
		Vec2 SetDirection(char d)
		{
			direction = d;
			return *this;
		}

		// Get currentc cardinal direction of vector.
		char Direction() const
		{
			return direction;
		}

		// Get current x value of vector.
		int X() const
		{
			return xPosition;
		}

		// Get current y value of vector.
		int Y() const
		{
			return yPosition;
		}
	protected:
	private:
		// The cardinal direction value.
		char direction;
		// The value of x.
		int xPosition;
		// The value of y.
		int yPosition;
};

#endif // VEC2_H