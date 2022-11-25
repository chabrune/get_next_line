/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chabrune <charlesbrunet51220@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:18:43 by chabrune          #+#    #+#             */
/*   Updated: 2022/11/25 17:43:02 by chabrune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{   
    char        *line;
    static char *stash;

    
    // 1. read from fd and add to linked list
    read_and_stash(fd, &stash);
    // 2. extract from stash to line
    // 3. clean up stash   

}

/* Uses read() to add characters to the stash */

void	read_and_stash(int fd, char *stash)
{
    int readed;
    char *buf;

    readed = 1;
    while(!found_newline(stash) && readed != 0)
    {
        buf = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1));
        if(!buf)
            return;
        readed = (int)read(fd, buf, BUFFER_SIZE);
    }

}
/* Adds the content of our buffer to the end of our stash */

void	add_to_stash()

/* Extracts all characters from our stash and stores them in out line.
 * stopping after the first \n it encounters */

void	extract_line()
{
    
}

/* After extracting the line that was read, we don't need those characters
 * anymore. This function clears the stash so only the characters that have
 * not been returned at the end of get_next_line remain in our static stash. */
