#include "InputHandler.h"

#include <string>

// Constructor of InputHandler class.
//
// Vec2& dimensions - The vector for the dimensions of the room.
// Vec2& position - The vector for the position and direction of toy.
// char*& commands - The commands for the toy to carry out.
InputHandler::InputHandler(Vec2& dimensions, Vec2& position, std::string& commands)
{
	dimensions = HandleDimensions();
	position = HandlePosition(dimensions);
	commands = HandleCommands();
}

// Returns the dimensions from the user input if the input has
// acceptable values. If not it will start over until user has entered 
// acceptable values.
Vec2 InputHandler::HandleDimensions()
{
	int x, y;
	Vec2 dimensions;

	// Collect the input and check if the values are corect.
	do {
		if (!std::cin)
		{
			std::cerr << "Error: Incorrect values as input!" << std::endl << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		std::cout << "Write in the Dimensions of the room: ";
		std::cin >> x >> y;

	} while (!std::cin || !IsDimension(x, y));

	// Set the values of dimensions.
	dimensions.SetX(x);
	dimensions.SetY(y);

	return dimensions;
}

// Returns the position and direction from the user input if the
// input has acceptable values. If not it will start over until user has 
// entered acceptable values.
//
// Vec2 dimensions - The dimensions of the room.
Vec2 InputHandler::HandlePosition(Vec2 dimensions)
{
	int x, y;
	char direction;
	Vec2 position;

	// Set acceptable directions.
	std::queue<char> que;
	std::set<char> values;
	values.insert('N');
	values.insert('E');
	values.insert('S');
	values.insert('W');

	// Collect the input and check if the values are corect.
	do {
		// Clear que.
		que.swap(std::queue<char>());

		if (!std::cin)
		{
			std::cerr << "Error: Incorrect values as input!" << std::endl << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		// Set value for direction, x and y then push the direction to the que.
		std::cout << "Write in the Direction and Position of the toy: ";
		std::cin >> direction >> x >> y;
		que.push(direction);

	} while (!std::cin || !IsValidInput(que, values) || !IsInRoom(x, y, dimensions));

	// Set the values of position.
	position.SetX(x);
	position.SetY(y);
	position.SetDirection(direction);

	return position;
}

// Returns the series of commands from the user input if the
// input has acceptable values. If not it will start over until user has 
// entered acceptable values.
std::string InputHandler::HandleCommands()
{	
	std::string commands;

	// Set acceptable commands
	std::queue<char> que;
	std::set<char> values;
	values.insert('A');
	values.insert('R');
	values.insert('L');

	// Collect the input and check if the values are corect.
	do {
		// Clear que.
		que.swap(std::queue<char>());
		
		if (!std::cin)
		{
			std::cerr << "Error: Incorrect values as commands!" << std::endl << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		// Set value for commands and push it to the que.
		std::cout << "Write in the Commands of the Toy: ";
		std::cin >> commands;
		for (unsigned int i = 0; i < commands.length(); i++)
			que.push(commands[i]);

	} while (!std::cin || !IsValidInput(que, values));

	return commands;
}

// Check if input values match with the acceptable directions or commands.
//
// std::queue<char> que - The input values from the user.
// std::set<char> values - The values that are acceptable.
bool InputHandler::IsValidInput(std::queue<char> que, std::set<char> values)
{
	if (values.find(que.front()) == values.end())
	{
		std::cerr << "Error: Incorrect values as input!" << std::endl << std::endl;
		return false;
	}
	que.pop();
	return que.empty() ? true : IsValidInput(que, values);
}

// Check if toy is in the dimensions of the room.
//
// int x - The x value of the user input. 
// int y - The y value of the user input.
// Vec2 dimensions - The dimensions of the room.
bool InputHandler::IsInRoom(int x, int y, Vec2 dimensions)
{
	if ((x < 0 || y < 0 || x > dimensions.X() || y > dimensions.Y()))
	{
		std::cerr << "Error: Position is out of bounds!" << std::endl << std::endl;
		return false;
	}
	return true;
}

// Check if dimensions are not equal or lower then 0
//
// int x - The x value of the user input. 
// int y - The y value of the user input. 
bool InputHandler::IsDimension(int x, int y)
{
	if (x < 1 || y < 1)
	{
		std::cerr << "Error: x or y value is 0 or lower!" << std::endl << std::endl;
		return false;
	}
	return true;
}