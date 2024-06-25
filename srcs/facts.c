#include "../include/Malagasy_Independent_day.h"

char	*FACTS[FACTS_LEN] = {
	"It’s the world’s fourth largest island Discounting continental landmasses such as Australia, Madagascar is the world’s fourth-largest island after Greenland, New Guinea and Bornéo",
	"From 1828 to 1861, Madagascar was ruled by Queen Ranavalona I. A brutal and controversial leader, she repeatedly repelled French and European advances on Madagascar but also persecuted Christians, neighboring kingdoms and political rivals.",
	"It’s paradise for wildlife lovers According to Conservation International, just 17 countries are considered megadiverse. Each possesses a vast number\
	of different species  many found nowhere else. And Madagascar, thanks largely to being undisturbed by humans for so very long, is one. Among its resident \
	animals are more than half the world’s chameleons and dozens of species of lemur",
	"Madagascar is a former French colony. The French arrived in force during the 1880s. In 1947 they suppressed an armed rebellion killing thousands.",
	"The flag of Madagascar was adopted in 1958. The white represents purity, the red symbolizes sovereignty, and the green denotes the coastal regions\
	and expresses hope.",
	"5% of all the world’s known animal and plant species can be found in Madagascar. Furthermore, it’s home to the second-highest number of endangered mammals in the world.",
	"Approximately 92% of Madagascar’s mammals, 89% of its plant life and 95% of its reptiles cannot be found anywhere else on Earth.",
	"Following a vote for autonomy in 1958, Madagascar gained independence from France in 1960. Philibert Tsiranana became their first president.",
	"Madagascar’s most famous animal is the lemur. There are at least 100 species and subspecies of lemur in Madagascar",
	"One of the most iconic sights in Madagascar is Allée des Baobabs (Avenue of the Baobabs), a 2km natural avenue lined with baobab trees. The trees are \
	known as renala – ‘mother of the forest’ – in Malagasy.",
	"Moraingy is a traditional martial art of Madagascar. The bare-knuckle fighting sport takes place in outdoor rings between two opponents.",
	"Madagascar is regularly struck by tropical storms. The worst of which was Gafilo, a cyclone that killed more than 300 people in Madagascar in 2004. Cyclone Enawo hit in 2017 killing at least 80."
};

void	random_fact()
{
	int	random_num;

	srand(time(NULL));
	random_num = rand() % FACTS_LEN;
	printf("%s\n", FACTS[random_num]);
}

