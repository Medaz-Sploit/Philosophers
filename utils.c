/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:21:23 by mazoukni          #+#    #+#             */
/*   Updated: 2021/11/08 23:49:38 by mazoukni         ###   ########.fr       */
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

int	check_meals(t_rule *rules)
{
	int	r;
	int	i;

	r = 0;
	i = -1;
	if (rules->nbr_meals != -1)
	{
		while (++i < rules->nbr_philo)
		{
			if (rules->philos[i].meals >= rules->nbr_meals)
				r++;
		}
		if (r == rules->nbr_philo)
		{
			pthread_mutex_lock(&rules->display);
			write(1, KNRM, ft_strlen(KNRM));
			write(1, FIN, ft_strlen(FIN));
			ft_putnbr(rules->nbr_meals);
			write(1, " times\n", 6);
			return (1);
		}
	}
	return (0);
}
