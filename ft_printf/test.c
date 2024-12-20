#include "ft_printf.h"
int main(void)
{
    char a[] = "bonjour";
    int b = 42;
    ft_printf("%s\n %d", &a, b);
}