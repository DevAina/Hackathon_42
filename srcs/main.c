#include "../include/Malagasy_Independent_day.h"

int	joke_count = 0;

void	clear_command(void)
{
	system("clear");
}

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
	system("./srcs/flag.sh");
	printf("Use the " GREEN"'grademe' " RESET "command to be graded, or " GREEN"'help'" RESET" to get some help.\n");
	while (1)
	{
		printf("independentshell> ");
		scanf("%s", command);
		if (strcmp(command, "fafao") == 0)
			clear_command();
		else if (strcmp(command, "izazaho") == 0)
			whoami_command();
		else if (strcmp(command, "sangisangy") == 0)
			give_me_a_joke_command();
		else if (strcmp(command, "exit") == 0 || strcmp(command, "quit") == 0)
			printf("Say goodbye in Malagasy to quit please\n");
		else if (strcmp(command, "veloma") == 0)
			break ;
		else if (strcmp(command, "grademe") == 0)
			random_riddle();
		else if (strcmp(command, "hira") == 0)
			playsound("./srcs/hymme.mp3");
		else if (strcmp(command, "tantara") == 0)
			random_legends();
		else if (strcmp(command, "help") == 0)
			help_command();
		else if (strcmp(command, "faneva") == 0)
			hymne();
		else
			help_command();
	}
}
