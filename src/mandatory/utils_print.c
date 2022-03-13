/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <pveeta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:55:36 by pveeta            #+#    #+#             */
/*   Updated: 2022/03/08 21:38:21 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_error(t_input *input, U_INT error_num, char *msg, char *descrip)
{
	input->num_error = error_num;
	write(2, "", 11);
	if (msg != NULL)
	{
		printf("1print_error\n");
		write(2, msg, ft_strlen(msg));
		write(2, ": ", 2);
	}
	if (descrip == NULL)
		write(2, strerror(error_num), ft_strlen(strerror(error_num)));
	else
		write(2, descrip, ft_strlen(descrip));
	write(2, "\n", 1);
	free_all(input);
	printf("qwe\n");
	exit(error_num);
}

t_status	print_token(t_input *input)
{
	input->num_error = 258;
	write(1, "minishell: ", 11);
	write(2, "syntax error near unexpected token", 34);
	write(2, " `", 2);
	write(2, input->token, ft_strlen(input->token));
	write(2, "'\n", 2);
	free(input->token);
	input->token = NULL;
	return (fail);
}
