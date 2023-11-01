/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:27:32 by pharbst           #+#    #+#             */
/*   Updated: 2023/11/01 23:14:15 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

const char* unknownClassException::what() const throw() {
	return ("Unknown class.");
}

Base::~Base() {}
