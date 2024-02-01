#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contact.hpp"
# include <iostream>
# include <iomanip>

class PhoneBook {
	private:
		Contact	_contacts[8];
		int		_index;
		int		_amount;
	public:
		PhoneBook();
		~PhoneBook();
		void	Welcome(void);
		void	addContact(void);
		void	printBook(void);
		void	searchContact(void);
};

#endif