/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yed-dyb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 12:55:33 by yed-dyb           #+#    #+#             */
/*   Updated: 2021/11/13 12:10:24 by yed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdarg.h>
#include<unistd.h>
#include <stdio.h>
#include "ft_putchar.c"
#include "ft_putstr.c"
#include "ft_putnbr.c"
#include "ft_puthex.c"
#include "ft_tounsigned.c"

void print_types(const char *s, int i, va_list args)
{
	unsigned int nbr;
	int n;
	if (s[i] == 'd')
		ft_putnbr(va_arg(args, int));
	else if (s[i] == 'c')
		ft_putchar(va_arg(args, int));
	else if (s[i] == 's')
		ft_putstr(va_arg(args, char *));
	else if (s[i] == 'p')
	{
		ft_putstr("0x10");
		ft_puthex(va_arg(args, int), 0);
	} else if (s[i] == 'i')
		ft_putnbr(va_arg(args, int));
	else if (s[i] == 'u')
		ft_tounsigned(va_arg(args, unsigned int));
	else if (s[i] == 'x')
		ft_puthex(va_arg(args, unsigned int), 0);
	else if (s[i] == 'X')
		ft_puthex(va_arg(args, unsigned int), 1);
	else if (s[i] == '%')
		ft_putchar('%');
	
}

int ft_printf(const char *s, ...)
{
	va_list args;
	int i;

	va_start(args, s);
	i = 0;
	while(s[i])
	{
		if (s[i] != '%')
			ft_putchar(s[i]);
		else
			print_types(s, ++i, args);
		i++;
	}
	va_end(args);
	return 0;
}

int main ()
{
	char *s = "hello";
	int a, b, c;

	printf("Enter value of a in decimal format:");
    scanf("%d", &a);
    
	ft_printf("x = %%\n");
    printf("x = %%\n");
 
    return 0;
}
