/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_formated_u.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mismene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 09:28:33 by mismene           #+#    #+#             */
/*   Updated: 2021/01/03 16:25:00 by mismene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_formated_u_p1(t_shamil *tab, unsigned int digit)
{
	size_t	width;
	char	*str;
	char	*malloced_str;

	malloced_str = ft_itoa_u(digit);
	if (!tab->accuracy && tab->met_point && !digit)
	{
		while (tab->width--)
			ft_putchar(' ', tab);
		return ;
	}
	width = ft_strlen(malloced_str);
	str = ft_itoa_u(digit);
	print_spaces_u(tab, digit);
	print_zeroes(tab, width);
	ft_putstr(str, tab);
	free(str);
	free(malloced_str);
}

void	print_formated_u_p2(t_shamil *tab, unsigned int digit)
{
	size_t	width;
	char	*str;
	char	*malloced_str;

	malloced_str = ft_itoa_u(digit);
	if (!tab->accuracy && tab->met_point && !digit)
	{
		while (tab->width--)
			ft_putchar(' ', tab);
		return ;
	}
	width = ft_strlen(malloced_str);
	str = ft_itoa_u(digit);
	print_zeroes(tab, width);
	ft_putstr(str, tab);
	print_spaces_u(tab, digit);
	free(str);
	free(malloced_str);
}

void	print_formated_u_p3(t_shamil *tab, unsigned int digit)
{
	size_t	width;
	char	*str;
	char	*malloced_str;

	malloced_str = ft_itoa_u(digit);
	width = ft_strlen(malloced_str);
	str = ft_itoa_u(digit);
	print_spaces_u(tab, digit);
	print_zeroes(tab, width);
	ft_putstr(str, tab);
	free(str);
	free(malloced_str);
}

void	print_formated_u_p4(t_shamil *tab, unsigned int digit)
{
	size_t	width;
	char	*str;
	char	*malloced_str;

	malloced_str = ft_itoa_u(digit);
	width = ft_strlen(malloced_str);
	str = ft_itoa_u(digit);
	if (tab->accuracy)
		print_spaces_u(tab, digit);
	print_zeroes(tab, width);
	if (tab->accuracy && tab->flag != '0')
		print_zeroes(tab, width);
	ft_putstr(str, tab);
	free(str);
	free(malloced_str);
}

void	print_formated_u(t_shamil *tab, unsigned int digit)
{
	char	*str;

	str = ft_itoa_u(digit);
	print_formated_u_if_else(tab, digit, str);
	free(str);
}
