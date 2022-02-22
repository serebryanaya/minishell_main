/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <pveeta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 20:44:38 by pveeta            #+#    #+#             */
/*   Updated: 2022/02/20 19:46:25 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static inline t_status	check_quotes(t_input *input, char *str)
{
	U_INT	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			if (go_to_end_quote(str, &i, str[i], input) == fail)
				return (fail);
		}
		else
			i++;
	}
	return (success);
}

t_status	finder(char *str_command, t_input *input) // сейчас тут только проверка на то, \
// что строка не начинается пайпом
{
    U_INT i;

    i = 0;
    if (check_quotes(input, str_command) == fail)
		return (fail);
	while (str_command[i] == ' ')
		i++;
    if (str_command[i] == '|')
    {
        if (str_command[i + 1] && str_command[i + 1] == '|')
            input->token = modif_strdup("||", input);
        else
            input->token = modif_strdup("|", input);
        return (print_token(input));
    }
	// while (str_command[i] && str_command[i] != '|')
	// 	i++;
	// if (!str_command[i])
	// 	return (fail);
    return (success);
}