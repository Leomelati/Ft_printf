# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmartins <lmartins@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/24 10:59:55 by lmartins          #+#    #+#              #
#    Updated: 2020/05/20 07:27:53 by lmartins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = src/
SRC_FILES = ft_printf.c
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_DIR = src/obj/
OBJ_FILES = $(SRC:.c=.o)
OBJ = $(addprefix $(OBJ_DIR), $(notdir $(OBJ_FILES)))

CC = gcc -Wall -Wextra -Werror

NAME = libftprintf.a

LIBS = Libft/libft.a

INCLUDES = -I./ -I../Libft/libft.h

RM = rm -rf

all:	$(NAME)

$(NAME): obj
	@make -sC Libft/
	@mv $(LIBS) $(SRC_DIR)$(NAME)
	@ar rcs $(SRC_DIR)$(NAME) $(OBJ)

obj: $(OBJ_FILES)
	@mkdir -p $(OBJ_DIR)
	@mv $(OBJ_FILES) $(OBJ_DIR)
	
clean:
	@make -sC Libft/ clean
	@$(RM) $(OBJ_DIR)

lclean: clean
	@make -sC Libft/ lclean
	@$(RM) $(LIB_NAME)

fclean:	clean lclean
	@make -sC Libft/ fclean
	@$(RM) $(SRC_DIR)$(NAME)
	
re:	fclean all

.c.o:
	@$(CC) -c $< $(INCLUDES) -o $(<:.c=.o)
