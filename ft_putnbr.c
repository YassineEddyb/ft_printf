/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yed-dyb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 09:29:54 by yed-dyb           #+#    #+#             */
/*   Updated: 2021/11/13 14:37:18 by yed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nb, int *count)
{
	long int	nbr;

	nbr = nb;
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar('-', count);
	}
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10, count);
		ft_putnbr(nbr % 10, count);
	}
	else
		ft_putchar(nbr + 48, count);
}
