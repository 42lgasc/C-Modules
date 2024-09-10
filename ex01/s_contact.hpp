/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_contact.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 20:21:53 by lgasc             #+#    #+#             */
/*   Updated: 2024/09/10 19:15:20 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP_H
# define CONTACT_HPP_H

#include <string>

struct s_contact {
	struct s_labels {
		static const std::string
			first_name, last_name, nickname, phone_number, darkest_secret;
	};

	static const std::string
		nullish;

	std::string	first_name, last_name, nickname, phone_number, darkest_secret;

	s_contact (
		std::string	first_name		= nullish,
		std::string	last_name		= nullish,
		std::string	nickname		= nullish,
		std::string	phone_number	= nullish,
		std::string	darkest_secret	= nullish
	) :	first_name		(first_name),
		last_name		(last_name),
		nickname		(nickname),
		phone_number	(phone_number),
		darkest_secret	(darkest_secret)
	{};
};
#endif
