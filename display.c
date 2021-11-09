/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 10:55:30 by mazoukni          #+#    #+#             */
/*   Updated: 2021/11/08 23:17:19 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_msg(t_philo *philo, char *c, char *msg)
{
	pthread_mutex_lock(philo->display);
	write(1, c, ft_strlen(c));
	ft_putnbr(get_time() - ((t_philo *)philo)->g_rules->time);
	write(1, " ", 1);
	ft_putnbr(philo->id);
	write(1, msg, ft_strlen(msg));
	write(1, KNRM, ft_strlen(KNRM));
	pthread_mutex_unlock(philo->display);
}

void	eating(t_philo *philo, int right_fork, int left_fork)
{
	pthread_mutex_lock(&((t_philo *)philo)->forks[left_fork]);
	print_msg(philo, KBLU, TAKE_FORK);
	pthread_mutex_lock(&((t_philo *)philo)->forks[right_fork]);
	print_msg(philo, KBLU, TAKE_FORK);
	print_msg(philo, KGRN, EATING);
	pthread_mutex_lock(&((t_philo *)philo)->eating);
	((t_philo *)philo)->is_eating = 1;
	((t_philo *)philo)->lastime_eat = get_time();
	ft_usleep(((t_philo *)philo)->g_rules->time_to_eat);
	pthread_mutex_unlock(&((t_philo *)philo)->eating);
	((t_philo *)philo)->is_eating = 0;
	((t_philo *)philo)->meals++;
	pthread_mutex_unlock(&((t_philo *)philo)->forks[left_fork]);
	pthread_mutex_unlock(&((t_philo *)philo)->forks[right_fork]);
}

void	sleeping(t_philo *philo)
{
	print_msg(philo, KYEL, SLEEPING);
	ft_usleep(((t_philo *)philo)->g_rules->time_to_sleep);
	print_msg(philo, KMAG, THINKING);
}

void	routine(t_philo *philo, int right_fork, int left_fork)
{
	eating(philo, right_fork, left_fork);
	sleeping(philo);
}
