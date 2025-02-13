/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsamy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:14:13 by bsamy             #+#    #+#             */
/*   Updated: 2025/01/06 15:17:37 by bsamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

void		ft_put_hex(unsigned int num, const char format);
void		ft_put_ptr(uintptr_t nb);
int			ft_len(int n);
int			hex_len(unsigned int num);
int			len_ptr(uintptr_t nb);
int			ft_unsigned_len(unsigned int nb);
int			ft_putchar(int c);
int			ft_putstr(char *str);
int			ft_putnbr(int n);
int			ft_puthex(unsigned int num, const char format);
int			ft_putptr(uintptr_t ptr);
int			ft_putunsigned(unsigned int nb);
int			ft_conversion(va_list vl, const char format);
int			ft_printf(const char *format, ...);
char		*ft_char(char *s, unsigned int number, int len);
char		*ft_itoa(int n);
char		*ft_uitoa(unsigned int nb);

#endif
