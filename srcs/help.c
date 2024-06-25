#include "../include/Malagasy_Independent_day.h"

void	help_command(void)
{
	char *commands[9] = {
		"help",
		"izazaho",
		"fafao",
		"sanginsangy",
		"grademe",
		"tantara",
		"hira",
		"faneva",
		"veloma"
	};

	printf("Available commands :\n");
	for(int i = 0; i < 8; ++i)
		printf("- %s\n", commands[i]);
}
