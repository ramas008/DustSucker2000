#include "Vec2.h"
#include "Room.h"
#include "Toy.h"
#include "InputHandler.h"

#include <string>
#include <fstream>

int main() {
	// Initilaze input values
	std::string commands;
	Vec2 position, dimensions;

	// Create InputHandler, Room and Toy
	InputHandler handler(dimensions, position, commands);
	Room room(dimensions);
	Toy vacuum(&room, position);

	// Outputs
	std::string line;
	std::ifstream myfile("description.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
			std::cout << line << '\n';
		myfile.close();
	}
	std::cout << std::endl << "Room Dimensions: " << room.GetDimensions() << std::endl;
	std::cout << "Starting Position of vacuum: " << vacuum.GetPosition() << std::endl;
	std::cout << "Movement Commands: " << commands << std::endl;

	// The execution of the commands
	vacuum.ExecuteCommands(commands);

	// Output of the end result
	std::cout << "Result: " << vacuum.GetPosition() << std::endl;

	return 0;
}
