/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chansen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 04:24:01 by chansen           #+#    #+#             */
/*   Updated: 2016/12/12 06:32:58 by chansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_hexval(int uchr, int r)
{
	char	b[16] = "0123456789abcdef";

	if (r == 2)
		print_hexval(uchr / 16, r - 1);
	ft_putchar(b[uchr % 16]);
}

void	print_chrval(const unsigned char d)
{
	unsigned char	c = d;

	if ( c >= ' ' && c <= '~')
		ft_putchar(c);
	else
		ft_putchar('.');
}

void	print_memory(const void	*addr, size_t size)
{
	const unsigned char	*data = addr;
	int			c;
	unsigned	i;
	unsigned	j;

	c = 0;
	i = 0;
	j = 16;
	while (i < size)
	{
		while (i < j && i < size)
		{
			print_hexval(data[i], 2);
			i++;
			if (i % 2 == 0)
				ft_putchar(' ');
		}
		while (i < j)
		{
			ft_putchar(' ');
			ft_putchar(' ');
			if (i % 2 == 0)
				ft_putchar(' ');
			i++;
		}
		i = i - 16;
		while (i < j && i < size)
		{
			print_chrval(data[i]);
			i++;
		}
		j = j + 16;
		ft_putchar('\n');
	}
}
