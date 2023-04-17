/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myAccount.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 08:09:05 by pharbst           #+#    #+#             */
/*   Updated: 2023/04/17 08:47:11 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

// Initialize static member variables
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// Helper function to get the current timestamp
void	Account::_displayTimestamp(void)
{
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);
	std::cout << "[" << std::setfill('0') << std::setw(4) << now->tm_year + 1900;
	std::cout << std::setfill('0') << std::setw(2) << now->tm_mon + 1;
	std::cout << std::setfill('0') << std::setw(2) << now->tm_mday << "_";
	std::cout << std::setfill('0') << std::setw(2) << now->tm_hour;
	std::cout << std::setfill('0') << std::setw(2) << now->tm_min;
	std::cout << std::setfill('0') << std::setw(2) << now->tm_sec << "] ";
}

// static member function
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

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount
		<< ";deposits:" << _totalNbDeposits << ";withdrawals:"
		<< _totalNbWithdrawals << std::endl;
}

// Constructor
Account::Account(int initial_deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _nbAccounts << ";amount:" << initial_deposit
		<< ";created" << std::endl;
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += initial_deposit;
}

// Destructor
Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
		<< ";closed" << std::endl;
	_nbAccounts--;
	_totalAmount -= _amount;
}

// Member functions
void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
		<< ";deposit:" << deposit << ";amount:" << _amount + deposit
		<< ";nb_deposits:" << _nbDeposits + 1 << std::endl;
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
		<< ";withdrawal:";
	if (withdrawal > _amount)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	else
	{
		std::cout << withdrawal << ";amount:" << _amount - withdrawal
			<< ";nb_withdrawals:" << _nbWithdrawals + 1 << std::endl;
		_amount -= withdrawal;
		_nbWithdrawals++;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		return (true);
	}
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
		<< ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals
		<< std::endl;
}
