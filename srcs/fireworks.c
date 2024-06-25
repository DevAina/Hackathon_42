#include "../include/Malagasy_Independent_day.h"

// Définir la taille de l'écran
#define WIDTH 40
#define HEIGHT 20

void clear_screen() {
    printf("\033[H\033[J");
}

void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y + 1, x + 1);
}

void draw_firework(int x, int y) {
    const char *explosion[] = {
        "   .   ",
        "  .*.  ",
        " .*o*. ",
        "  .*.  ",
        "   .   "
    };

    int explosion_size = sizeof(explosion) / sizeof(explosion[0]);

    for (int i = 0; i < explosion_size; ++i) {
        gotoxy(x - 3, y - 2 + i);
        printf("%s", explosion[i]);
    }
}

void draw_sparkles(int x, int y) {
    const char *sparkles[] = {
        " *   * ",
        "   *   ",
        " *   * "
    };

    int sparkles_size = sizeof(sparkles) / sizeof(sparkles[0]);

    for (int i = 0; i < sparkles_size; ++i) {
        gotoxy(x - 3, y - 1 + i);
        printf("%s", sparkles[i]);
    }
}

void animate_fireworks() {
    while (1) {
        int x = rand() % (WIDTH - 6) + 3;
        int y = rand() % (HEIGHT - 4) + 2;

        clear_screen();
        gotoxy(x, y);
        printf("|");
        fflush(stdout);
        usleep(300000);

        clear_screen();
        draw_firework(x, y);
        fflush(stdout);
        usleep(500000);

        clear_screen();
        draw_sparkles(x, y);
        fflush(stdout);
        usleep(300000);
    }
}

void fireworks() {
    printf("ok");
    srand(time(NULL));
    clear_screen();
    animate_fireworks();
    printf("Felicitation");   
}