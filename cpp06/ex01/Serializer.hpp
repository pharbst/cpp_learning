/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:38:27 by pharbst           #+#    #+#             */
/*   Updated: 2023/11/01 23:01:09 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <cstdint>

class Serializer {
	private:
		Serializer();
		Serializer(Serializer const & ref);
		Serializer & operator=(Serializer const & ref);
		~Serializer();
		
	public:
		static uintptr_t	serialize(void * raw);
		static void*		deserialize(uintptr_t raw);
};

#endif