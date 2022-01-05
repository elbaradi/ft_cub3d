/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_trnuc.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/27 20:35:56 by tel-bara      #+#    #+#                 */
/*   Updated: 2021/02/27 22:58:50 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

unsigned char	ft_trnuc(int condition, unsigned char a, unsigned char b)
{
	if (condition)
		return (a);
	else
		return (b);
}
