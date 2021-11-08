/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:06:46 by mazoukni          #+#    #+#             */
/*   Updated: 2021/11/08 20:33:16 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_error(int e)
{
	if (e == 0)
		ft_putstr_fd("Error\n Only input 5 or 6 arguments\n", 1);
	else if (e == 1)
		ft_putstr_fd("Error\n Arguments must be numbers\n", 1);
	else
		ft_putstr_fd("###############\tTry agin\t##############\n", 1);
	exit(0);
}
