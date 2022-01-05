/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_trns.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/27 20:35:56 by tel-bara      #+#    #+#                 */
/*   Updated: 2021/02/27 22:58:54 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_trns(int condition, char *a, char *b)
{
	if (condition)
		return (a);
	else
		return (b);
}
