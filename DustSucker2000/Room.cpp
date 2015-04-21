#include "Room.h"

Room::Room(Vec2 dim)
{
	dimensions = dim;
}

bool Room::InBounds(Vec2 position)
{
	return !(position.X() < 0 || position.Y() < 0 || position.X() > dimensions.X() || position.Y() > dimensions.Y());
}

Vec2 Room::GetDimensions()
{
	return dimensions;
}