/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_formated_helpers_part2.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mismene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 10:13:32 by mismene           #+#    #+#             */
/*   Updated: 2021/01/03 16:24:15 by mismene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_formated_helper_p6(t_shamil *tab, int digit, size_t width)
{
	tab->sign ? ft_putchar('-', tab) : 1;
	print_spaces(tab, digit);
	print_zeroes(tab, width);
	ft_putnbr(digit, tab);
}

void	print_formated_helper_p7(t_shamil *tab, int digit)
{
	tab->flag = '1';
	print_spaces(tab, digit);
	tab->sign ? ft_putchar('-', tab) : 1;
	ft_putnbr(digit, tab);
}

void	print_formated_helper_p8(t_shamil *tab, int digit, size_t width)
{
	tab->sign ? ft_putchar('-', tab) : 1;
	print_zeroes(tab, width);
	ft_putnbr(digit, tab);
}
