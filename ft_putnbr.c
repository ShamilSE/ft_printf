/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mismene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 11:57:33 by mismene           #+#    #+#             */
/*   Updated: 2021/01/03 16:23:00 by mismene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, t_shamil *tab)
{
	unsigned int num;

	if (n == -2147483648)
	{
		ft_putstr("2147483648", tab);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-', tab);
		num = (unsigned int)(n * -1);
	}
	else
		num = (unsigned int)n;
	if (num > 9)
		ft_putnbr(num / 10, tab);
	ft_putchar(((char)(num % 10 + 48)), tab);
}
