# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/17 14:43:00 by jjauzion          #+#    #+#              #
#    Updated: 2018/01/31 14:00:09 by jjauzion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re, LIB

SRC_NAME1 = ft_checker.c \
			ft_free_stack.c \
			ft_parser.c \
			get_next_line.c \
			ft_exec_cmd.c \
			operation.c \
			ft_display.c \
			ft_issorted.c

SRC_PATH1 = src/

OBJ_PATH1 = .obj/

LIB_PATH = libft/

LDLIBS = libftprintf.a

INC_PATH1 = libft/

INC_PATH2 = includes/

INC_NAME1 = ft_printf.h \
			libft.h

INC_NAME2 = header.h \
			get_next_line.h

NAME = checker

CC = gcc

ifdef FLAG
	ifeq ($(FLAG), no)
	CFLAGS =
	DBFLAGS =
endif
ifeq ($(FLAG), debug)
	CFLAGS = -Wall -Wextra -Werror
	DBFLAGS = -g3 -fsanitize=address
endif
else
	CFLAGS = -Wall -Wextra -Werror
	DBFLAGS =
endif

SRC = $(addprefix $(SRC_PATH1),$(SRC_NAME1))

OBJ = $(addprefix $(OBJ_PATH1),$(SRC_NAME1:.c=.o))

INC =  $(addprefix $(INC_PATH2),$(INC_NAME2)) \
	   $(addprefix $(INC_PATH1),$(INC_NAME1))

LDFLAGS = $(addprefix $(LIB_PATH),$(LDLIBS))

CPPFLAGS = $(addprefix -I,$(INC_PATH1)) \
		   $(addprefix -I,$(INC_PATH2))

all: LIB $(NAME)

$(NAME): $(OBJ)
	$(CC) $(DBFLAGS) $(LDFLAGS) $(OBJ) -o $(NAME)

LIB:
	make -C libft

$(OBJ_PATH1)%.o: $(SRC_PATH1)%.c $(INC) Makefile
	@mkdir $(OBJ_PATH1) 2> /dev/null || true
	$(CC) $(CFLAGS) $(DBFLAGS) -c $< $(CPPFLAGS) -o $@

clean:
	make -C libft clean
	rm -f $(OBJ)
	@rmdir $(OBJ_PATH1) 2> /dev/null || true

fclean: clean
	make -C libft fclean
	rm -fv $(NAME)

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC)
