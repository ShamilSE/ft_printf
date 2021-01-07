/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_strings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mismene <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 15:23:03 by mismene           #+#    #+#             */
/*   Updated: 2021/01/03 16:49:43 by mismene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*terminate_string(char *string, int accuracy)
{
	char	*s;
	int		i;

	i = 0;
	s = malloc((int)ft_strlen(string + 1));
	while (accuracy--)
	{
		s[i] = string[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

void	print_strings_helper(t_shamil *tab, char *string)
{
	char *s;

	s = terminate_string(string, tab->accuracy);
	if (tab->accuracy && tab->accuracy < (int)ft_strlen(string) && tab->width)
	{
		while (tab->width-- > (int)ft_strlen(s))
			ft_putchar(' ', tab);
		ft_putstr(s, tab);
	}
	else if (tab->accuracy && tab->accuracy < (int)ft_strlen(string))
		ft_putstr(s, tab);
	else if (tab->width)
	{
		while (tab->width-- > (int)ft_strlen(string))
			tab->flag == '0' ? ft_putchar('0', tab) : ft_putchar(' ', tab);
		ft_putstr(string, tab);
	}
	else
		ft_putstr(string, tab);
	free(s);
}

void	print_strings_helper_p2(t_shamil *tab, char *string)
{
	int		width;
	char	*s;

	s = terminate_string(string, tab->accuracy);
	width = (int)ft_strlen(string);
	if (tab->flag == '-' && tab->width && tab->accuracy)
	{
		ft_putstr(s, tab);
		while (tab->width-- > (int)ft_strlen(s))
			ft_putchar(' ', tab);
	}
	else if (tab->flag == '-' && tab->width)
	{
		ft_putstr(string, tab);
		while (tab->width > width)
		{
			ft_putchar(' ', tab);
			tab->width--;
		}
	}
	else
		print_strings_helper(tab, string);
	free(s);
}

void	print_strings_helper_p3(t_shamil *tab)
{
	char	*str;

	str = ft_strdup("(null)");
	if (tab->accuracy && tab->accuracy < 6)
		str[tab->accuracy] = '\0';
	if (tab->width && tab->flag != '-')
		while (tab->width-- > (int)ft_strlen(str))
			tab->flag == '0' ? ft_putchar('0', tab) : ft_putchar(' ', tab);
	ft_putstr(str, tab);
	if (tab->width && tab->flag == '-')
		while (tab->width-- > (int)ft_strlen(str))
			ft_putchar(' ', tab);
	free(str);
}

void	print_strings(char *string, t_shamil *tab)
{
	int	width;

	width = (int)ft_strlen(string);
	if (tab->met_point && !tab->accuracy)
		while (tab->width--)
			tab->flag == '0' ? ft_putchar('0', tab) : ft_putchar(' ', tab);
	else if (string == NULL)
		print_strings_helper_p3(tab);
	else if (tab->flag == '1' && tab->width && !tab->accuracy)
	{
		while (tab->width > width)
		{
			ft_putchar(' ', tab);
			tab->width--;
		}
		ft_putstr(string, tab);
	}
	else
		print_strings_helper_p2(tab, string);
}
