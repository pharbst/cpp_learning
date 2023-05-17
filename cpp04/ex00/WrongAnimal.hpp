/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:20:54 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/17 17:20:49 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#ifndef IOSTREAM
# include <iostream>
#endif

class WrongAnimal{
	public:
		WrongAnimal(void);
		WrongAnimal(std::string type);
		WrongAnimal(WrongAnimal const &old);
		WrongAnimal& operator=(const WrongAnimal& old);
		~WrongAnimal(void);

		std::string	getType(void) const;
		void	makeSound(void) const;

	protected:
		std::string	_type;
};

#endif