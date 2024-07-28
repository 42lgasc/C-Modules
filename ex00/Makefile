# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgasc <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/08 18:19:19 by lgasc             #+#    #+#              #
#    Updated: 2024/07/28 18:19:34 by lgasc            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= megaphone

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



.PHONY:	all re clean fclean	debug test

all:		$(NAME)

$(NAME):	$(OBJECTS)
	$(CXX) -g $(OBJECTS) $(LDLIBS) --output $(NAME)
	-norminette
	-grep -P 'TODO|FIXME|XXX|(?<!'\'')\?|\?(?!'\'')|!!|DEPREC\w*|[Dd]eprec\w*' \
		--recursive . --include=\*.[ch] --line-number --colour=auto

clean:		
	#$(MAKE) -C $(dir $(LIBFT)) fclean
	for O in $(OBJECTS);	\
		do if [ -f $$O ];		\
			then rm $$O;		\
			fi done

fclean:		clean
	if [ -f $(NAME) ];		\
		then rm $(NAME);	\
		fi

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
