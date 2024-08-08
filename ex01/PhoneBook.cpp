/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgasc <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:11:15 by lgasc             #+#    #+#             */
/*   Updated: 2024/08/08 17:18:47 by lgasc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <string>

#include "PhoneBook.hpp"

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
static void		ft_intro(void);

enum e_command
{
	Add,
	search,
	EXIT
};

class Command
{
	int x;
int				y;

enum e_command	ft_type(void);
}
;
using std		:: istream;

///https://stackoverflow.com/a/4421719/22306298
std::istream&	operator>> (std::istream & is, enum e_command & command)
{
	using std::string;
	string	s;

	is >> s;
	if (s == "ADD")
		///TODO
		command = Add, std::cerr << "adding";
	else if (s == "SEARCH")
		///TODO
		command = search;
	else if (s == "EXIT")
		///TODO
		command = EXIT;
	else
	//!TODO: Read `object` from stream
		is.setstate(std::ios::failbit), std::cerr << "failing";
	return (is);
}

//void	operator , (int _);

int	main(void)
{
	e_command	command;

	ft_intro();
	(std::cout) << "Commandes: `" UNDERLINE"ADD" LINELESS"`, `"
	UNDERLINE"SEARCH" LINELESS"`, `" UNDERLINE"EXIT" LINELESS"`.\n";
	(std::cout) << "Entrez une commande: ";
	while (not (std::cin >> command))
		(std::cout) << "Try again: ", std::cin.clear();
	return (EXIT_SUCCESS);
}

static void	ft_intro(void)
{
	(std::cout) << M_P" _______    " Y_F"_        " R_FG"_______               "
	"          " R_FG"_             \n" M_F"🭮" INV"_______" RT"🭬  " Y_F"🬳" INV
	" " RT"🭐  " L_F"__  " R_FG"🭮" INV"_______" RT"🭬                       " R_FG
	"🭮" INV"_" RT"🭬            \n    " M_F"_ " B_F"🭅" INV"__" RT"🭬_" Y_F"🬗" INV
	" " RT"▓ " L_F"🭅" INV"__" RT"🭬_ " R_FG"_______ " M_F"____  " B_F"____  " Y_F
	"_   _ " L_F"_____ " R_FG"_  " M_F"____ " B_F"_____ \n" M_F"   🬳" INV" " B_M
	"🭐" P_U" ___ " Y_B"🭎" P_U" " RT"▓" L_F"🬳" INV" ___ " R_L"🭎" P_U"  ___  " M_R
	"🬈" P_U"  _ " RT"🭎" B_F"🬳" INV"  _ " RT"🭎" Y_F"🬳" INV" " RT"🭐 🭅" INV" " L_Y
	"🭪" P_U"____ " R_L"🬈" P_U" " RT"🭐" M_F"🭃" INV" ___" B_M"🭬" P_U" ___ " RT"🭎"
	"\n" M_F"   🬗" INV" " B_M"▓" P_U" ____" Y_B"🭟" P_U" " RT"▓" L_F"🬗" INV" ___"
	"_" R_L"🭟" P_U" " RT"▓   🭨" INV" " M_R"🬗" P_U" " RT"▓ 🭨" INV" " B_M"🬗" P_U
	" " RT"▓ 🭨" INV" " Y_B"🬗" P_U" " RT"▓_🭨" INV" " L_Y"🭙" P_U" ___ " R_L"🬗" P_U
	" " M_R"▓" P_U" " RT"▓   " B_F"🬗" INV" ____" RT"🭟\n" M_F"   🭖" INV"_" B_M"🭟"
	P_U "_____" RT"🭬" Y_F"🭔" INV"_" L_Y"🭬" P_U"_____" R_L"🭬" P_U"_" RT"🭟   🭖"
	INV"_" M_R"🭀" P_U"_" RT"🭟 🭖" INV"_" B_M"🭀" P_U"_" RT"🭟 🭖" INV"_" Y_B"🬾" P_U
	"____" RT"🭡" L_F"🭔" INV"_____" R_L"🭀" P_U"_" M_R"🭟" P_U"_" RT"🭟   " B_F"🭔"
	INV"_____" RT"🭬\n\n                  " SUBTITLE"L'incroyable annuaire logic"
	"iel!" SIMPLE"                  \n\n" SEARCH"Recherche Éclair:" REG_ITAL"  "
	"      Trouvez vos contacts en quelques secondes!\n" STORAGE"Large Stockage"
	":" REG_ITAL"                   Enregistrez jusqu'a 8" BAD"00" GOOD" contac"
	"ts!\n" FOR_YOU"Fait Pour Vous:" REG_ITAL"                    Naviguez et o"
	"rganisez avec aise!\n" CUSTOMIZE"Fiches Personnalisables:" REG_ITAL"   Ajo"
	"utez surnoms, téléphones, et secrets!\n" ROMAN COLORLESS;
}
