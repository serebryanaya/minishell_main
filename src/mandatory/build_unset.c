/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_unset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveeta <pveeta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 22:03:53 by pveeta            #+#    #+#             */
/*   Updated: 2022/03/06 21:20:15 by pveeta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int find_key(t_env **env, char *str) //int  ft_check_first(t_env **env, char *str)
{
    t_env   *copy;
    copy = *env;
    if (!ft_strcmp(str, copy->key))
    {
        *env = (*env)->next;
        free(copy->key);
        free(copy->value);
        free(copy);
        return (1);
    }
    return (0);
}

void    remove_env(t_env *env) //void   ft_del_env(t_env *env)
{
    t_env   *copy;
    copy = env->next;
    env->next = copy->next;
    free(copy->key);
    free(copy->value);
    free(copy);
}

U_INT   launch_unset(t_input *input, t_comm *command)
{
    int     i;
    t_env   *copy1;
    t_env   *copy2;

    i = 1;
    while (command->words[i])
    {
        if (!input->envp)
            break ;
        if (!ft_isalpha(command->words[i][0]))
        {
            // printf("command->words[1][0]=%c, command->words[2][0]=%c, command->words[3][0]=%c\n", command->words[1][0], command->words[2][0], command->words[3][0]);
            input->num_error = 1;
            // write(2, "export: `", 9);
            // write(2, input->command->words[i], ft_strlen(input->command->words[i]));
            // write(2, "': not a valid identifier\n", 26);
            printf("%s%s%s\n", "unset: `", command->words[i], "': not a valid identifier");
        }
        if (command->words[i][0] == '_')
            continue ;
        if (find_key(&input->envp, command->words[i]))
            continue ;
        copy1 = input->envp;
        copy2 = copy1->next;
        while (copy2 && ft_strcmp(command->words[i], copy2->key))
        {
            copy1 = copy2;
            copy2 = copy2->next;
        }
        if (copy2)
            remove_env(copy1);
        i++;    
    }
    return (0);
}
