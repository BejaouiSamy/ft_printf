/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_int.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:18:45 by bsamy             #+#    #+#             */
/*   Updated: 2024/12/18 13:23:08 by bsamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_len(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int nb)
{
	char	*str;
	int		len;

	len = ft_unsigned_len(nb);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len] = '\0';
	while (nb != 0)
	{
		str[len - 1] = nb % 10 + 48;
		nb = nb / 10;
		len--;
	}
	return (str);
}

int	ft_putunsigned(unsigned int nb)
{
	int		char_printed;
	char	*str;

	char_printed = 0;
	if (nb == 0)
		char_printed += write(1, "0", 1);
	else
	{
		str = ft_uitoa(nb);
		char_printed += ft_putstr(str);
		free(str);
	}
	return (char_printed);
}
/*La fonction ft_unsigned_len calcule la
longueur (en nombre de chiffre) de l'entier
non signe (nb) lorsqu'il est represente en
base 10.

La fonction ft_uitoa convertit un entier non
signe (nb) en une chaine de caracteres
representant cet entier en base 10.

La fonction ft_putunsigned affiche un entier
non signe (nb) en appelant ft_uitoa pour le
convertir en chaine de caracteres, puis en
affichant la chaine via ft_putstr. Elle
retourne egalement le nombre de caracteres
imprimes.*/