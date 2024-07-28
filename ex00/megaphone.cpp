/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:05:03 by lgasc             #+#    #+#             */
/*   Updated: 2024/07/28 18:18:12 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

int	main(const int argc, const char *const argv [])
{
	if (argc - 1 == 0)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *"
			<< std::endl, EXIT_SUCCESS);
	for (size_t arg = 1; argv [arg] != static_cast < char *> (NULL); ++ arg)
		for (size_t i = 0; argv [arg][i] != '\0'; ++ i)
			(std::cout) << static_cast < char > (std::toupper(argv [arg][i]));
	(std::cout) << std::endl;
}
