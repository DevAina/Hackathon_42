#include "../include/Malagasy_Independent_day.h"

void clear_screen() {
    printf("\033[H\033[J");
}

void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y + 1, x + 1);
}

void typewriter_effect(const char *text, int x, int y) {
    gotoxy(x, y);
    printf("     ");
    for (size_t i = 0; i < strlen(text); i++) {
        printf("%c", text[i]);
        fflush(stdout);
        usleep(100000); // Vitesse de l'effet machine à écrire (100 ms par caractère)
    }
}

void draw_ascii_art(int frame) {
    const char *art1[] = {
        "   /\\",
        "  /  \\",
        " /    \\",
        "/______\\",
        "|      |",
        "|  []  |",
        "|      |"
    };

    const char *art2[] = {
        "   /\\",
        "  /  \\",
        " / ** \\",
        "/******\\",
        "| **** |",
        "|  []  |",
        "| **** |"
    };

    int art_size = sizeof(art1) / sizeof(art1[0]);

    for (int i = 0; i < art_size; ++i) {
        gotoxy(25, 5 + i);
        if (frame % 2 == 0) {
            printf("\n%s", art1[i]);
        } else {
            printf("\n%s", art2[i]);
        }
    }
}

void animate_hymne() {
    const char *lines[] = {
        "Ry Tanindrazanay malala o",
        "Ry Madagasikara soa",
        "Ny fitiavanay anao tsy miala",
        "Fa ho anao, ho anao doria tokoa",
        "Tahionao ry Zanahary",
        "'Ty Nosindrazanay ity",
        "Hiadana sy ho finaritra",
        "He sambatra tokoa izahay",
        "Ry Tanindrazanay malala ô",
        "Irinay mba hanompoana anao",
        "Ny tena sy fo fanahy anananay",
        "‘zay sarobidy sy mendrika tokoa.",
        "Refrain",
        "Ry Tanindrazanay malala ô",
        "Irinay mba hitahiana anao,",
        "Ka ilay Nahary izao tontolo izao",
        "No fototra ijoroan'ny satanao"
    };

    int num_lines = sizeof(lines) / sizeof(lines[0]);

    clear_screen();
    for (int i = 0; i < num_lines; i++) {
        typewriter_effect(lines[i], 5, i + 5);
        draw_ascii_art(i);
        //draw_music_notes(i);
        usleep(500000);
        if (getchar() == ' ')
        {
            return ;
        }
    }
}

void hymne()
{
    clear_screen();
    printf(CYAN "Press" RED"'q'" CYAN "to quit" RESET);
    animate_hymne();
}