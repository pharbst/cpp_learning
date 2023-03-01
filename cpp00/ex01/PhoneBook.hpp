/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 05:15:41 by pharbst           #+#    #+#             */
/*   Updated: 2023/03/01 05:46:57 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		void			add_contact(void);
		void			search_contact(void);
		void			print(void);

	private:
		int			contact_count;
		Contact		contacts[8];
};

#endif