/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:12:33 by lgasc             #+#    #+#             */
/*   Updated: 2024/09/10 18:49:17 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP_H
# define PHONEBOOK_HPP_H

# include "s_contact.hpp"

# include <string>

class PhoneBook
{
	static const size_t	capacity = 8;

	s_contact			contacts [capacity];
	std::istream		& in;
	std::ostream		& out;

	void	ft_add(void);
	bool	ft_ask_field(const std::string & label, std::string & field) const
			__attribute__ ((warn_unused_result));
	void	ft_push(const s_contact & contact);
	void	ft_search(void) const;

	public:
		PhoneBook	(void);
		~ PhoneBook	(void);
		bool		operator () (void) __attribute__ ((warn_unused_result));
};
#endif
