/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaulas- <fpaulas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 06:16:20 by fpaulas-          #+#    #+#             */
/*   Updated: 2024/07/26 06:16:34 by fpaulas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int count_words(char *str, char c)
{
    int count = 0;
    int i = 0;

    while (str[i])
    {
        while (str[i] && str[i] == c)
            i++;
        if (str[i])
            count++;
        while (str[i] && str[i] != c)
            i++;
    }
    return (count);
}

static char *get_word(char *str, char c)
{
    int len = 0;
    char *word;

    while (str[len] && str[len] != c)
        len++;
    word = (char *)malloc(sizeof(char) * (len + 1));
    if (!word)
        return (NULL);
    len = 0;
    while (str[len] && str[len] != c)
    {
        word[len] = str[len];
        len++;
    }
    word[len] = '\0';
    return (word);
}

char **ft_split(char *str, char c)
{
    char **split;
    int i = 0;
    int words = count_words(str, c);

    split = (char **)malloc(sizeof(char *) * (words + 1));
    if (!split)
        return (NULL);
    while (*str)
    {
        while (*str && *str == c)
            str++;
        if (*str)
            split[i++] = get_word(str, c);
        while (*str && *str != c)
            str++;
    }
    split[i] = NULL;
    return (split);
}
