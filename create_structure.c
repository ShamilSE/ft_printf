/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_structure.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mismene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 09:36:00 by mismene           #+#    #+#             */
/*   Updated: 2021/01/03 16:30:24 by mismene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_shamil	*create_structure(const char *string)
{
	t_shamil	*structure;

	structure = (t_shamil*)malloc(sizeof(t_shamil));
	initialize_structure(structure);
	structure->string_size = ft_strlen(string);
	structure->p = (char *)string;
	return (structure);
}
