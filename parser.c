/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mismene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 16:45:10 by mismene           #+#    #+#             */
/*   Updated: 2021/01/03 16:23:46 by mismene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	love_norminette(t_shamil *tab)
{
	while (ft_isdigit(*tab->p))
	{
		if (*tab->p != '0')
			break ;
		tab->p++;
	}
	while (ft_isdigit(*tab->p))
	{
		tab->accuracy = (tab->accuracy * 10) + (*tab->p - 48);
		tab->p++;
	}
	if (!tab->accuracy)
	{
		tab->null = 1;
		return ;
	}
}

void	accuracy_check(t_shamil *tab)
{
	tab->p++;
	tab->met_point = 1;
	if (*tab->p == '*')
	{
		tab->accuracy = va_arg(tab->args, int);
		tab->p++;
	}
	else if (ft_isdigit(*tab->p) && *tab->p != '0')
	{
		while (ft_isdigit(*tab->p))
		{
			tab->accuracy = (tab->accuracy * 10) + (*tab->p - 48);
			tab->p++;
		}
	}
	else if (ft_isdigit(*tab->p) && *tab->p == '0')
		love_norminette(tab);
	else
		tab->null = 1;
}

void	type_check(t_shamil *tab)
{
	if (ft_isalpha(*tab->p))
	{
		tab->type = *tab->p;
		tab->p++;
	}
}

void	parser_2(t_shamil *tab)
{
	if (*tab->p == '.')
		accuracy_check(tab);
	if (ft_isalpha(*tab->p))
		type_check(tab);
	if (!tab->type && ft_strlen(tab->p))
	{
		while (!tab->type && ft_strlen(tab->p))
		{
			if (ft_isalpha(*tab->p))
				tab->type = *tab->p;
			if (*tab->p == '%')
				tab->type = 't';
			tab->p++;
		}
	}
	if (tab->width < 0)
	{
		tab->flag = '-';
		tab->width *= -1;
	}
	if (tab->accuracy < 0)
	{
		tab->accuracy = 0;
		tab->met_point = 0;
	}
}

void	parser(t_shamil *tab)
{
	tab->p++;
	if (*tab->p == '%')
	{
		ft_putchar('%', tab);
		tab->p++;
		return ;
	}
	if (*tab->p == '-' || (*tab->p == '0' && *tab->p + 1 != '.'))
		flag_check(tab);
	while (*tab->p == '-' || *tab->p == '0')
		tab->p++;
	if (ft_isdigit(*tab->p) || *tab->p == '*')
		width_check(tab);
	if (tab->width && (ft_isdigit(*tab->p) || *tab->p == '*'))
		while (*tab->p != '.')
			tab->p++;
	parser_2(tab);
}
