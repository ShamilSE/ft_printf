/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mismene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 15:38:16 by mismene           #+#    #+#             */
/*   Updated: 2021/01/03 15:41:36 by mismene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reverse_str(char *s)
{
	int		c;
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s) - 1;
	while (i < j)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
		i++;
		j--;
	}
}

void	to_hex(char *str, unsigned long decimal, char type)
{
	int	i;
	int	remainder;

	i = 0;
	if (decimal == 0)
	{
		str[0] = '0';
		return ;
	}
	while (decimal > 0)
	{
		remainder = decimal % 16;
		if (remainder > 9 && type == 'x')
			str[i] = 'a' + remainder - 10;
		else if (remainder > 9 && type == 'X')
			str[i] = 'A' + remainder - 10;
		else
			str[i] = '0' + remainder;
		decimal = decimal / 16;
		++i;
	}
	reverse_str(str);
}
