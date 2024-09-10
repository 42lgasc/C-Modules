/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_contact.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:46:13 by lgasc             #+#    #+#             */
/*   Updated: 2024/09/10 19:15:03 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_contact.hpp"

#include <string>

const std::string
	s_contact::s_labels::first_name		= "Prénom",
	s_contact::s_labels::last_name		= "Nom de famille",
	s_contact::s_labels::nickname		= "Surnom",
	s_contact::s_labels::phone_number	= "Numéro de téléphone",
	s_contact::s_labels::darkest_secret	= "Plus sombre secret";

const std::string	s_contact::nullish = "(vide)";
