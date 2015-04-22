#include "InputHandler.h"

#include <string>

InputHandler::InputHandler(Vec2& dimensions, Vec2& position, std::string& commands)
{
	dimensions = HandleDimensions();
	position = HandlePosition(dimensions);
	commands = HandleCommands();
}

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

		// Set value of x and y.
		std::cout << "Write in the Dimensions of the room: ";
		std::cin >> x >> y;

	} while (!std::cin || !IsDimension(x, y));

	// Set the values of dimensions.
	dimensions.SetX(x);
	dimensions.SetY(y);

	return dimensions;
}

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

bool InputHandler::IsValidInput(std::queue<char> que, std::set<char> values)
{
	// If there is a char that is not allowed it will return false.
	if (values.find(que.front()) == values.end())
	{
		std::cerr << "Error: Incorrect values as input!" << std::endl << std::endl;
		return false;
	}
	que.pop();
	return que.empty() ? true : IsValidInput(que, values);
}

bool InputHandler::IsInRoom(int x, int y, Vec2 dimensions)
{
	// If the position of the toy is outside the dimensions it will return false.
	if ((x < 0 || y < 0 || x > dimensions.X() || y > dimensions.Y()))
	{
		std::cerr << "Error: Position is out of bounds!" << std::endl << std::endl;
		return false;
	}
	return true;
}

bool InputHandler::IsDimension(int x, int y)
{
	if (x < 1 || y < 1)
	{
		std::cerr << "Error: x or y value is 0 or lower!" << std::endl << std::endl;
		return false;
	}
	return true;
}