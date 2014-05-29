/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 12:10:10 by jbernabe          #+#    #+#             */
/*   Updated: 2014/04/17 00:41:09 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		ft_isspace(int c)
{
	if (c == ' ' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == '\t' || c == '\b' || c == '\a')
		return (1);
	return (0);
}

int				ft_atoi(const char *str)
{
	int	i;
	int	op;
	int	pnbr;

	i = 0;
	op = 1;
	pnbr = 0;
	while (ft_isspace(str[i]))
		i++;
	if ((str[i] == '-'))
	{
		op = -1;
		i++;
	}
	else if ((str[i] == '+'))
		i++;
	while ((str[i] <= '9') && (str[i] >= '0'))
	{
		pnbr = pnbr * 10 + ((str[i] - '0') * op);
		i++;
	}
	return (pnbr);
}
