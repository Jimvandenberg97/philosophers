# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: JKCTech <admin@jkctech.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2021/02/02 12:25:57 by JKCTech       #+#    #+#                  #
#    Updated: 2021/02/12 12:56:53 by JKCTech       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CLR_GREEN	= \033[0;32m
CLR_CYAN	= \033[0;36m
CLR_RED		= \033[1;31m
CLR_YELLOW	= \033[0;33m
CLR_RESET	= \033[m

STR_OK		= [OK]
STR_FAIL	= [FAIL]

NAME = philo_three
FLAGS = -g -Wall -Werror -Wextra -Isrcs/common -Isrcs -pthread
SOURCES = srcs/main.c \
			srcs/common/ft_atoi.c \
			srcs/common/ft_bzero.c \
			srcs/common/ft_calloc.c \
			srcs/common/ft_isdigit.c \
			srcs/common/ft_putnbr.c \
			srcs/common/ft_strlen.c \
			srcs/common/parse.c \
			srcs/common/printer.c \
			srcs/actions.c \
			srcs/philo.c \
			srcs/semaphores.c \
			srcs/settings.c

HEADERS	= srcs/common/utils.h \
			srcs/philo.h

CC = clang

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@printf "%-64b" "$(CLR_RED)Compiling $(CLR_YELLOW)$(NAME): $(CLR_RESET)"
	@$(CC) $(OBJECTS) $(FLAGS) -o $(NAME)
	@printf "%b" "$(CLR_GREEN)$(STR_OK)\n$(CLR_RESET)"
	@printf "%b" "$(CLR_GREEN) -- Complete! --\n$(CLR_RESET)"

%.o: %.c $(HEADERS)
	@$(CC) -c $(FLAGS) $< -o $@; \
        RESULT=$$?; \
        if [ $$RESULT -ne 0 ]; then \
            printf "%-60b %b" "$(CLR_RED)Compiling$(CLR_CYAN) $<" \
				"$(CLR_RED)$(STR_FAIL)$(CLR_RESET)\n"; \
		else  \
            printf "%-60b %b" "$(CLR_RED)Compiling$(CLR_CYAN) $<" \
				"$(CLR_GREEN)$(STR_OK)$(CLR_RESET)\n"; \
        fi; \
        exit $$RESULT

clean:
	@printf "%-57b" "$(CLR_RED)Cleaning up objects: $(CLR_RESET)"
	@$(RM) $(OBJECTS)
	@printf "%b" "$(CLR_GREEN)$(STR_OK)\n$(CLR_RESET)"

fclean: clean
	@printf "%-57b" "$(CLR_RED)Cleaning up binary file: $(CLR_RESET)"
	@$(RM) $(NAME)
	@printf "%b" "$(CLR_GREEN)$(STR_OK)\n$(CLR_RESET)"

re: fclean all

.PHONY: all clean fclean re
