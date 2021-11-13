/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yed-dyb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:58:41 by yed-dyb           #+#    #+#             */
/*   Updated: 2021/11/13 12:05:17 by yed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_put(int nb, int upper)
{
	if (nb < 10)
		ft_putchar(nb + 48);
	else
	{
		if (upper)
			ft_putchar(nb - 10 + 65);
		else
			ft_putchar(nb - 10 + 97);
	}
}

void	ft_puthex(unsigned int nb, int upper)
{
	if (nb >= 16)
	{
		ft_puthex(nb / 16, upper);
		ft_puthex(nb % 16, upper);
	}
	else
		ft_put(nb, upper);
}
