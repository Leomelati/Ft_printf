# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmartins <lmartins@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/24 10:59:55 by lmartins          #+#    #+#              #
#    Updated: 2020/07/16 08:37:21 by lmartins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TEST_FILES = src/ft_printf.c src/main.c src/ft_printf.h src/hexadecimal.c \
src/numbers.c src/parameters.c src/strings.c src/utils.c Libft/ft_atoi.c \
Libft/ft_putnbr_fd.c Libft/ft_isdigit.c Libft/ft_putstr_fd.c \
Libft/ft_putnbr_uns_fd.c Libft/ft_putnbr_hex.c Libft/ft_putchar_fd.c \
Libft/ft_putnbr_hex_lower.c Libft/ft_strchr.c Libft/ft_strlen.c \
Libft/ft_intlen.c Libft/ft_itoa.c Libft/ft_hexlen.c Libft/ft_itoa_uns.c \
Libft/ft_itoa_base.c Libft/ft_isalpha.c Libft/ft_itoa_uns_base.c
TEST_FLAGS = -g

SRC_DIR = src/
SRC_FILES = ft_printf.c hexadecimal.c numbers.c parameters.c strings.c \
utils.c
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_DIR = src/obj/
OBJ_FILES = $(SRC:.c=.o)
OBJ = $(addprefix $(OBJ_DIR), $(notdir $(OBJ_FILES)))

#CC = gcc -Wall -Wextra -Werror
CC = gcc

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
