/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_me.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mismene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 15:43:29 by mismene           #+#    #+#             */
/*   Updated: 2021/01/03 16:52:10 by mismene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_spaces_helper(t_shamil *tab, int length, int width)
{
	while (length > width + (int)tab->sign && width < tab->width)
	{
		tab->flag == '0' && !tab->accuracy ?
			ft_putchar(' ', tab) : ft_putchar(' ', tab);
		length--;
	}
}

void	print_spaces(t_shamil *tab, int digit)
{
	char	*str;
	int		width;
	int		length;

	str = ft_itoa(digit);
	width = (ft_strchr(str, '-')) ?
		(int)ft_strlen(str) - 1 :
		(int)ft_strlen(str);
	length = tab->width;
	if (tab->accuracy > width)
		while (length > tab->accuracy + (int)tab->sign)
		{
			ft_putchar(' ', tab);
			length--;
		}
	else
		print_spaces_helper(tab, length, width);
	free(str);
}

void	print_minus(t_shamil *tab, int *digit, size_t *width)
{
	char	*str;

	str = ft_itoa(*digit);
	if (ft_strchr(str, '-') && (long)*digit != -2147483648)
	{
		ft_putchar('-', tab);
		*digit *= -1;
		*width = (int)ft_strlen(str);
		tab->sign = 1;
	}
	free(str);
}

void	print_zeroes(t_shamil *tab, size_t width)
{
	size_t	accuracy;
	size_t	length;

	accuracy = tab->accuracy;
	length = tab->width;
	if (tab->accuracy)
		while (accuracy > width)
		{
			ft_putchar('0', tab);
			accuracy--;
		}
	else if (tab->width && tab->flag == '0')
	{
		while (length > width + tab->sign)
		{
			ft_putchar('0', tab);
			length--;
		}
	}
}
