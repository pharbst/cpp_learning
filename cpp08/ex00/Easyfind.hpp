/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:48:07 by pharbst           #+#    #+#             */
/*   Updated: 2023/09/23 18:53:19 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <list>


class TargetNotFoundException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Target not found";
    }
};

template <typename T, typename S>
unsigned int	easyfind(T container, S target) {
	typename T::iterator it = std::find(container.begin(), container.end(), target);

	if (it != container.end())
		return std::distance(container.begin(), it);
	throw TargetNotFoundException();
}

#endif
