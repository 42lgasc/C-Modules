/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 16:35:14 by lgasc             #+#    #+#             */
/*   Updated: 2024/09/10 18:25:39 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

#include <iostream>

bool	Command::ft_valid(const std::string & command) {
	return (command == ft_text(Add)
		or	command == ft_text(Search)
		or	command == ft_text(Exit));
}

///**Always check the string to be `valid` before
///								attempting to deduce the `kind` it represents.**
Command::e_kind	Command::ft_kind(const std::string & command) {
	if (		command == ft_text(Add))
		return (Add);
	else if (	command == ft_text(Search))
		return (Search);
	else if (	command == ft_text(Exit))
		return (Exit);
	__builtin_unreachable();
}

std::string	Command::ft_text(const e_kind command) {
	switch (command) {
		case Add:
			return ("ADD");
		case Search:
			return ("SEARCH");
		case Exit:
			return ("EXIT");
		default:
			__builtin_unreachable();
			return ("WHAT");
}	}
