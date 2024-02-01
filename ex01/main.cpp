#include "phonebook.hpp"

int		main(void)
{
	PhoneBook	book;
	std::string	input = "";

	book.Welcome();
	while (true)
	{
		std::cout << "Enter command: " << std::flush;
		std::cin >> input;
		if (input == "ADD")	
			book.addContact();
		else if (input == "SEARCH")
			book.searchContact();
		else if (input == "EXIT")
			return (0);
		else
			std::cout << "Possible commands: ADD, SEARCH, EXIT." << std::endl;
	}
}
