# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmartins <lmartins@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/24 10:59:55 by lmartins          #+#    #+#              #
#    Updated: 2020/07/07 06:30:40 by lmartins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memccpy.c \
ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
ft_substr.c ft_tolower.c ft_toupper.c ft_lstadd_back.c ft_lstadd_front.c \
ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c \
ft_lstnew.c ft_lstsize.c ft_putnbr_uns_fd.c ft_putnbr_hex.c \
ft_putnbr_hex_lower.c ft_intlen.c ft_hexlen.c

OBJ_DIR = obj/
OBJ_FILES = $(FILES:.c=.o)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

CC = gcc -Wall -Wextra -Werror
NAME = libft.a

INCLUDES = -I./

RM = rm -rf

all:	$(NAME)

$(NAME): obj
	@ar rcs $(NAME) $(OBJ)

obj: $(OBJ_FILES)
	@mkdir -p $(OBJ_DIR)
	@mv $(OBJ_FILES) $(OBJ_DIR)

clean:
	@$(RM) $(OBJ_DIR)

lclean: clean
	@$(RM) $(LIB_NAME)

fclean:	clean lclean
	@$(RM) $(NAME)
	
re:	fclean all

.c.o:
	@$(CC) -c $< $(INCLUDES) -o $(<:.c=.o)
