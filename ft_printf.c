/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yed-dyb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 12:55:33 by yed-dyb           #+#    #+#             */
/*   Updated: 2021/11/13 22:27:24 by yed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include<stdio.h>

void print_space(int nbr, int *count)
{
    while (nbr > 0)
    {
        ft_putchar(' ', count);
        nbr--;
    }
}

void check_prefix(const char *s, int *i, int *count)
{
    int nbr;
    int neg;
    int j;

    nbr = 0;
    neg = 1;
    j = 0;
    if ((s[*i] >= '0' && s[*i] <= '9') || s[*i] == '-')
    {
        if (s[*i] == '-')
        {
            neg = 0;
            (*i)++;
        }
		while(s[*i] >= '0' && s[*i] <= '9')
        {
            nbr = (s[*i] - '0') + (nbr * 10);
            (*i)++;
            j++;
        }
        print_space((nbr - j) * neg, count);
	}
}

void print_types(const char *s, int *i, va_list args, int *count)
{
    check_prefix(s, i, count);
    if (s[*i] == 'd')
		ft_putnbr(va_arg(args, int), count);
	else if (s[*i] == 'c')
		ft_putchar(va_arg(args, int), count);
	else if (s[*i] == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (s[*i] == 'p')
	{
		ft_putstr("0x", count);
		ft_puthex(va_arg(args, long int), 0, count);
	} 
    else if (s[*i] == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if (s[*i] == 'u')
		ft_tounsigned(va_arg(args, unsigned int), count);
	else if (s[*i] == 'x')
		ft_puthex(va_arg(args, unsigned int), 0, count);
	else if (s[*i] == 'X')
		ft_puthex(va_arg(args, unsigned int), 1, count);
	else if (s[*i] == '%')
		ft_putchar('%', count);
}

int ft_printf(const char *s, ...)
{
	va_list args;
    int i;
    int count;

	va_start(args, s);
    i = 0;
    count = 0;
	while(s[i])
	{
		if (s[i] != '%')
			ft_putchar(s[i], &count);
		else
        {
            (i)++;
			print_types(s, &i, args, &count);
        }
		(i)++;
	}
	va_end(args);
	return (count);
}

// int main ()
// {
// 	//printf("%10c\n", 97);
//     int a = 9;
// 	ft_printf("%p\n", &a);
//     printf("%p\n", &a);
//     //printf("%d\n%d", a, b);

//     return (0);
//     // system("leaks a.out");
// }