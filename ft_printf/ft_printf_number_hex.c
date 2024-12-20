/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_number_hex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:22:51 by bsamy             #+#    #+#             */
/*   Updated: 2024/12/18 13:22:52 by bsamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len ++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_hex(unsigned int num, const char format)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, format);
		ft_put_hex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_putchar((num + '0'));
		else
		{
			if (format == 'x')
				ft_putchar((num - 10 + 'a'));
			if (format == 'X')
				ft_putchar((num - 10 + 'A'));
		}
	}
}

int	ft_puthex(unsigned int num, const char format)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_put_hex(num, format);
	return (hex_len(num));
}
/*La fonction hex_len calcule la longueur
(en nombre de chiffres) de la representation
hexadecimal de l'entier (num).

La fonction ft_put_ex affiche recursivement
un nombre en base hexadecimal. elle prend en
compte le format(x pour minuscules, X
pour majuscules) et affiche les chiffres
hexadecimaux sous forme de caracteres.

La fonction affiche un numbre en hexadecimal,
en appelant ft_put_hex pour l'affichage, puis
retourne la longueur de la chaine hexadecimal.
Ex : 
	Pour num = 255 et format = 'x', la fonction
	affichera "ff" et retournera 2.
*/