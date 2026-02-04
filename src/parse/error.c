/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomin <mcomin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 01:46:10 by mcomin            #+#    #+#             */
/*   Updated: 2026/02/04 04:10:59 by mcomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int is_empty_or_spaces(char *input)
{
    int i;

    i = 0;
    if (!input[i] || input[i] == '\0')
        return (1);
    else if (input[i] == ' ')
    {
        while (input[i] == ' ')
            i++;
        if (input[i] == '\0')
            return (1);
    }
    return (0);
}

int check_quotes(char *input)
{
    int i;
    char quotes;
    
    i = 0;
    quotes = 0;
    while(input[i])
    {
        if (input[i] == '\'' && !quotes)
            quotes = input[i];
        else if (input[i] == '\'' && quotes == '\'')
            quotes = 0; 
        else if (input[i] == '\"' && !quotes)
            quotes = input[i];
        else if (input[i] == '\"' && quotes == '\"')
            quotes = 0;
        i++; 
    }
    if (quotes)
        return (1);
    return (0);
}

int check_pipes(char *input)
{
    int i;
    int save;

    i = 0;
    save = i;
    while(input[i])
    {
        if(input[i] == '|')
        {
            save = i;
            while (i >= 0)
            {
                if(input[i] != ' ' || input[i] != '\t')
                    break ;
                if (i == 0)
                    return (1);
                i--; 
            }
            i = save;
            while (input[i])
            {
                if(input[i] != ' ' || input[i] != '\t')
                    break ;
                if (i == 0)
                    return (1);
                i++; 
            }
        }   
        i++;
    }
}

int check_syntax(char *input)
{
    if (check_quotes)
        return (1);
    if (check_pipes)
        return (1);
    return (0);
}
