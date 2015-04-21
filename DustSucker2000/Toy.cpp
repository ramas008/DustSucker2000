#include "Toy.h"

// Constructor of Toy class.
//
// Room* r - The current room for the toy.
// Vec3 pos - The position and direction of the toy in the room.
Toy::Toy(Room* r, Vec3 pos)
{
	room = r;
	position = pos;
}

// Execute command depending on what the command is.
//
// char* commands - An array with all of the commands.
void Toy::ExecuteCommands(char* commands)
{
	// Loop each command
	for (unsigned int i = 0; i < strlen(commands); i++)
	{
		// Check what command it is and execute function
		switch (commands[i])
		{
			case 'A':
				MoveForward();
				break;
			default:
				RotateDirection(commands[i]);
		}
	}
}

// Checks if it is possible to move forward and executes it.
void Toy::MoveForward()
{
	Vec3 newPosition;
	
	// Calculate the new position after moving forward.
	switch (position.Direction())
	{
		case 'W':
			newPosition = Vec3(position.Direction(), position.X() - 1, position.Y());
			break;
		case 'N':
			newPosition = Vec3(position.Direction(), position.X(), position.Y() + 1);
			break;
		case 'E':
			newPosition = Vec3(position.Direction(), position.X() + 1, position.Y());
			break;
		case 'S':
			newPosition = Vec3(position.Direction(), position.X(), position.Y() - 1);
			break;
	}

	// Check if the new position is in bounds of the room .
	if (room->InBounds(newPosition))
		position = newPosition;
}

// Calculates the new direction of the toy depending on turn command.
//
// char turnDirection - The command for what way to rotate.
void Toy::RotateDirection(char turnDirection)
{
	switch (position.Direction())
	{
		case 'W':
			if (turnDirection == 'R')
				position.SetDirection('N');
			else
				position.SetDirection('S');
			break;
		case 'N':
			if (turnDirection == 'R')
				position.SetDirection('E');
			else
				position.SetDirection('W');
			break;
		case 'E':
			if (turnDirection == 'R')
				position.SetDirection('S');
			else
				position.SetDirection('N');
			break;
		case 'S':
			if (turnDirection == 'R')
				position.SetDirection('W');
			else
				position.SetDirection('E');
			break;
	}
}

// Returns the position and direction of the toy.
Vec3 Toy::GetPosition()
{
	return position;
}

