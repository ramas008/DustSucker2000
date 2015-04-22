#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include "Vec2.h"
#include <queue>
#include <set>

// Handles all inputs from the user and checks if the input
// is correct or not. It gathers the dimensions, positions and
// commands from the user and stores them in vectors and strings.
class InputHandler
{
	public:
		// Constructor of InputHandler class.
		// Vec2& dimensions - The vector for the dimensions of the room.
		// Vec2& position - The vector for the position and direction of toy.
		// std::string& commands - The commands for the toy to carry out.
		InputHandler(Vec2& dimensions, Vec2& position, std::string& commands);

		// Returns the dimensions from the user input if the input has
		// acceptable values. If not it will start over until user has entered 
		// acceptable values.
		Vec2 HandleDimensions();

		// Returns the position and direction from the user input if the
		// input has acceptable values. If not it will start over until user has 
		// entered acceptable values.
		// Vec2 dimensions - The dimensions of the room.
		Vec2 HandlePosition(Vec2 dimensions);

		// Returns the series of commands from the user input if the
		// input has acceptable values. If not it will start over until user has 
		// entered acceptable values.
		std::string HandleCommands();

		// Check if input values match with the acceptable directions or commands.
		// std::queue<char> que - The input values from the user.
		// std::set<char> values - The values that are acceptable.
		bool IsValidInput(std::queue<char> que, std::set<char> values);

		// Check if toy is in the dimensions of the room.
		// int x - The x value of the user input. 
		// int y - The y value of the user input.
		// Vec2 dimensions - The dimensions of the room.
		bool IsInRoom(int x, int y, Vec2 dimensions);

		// Check if dimensions are not equal or lower then 0.
		// int x - The x value of the user input. 
		// int y - The y value of the user input. 
		bool IsDimension(int x, int y);
	protected:
	private:
};

#endif // INPUTHANDLER_H