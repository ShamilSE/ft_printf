/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mismene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 09:39:28 by mismene           #+#    #+#             */
/*   Updated: 2021/01/04 10:16:30 by mismene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	meet_percent(t_shamil *tab)
{
	parser(tab);
	if (tab->null && !tab->width && tab->type != 'p'
			&& (tab->accuracy && !tab->met_point))
		return ;
	router(tab);
	null_flags(tab);
	if (tab->p)
		print_text(tab);
}

void	type_until_percent(t_shamil *tab)
{
	int		i;
	char	*string;

	string = tab->p;
	i = 0;
	while (string[i] != '%')
	{
		ft_putchar(string[i], tab);
		i++;
	}
}

void	print_text(t_shamil *tab)
{
	if (*tab->p == '%')
		meet_percent(tab);
	while (*tab->p && *tab->p != '%')
		ft_putchar(*tab->p++, tab);
	if (*tab->p == '%')
		meet_percent(tab);
}

void	print_percent(t_shamil *tab)
{
	if (tab->flag == '-')
	{
		ft_putchar('%', tab);
		while (tab->width-- - 1)
			ft_putchar(' ', tab);
	}
	else
	{
		while (tab->width-- - 1)
			tab->flag == '0' ? ft_putchar('0', tab) : ft_putchar(' ', tab);
		ft_putchar('%', tab);
	}
}

int		ft_printf(const char *string, ...)
{
	t_shamil	*tab;
	int			return_value;

	tab = create_structure(string);
	va_start(tab->args, string);
	proccessor(tab);
	va_end(tab->args);
	return_value = tab->return_value;
	free(tab);
	return (return_value);
}
