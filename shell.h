#ifdef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* for read/write buffers */

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for command chaining */
#define CMD_NORM	0
#define CMD_OR			1
#define CMD_AND			2
#define CMD_CHAIN	3

/* for convert number() */

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2


