/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mismene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 14:58:23 by mismene           #+#    #+#             */
/*   Updated: 2021/01/03 16:22:06 by mismene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_check(t_shamil *tab)
{
	if (*tab->p == '-')
		tab->flag = '-';
	else if (*tab->p == '0')
		tab->flag = '0';
	tab->p++;
	if (*tab->p == '-')
	{
		tab->flag = '-';
		tab->p++;
	}
}

void	width_check(t_shamil *tab)
{
	if (*tab->p == '*')
	{
		tab->width = va_arg(tab->args, int);
		tab->p++;
	}
	while (ft_isdigit(*tab->p))
	{
		tab->width = (tab->width * 10) + (*tab->p - 48);
		tab->p++;
	}
}
