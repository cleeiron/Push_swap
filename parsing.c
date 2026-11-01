/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleiron <cleiron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 11:20:35 by cleiron           #+#    #+#             */
/*   Updated: 2026/11/01 12:44:50 by cleiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



int	ft_digit_isvalid(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]))
			i++;
		else 
			return (0);
	}
	return (1);
}

int ft_int_isvalid(char *str)
{
	long	n;
	int	i;
	long limit;

	n = 0;
	i = 0;
	limit = INT_MAX;
	if (!ft_digit_isvalid(str))
		return (0);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			limit = -(long)INT_MIN;
		i++;
	}
	while (str[i] != '\0')
	{
		if (n > (limit - (str[i] - '0')) / 10)
			return (0);
		n = n *10 + (str[i] - '0');
		i++;
	}
	return (1);
}
		
		