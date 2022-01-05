# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tel-bara <tel-bara@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/01/17 17:39:30 by tel-bara      #+#    #+#                  #
#    Updated: 2022/01/05 09:26:44 by tel-bara      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	=   cub3D
SRCDIR	=	srcs
SRCS	=	$(SRCDIR)/colors.c \
			$(SRCDIR)/dda.c \
			$(SRCDIR)/draw_frame.c \
			$(SRCDIR)/draw_lines.c \
			$(SRCDIR)/error.c \
			$(SRCDIR)/frame.c \
			$(SRCDIR)/hooks.c \
			$(SRCDIR)/import_map.c \
			$(SRCDIR)/load_textures.c \
			$(SRCDIR)/main.c \
			$(SRCDIR)/make_map.c \
			$(SRCDIR)/movement.c \
			$(SRCDIR)/parse_settings_rns.c \
			$(SRCDIR)/parse_settings_wefc.c \
			$(SRCDIR)/screenshot.c \
			$(SRCDIR)/set_map.c \
			$(SRCDIR)/sprites.c
B_SRCS	=	$(SRCDIR)/bonus_bonus.c
OBJS	= $(SRCS:.c=.o)
B_OBJS	= $(B_SRCS:.c=.o)
CC		= cc
INCS	= -Iincludes -Ilibft -Iminilibx_mms_20200219
FLAGS	= -O3 -g3 -Wall -Wextra -Werror
FRWRKS	= -framework OpenGL -framework AppKit
LIBS_P	= libmlx.dylib libft/libft.a

ifdef BONUS
FLAGS	+= -D BONUS
RELEVANT_OBJS = $(OBJS) $(B_OBJS)
else
RELEVANT_OBJS = $(OBJS)
endif

%.o: %.c
	${CC} ${FLAGS} -c ${INCS} -o $@ $<

$(NAME): ${RELEVANT_OBJS}
	make libs -C .
	gcc $(RELEVANT_OBJS) ${FLAGS} ${FRWRKS} -o $(NAME) ${LIBS_P}

all: $(NAME)

libs:
	make -C minilibx_mms_20200219
	make -C libft
	cp minilibx_mms_20200219/libmlx.dylib ./libmlx.dylib

clean:
	rm -rf $(OBJS) $(B_OBJS)
	make clean -C minilibx_mms_20200219
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	rm -rf **.dylib
	make fclean -C libft

re: fclean all

bonus:
	${MAKE} BONUS=1 all

.PHONY: all clean fclean re .c.o libs
