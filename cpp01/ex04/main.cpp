/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:12:26 by pharbst           #+#    #+#             */
/*   Updated: 2023/04/18 18:22:27 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

class	FileEditor
{
	public:
		FileEditor(const std::string& filename, const std::string& from, const std::string& to) : _filename(filename), _from(from), _to(to), _fileOutName(filename + ".replace"){}
		~FileEditor(void){}
		void		Replace();

	private:
		std::string	_filename;
		std::string	_from;
		std::string	_to;
		std::string	_fileOutName;
};

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::string	filename, from, to;
		std::cout << "enter fileName: ";
		std::cin >> filename;
		std::cout << std::endl << "enter string to replace: ";
		std::cin >> from;
		std::cout << std::endl << "enter replacement strng: ";
		std::cin >> to;
		std::cout << std::endl;
		
	}
	else if (argc != 4)
	{
		std::cerr << "Bad usage" << std::endl;
		std::cout << "Usage: ./sedForLoosers <filename> <string to replace> <string to replace with>" << std::endl << "or just: ./sedForLoosers" << std::endl;
		return (1);
	}

	std::string	filename = argv[1];
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];
	
}
