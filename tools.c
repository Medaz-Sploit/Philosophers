/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:42:27 by mazoukni          #+#    #+#             */
/*   Updated: 2021/11/08 20:59:46 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_time(void)
{
	struct timeval		tv;
	unsigned long int	usec;

	gettimeofday(&tv, NULL);
	usec = (1000 * tv.tv_sec) + (tv.tv_usec / 1000);
	return (usec);
}

void	ft_usleep(size_t time)
{
	size_t	start;

	start = get_time();
	usleep((time * 1e3) - 20000);
	while (get_time() - start < time)
		;
}

void	ft_putnbr(int n)
{
	char			c;
	unsigned int	nbr;

	nbr = n;
	if (n < 0)
	{
		write(1, "-", 1);
		nbr = -n;
	}
	if (nbr <= 9)
	{
		c = '0' + nbr;
		write(1, &c, 1);
	}
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		c = nbr % 10 + '0';
		write(1, &c, 1);
	}
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	is_dead(void *g_rules)
{
	size_t	current_time;
	int		i;

	i = -1;
	current_time = 0;
	while (++i < ((t_rule *)g_rules)->nbr_philo)
	{
		if (((t_rule *)g_rules)->philos[i].is_eating == 0)
		{
			current_time = get_time();
			if (current_time - ((t_rule *)g_rules)->philos[i].lastime_eat >= \
			((t_rule *)g_rules)->time_to_die)
			{
				pthread_mutex_lock(&((t_rule *)g_rules)->display);
				write(1, KRED, ft_strlen(KRED));
				ft_putnbr(get_time() - ((t_rule *)g_rules)->time);
				write(1, " ", 1);
				ft_putnbr(((t_rule *)g_rules)->philos[i].id);
				write(1, DIED, ft_strlen(DIED));
				write(1, KNRM, ft_strlen(KNRM));
				exit(0);
			}
		}
	}
	return (0);
}
