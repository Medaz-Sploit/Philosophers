/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:28:34 by mazoukni          #+#    #+#             */
/*   Updated: 2021/11/09 15:32:49 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <strings.h>
# include <stdio.h>
# include <sys/time.h>
# define TAKE_FORK " has taken a fork\n"
# define EATING " is eating\n"
# define SLEEPING " is sleeping\n"
# define THINKING " is thinking\n"
# define FIN "ALL PHILOSOPHER HAS EATEN AT LEAST "
# define ERORR "Error\n"
# define DIED " died\n"
# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"

struct	s_rule;

typedef struct s_philo
{
	pthread_t			index;
	pthread_mutex_t		*forks;
	pthread_mutex_t		*display;
	pthread_mutex_t		eating;
	int					meals;
	int					id;
	size_t				lastime_eat;
	int					is_eating;
	struct s_rule		*rules;
}						t_philo;

typedef struct s_rule
{
	pthread_t			supervisor;
	pthread_mutex_t		*forks;
	t_philo				*philos;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	size_t				time_to_die;
	int					nbr_philo;
	int					nbr_meals;
	pthread_mutex_t		display;
	size_t				time;
}						t_rule;

size_t	get_time(void);
void	ft_init_philosophers(t_rule *rules);
void	routine(t_philo *philo, int right_fork, int left_fork);
void	ft_init(t_rule *rules, int argc, char **argv);
void	ft_usleep(size_t time);
void	ft_putnbr(int n);
size_t	ft_strlen(char *s);
void	print_msg(t_philo *philo, char *c, char *msg);
void	ft_putstr_fd(char *s, int fd);
int		print_error(int e);
int		check_digits(int ac, char **av);
int		check_meals(t_rule *rules);
int		is_dead(t_rule *rules, int *i, size_t *current_time);
#endif
