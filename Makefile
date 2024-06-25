NAME = malagasy_independent

SRCS = ./srcs/facts.c ./srcs/hymne.c ./srcs/legends.c ./srcs/main.c ./srcs/playsound.c ./srcs/riddle_joke.c ./srcs/help.c

#OBJS = ${SRCS:.c=.o}

#all: ${NAME}
#	cc -Wall -Weror -Wextra -I./raudio/src -Lraylib/lib -lraylib -lm -c $< -o ${<.c=.o}

${NAME}: 
	cc -g ${SRCS} -Wall -Werror -Wextra -I./raudio/src -Lraylib/lib -lraylib -lm  -o ${NAME}

fclean:
	rm -f ${NAME}
	
