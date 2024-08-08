# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgasc <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/08 18:19:19 by lgasc             #+#    #+#              #
#    Updated: 2024/07/30 15:29:31 by lgasc            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= PhoneBook

SOURCES			= $(NAME).cpp

#LDLIBS			+= -lreadline

#LIBFT			= libft/libft.a

#LIB_ARCHIVES	= $(LIBFT)

#OBJECTS		= $(SOURCES:.c=.o) $(LIB_ARCHIVES)
OBJECTS			= $(SOURCES:.cpp=.o) $(LIB_ARCHIVES)


CFLAGS			+= -Wall -Wmissing-noreturn -Werror		\
	-Wnull-dereference -Wstrict-overflow=5 -Wpedantic	\
	-Wattributes -Wmissing-format-attribute -Wnonnull	\
	-Wextra #-Wsuggest-attribute=returns_nonnull

ifeq ($(CC), gcc)
CFLAGS			+= -Wduplicated-cond -Wsuggest-attribute=const	\
	-Wsuggest-attribute=cold -Wsuggest-attribute=pure	\
	-Wduplicated-branches -Wsuggest-attribute=format	\
	-Wattribute-alias=2 -Wsuggest-attribute=noreturn	\
	-Wsuggest-attribute=malloc -Wstringop-overflow=4

else ifeq ($(CC), clang)
CFLAGS			+= -Wproperty-attribute-mismatch
endif

CXXFLAGS		+= -std=c++98 $(CFLAGS)

RESET			= \033[0m
#BOLD			= \033[1m
FAINT			= \033[2m
#REGULAR		= \033[22m
ITALIC			= \033[3m
ROMAN			= \033[23m
BLACK_FORE		= \033[30m
OLIVE_FORE		= \033[33m
DEFAULT_FORE	= \033[39m
DEFAULT_BOTH	= \033[39;49m
OLIVE_BACK		= \033[43m
GREY_FORE		= \033[90m
WHITE_FORE		= \033[97m
LOW_SCRIPT		= \033[22;2;23;4m
L_C				= $(LOW_SCRIPT)
# Loose inspiration from a gnu head
GNU_SCRIPT		= \033[22;1;3;24m
G_C				= $(GNU_SCRIPT)
GNU_STYLE		= \033[1;3;43;90m
G_Y				= $(GNU_STYLE)



.PHONY:	all re clean fclean	debug test

all:		$(NAME)

$(NAME):	$(OBJECTS)
	$(CXX) -g $(OBJECTS) $(LDLIBS) --output $(NAME)
	-norminette
	-grep -P 'TODO|FIXME|XXX|(?<!'\'')\?|\?(?!'\'')|!!|DEPREC\w*|[Dd]eprec\w*' \
		--recursive . --include=\*.[ch] --line-number --colour=auto

clean:		
	#$(MAKE) -C $(dir $(LIBFT)) fclean
	for O in $(OBJECTS); do if [ -f $$O ]; then if [ -z $$RM ];			\
				then echo -n '$(G_Y)Removing `$(L_C)'$$O;				\
			else echo -n '$(G_C)`, `$(L_C)'$$O; fi; RM=$$RM$$O; rm $$O;	\
		fi done; if [ -n ''$$RM ]; then echo '$(G_C)`...$(RESET)';		\
	else echo '$(G_Y)No object file to remove.$(RESET)'; fi				;

fclean:		clean
	if [ -f $(NAME) ];														\
		then echo '$(G_Y)Removing `$(L_C)$(NAME)$(G_C)`...$(RESET)';		\
		rm $(NAME); else echo '$(G_Y)No executable to remove.$(RESET)'; fi	;

re:			fclean all

$(LIBFT):	
	$(MAKE) -C $(dir $@) #bonus



# Use `CC=...` or `CXX=...` instead.
#test:		$(OBJECTS)
#	- clang	$(CFLAGS) $(OBJECTS) $(LDLIBS)
#	- gcc	$(CFLAGS) $(OBJECTS) $(LDLIBS)
#	$(CC)	$(CFLAGS) $(OBJECTS) $(LDLIBS)

#$(SOURCES:.c=.o):	$@
#	echo '@$@ <$< ?$? ^$^'
