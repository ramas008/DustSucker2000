#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include "Vec2.h"
#include <iostream>
#include <queue>
#include <set>

// Handles all inputs from the user and checks if the input
// is correct or not. It gathers the dimensions, position and commands
// as reference for it to change the value depending on input.
class InputHandler
{
	public:
		InputHandler(Vec2& dimensions, Vec2& position, std::string& commands);

		Vec2 HandleDimensions();
		Vec2 HandlePosition(Vec2 dimensions);
		std::string HandleCommands();

		bool IsValidInput(std::queue<char> que, std::set<char> values);
		bool IsInRoom(int x, int y, Vec2 dimensions);
		bool IsDimension(int x, int y);
	protected:
	private:
};

#endif // INPUTHANDLER_H