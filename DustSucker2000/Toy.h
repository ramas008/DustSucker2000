#ifndef TOY_H
#define TOY_H

#include "Vec3.h"
#include "Room.h"

// Create a Toy with the specified room and position in room. Sample usage:
//		Toy* yourToy = new Toy(yourRoom, position);
class Toy
{
public:
	Toy(Room* r, Vec3 pos);

	void ExecuteCommands(char* commands);
	void RotateDirection(char turnDirection);
	void MoveForward();
	Vec3 GetPosition();
protected:
private:
	Room* room;
	Vec3 position;
};

#endif // TOY_H