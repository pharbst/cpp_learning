/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:38:19 by pharbst           #+#    #+#             */
/*   Updated: 2023/09/20 15:54:22 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(Serializer const & ref) {
	*this = ref;
}

Serializer & Serializer::operator = (Serializer const & ref) {
	if (this == &ref)
		return (*this);
	return (*this);
}

Serializer::~Serializer() {}

uintptr_t	Serializer::serialize(void *raw) {
	return reinterpret_cast<uintptr_t>(raw);
}

void*	Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<void*>(raw);
}
