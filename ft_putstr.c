/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yed-dyb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 10:26:50 by yed-dyb           #+#    #+#             */
/*   Updated: 2021/11/13 14:38:07 by yed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *count)
{
	int		index;

    if (!str) {
        ft_putstr("(null)", count);
        return ;
    }   
	index = 0;
	while (str[index] != '\0')
	{
		ft_putchar(str[index], count);
		index++;
	}
}
