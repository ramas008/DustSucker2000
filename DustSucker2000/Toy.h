#ifndef TOY_H
#define TOY_H

#include "Vec2.h"
#include "Room.h"

// Create a Toy with the specified room and position in room.
// The class also handles the movement and execution of commands.
class Toy
{
	public:
		// Constructor of Toy class.
		// Room* r - The current room for the toy.
		// Vec2 pos - The position and direction of the toy in the room.
		Toy(Room* r, Vec2 pos);

		// Execute command depending on what the command is.
		// char* commands - An array with all of the commands.
		void ExecuteCommands(std::string commands);

		// Checks if it is possible to move forward and executes it.
		void MoveForward();

		// Calculates the new direction of the toy depending on turn command.
		// char turnDirection - The command for what way to rotate.
		void RotateDirection(char turnDirection);

		// Returns the position and direction of the toy.
		Vec2 GetPosition();
	protected:
	private:
		// The room that the toy is in.
		Room* room;
		// The direction and position of the toy in the room.
		Vec2 position;
};

#endif // TOY_H