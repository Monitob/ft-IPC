/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbernabe <jbernabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 19:12:28 by jbernabe          #+#    #+#             */
/*   Updated: 2014/03/23 19:50:26 by jbernabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *str1, const char *str2)
{
	int	counter;

	counter = 0;
	while (str1[counter] != '\0' && str2[counter] != '\0'
			&& str1[counter] == str2[counter])
		counter++;
	if (str1[counter] != str2[counter])
	{
		if (str1[counter] > str2[counter])
		{
			return (1);
		}
		else
		{
			return (-1);
		}
	}
	else
		return (0);
}
