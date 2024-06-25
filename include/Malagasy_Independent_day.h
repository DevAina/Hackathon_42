#ifndef MALAGASY_INDEPENDENT_DAY_H
# define MALAGASY_INDEPENDENT_DAY_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include "raudio.h"
# include <sys/types.h>
# include <sys/wait.h>

#define RIDDLE_LEN 9
#define JOKE_LEN 8
#define MAX_LINE 1024

#define LEGEND_LEN 5 
#define FACTS_LEN 12

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define RESET "\033[0m"

void	random_riddle();
void	random_joke();
void 	playsound(char *str);
void	hymne(void);
void	random_legends(void);
void	help_command();
void	random_joke(void);
void 	fireworks();
#endif
