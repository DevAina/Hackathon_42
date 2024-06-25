# include "../include/Malagasy_Independent_day.h"

char *Riddle[RIDDLE_LEN] = {
	" Qu’est-ce qui a un corps mais deux têtes?",
	"Plus on en enlève, plus il grandit, qu’est-ce que c’est?",
	"Inona ary izany ? Hano aho ihinanako anao",
	"Que suis-je ? Mange moi et je te mangerai en retour",
	"Inona ary izany ? Elo be tsy mipika",
	"Que suis-je ? Le grand parapluie qui ne se ferme pas",
	"Que suis-je ? Je marche à quatre pattes le matin, à deux le midi et à trois le soir…",
	"Inona ary izany ? maraina aho mandady, atoandro aho mandeha tongotra, ary ny ariva aho mandringa",
	"Qu'est-ce qui peut remplir une pièce entière sans prendre de place ?"
};

char	*riddle_answers[RIDDLE_LEN] = {
	"Pain",
	"Trou",
	"Sakay",
	"Piment",
	"Lanitra",
	"Ciel",
	"Homme",
	"Olombelona",
	"Lumiere"
};

char	*Joke[RIDDLE_LEN] = {
	" Quel est le contraire d’un cochon triste ?",
	"Qu'est-ce que fait une fraise sur un cheval ?",
	"Qu'est-ce qu'un canif ?",
	"Une tortue dit à un renard : - « Je suis sûre que je peux te battre aux 100 mètres même en démarrant 200 mètres derrière toi ! ». Est-ce possible ?",
	"Pourquoi Harry chuchote-t-il ?",
	"Toto est né un 23 décembre et pourtant il fête son anniversaire en été. Comment est-ce possible ?",
	"Qu’est-ce qu’on peut écraser avec le pied droit mais pas avec le pied gauche ?",
	"Que dit une noisette quand elle tombe à l'eau ?"
};

char	*joke_answers[RIDDLE_LEN] = {
	"Un porc tout gai (un portugais).",
	"Tagada, tagada",
	"Un petit fien",
	"Non, ce n'est pas possible, puisque comme tout le monde le sait, un animal ne parle pas.",
	"Parce que Dumble dort.",
	"Toto habite dans l'hémisphère sud.",
	"Le pied gauche",
	"Je me noix."
};

void	random_riddle()
{
	int					random_num;
	char				answr[MAX_LINE];
	int		count = 2;

	srand(time(NULL));
	random_num = rand() % RIDDLE_LEN;
	printf("%s\n", Riddle[random_num]);
	while (1)
	{
		scanf("%s", answr);
		if (strcmp(answr, riddle_answers[random_num]) == 0)
		{
			system("clear");
			system("./srcs/flag.sh");
			printf("Marina\n");
			return ;
		}
		else if (strcmp(answr, riddle_answers[random_num]) != 0 && count != 0)
		{
			printf( RED "Diso, mbola manana andrana %d ianao\n" RESET, count);
			count--;
		}
		else if (count == 0)
		{
			printf(RED"Resy ianao!! Tsy mahalala ny valiny\n" RESET);
			return ;
		}
	}
}

void	random_joke()
{
	int	random_num;

	srand(time(NULL));
	random_num = rand() % RIDDLE_LEN;
	printf("%s\n", Joke[random_num]);
	sleep(15);
	printf("%s\n", joke_answers[random_num]);
}
