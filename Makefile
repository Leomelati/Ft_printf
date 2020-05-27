# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmartins <lmartins@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/24 10:59:55 by lmartins          #+#    #+#              #
#    Updated: 2020/05/27 06:22:58 by lmartins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TEST_FILES = src/ft_printf.c src/main.c src/ft_printf.h Libft/ft_atoi.c \
Libft/ft_putnbr_fd.c Libft/ft_isdigit.c Libft/ft_putstr_fd.c \
Libft/ft_putnbr_uns_fd.c Libft/ft_putnbr_hex.c Libft/ft_putchar_fd.c
TEST_FLAGS = -g

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
	@mv $(LIBS) $(NAME)
	@ar rcs $(NAME) $(OBJ)

obj: $(OBJ_FILES)
	@mkdir -p $(OBJ_DIR)
	@mv $(OBJ_FILES) $(OBJ_DIR)

test:
	@$(CC) $(TEST_FLAGS) $(TEST_FILES)
	
clean:
	@make -sC Libft/ clean
	@$(RM) $(OBJ_DIR)

lclean: clean
	@make -sC Libft/ lclean
	@$(RM) $(NAME)

fclean:	clean lclean
	@make -sC Libft/ fclean
	@$(RM) $(NAME)
	
re:	fclean all

.c.o:
	@$(CC) -c $< $(INCLUDES) -o $(<:.c=.o)
