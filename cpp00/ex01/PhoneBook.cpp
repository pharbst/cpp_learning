/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 05:35:32 by pharbst           #+#    #+#             */
/*   Updated: 2023/03/02 07:20:56 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::add_contact(void)
{
	std::string		first_name;
	std::string		last_name;
	std::string		nickname;

	std::cout << "Enter first name: ";
	std::getline(std::cin, first_name);
	std::cout << "Enter last name: ";
	std::getline(std::cin, last_name);
	std::cout << "Enter nickname: ";
	std::getline(std::cin, nickname);
	this->contacts[this->contact_count].set_first_name(first_name);
	this->contacts[this->contact_count].set_last_name(last_name);
	this->contacts[this->contact_count].set_nickname(nickname);
	this->contact_count++;
}

void	PhoneBook::search_contact(void)
{
	std::cout << "index	|first name	|last name	|nickname" << std::endl;
	this->contacts[0].print();
}

void	PhoneBook::print(void)
{
	std::cout << "index		|first name	|last name	|nickname" << std::endl;
	std::cout << "--------------------------------------------------------------" << std::endl;
	std::cout << "0		|" << this->contacts[0].first_name << "		|" << this->contacts[0].last_name << "		|" << this->contacts[0].nickname << std::endl;
	std::cout << "1		|" << this->contacts[1].first_name << "		|" << this->contacts[1].last_name << "		|" << this->contacts[1].nickname << std::endl;
	std::cout << "2		|" << this->contacts[2].first_name << "		|" << this->contacts[2].last_name << "		|" << this->contacts[2].nickname << std::endl;
	std::cout << "3		|" << this->contacts[3].first_name << "		|" << this->contacts[3].last_name << "		|" << this->contacts[3].nickname << std::endl;
	std::cout << "4		|" << this->contacts[4].first_name << "		|" << this->contacts[4].last_name << "		|" << this->contacts[4].nickname << std::endl;
	std::cout << "5		|" << this->contacts[5].first_name << "		|" << this->contacts[5].last_name << "		|" << this->contacts[5].nickname << std::endl;
	std::cout << "6		|" << this->contacts[6].first_name << "		|" << this->contacts[6].last_name << "		|" << this->contacts[6].nickname << std::endl;
	std::cout << "7		|" << this->contacts[7].first_name << "		|" << this->contacts[7].last_name << "		|" << this->contacts[7].nickname << std::endl;
}

int main()
{
	PhoneBook	phonebook;
	std::string	command;

	phonebook.contact_count = 0;
	while (1)
	{
		std::cout << "Enter command: ";
		std::getline(std::cin, command);
		if (command == "ADD" || command == "add")
			phonebook.add_contact();
		else if (command == "SEARCH" || command == "search")
			phonebook.search_contact();
		else if (command == "PRINT" || command == "print")
			phonebook.print();
		else if (command == "EXIT" || command == "exit")
			break ;
		else
			std::cout << "Invalid command" << std::endl;
	}
	return (0);
}