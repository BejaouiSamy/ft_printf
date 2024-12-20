/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int_decimal.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:22:43 by bsamy             #+#    #+#             */
/*   Updated: 2024/12/18 13:22:44 by bsamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_char(char *s, unsigned int number, int len)
{
	while (number > 0)
	{
		s[len--] = 48 + (number % 10);
		number = number / 10;
	}
	return (s);
}

int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char				*s;
	int					len;
	unsigned int		number;
	int					sign;

	sign = 1;
	len = ft_len(n);
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!(s))
		return (NULL);
	s[len--] = '\0';
	if (n == 0)
		s[0] = '0';
	if (n < 0)
	{
		sign *= -1;
		number = n * -1;
		s[0] = '-';
	}
	else
		number = n;
	s = ft_char(s, number, len);
	return (s);
}

int	ft_putnbr(int n)
{
	int		len;
	char	*num;

	num = ft_itoa(n);
	len = ft_putstr(num);
	free(num);
	return (len);
}
/* La fonction ft_char rempli un tableau de caracteres
avec la representation en chaine d'entier, en ajoutant
les chiffres un par un dans le tableau (s).

La fonction ft_len calcule la longueur
(en nombre de caracteres) necessaire pour representer
un entier (n) en chaine de caracteres. On ne peut pas
utiliser un strlen classique car elle est utile pour
calculer la longueur d'une chaine deja creee. mais
avant de creer la chaine qui representera l'entier
nous ne connaissons pas encore sa longueur.

La fonction ft_itoa converti un entier (n) en chaine
de caracteres.

La fonction ft_putnbr affiche un entier (n) en utilisant
la fonction ft_itoa pour le convertir en chaine et
ft_putstr pour l'afficher.*/