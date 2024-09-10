/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 16:35:54 by lgasc             #+#    #+#             */
/*   Updated: 2024/09/10 18:47:27 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_HPP_H
# define COMMAND_HPP_H

# include "PhoneBook.hpp"

# include <string>

namespace Command {
	enum e_kind
	{
		Add,
		Search,
		Exit
	};

	bool		ft_valid(const std::string & command);
	e_kind		ft_kind(const std::string & s);
	std::string	ft_text(e_kind command);
}
#endif
