/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mismene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 11:57:33 by mismene           #+#    #+#             */
/*   Updated: 2020/10/30 11:57:40 by mismene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa(int nbr)
{
	int		temp;
	int		size;
	int		sign;
	char	*str;

	temp = nbr;
	size = 1;
	sign = nbr < 0;
	while (temp /= 10)
		size++;
	if (!(str = malloc(sizeof(char) * (size + 1 + sign))))
		return (NULL);
	if (sign)
		*str++ = '-';
	str += size;
	*str-- = '\0';
	if (nbr == 0)
		*str-- = '0';
	while (nbr)
	{
		*str-- = (nbr % 10) * (sign ? -1 : 1) + '0';
		nbr /= 10;
	}
	return (str + 1 - sign);
}
