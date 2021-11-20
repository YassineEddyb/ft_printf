#include "ft_printf.h"

void change_number(int *i)
{
    ++(*i);
}

int main ()
{
	ft_printf("%10c\n", 97);
	printf("%10c\n", 97);

    return (0);
}