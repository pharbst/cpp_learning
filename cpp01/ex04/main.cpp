/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:12:26 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/11 08:37:01 by pharbst          ###   ########.fr       */
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
		
		void	modifyLine(std::string& line)
		{
			std::string	result;
			size_t		start = 0;
			size_t		end = line.find(_from);

			while (end != std::string::npos)
			{
				result += line.substr(start, end - start) + _to;
				start = end + _from.length();
				end = line.find(_from, start);
			}
			result += line.substr(start);
			line = result;
    	}

		void		Replace()
		{
			std::ifstream	fileIn(_filename.c_str());
			if (!fileIn.is_open())
			{
				std::cerr << "Error: could not open file" << _filename << std::endl;
				return ;
			}
			std::ofstream	fileOut(_fileOutName.c_str());
			if (!fileOut.is_open())
			{
				std::cerr << "Error: could not open file" << _fileOutName << std::endl;
				return ;
			}
			std::string		line;
			while (std::getline(fileIn, line))
			{
				modifyLine(line);
				fileOut << line << std::endl;
			}
		}

	private:
		std::string	_filename;
		std::string	_from;
		std::string	_to;
		std::string	_fileOutName;
};

int	main(int argc, char *argv[])
{
	std::string	filename, from, to;

	if (argc == 1)
	{
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
	else if (argc == 4)
	{
		filename = argv[1];
		from = argv[2];
		to = argv[3];
	}
	FileEditor	fileEditor(filename, from, to);
	fileEditor.Replace();
	return (0);
}
