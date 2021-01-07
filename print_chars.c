/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mismene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:15:33 by mismene           #+#    #+#             */
/*   Updated: 2021/01/03 16:23:51 by mismene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_chars(int c, t_shamil *tab)
{
	if (tab->flag == '-')
	{
		ft_putchar(c, tab);
		if (tab->width)
			while (--tab->width)
				ft_putchar(' ', tab);
	}
	else if (tab->width)
	{
		while (--tab->width)
			ft_putchar(' ', tab);
		ft_putchar(c, tab);
	}
	else
		ft_putchar(c, tab);
}
