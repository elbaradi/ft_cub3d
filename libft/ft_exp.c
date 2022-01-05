/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_exp.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 17:27:38 by tel-bara      #+#    #+#                 */
/*   Updated: 2021/02/26 01:13:49 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

long long	ft_exp(long long base, long long exp)
{
	if (exp == 0)
		return (1);
	return (base * ft_exp(base, exp - 1));
}
