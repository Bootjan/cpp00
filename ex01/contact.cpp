/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bootjan <bootjan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 12:48:09 by bootjan           #+#    #+#             */
/*   Updated: 2024/01/07 14:01:42 by bootjan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact()
{
}

std::string	Contact::getString(std::string prompt)
{
	std::string	ret = "";

	while (ret.size() == 0 || !std::cin.good())
	{
		std::cout << prompt << std::flush;
		std::cin >> ret;
	}
	return (ret);
}

void	Contact::Init(void)
{
	std::cin.ignore();
	this->_firstName = this->getString("Please enter first name: ");
	this->_lastName = this->getString("Please enter last name: ");
	this->_nickName = this->getString("Please enter nickname: ");
	this->_phoneNumber = this->getString("Please enter phone number: ");
	this->_darkestSecret = this->getString("Please enter darkest secret: ");
}

static void	printString(std::string str) {
	for (int i = 0; i + str.size() < 10; i++)
		std::cout << " " << std::flush;
	std::cout << str.substr(0, 9) << std::flush;
	if (str.size() >= 10)
		std::cout << "." << std::flush;
}

void	Contact::Print(void)
{
	printString(this->_firstName);
	std::cout << "|" << std::flush;
	printString(this->_lastName);
	std::cout << "|" << std::flush;
	printString(this->_nickName);
	std::cout << "|" << std::flush;
	printString(this->_phoneNumber);
	std::cout << std::endl;
}
