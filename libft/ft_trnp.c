/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_trnp.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/27 20:35:56 by tel-bara      #+#    #+#                 */
/*   Updated: 2021/02/27 22:58:56 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	*ft_trnp(int condition, void *a, void *b)
{
	if (condition)
		return (a);
	else
		return (b);
}
