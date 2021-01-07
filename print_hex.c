/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mismene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 10:53:23 by mismene           #+#    #+#             */
/*   Updated: 2021/01/03 16:47:18 by mismene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_formated_hex_helper(t_shamil *tab, char *str)
{
	size_t	acc;

	acc = tab->accuracy;
	while (tab->width > tab->accuracy &&
			tab->width > (int)ft_strlen(str) && tab->flag != '-')
	{
		ft_putchar(' ', tab);
		tab->width--;
	}
	while (acc > ft_strlen(str))
	{
		ft_putchar('0', tab);
		acc--;
	}
	ft_putstr(str, tab);
	if (tab->flag == '-' && tab->width && tab->accuracy > (int)ft_strlen(str))
		while (tab->width-- > tab->accuracy)
			ft_putchar(' ', tab);
	else if (tab->flag == '-' && tab->width)
		while (tab->width-- > (int)ft_strlen(str))
			ft_putchar(' ', tab);
}

void	print_formated_hex_helper_p2(t_shamil *tab, char *str)
{
	if (!tab->accuracy && tab->met_point && str[0] == '0')
	{
		while (tab->width--)
			ft_putchar(' ', tab);
		return ;
	}
	if (tab->flag == '1')
		while ((int)ft_strlen(str) < tab->width--)
			ft_putchar(' ', tab);
	ft_putstr(str, tab);
	if (tab->flag == '-')
		while ((int)ft_strlen(str) < tab->width--)
			ft_putchar(' ', tab);
}

void	print_formated_hex_helper_p3(t_shamil *tab, char *str)
{
	if (!tab->accuracy && tab->met_point && str[0] == '0')
	{
		while (tab->width--)
			ft_putchar(' ', tab);
		return ;
	}
	while ((int)ft_strlen(str) < tab->width--)
		ft_putchar('0', tab);
	ft_putstr(str, tab);
}

void	print_formated_hex(t_shamil *tab, char *str)
{
	if (tab->null && tab->width)
		while (tab->width--)
			ft_putchar(' ', tab);
	else if (tab->width && tab->accuracy)
		print_formated_hex_helper(tab, str);
	else if (tab->width && tab->flag != '0')
		print_formated_hex_helper_p2(tab, str);
	else if (!tab->accuracy && tab->met_point &&
				tab->flag == '0' && str[0] == '0')
		while (tab->width--)
			ft_putchar(' ', tab);
	else if (!tab->accuracy && tab->met_point && tab->flag == '0')
	{
		while (tab->width-- > (int)ft_strlen(str))
			ft_putchar(' ', tab);
		ft_putstr(str, tab);
	}
	else if (tab->width && tab->flag == '0')
		print_formated_hex_helper_p3(tab, str);
	else if (tab->accuracy)
		print_formated_hex_helper_p4(tab, str);
}

void	print_hex(unsigned int hex, t_shamil *tab)
{
	char	str[20];

	ft_bzero(str, 20);
	to_hex(str, hex, tab->type);
	if (!hex && !tab->accuracy && tab->met_point && !tab->width)
		return ;
	if ((tab->width > (int)ft_strlen(str)) || tab->accuracy)
		print_formated_hex(tab, str);
	else if (!hex && tab->met_point && tab->width)
		while (tab->width--)
			ft_putchar(' ', tab);
	else
		ft_putstr(str, tab);
}
