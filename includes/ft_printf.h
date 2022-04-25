/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumarin <aumarin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:44:50 by aumarin           #+#    #+#             */
/*   Updated: 2022/03/12 00:09:19 by aumarin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/**
 *	INCLUDES
**/
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

/**
 *	PROTOTYPES
**/
int		ft_putnbr_int(int nb, int count);
int		ft_putnbr_uint(int nb, int count);
int		ft_putnbr_hex(unsigned int nbr, int isUpper, int c);
size_t	ft_strlen(const char *s);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_printf(const char *str, ...);
//int		ft_putptr_hex(unsigned long int n);
int		ft_putptr_hex(unsigned long int n);

#endif