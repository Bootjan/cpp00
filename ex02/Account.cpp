/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bootjan <bootjan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:10:24 by bootjan           #+#    #+#             */
/*   Updated: 2024/01/07 16:32:04 by bootjan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <locale>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	display_time(void)
{
	std::time_t	tmp = std::time(NULL);
	std::string	daySpacing = "";
	std::string	monthSpacing = "";

	if (std::localtime(&tmp)->tm_mday < 10)
		daySpacing = "0";
	if (std::localtime(&tmp)->tm_mon < 10)
		monthSpacing = "0";
	std::cout	<< "[" << (std::localtime(&tmp)->tm_year + 1900)
				<< monthSpacing
				<< std::localtime(&tmp)->tm_mon + 1
				<< daySpacing
				<< std::localtime(&tmp)->tm_mday << "_"
				<< std::localtime(&tmp)->tm_hour
				<< std::localtime(&tmp)->tm_min
				<< std::localtime(&tmp)->tm_sec
				<< "] " << std::flush;
}

Account::Account(int initial_deposit)
{
	this->_accountIndex = this->_nbAccounts++;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals= 0;
	this->_totalAmount += this->_amount;
	this->_totalNbDeposits= this->_nbDeposits;
	this->_totalNbWithdrawals+= this->_nbWithdrawals;
	display_time();
	std::cout	<< "index:" << this->_accountIndex << ";"
				<< "amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account()
{
	display_time();
	std::cout	<< "index:" << this->_accountIndex << ";"
				<< "amount:" << this->_amount << ";closed" << std::endl;
}

void	Account::displayAccountsInfos(void)
{
	int	nbAccounts = Account::getNbAccounts();
	int	totalAmount = Account::getTotalAmount();
	int	nbDeposits = Account::getNbDeposits();
	int	nbWithdrawals = Account::getNbWithdrawals();
	display_time();
	std::cout	<< "accounts:" << nbAccounts << ";"
				<< "total:" << totalAmount << ";"
				<< "deposits:" << nbDeposits << ";"
				<< "withdrawals:" << nbWithdrawals << std::endl;
}

void	Account::displayStatus(void) const
{
	display_time();
	std::cout	<< "index:" << this->_accountIndex << ";"
				<< "amount:" << this->_amount << ";"
				<< "deposits:" << this->_nbDeposits << ";"
				<< "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	display_time();
	std::cout	<< "index:" << this->_accountIndex << ";"
				<< "p_amount:" << this->_amount << ";"
				<< "deposit:" << deposit << std::flush;
	this->_amount += deposit;
	this->_totalAmount += deposit;
	this->_nbDeposits++;
	this->_totalNbDeposits++;
	std::cout	<< ";amount:" << this->_amount << ";"
				<< "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	display_time();
	std::cout	<< "index:" << this->_accountIndex << ";"
				<< "p_amount:" << this->_amount << ";"
				<< "withdrawal:" << std::flush;
	if (this->_amount < withdrawal)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	this->_amount -= withdrawal;
	this->_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	this->_totalNbWithdrawals++;
	std::cout	<< withdrawal  << ";amount:" << this->_amount << ";"
				<< "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}
