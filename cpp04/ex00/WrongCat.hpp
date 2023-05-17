/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:33:44 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/17 17:22:16 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
	public:
		WrongCat(void);
		WrongCat(WrongCat const &old);
		WrongCat& operator=(const WrongCat& old);
		~WrongCat(void);

		 void	makeSound(void) const;
};

#endif