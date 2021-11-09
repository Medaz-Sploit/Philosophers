/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:28:30 by mazoukni          #+#    #+#             */
/*   Updated: 2021/11/09 15:33:41 by mazoukni         ###   ########.fr       */
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
		if (((t_philo *)philo)->id == ((t_philo *)philo)->rules->nbr_philo)
			right_fork = 0;
		else
			right_fork = ((t_philo *)philo)->id;
		routine(philo, right_fork, left_fork);
	}
}

void	*supervisor(void *rules)
{
	int		i;
	size_t	current_time;

	i = -1;
	current_time = 0;
	while (++i < ((t_rule *)rules)->nbr_philo)
		pthread_create(&((t_rule *)rules)->philos[i].index, NULL, \
		lifespan_philo, (void *)&((t_rule *)rules)->philos[i]);
	usleep(100);
	while (1)
	{
		if (is_dead(rules, &i, &current_time))
			return (NULL);
		if (check_meals(rules))
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_rule	rules;

	rules.time = get_time();
	if (!(argc == 5 || argc == 6))
		print_error(0);
	if (!check_digits(argc, argv))
		print_error(1);
	ft_init(&rules, argc, argv);
	ft_init_philosophers(&rules);
	pthread_create(&rules.supervisor, NULL, supervisor, (void *)&rules);
	pthread_join(rules.supervisor, NULL);
	return (0);
}
