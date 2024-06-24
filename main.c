#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define JOKES_LEN 5
char	*JOKES[JOKES_LEN] = {
	"Jokes 1",
	"Jokes 2",
	"Jokes 3",
	"Jokes 4",
	"Jokes 5"
};

int	joke_count = 0;

void	random_joke()
{
	int	random_num;

	srand(time(NULL));
	random_num = rand() % JOKES_LEN;
	printf("%s\n", JOKES[random_num]);
}

void	clear_command(void)
{
	system("clear");
}

void	grademe_command(void)
{}

void	help_command(void)
{}

void	give_me_a_joke_command()
{
	joke_count++;
	if (joke_count <= 3)
	{
		printf("Am I a joke to you?\n You can repeat, maybe the joke will appear\n");
	}
	else
		random_joke();
}

void	whoami_command()
{
	printf("%s\n", getenv("USER"));
}

int	main(void)
{
	char	command[1024];

	system("clear");
	system("./flag.sh");
	while (1)
	{
		printf("examshell> ");
		scanf("%s", command);
		if (strcmp(command, "clear") == 0)
			clear_command();
		else if (strcmp(command, "whoami") == 0)
			whoami_command();
		else if (strcmp(command, "give_me_joke") == 0)
			give_me_a_joke_command();
		else if (strcmp(command, "exit") == 0 || strcmp(command, "quit") == 0)
			printf("Say goodbye in Malagasy to quit please\n");
		else if (strcmp(command, "veloma") == 0)
			break ;
		else
			help_command();
	}
}
