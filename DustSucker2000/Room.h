#ifndef ROOM_H
#define ROOM_H

#include "Vec3.h"

// Creates a room with specifed dimensions. Sample usage:
//		Room* yourRoom = new Room(dimensions vector);
class Room
{
	public:
		Room(Vec3 dim);

		bool InBounds(Vec3 position);
		Vec3 GetDimensions();
	protected:
	private:
		Vec3 dimensions;
};

#endif // ROOM_H