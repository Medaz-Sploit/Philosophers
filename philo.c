/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:28:30 by mazoukni          #+#    #+#             */
/*   Updated: 2021/11/08 20:58:06 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*lifespan_philo(void *philo)
{
	int	left_fork;
	int	right_fork;

	if (((t_philo *)philo)->id % 2 == 0)
		usleep(200);
	while (1)
	{
		left_fork = ((t_philo *)philo)->id - 1;
		if (((t_philo *)philo)->id == ((t_philo *)philo)->g_rules->nbr_philo)
			right_fork = 0;
		else
			right_fork = ((t_philo *)philo)->id;
		routine(philo, right_fork, left_fork);
	}
}

void	*supervisor(void *g_rules)
{
	int	i;

	i = -1;
	while (++i < ((t_rule *)g_rules)->nbr_philo)
		pthread_create(&((t_rule *)g_rules)->philos[i].index, NULL, \
		lifespan_philo, (void *)&((t_rule *)g_rules)->philos[i]);
	usleep(100);
	while (1)
	{
		is_dead(g_rules);
		check_meals(&i, g_rules);
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	g_rules.time = get_time();
	if (!(argc == 5 || argc == 6))
		print_error(0);
	if (!check_digits(argc, argv))
		print_error(1);
	ft_init(argc, argv);
	ft_init_philosophers();
	pthread_create(&g_rules.supervisor, NULL, supervisor, (void *)&g_rules);
	pthread_join(g_rules.supervisor, NULL);
	return (0);
}
