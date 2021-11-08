/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 10:29:01 by mazoukni          #+#    #+#             */
/*   Updated: 2021/11/08 20:58:06 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init(int argc, char **argv)
{
	g_rules.nbr_philo = atoi(argv[1]);
	g_rules.time_to_die = atoi(argv[2]);
	g_rules.time_to_eat = atoi(argv[3]);
	g_rules.time_to_sleep = atoi(argv[4]);
	if (argc == 6)
		g_rules.nbr_meals = atoi(argv[5]);
	else
		g_rules.nbr_meals = -1;
	g_rules.philos = malloc(sizeof(t_philo) * g_rules.nbr_philo);
	g_rules.forks = malloc(sizeof(pthread_mutex_t) * g_rules.nbr_philo);
}

void	ft_init_philosophers(void)
{
	int	i;

	i = -1;
	while (++i < g_rules.nbr_philo)
		pthread_mutex_init(&g_rules.forks[i], NULL);
	pthread_mutex_init(&g_rules.display, NULL);
	i = -1;
	while (++i < g_rules.nbr_philo)
	{
		g_rules.philos[i].forks = g_rules.forks;
		g_rules.philos[i].id = i + 1;
		g_rules.philos[i].meals = 0;
		g_rules.philos[i].display = &(g_rules.display);
		g_rules.philos[i].g_rules = &g_rules;
		g_rules.philos[i].lastime_eat = get_time();
		g_rules.philos[i].is_eating = 0;
		pthread_mutex_init(&(g_rules.philos[i].eating), NULL);
	}
}
