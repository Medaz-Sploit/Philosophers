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

void	ft_init(t_rule *rules, int argc, char **argv)
{
	rules->nbr_philo = atoi(argv[1]);
	rules->time_to_die = atoi(argv[2]);
	rules->time_to_eat = atoi(argv[3]);
	rules->time_to_sleep = atoi(argv[4]);
	if (argc == 6)
		rules->nbr_meals = atoi(argv[5]);
	else
		rules->nbr_meals = -1;
	rules->philos = malloc(sizeof(t_philo) * rules->nbr_philo);
	rules->forks = malloc(sizeof(pthread_mutex_t) * rules->nbr_philo);
}

void	ft_init_philosophers(t_rule *rules)
{
	int	i;

	i = -1;
	while (++i < rules->nbr_philo)
		pthread_mutex_init(&rules->forks[i], NULL);
	pthread_mutex_init(&rules->display, NULL);
	i = -1;
	while (++i < rules->nbr_philo)
	{
		rules->philos[i].forks = rules->forks;
		rules->philos[i].id = i + 1;
		rules->philos[i].meals = 0;
		rules->philos[i].display = &(rules->display);
		rules->philos[i].rules = rules;
		rules->philos[i].lastime_eat = get_time();
		rules->philos[i].is_eating = 0;
		pthread_mutex_init(&(rules->philos[i].eating), NULL);
	}
}
