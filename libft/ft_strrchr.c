/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 18:37:52 by tel-bara      #+#    #+#                 */
/*   Updated: 2021/02/26 01:09:18 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*last;

	i = 0;
	last = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			last = (char *)s + i;
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (last);
}
