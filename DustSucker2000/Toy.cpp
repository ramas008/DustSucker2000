#include "Toy.h"


Toy::Toy(Room* r, Vec2 pos)
{
	room = r;
	position = pos;
}

void Toy::ExecuteCommands(std::string commands)
{
	// Loop each command
	for (unsigned int i = 0; i < commands.length(); i++)
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

void Toy::MoveForward()
{
	Vec2 newPosition;
	
	// Calculate the new position after moving forward.
	switch (position.Direction())
	{
		case 'W':
			newPosition = Vec2(position.Direction(), position.X() - 1, position.Y());
			break;
		case 'N':
			newPosition = Vec2(position.Direction(), position.X(), position.Y() + 1);
			break;
		case 'E':
			newPosition = Vec2(position.Direction(), position.X() + 1, position.Y());
			break;
		case 'S':
			newPosition = Vec2(position.Direction(), position.X(), position.Y() - 1);
			break;
	}

	// Check if the new position is in bounds of the room .
	if (room->InBounds(newPosition))
		position = newPosition;
}

void Toy::RotateDirection(char turnDirection)
{
	// Check what the direction of the toy is and rotate/turn it accordingly.
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

Vec2 Toy::GetPosition()
{
	return position;
}

