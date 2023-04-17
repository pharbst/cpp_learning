/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharbst <pharbst@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 05:09:47 by pharbst           #+#    #+#             */
/*   Updated: 2023/03/17 06:18:54 by pharbst          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
	public:
		Contact();
		~Contact();
		void			set_first_name(std::string first_name);
		void			set_last_name(std::string last_name);
		void			set_nickname(std::string nickname);
		void			set_secret(std::string secret);
		void			print_first_name(void);
		void			print_last_name(void);
		void			print_nickname(void);
		void			print_secret(void);
	private:
		std::string		first_name;
		std::string		last_name;
		std::string		nickname;
		std::string		secret;
};

#endif