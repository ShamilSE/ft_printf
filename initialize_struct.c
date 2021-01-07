/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mismene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:12:45 by mismene           #+#    #+#             */
/*   Updated: 2021/01/03 16:23:24 by mismene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialize_structure(t_shamil *structure)
{
	structure->p = NULL;
	structure->flag = '1';
	structure->string_size = 0;
	structure->type = 0;
	structure->accuracy = 0;
	structure->width = 0;
	structure->return_value = 0;
	structure->sign = 0;
	structure->null = 0;
	structure->met_point = 0;
}

void	null_flags(t_shamil *tab)
{
	tab->width = 0;
	tab->accuracy = 0;
	tab->flag = '1';
	tab->type = 0;
	tab->sign = 0;
	tab->met_point = 0;
}
