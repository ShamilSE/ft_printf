/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   router.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mismene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 15:20:46 by mismene           #+#    #+#             */
/*   Updated: 2021/01/03 16:26:21 by mismene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	router(t_shamil *tab)
{
	if (tab->type == 'd' || tab->type == 'i')
		print_digits(va_arg(tab->args, int), tab);
	if (tab->type == 'u')
		print_unsigned(va_arg(tab->args, unsigned int), tab);
	else if (tab->type == 'x' || tab->type == 'X')
		print_hex(va_arg(tab->args, unsigned int), tab);
	else if (tab->type == 's')
		print_strings(va_arg(tab->args, char*), tab);
	else if (tab->type == 'c')
		print_chars(va_arg(tab->args, int), tab);
	else if (tab->type == 'p')
		print_pointers(va_arg(tab->args, unsigned long), tab);
	else if (tab->type == 't')
		print_percent(tab);
}

void	proccessor(t_shamil *tab)
{
	while (tab->string_size)
	{
		print_text(tab);
		tab->string_size = ft_strlen(tab->p);
	}
}
