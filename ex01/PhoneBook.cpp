/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:11:15 by lgasc             #+#    #+#             */
/*   Updated: 2024/09/10 19:23:46 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#include "Command.hpp"

#include <iomanip>
#include <iostream>
#include <sstream>

// TODO: Bundle all of these into constants of class with operator
#define BOLD				"\x1B[1m"
#define REGULAR				"\x1B[22m"
#define ITALIC				"\x1B[3m"
#define ROMAN				"\x1B[23m"
#define UNDERLINE			"\x1B[4m"
#define LINELESS			"\x1B[24m"
#define INV					"\x1B[7m"
///Made up word
#define EXVERT				"\x1B[27m"
#define RIGHT				"\x1B[27m"
#define RT					"\x1B[27m"
#define MAROON				"\x1B[31m"
#define NAVY_BACK			"\x1B[44m"
#define PURPLE_BACKGROUND	"\x1B[45m"
#define P_U					"\x1B[45m"
#define RED_FOREGROUND		"\x1B[91m"
#define R_FG				"\x1B[91m"
#define LIME_FOREGROUND		"\x1B[92m"
#define L_F					"\x1B[92m"
#define YELLOW_FOREGROUND	"\x1B[93m"
#define Y_F					"\x1B[93m"
#define BLUE_FOREGROUND		"\x1B[94m"
#define B_F					"\x1B[94m"
#define MAGENTA_FOREGROUND	"\x1B[95m"
#define M_F					"\x1B[95m"
#define CYAN_FRONT			"\x1B[96m"
#define ERROR				"\x1b[1;31m"
#define OK					"\x1b[22;39m"
#define SEARCH				"\x1B[1;44;93m"
#define FOR_YOU				"\x1B[1;23;44;94m"
#define STORAGE				"\x1B[1;23;45;91m"
#define CUSTOMIZE			"\x1B[1;23;45;96m"
#define REG_ITAL			"\x1B[22;3m"
#define BAD					"\x1B[2;9;31m"
#define GOOD				"\x1B[22;29;91m"
#define SUBTITLE			"\x1B[3;4;92m"
#define SIMPLE				"\x1B[23;24m"
#define INVERT_RED			"\x1B[7;91m"
#define I_R					"\x1B[7;91m"
#define INVERT_LIME			"\x1B[7;92m"
#define I_L					"\x1B[7;92m"
#define INVERT_YELLOW		"\x1B[7;93m"
#define I_Y					"\x1B[7;93m"
#define INVERT_BLUE			"\x1B[7;94m"
#define I_B					"\x1B[7;94m"
#define INVERT_MAGENTA		"\x1B[7;95m"
#define I_M					"\x1B[7;95m"
#define RIGHT_RED			"\x1B[27;91m"
#define RT_R				"\x1B[27;91m"
#define RIGHT_LIME			"\x1B[27;92m"
#define RT_L				"\x1B[27;92m"
#define RIGHT_YELLOW		"\x1b[27;93m"
#define RT_Y				"\x1b[27;93m"
#define RIGHT_BLUE			"\x1B[27;94m"
#define RT_B				"\x1B[27;94m"
#define RIGHT_MAGENTA		"\x1B[27;95m"
#define RT_M				"\x1B[27;95m"
#define COVER_BLUE			"\x1B[27;104m"
#define COV_BLU				"\x1B[27;104m"
#define COLORLESS			"\x1B[39;49m"
#define RED_ON_MAGENTA		"\x1B[45;91m"
#define MGTA_ON_PRPL		"\x1B[45;95m"
#define M_P					"\x1B[45;95m"
#define RED_ON_LIME			"\x1B[91;102m"
#define R_L					"\x1B[91;102m"
#define RED_ON_YELLOW		"\x1b[91;103m"
#define R_Y					"\x1b[91;103m"
#define LIME_ON_YELLOW		"\x1B[92;103m"
#define L_Y					"\x1B[92;103m"
#define YELLOW_ON_BLUE		"\x1B[93;104m"
#define Y_B					"\x1B[93;104m"
#define BLUE_ON_MAGENTA		"\x1B[94;105m"
#define B_M					"\x1B[94;105m"
#define MAGENTA_ON_RED		"\x1b[95;101m"
#define M_R					"\x1B[95;101m"
#define MAGENTA_ON_BLUE		"\x1B[95;104m"
#define M_B					"\x1B[95;104m"
//blacK	mAroon	Green	Olive	Navy	Purple	Teal	Silver
//grEy	Red		Lime	Yellow	Blue	Magenta	Cyan	White
//K A G O N P T S / E R L Y B M C W
//A B C E G K L M N O P R S T Y W

//void	operator , (int _); // Yes you can!	disaster

int	main(void)
{
	return (PhoneBook ()());
}

PhoneBook::PhoneBook	(void) : in (std::cin), out (std::cout) {
	out << M_P" _______    " Y_F"_        " R_FG "_______                      "
		"   " R_FG"_             \n" M_F"🭮" INV"_______" RT"🭬  " Y_F "🬳" INV " "
		RT"🭐  " L_F"__  " R_FG"🭮" INV"_______" RT"🭬                       " R_FG
		"🭮" INV"_" RT"🭬            \n    " M_F"_ " B_F"🭅" INV"__" RT"🭬_" Y_F "🬗"
		INV" " RT"▓ " L_F"🭅" INV"__" RT"🭬_ " R_FG"_______ " M_F "____  " B_F "_"
		"___  " Y_F"_   _ " L_F"_____ " R_FG"_  " M_F "____ " B_F "_____ \n" M_F
		"   🬳" INV" " B_M"🭐" P_U" ___ " Y_B"🭎" P_U" " RT "▓" L_F "🬳" INV " ___ "
		R_L"🭎" P_U"  ___  " M_R"🬈" P_U"  _ " RT"🭎" B_F"🬳" INV"  _ " RT"🭎" Y_F"🬳"
		INV" " RT"🭐 🭅" INV" " L_Y"🭪" P_U"____ " R_L"🬈" P_U" " RT "🭐" M_F "🭃" INV
		" ___" B_M"🭬" P_U" ___ " RT"🭎\n" M_F"   🬗" INV" " B_M"▓" P_U " ____" Y_B
		"🭟" P_U" " RT"▓" L_F"🬗" INV" ____" R_L"🭟" P_U" " RT"▓   🭨" INV" " M_R"🬗"
		P_U" " RT"▓ 🭨" INV" " B_M"🬗" P_U" " RT"▓ 🭨" INV" " Y_B"🬗" P_U" " RT"▓_🭨"
		INV" " L_Y"🭙" P_U" ___ " R_L"🬗" P_U" " M_R"▓" P_U" " RT"▓   " B_F"🬗" INV
		" ____" RT"🭟\n" M_F"   🭖" INV"_" B_M"🭟" P_U"_____" RT"🭬" Y_F "🭔" INV "_"
		L_Y"🭬" P_U"_____" R_L"🭬" P_U"_" RT"🭟   🭖" INV"_" M_R"🭀" P_U "_" RT "🭟 🭖"
		INV"_" B_M"🭀" P_U"_" RT"🭟 🭖" INV"_" Y_B"🬾" P_U "____" RT "🭡" L_F "🭔" INV
		"_____" R_L"🭀" P_U"_" M_R"🭟" P_U"_" RT"🭟   " B_F"🭔" INV "_____" RT "🭬\n"
		"\n                  " SUBTITLE "L'incroyable annuaire logiciel!" SIMPLE
		"                  \n\n" SEARCH "Recherche Éclair:" REG_ITAL"        T"
		"rouvez vos contacts en quelques secondes!\n" STORAGE "Large Stockage:"
		REG_ITAL "                   Enregistrez jusqu'a 8" BAD "00" GOOD " co"
		"ntacts!\n" FOR_YOU "Fait Pour Vous:" REG_ITAL "                    Na"
		"viguez et organisez avec aise!\n" CUSTOMIZE "Fiches Personnalisables:"
		REG_ITAL "   Ajoutez surnoms, téléphones, et secrets!" ROMAN COLORLESS
		<< std::endl;
}

PhoneBook::~	PhoneBook(void) { out << "Arret..." << std::endl; }

// Why I use `not s.good()` instead of `s.operator bool ()`:
// 	https://en.cppreference.com/w/cpp/io/ios_base/iostate#See_also
bool	PhoneBook::operator () (void) {
	while (true) {
		out << "Commandes: `" UNDERLINE << Command::ft_text(Command::Add)
			<< LINELESS"`, `" UNDERLINE << Command::ft_text(Command::Search)
			<< LINELESS"`, `" UNDERLINE << Command::ft_text(Command::Exit)
			<< LINELESS"`.\n" << "Entrez une commande:\t";
		std::string	line;
		while (not getline(in, line) or not Command::ft_valid (line))
			if (not in.good() or not (out << "Réessayez:\t"))
				return (true);
		switch (Command::ft_kind(line)) {
			case Command::Add:
				ft_add();
				break ;
			case Command::Search:
				ft_search();
				break ;
			case Command::Exit:
				return (false);
}	}	}

void	PhoneBook::ft_add(void) {
	std::string	first_name, last_name, nickname, phone_number, darkest_secret;
	out << INV "Ajouter un contact" RT "\n";
	if (ft_ask_field(s_contact::s_labels::first_name, first_name) == true)
		return ;
	if (ft_ask_field(s_contact::s_labels::last_name, last_name) == true)
		return ;
	if (ft_ask_field(s_contact::s_labels::nickname, nickname) == true)
		return ;
	if (ft_ask_field(s_contact::s_labels::phone_number, phone_number) == true)
		return ;
	if (ft_ask_field(s_contact::s_labels::darkest_secret, darkest_secret)
		== true)
		return ;
	ft_push(
		s_contact(first_name, last_name, nickname, phone_number, darkest_secret)
	);
}

// Why I use `not s.good()` instead of `s.operator bool ()`:
// 	https://en.cppreference.com/w/cpp/io/ios_base/iostate#See_also
bool
PhoneBook::ft_ask_field(const std::string & label, std::string & field) const {
	const std::string	blank = "\t\n\v\f\r ";

	out << ITALIC << label << ":\t" ROMAN;
	if (not getline(in, field).good()
		|| field.find_first_not_of(blank) == std::string::npos)
		return (std::cerr << ERROR "Les champs doivent ne pas être vide."
		OK << std::endl, out << "Annulation..." << std::endl, true);
	return (false);
}

void	PhoneBook::ft_push(const s_contact & c)
{
	for (size_t i = capacity - 1; i > 0; -- i)
		contacts [i] = contacts [i - 1];
	contacts [0] = c;
}

void	PhoneBook::ft_search(void) const
{
	const int	column_width = 10;
	const char	ellipsis [2] = {'.'};

	out << INV "Chercher un contact" RT "\n";
	for (size_t i = 0; i < capacity; ++i)
	{
		out << std::setw(column_width) << i + 1
			<< '|' << std::setw(column_width);
		if (contacts [i].first_name.length() > column_width)
			out << contacts [i].first_name.substr().replace
				(column_width - 1, std::string::npos, ellipsis);
		else
			out << contacts [i].first_name;
		out << '|' << std::setw(column_width);
		if (contacts [i]. last_name .length() > column_width)
			out << contacts [i].last_name.substr().replace
				(column_width - 1, std::string::npos, ellipsis);
		else
			out << contacts [i].last_name;
		out << '|' << std::setw(column_width);
		if (contacts [i].nickname.length() > column_width)
			out << contacts [i].nickname.substr().replace
				(column_width - 1, std::string::npos, ellipsis);
		else
			out << contacts [i].nickname;
		out << '\n';
	}
	out << "Afficher les details du contact portant ce numéro:\t";
	std::string	query;
	size_t		index;
	if (not getline(in, query).good()
		or query.find_first_not_of("0123456789") != std::string::npos
		or not (std::istringstream (query) >> index)
		or index == 0 or index > capacity)
	{
		std::cerr << ERROR "Seul un numéro de rang est requis." OK << std::endl;
		out << "Annulation..." << std::endl;
		return ;
	}
	-- index, out << ITALIC << s_contact::s_labels::first_name << ":\t" ROMAN
		<< contacts [index].first_name << "\n"
		ITALIC << s_contact::s_labels::last_name << ":\t" ROMAN
		<< contacts [index].last_name << "\n"
		ITALIC << s_contact::s_labels::nickname << ":\t" ROMAN
		<< contacts [index].nickname << "\n"
		ITALIC << s_contact::s_labels::phone_number << ":\t" ROMAN
		<< contacts [index].phone_number << "\n"
		ITALIC << s_contact::s_labels::darkest_secret << ":\t" ROMAN
		<< contacts [index].darkest_secret << std::endl;
	return ;
}
