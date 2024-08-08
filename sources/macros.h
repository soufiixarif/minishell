/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kelmounj <kelmounj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:00:34 by kelmounj          #+#    #+#             */
/*   Updated: 2024/08/08 17:00:49 by kelmounj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_ERRNO_H
#define MY_ERRNO_H

#define ENOENT  2   // No such file or directory

// Define other error codes as needed
#define EACCES  13  // Permission denied
#define EINVAL  22  // Invalid argument
#define ENOMEM  12  // Out of memory

// Add more error codes as required by your project

extern int errno;  // Declare errno as an external variable

#endif // MY_ERRNO_H

