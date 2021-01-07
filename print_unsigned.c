/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mismene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 08:50:06 by mismene           #+#    #+#             */
/*   Updated: 2021/01/03 16:47:03 by mismene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_u(unsigned int nbr)
{
	unsigned int	temp;
	int				size;
	int				sign;
	char			*str;

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

void	print_spaces_u_helper(t_shamil *tab, int length, int width)
{
	while (length > width && width < tab->width)
	{
		tab->flag == '0' && !tab->accuracy ?
			ft_putchar('0', tab) : ft_putchar(' ', tab);
		length--;
	}
}

void	print_spaces_u(t_shamil *tab, unsigned int digit)
{
	int		width;
	int		length;
	char	*malloced_str;
	int		size;

	malloced_str = ft_itoa_u(digit);
	size = tab->accuracy > (int)ft_strlen(malloced_str) ?
		tab->accuracy : (int)ft_strlen(malloced_str);
	length = tab->width;
	width = (int)ft_strlen(malloced_str);
	if ((tab->accuracy > width) || (!tab->accuracy && tab->met_point))
		while (length > size)
		{
			ft_putchar(' ', tab);
			length--;
		}
	else
	{
		print_spaces_u_helper(tab, length, width);
	}
	free(malloced_str);
}

void	format_util_u(unsigned int digit, t_shamil *tab)
{
	if (tab->null && tab->width && !tab->accuracy && !digit)
		while (tab->width)
		{
			ft_putchar(' ', tab);
			tab->width--;
		}
	else if (tab->flag || tab->accuracy)
		print_formated_u(tab, digit);
	else if (digit == 0)
		while (tab->width--)
			ft_putchar(' ', tab);
}

void	print_unsigned(unsigned int digit, t_shamil *tab)
{
	char	*str;

	str = ft_itoa_u(digit);
	if (!digit && !tab->accuracy && tab->met_point && !tab->width)
		return ;
	if ((tab->width > (int)ft_strlen(str)) || tab->accuracy)
		format_util_u(digit, tab);
	else if (!digit && tab->met_point && tab->width)
		while (tab->width--)
			ft_putchar(' ', tab);
	else
		ft_putstr(str, tab);
	free(str);
}
