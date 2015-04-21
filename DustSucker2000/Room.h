#ifndef ROOM_H
#define ROOM_H

#include "Vec2.h"

// Creates a room with a specific dimension.
// It can also check if toys are in the room dimension or not.
class Room
{
	public:
		// Constructor for Room class.
		// Vec2 dim - The vector containing the dimensions.
		Room(Vec2 dim);

		// Returns if vector is in bounds of the dimension or not.
		// Vec2 position - The position of the toy to check if in bounds.
		bool InBounds(Vec2 position);
		
		// Returns the dimensions of the room.
		Vec2 GetDimensions();
	protected:
	private:
		// The vector containing the dimensions of the room.
		Vec2 dimensions;
};

#endif // ROOM_H