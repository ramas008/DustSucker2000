#ifndef VEC2_H
#define VEC2_H

#include <iostream>

// Vector class that will contain the direction, x and y value. Sample usage:
//		Vec3 vector(direction, x, y);
// It can also be used as an vector with only the x and y value. Sample usage:
//		Vec3 vector(x, y);
class Vec3
{
	public:
		// Constructors.
		Vec3() : direction(' '), xPosition(0), yPosition(0) {}
		Vec3(int x, int y) : direction(' '), xPosition(x), yPosition(y) {}
		Vec3(char d, int x, int y) : direction(d), xPosition(x), yPosition(y) {}

		// Operator overloading of "<<" to print the vector.
		friend std::ostream& operator<<(std::ostream& os, const Vec3& pos)
		{
			if (pos.Direction() == ' ')
				os << pos.X() << " " << pos.Y();
			else
				os << pos.Direction() << " " << pos.X() << " " << pos.Y();
			return os;
		}

		// Operator overloading of "=".
		Vec3 operator = (Vec3 pos)
		{
			direction = pos.Direction();
			xPosition = pos.X();
			yPosition = pos.Y();
			return *this;
		}

		// Change the x value of the vector.
		Vec3 SetX(int xPos)
		{
			xPosition = xPos;
			return *this;
		}

		// Change the y value of the vector.
		Vec3 SetY(int yPos)
		{
			yPosition = yPos;
			return *this;
		}

		// Change the direction of the vector.
		Vec3 SetDirection(char d)
		{
			direction = d;
			return *this;
		}

		// Get current direction of vector.
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
		char direction;
		int xPosition;
		int yPosition;
};

#endif // VEC2_H