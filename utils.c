/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:21:23 by mazoukni          #+#    #+#             */
/*   Updated: 2021/11/08 20:58:06 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s != '\0')
	{
		write(fd, s, 1);
		s++;
	}
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	is_str_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_digits(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!is_str_digit(av[i]))
			return (0);
		i++;
	}
	return (1);
}

void	*check_meals(int *i, void *g_rules)
{
	int	r;

	r = 0;
	(*i) = -1;
	while (++(*i) < ((t_rule *)g_rules)->nbr_philo)
	{
		if (((t_rule *)g_rules)->philos[(*i)].meals == \
		((t_rule *)g_rules)->nbr_meals)
			r++;
	}
	if (r != ((t_rule *)g_rules)->nbr_philo)
		r = 0;
	else
	{
		pthread_mutex_lock(&((t_rule *)g_rules)->display);
		write(1, KNRM, ft_strlen(KNRM));
		write(1, FIN, ft_strlen(FIN));
		ft_putnbr(((t_rule *)g_rules)->nbr_meals);
		write(1, " times\n", 6);
		exit(0);
	}
	return (NULL);
}
