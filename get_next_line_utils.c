/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chabrune <charlesbrunet51220@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:21:50 by chabrune          #+#    #+#             */
/*   Updated: 2022/11/25 17:43:07 by chabrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *strchr(char *s, int c)
    int i
    i = 0
    
    if c = /0
        return &s ft_strlen de s
     while s de i diff de /0
         if s de i == c
            return s de i 
         i++
     return 0

int	ft_strlen(const char *str)
{
    int i;

    i = 0;
    while(str[i])
        i++;
    return(i);
}

char *strjoin (char s1 char s2)
    int i
    int j
    char *str
    
    j = 0
    i = 0
    
    if !s1
        malloc sizeof char * 1
        s1 de 0 = /0
    if !s1 et !s2
        return NULL
    str = malloc ft strlen de s1 et s2 + 1
    if (!str)
        return NULL
     while s1 de i
        str de i = s1 de i
        i++
     while s2 de i
     str de i = s2 de c
     i++
     c++
     str de ft strlen de s1 + s2 = /0
     return str
     
