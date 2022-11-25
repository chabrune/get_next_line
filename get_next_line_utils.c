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

/* Looks for a newline character in the given linked list. */

int	found_newline(char *stash)
{
    int i;

    i = 0;
    while(stash[i])
    {
        if(stash[i] == "\n")
            return(1);
        i++;
    }
    return(0);
}

/* Calculates the number of chars in the current line, including the trailing
 * \n if there is one, and allocates memory accordingly. */

void	generate_line(char **line, char *stash)
{
    int i;
    int len;

    i = 0;
    len = 0;
    while(stash[i])
    {
        if(stash[i] == '\n')
        {
            len++;
            break;
        }
        i++;
        len++;
    }
    *line = (char*)malloc(sizeof(char) * (len + 1));
}

int	ft_strlen(const char *str)
{
    int i;

    i = 0;
    while(str[i])
        i++;
    return(i);
}