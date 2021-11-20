/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yed-dyb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:58:41 by yed-dyb           #+#    #+#             */
/*   Updated: 2021/11/13 14:37:06 by yed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void ft_put(int nb, int upper, int *count)
{
	if (nb < 10)
		ft_putchar(nb + 48, count);
	else
	{
		if (upper)
			ft_putchar(nb - 10 + 65, count);
		else
			ft_putchar(nb - 10 + 97, count);
	}
}

void	ft_puthex(unsigned long int nb, int upper, int *count)
{
	if (nb >= 16)
	{
		ft_puthex(nb / 16, upper, count);
		ft_puthex(nb % 16, upper, count);
	}
	else
		ft_put(nb, upper, count);
}
