/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/04 12:55:02 by tel-bara      #+#    #+#                 */
/*   Updated: 2021/02/27 22:43:06 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

typedef struct s_gnl_list
{
	char				buf[BUFFER_SIZE];
	ssize_t				index;
	int					fd;
	ssize_t				bytes_read;
	int					newline_reached;
	int					eob_reached;
	struct s_gnl_list	*next;
}				t_gnl_list;

int				get_next_line(int fd, char **line);
size_t			ft_strlen(const char *s);
char			*ft_gnl_strcat(char **dst, char *src);
void			*ft_memset(void *b, int c, size_t len);

#endif
