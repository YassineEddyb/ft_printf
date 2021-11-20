/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yed-dyb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 14:17:03 by yed-dyb           #+#    #+#             */
/*   Updated: 2021/11/13 14:39:33 by yed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include<unistd.h>
#include<stdarg.h>
#include<stdlib.h>
#include<stdio.h>

int     ft_printf(const char *s, ...);
void	ft_putchar(char c, int *count);
void	ft_puthex(unsigned long int nb, int upper, int *count);
void	ft_putnbr(int nb, int *count);
void	ft_putstr(char *str, int *count);
void	ft_tounsigned(unsigned int nb, int *count);
int	    ft_atoi(const char *str);

#endif
