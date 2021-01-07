/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_formated_u_p2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mismene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 09:32:54 by mismene           #+#    #+#             */
/*   Updated: 2021/01/03 16:24:43 by mismene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_formated_u_p5(t_shamil *tab, unsigned int digit)
{
	size_t	width;
	char	*str;
	char	*malloced_str;

	malloced_str = ft_itoa_u(digit);
	if (!tab->accuracy && tab->met_point && !digit && !tab->flag)
	{
		while (tab->width--)
			ft_putchar(' ', tab);
		return ;
	}
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

void	print_formated_u_p6(t_shamil *tab, unsigned int digit, char *str)
{
	while ((unsigned long)tab->width-- > ft_strlen(ft_itoa_u(digit)))
		ft_putchar(' ', tab);
	ft_putstr(str, tab);
}

void	print_formated_u_p7(t_shamil *tab, size_t width, char *str)
{
	print_zeroes(tab, width);
	ft_putstr(str, tab);
}

void	print_formated_u_if_else(t_shamil *tab, int digit, char *str)
{
	size_t	width;
	char	*malloced_str;

	malloced_str = ft_itoa_u(digit);
	width = ft_strlen(malloced_str);
	if ((tab->flag == '1' && tab->width > 0))
		print_formated_u_p1(tab, digit);
	else if (tab->flag == '-')
		print_formated_u_p2(tab, digit);
	else if (tab->accuracy > tab->width)
		print_formated_u_p3(tab, digit);
	else if (tab->accuracy && tab->sign)
		print_formated_u_p4(tab, digit);
	else if (tab->width > tab->accuracy && tab->accuracy > 0)
		print_formated_u_p5(tab, digit);
	else if (tab->flag == '0' && !tab->accuracy && tab->met_point && !digit)
		while (tab->width--)
			ft_putchar(' ', tab);
	else if (tab->flag == '0' && !tab->accuracy && tab->met_point)
		print_formated_u_p6(tab, digit, str);
	else if (tab->flag == '0')
		print_formated_u_p7(tab, width, str);
	free(malloced_str);
}
