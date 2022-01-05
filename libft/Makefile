# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tel-bara <tel-bara@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/10/28 00:17:49 by tel-bara      #+#    #+#                  #
#    Updated: 2021/02/27 21:51:13 by tel-bara      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
SRCS	=	ft_abs.c \
			ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_exp.c \
			ft_getnextline/get_next_line.c \
			ft_getnextline/get_next_line_utils.c \
			ft_hexlen.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstlast.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstsize.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_numlen.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putlchar_fd.c \
			ft_putlnbr_base_fd.c \
			ft_putlnstr_fd.c \
			ft_putlstr_fd.c \
			ft_putlunbr_base_fd.c \
			ft_putnbr_fd.c \
			ft_putstr.c \
			ft_putstr_fd.c \
			ft_putunbr_fd.c \
			ft_split.c \
			ft_strchr.c \
			ft_strclen.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_trnc.c \
			ft_trnf.c \
			ft_trni.c \
			ft_trnld.c \
			ft_trnlld.c \
			ft_trnp.c \
			ft_trns.c \
			ft_trnsize_t.c \
			ft_trnuc.c \
			ft_trnud.c \
			ft_trnuld.c \
			ft_trnulld.c \
			ft_unumlen.c
OBJS	=	$(SRCS:.c=.o)
LIBC	=	ar -rcs
RM		=	rm -f
CC		=	gcc
FLAGS	=	-Wall -Werror -Wextra
INCS	=	.

all:		$(NAME)

$(NAME):	$(OBJS)
			${LIBC} $(NAME) $(OBJS)

%.o:		%.c
			${CC} ${FLAGS} -c -I${INCS} $< -o $@

clean:
			${RM} $(OBJS)

fclean:		clean
			${RM} $(NAME)

re:			fclean all

.PHONY:		all .c.o clean fclean re
