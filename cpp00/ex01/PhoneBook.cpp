/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 05:35:32 by pharbst           #+#    #+#             */
/*   Updated: 2023/04/17 06:14:04 by pharbst          ###   ########.fr       */
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
	std::string		secret;

	if (this->contact_index == 8)
		this->contact_index = 0;
	std::cout << "Enter first name: ";
	std::getline(std::cin, first_name);
	std::cout << "Enter last name: ";
	std::getline(std::cin, last_name);
	std::cout << "Enter nickname: ";
	std::getline(std::cin, nickname);
	std::cout << "Enter secret: ";
	std::getline(std::cin, secret);
	this->contacts[this->contact_index].set_first_name(first_name);
	this->contacts[this->contact_index].set_last_name(last_name);
	this->contacts[this->contact_index].set_nickname(nickname);
	this->contacts[this->contact_index].set_secret(secret);
	this->contact_index++;
	if (this->contact_count != 8)
		this->contact_count++;
}

void	PhoneBook::print_contact(Contact contact)
{
	std::cout << "first name: ";
	contact.print_first_name();
	std::cout << std::endl;
	std::cout << "last name: ";
	contact.print_last_name();
	std::cout << std::endl;
	std::cout << "nickname: ";
	contact.print_nickname();
	std::cout << std::endl;
	std::cout << "secret: ";
	contact.print_secret();
	std::cout << std::endl;
}

void	PhoneBook::search_contact(void)
{
	std::cout << "index     |first name|last name " << std::endl;
	std::cout << "---------------------------------" << std::endl;
	for (int i = 0; i < this->contact_count; i++)
	{
		std::cout << i << "         |";
		this->contacts[i].print_first_name();
		std::cout << "|";
		this->contacts[i].print_last_name();
		std::cout << std::endl;
	}
	std::string		index;
	int				index_int;
	std::cout << "Enter index: ";
	std::getline(std::cin, index);
	index_int = std::atoi(index.c_str());
	if (index_int <= this->contact_count)
		print_contact(this->contacts[index_int]);
	else
		std::cout << "Invalid index" << std::endl;
}

int main()
{
	PhoneBook	phonebook;
	std::string	command;

	phonebook.contact_count = 0;
	phonebook.contact_index = 0;
	while (1)
	{
		std::cout << "Enter command: ";
		std::getline(std::cin, command);
		if (command == "ADD" || command == "add")
			phonebook.add_contact();
		else if (command == "SEARCH" || command == "search")
			phonebook.search_contact();
		else if (command == "EXIT" || command == "exit")
			break ;
		else
			std::cout << "Invalid command" << std::endl;
	}
	return (0);
}
