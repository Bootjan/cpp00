/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bootjan <bootjan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:17:29 by bootjan           #+#    #+#             */
/*   Updated: 2024/01/07 13:52:47 by bootjan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook(void) {
	this->_index = this->_amount = 0;
}

PhoneBook::~PhoneBook(void) {
}

void	PhoneBook::addContact(void) {
	this->_contacts[this->_index++].Init();
	if (this->_amount < 8)
		this->_amount++;
}

void	PhoneBook::printBook(void) {
	for (int i = 0; i < this->_amount; i++)
		this->_contacts[i].Print();
}

static int	getIndex(int max)
{
	int	index;
	
	std::cin.ignore();
	while (true)
	{
		std::cout << "Input index: " << std::flush;
		std::cin >> index;
		if (index < 1)
			std::cout << "Index has to be at least 1" << std::endl;
		else if (index > max)
			std::cout << "Phonebook doesn't contain this many contacts" << std::endl;
		else
			return (index);
	}
}

void	PhoneBook::searchContact(void) {
	int	index;

	if (this->_amount == 0)
	{
		std::cout << "Phonebook is empty!" << std::endl;
		return ;
	}
	this->printBook();
	index = getIndex(this->_amount);
	this->_contacts[index - 1].Print();
}

void	PhoneBook::Welcome(void)
{
	std::cout << "Welcome to your phonebook!" << std::endl;
	std::cout << std::endl;
	std::cout << "_________________USAGE_________________" << std::endl;
	std::cout << "ADD:\t add a contact to phonebook" << std::endl;
	std::cout << "SEARCH:\t search a contact in phonebook" << std::endl;
	std::cout << "EXIT:\t exit the phonebook" << std::endl;
	std::cout << "_______________________________________" << std::endl;
	std::cout << std::endl;
}
