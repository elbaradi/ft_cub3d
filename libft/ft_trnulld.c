/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_trnulld.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/27 20:35:56 by tel-bara      #+#    #+#                 */
/*   Updated: 2021/02/27 22:58:38 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

unsigned long long	ft_trnulld(int condition, unsigned long long a,
		unsigned long long b)
{
	if (condition)
		return (a);
	else
		return (b);
}
