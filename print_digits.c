/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mismene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 10:08:18 by mismene           #+#    #+#             */
/*   Updated: 2021/01/03 16:50:38 by mismene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_formated(t_shamil *tab, int digit)
{
	int		width;
	char	*str;

	str = ft_itoa(digit);
	width = (int)ft_strlen(str);
	if ((tab->flag == '1' && tab->width > 0))
		print_formated_helper_p4(tab, digit, width);
	else if (tab->flag == '-')
		print_formated_helper_p5(tab, digit, width);
	else if (tab->accuracy > tab->width)
		print_formated_helper_p6(tab, digit, width);
	else if (tab->accuracy && tab->sign)
		print_formated_helper_p2(tab, digit, width);
	else if (tab->width > tab->accuracy && tab->accuracy)
		print_formated_helper_p3(tab, digit, width);
	else if (tab->flag == '0' && !tab->accuracy && tab->met_point)
		print_formated_helper_p7(tab, digit);
	else if (tab->flag == '0')
		print_formated_helper_p8(tab, digit, width);
	else
		print_formated_helper(tab, digit, str);
	free(str);
}

void	format_util(int digit, t_shamil *tab)
{
	if (tab->null && tab->width && !tab->accuracy && !digit)
		while (tab->width)
		{
			ft_putchar(' ', tab);
			tab->width--;
		}
	else if (tab->flag || tab->accuracy || tab->width)
		print_formated(tab, digit);
	else if (digit == 0)
		while (tab->width--)
			ft_putchar(' ', tab);
}

void	print_digits(int digit, t_shamil *tab)
{
	char	*str;

	digit < 0 ? tab->sign = 1 : 0;
	str = digit < 0 ? ft_itoa(-digit) : ft_itoa(digit);
	digit = digit < 0 && digit != -2147483648 ? digit * -1 : digit * 1;
	if (!tab->accuracy && tab->met_point && digit == 0)
	{
		while (tab->width)
		{
			ft_putchar(' ', tab);
			tab->width--;
		}
		return ;
	}
	if ((tab->width > (int)ft_strlen(str) || tab->accuracy))
		format_util(digit, tab);
	else
	{
		tab->sign ? ft_putchar('-', tab) : 1;
		ft_putnbr(digit, tab);
	}
	free(str);
}
