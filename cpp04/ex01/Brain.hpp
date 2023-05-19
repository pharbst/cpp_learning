/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:21:09 by pharbst           #+#    #+#             */
/*   Updated: 2023/05/19 14:59:15 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <cstring>

class	Brain{
	public:
		Brain(void);
		Brain(const Brain& ref);
		Brain& operator = (const Brain& ref);
		~Brain(void);

		std::string getIdea(int i) const;
		void		setIdea(int i, std::string idea);

	private:
		std::string _ideas[100];
};

#endif