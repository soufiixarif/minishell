/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:52:33 by kelmounj          #+#    #+#             */
/*   Updated: 2024/07/16 13:55:48 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	int fd;
	
	fd = open("hmrabet", O_RDWR | O_CREAT, 0777);
	printf("%d\n", fd);
	// close(fd);
	fd = open("hmrabet", O_RDWR | O_CREAT, 0777);
	printf("%d\n", fd);
}