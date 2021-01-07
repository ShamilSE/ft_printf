/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_formated_helpers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mismene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 10:12:46 by mismene           #+#    #+#             */
/*   Updated: 2021/01/03 16:46:54 by mismene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_formated_helper(t_shamil *tab, int digit, char *str)
{
	if (tab->flag == '-')
	{
		ft_putnbr(digit, tab);
		while (tab->width-- > (int)ft_strlen(str))
			ft_putchar(' ', tab);
	}
	else
	{
		while (tab->width-- > (int)ft_strlen(str))
			ft_putchar(' ', tab);
		ft_putnbr(digit, tab);
	}
}

void	print_formated_helper_p2(t_shamil *tab, int digit, size_t width)
{
	if (tab->accuracy)
		print_spaces(tab, digit);
	tab->sign ? ft_putchar('-', tab) : 1;
	print_zeroes(tab, width);
	if (tab->accuracy && tab->flag != '0')
		print_zeroes(tab, width);
	ft_putnbr(digit, tab);
}

void	print_formated_helper_p3(t_shamil *tab, int digit, size_t width)
{
	if (tab->accuracy)
		print_spaces(tab, digit);
	print_zeroes(tab, width);
	tab->sign ? ft_putchar('-', tab) : 1;
	if (tab->accuracy && tab->flag != '0')
		print_zeroes(tab, width);
	ft_putnbr(digit, tab);
}

void	print_formated_helper_p4(t_shamil *tab, int digit, size_t width)
{
	print_spaces(tab, digit);
	tab->sign ? ft_putchar('-', tab) : 1;
	print_zeroes(tab, width);
	ft_putnbr(digit, tab);
}

void	print_formated_helper_p5(t_shamil *tab, int digit, size_t width)
{
	tab->sign ? ft_putchar('-', tab) : 1;
	print_zeroes(tab, width);
	ft_putnbr(digit, tab);
	print_spaces(tab, digit);
}
