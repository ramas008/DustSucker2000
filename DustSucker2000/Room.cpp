#include "Room.h"

// Constructor for Room class.
//
// Vec3 dim - The vector that contains the dimensions 
Room::Room(Vec3 dim)
{
	dimensions = dim;
}

// Returns if vector is in bounds of the dimension or not.
//
// Vec3 position - The position of the toy to check if in bounds.
bool Room::InBounds(Vec3 position)
{
	return (position.X() < 0 || position.Y() < 0 || position.X() > dimensions.X() || position.Y() > dimensions.Y()) ? false : true;
}

// Returns the dimensions of the room.
Vec3 Room::GetDimensions()
{
	return dimensions;
}