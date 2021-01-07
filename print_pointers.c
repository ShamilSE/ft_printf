/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mismene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 13:51:24 by mismene           #+#    #+#             */
/*   Updated: 2021/01/03 16:47:24 by mismene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_pointers_helper(unsigned long pointer, t_shamil *tab)
{
	char			*p;
	unsigned long	width;

	width = tab->width;
	p = ((void *)pointer == NULL && tab->met_point) || pointer ?
			ft_strdup("0x") : ft_strdup("0x0");
	if (tab->flag == '-')
	{
		ft_putstr(p, tab);
		while (tab->width-- > (int)ft_strlen(p))
			ft_putchar(' ', tab);
	}
	else
	{
		while (tab->width-- > (int)ft_strlen(p))
			ft_putchar(' ', tab);
		ft_putstr(p, tab);
	}
	if (tab->accuracy)
		while (tab->accuracy--)
			ft_putchar('0', tab);
	free(p);
}

void	print_pointers_helper_p2(t_shamil *tab, char *string, char *p)
{
	if (tab->accuracy && tab->width < tab->accuracy)
	{
		ft_putstr(p, tab);
		while (tab->accuracy-- > (int)ft_strlen(string))
			ft_putchar('0', tab);
		ft_putstr(string, tab);
	}
	else
	{
		ft_putstr(p, tab);
		ft_putstr(string, tab);
		if (tab->accuracy)
			while (tab->accuracy--)
				ft_putchar('0', tab);
	}
}

void	print_pointers_helper_p3(t_shamil *tab, char *string, char *p)
{
	unsigned long	width;

	width = tab->width;
	if (tab->flag == '-')
	{
		ft_putstr(p, tab);
		ft_putstr(string, tab);
		while (width-- > ft_strlen(string) +
				(!tab->accuracy ? ft_strlen(p) : 0))
			ft_putchar(' ', tab);
	}
	else
	{
		while (width-- > ft_strlen(string) +
				tab->accuracy + (!tab->accuracy ? ft_strlen(p) : 0))
			ft_putchar(' ', tab);
		ft_putstr(p, tab);
		ft_putstr(string, tab);
		if (tab->accuracy && tab->accuracy > tab->width)
			while (tab->accuracy--)
				ft_putchar('0', tab);
	}
}

void	print_pointers(unsigned long pointer, t_shamil *tab)
{
	char			*p;
	char			string[20];
	unsigned long	width;

	width = tab->width;
	ft_bzero(string, 20);
	p = ((void *)pointer == NULL && tab->met_point) || pointer ?
		ft_strdup("0x") : ft_strdup("0x0");
	if (pointer)
		to_hex(string, pointer, 'x');
	if (!pointer)
		print_pointers_helper(pointer, tab);
	else if (tab->width > tab->accuracy)
		print_pointers_helper_p3(tab, string, p);
	else
		print_pointers_helper_p2(tab, string, p);
	free(p);
	tab->null = 0;
}
