/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 05:12:36 by pharbst           #+#    #+#             */
/*   Updated: 2023/04/17 06:02:22 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void	Contact::set_first_name(std::string first_name)
{
	this->first_name = first_name;
}

void	Contact::set_last_name(std::string last_name)
{
	this->last_name = last_name;
}

void	Contact::set_nickname(std::string nickname)
{
	this->nickname = nickname;
}

void	Contact::set_secret(std::string secret)
{
	this->secret = secret;
}

void	Contact::print_first_name(void)
{
	if (std::strlen(this->first_name.c_str()) > 10)
	{
		for (int i = 0; i < 9; i++)
			std::cout << this->first_name[i];
		std::cout << ".";
	}
	else
	{
		std::cout << this->first_name;
		for (int i = 0; i < 10 - (int)std::strlen(this->first_name.c_str()); i++)
			std::cout << " ";
	}
}

void	Contact::print_last_name(void)
{
	if (std::strlen(this->last_name.c_str()) > 10)
	{
		for (int i = 0; i < 9; i++)
			std::cout << this->last_name[i];
		std::cout << ".";
	}
	else
	{
		std::cout << this->last_name;
		for (int i = 0; i < 10 - (int)std::strlen(this->last_name.c_str()); i++)
			std::cout << " ";
	}
}

void	Contact::print_nickname(void)
{
	if (std::strlen(this->nickname.c_str()) > 10)
	{
		for (int i = 0; i < 9; i++)
			std::cout << this->nickname[i];
		std::cout << ".";
	}
	else
	{
		std::cout << this->nickname;
		for (int i = 0; i < 10 - (int)std::strlen(this->nickname.c_str()); i++)
			std::cout << " ";
	}
}

void	Contact::print_secret(void)
{
	if (std::strlen(this->secret.c_str()) > 10)
	{
		for (int i = 0; i < 9; i++)
			std::cout << this->secret[i];
		std::cout << ".";
	}
	else
	{
		std::cout << this->secret;
		for (int i = 0; i < 10 - (int)std::strlen(this->secret.c_str()); i++)
			std::cout << " ";
	}
}
