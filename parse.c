/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:55:35 by sbartoul          #+#    #+#             */
/*   Updated: 2024/06/17 18:17:47 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parse_input(int argc, char *argv[])
{
	if (argc > 6 || argc < 5)
	{
	printf("Usage: ./philo no_of_phio time_to_die");
	 	return (printf(" time_to_eat time_to_sleep must_eat_times(optional)\n"));
	}
	if (!is_number(argv[1]) || ft_atoi(argv[1]) > INT_MAX || ft_atoi(argv[1]) <= 0)
		return (printf("Invalid philosophers number\n"));
	if (!is_number(argv[2]) || ft_atoi(argv[2]) > INT_MAX || ft_atoi(argv[2]) <= 0)
		return (printf("Invalid time to die\n"));
	if (!is_number(argv[3]) || ft_atoi(argv[3]) > INT_MAX || ft_atoi(argv[3]) <= 0)
		return (printf("Invalid time to eat\n"));
	if (!is_number(argv[4]) || ft_atoi(argv[4]) > INT_MAX || ft_atoi(argv[4]) <= 0)
		return (printf("Invalid time to sleep\n"));
	if (argv[5] && (!is_number(argv[5]) || ft_atoi(argv[5]) > INT_MAX || ft_atoi(argv[5]) <= 0))
		return (printf("Invalid number of times each philo must eat\n"));
	return (0);
}
