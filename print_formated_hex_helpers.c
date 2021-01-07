/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_formated_hex_helpers.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mismene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 11:07:51 by mismene           #+#    #+#             */
/*   Updated: 2021/01/03 16:46:47 by mismene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_formated_hex_helper_p4(t_shamil *tab, char *str)
{
	while (tab->accuracy > (int)ft_strlen(str))
	{
		ft_putchar('0', tab);
		tab->accuracy--;
	}
	ft_putstr(str, tab);
}
