#include "ft_printf.h"
#include <stdio.h>

int main()
{
    int ret;
    ret = printf(TEST);
    printf("\nret = %d\n", ret);
    ret = ft_printf(TEST);
    printf("\nret = %d\n", ret);
}
