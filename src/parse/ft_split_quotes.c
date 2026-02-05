/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcomin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 07:37:34 by mcomin            #+#    #+#             */
/*   Updated: 2026/02/05 07:37:39 by mcomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int is_in_quotes(char const *s, size_t pos)
{
    size_t  i;
    int     in_quote;

    i = 0;
    in_quote = 0;

    while (i < pos)
    {
        if (s[i] == '"')
            in_quote = !in_quote;
        i++;
    }

    return (in_quote);
}

static char **wordsmalloc(char const *s, char c)
{
    char    **str;
    size_t  i;
    size_t  words;
    int     in_word;

    i = 0;
    words = 0;
    in_word = 0;

    while (s[i])
    {
        if (!in_word && s[i] != c)
        {
            words++;
            in_word = 1;
        }
        else if (in_word && s[i] == c && !is_in_quotes(s, i))
        {
            in_word = 0;
        }
        i++;
    }
    str = calloc(words + 1, sizeof(char *));
    if (!str)
        return (NULL);
    return (str);
}

static char **fill(char const *s, char **str, char c)
{
    size_t  beg;
    size_t  end;
    size_t  i;

    end = 0;
    i = 0;
    while (s[end])
    {
        while (s[end] == c && !is_in_quotes(s, end))
            end++;
        beg = end;
        while (s[end] != '\0')
        {
            if (s[end] == c && !is_in_quotes(s, end))
                break;
            end++;
        }

        if (end > beg)
        {
            str[i] = ft_substr(s, beg, end - beg);
            if (!str[i])
                return (NULL);
            i++;
        }
    }
    str[i] = 0;
    return (str);
}

char **ft_split_quotes(char const *s, char c)
{
    size_t  i;
    char    **str;

    i = 0;
    if (!s)
        return (NULL);

    str = wordsmalloc(s, c);
    if (!str)
        return (NULL);

    if (!fill(s, str, c))
    {
        while (str[i])
        {
            free(str[i]);
            i++;
        }
        free(str);
        str = NULL;
    }

    return (str);
}
