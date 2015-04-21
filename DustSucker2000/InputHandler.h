#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include "Vec3.h"
#include <iostream>
#include <queue>
#include <set>

// Handles all inputs from the user and checks if the input
// is correct or not. It gathers the dimensions, position and commands
// as reference for it to change the value depending on input. Sample usage:
//		InputHandler* handler = new InputHandler(dimensions, position, commands);
class InputHandler
{
public:
	InputHandler(Vec3& dimensions, Vec3& position, char*& commands);

	Vec3 HandleDimensions();
	Vec3 HandlePosition(Vec3 dimensions);
	char* HandleCommands();

	bool IsValidInput(std::queue<char> que, std::set<char> values);
	bool IsInRoom(int x, int y, Vec3 dimensions);
	bool IsDimension(int x, int y);
protected:
private:
};

#endif // INPUTHANDLER_H