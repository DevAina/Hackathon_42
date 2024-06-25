
#include "raudio.h"             // raudio library

#include <stdio.h>              // Required for: printf()
#include <time.h>               // Required for: clock()

#if defined(_WIN32)
    #include <conio.h>          // Windows only, no stardard library
#else
    // Required for kbhit() function in non-Windows platforms
    #include <stdio.h>
    #include <termios.h>
    #include <unistd.h>
    #include <fcntl.h>
#endif

#define KEY_ESCAPE  27

//----------------------------------------------------------------------------------
// Module Functions Declaration
//----------------------------------------------------------------------------------
static void WaitTime(int ms);       // Simple time wait in milliseconds
static void PlayWaveCLI(Wave wave); // Play provided wave through CLI
#if !defined(_WIN32)
static int kbhit(void);             // Check if a key has been pressed
static char getch();                // Get pressed character
#endif

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
void playsound(char *str)
{
    Wave wave = LoadWave(str);  // Load audio (WAV, OGG, FLAC, MP3)
    PlayWaveCLI(wave);              // Play loaded audio
    UnloadWave(wave);               // Unload audio data    }
}

//----------------------------------------------------------------------------------
// Module Functions Definition
//----------------------------------------------------------------------------------

// Simple time wait in milliseconds
static void WaitTime(int ms)
{
    if (ms > 0)
    {
        int currentTime = clock()*1000/CLOCKS_PER_SEC;  // Current time in milliseconds
        int totalTime = currentTime + ms;               // Total required time in ms to return from this timeout

        //int percent = 0;
        //int prevPercent = percent;

        // Wait until current ms time matches total ms time
        while (currentTime <= totalTime)
        {
            // Check for key pressed to stop playing
            if (kbhit())
            {
                int key = getch();
                if ((key == 13) || (key == 27)) break;    // KEY_ENTER || KEY_ESCAPE
            }

            currentTime = clock()*1000/CLOCKS_PER_SEC;
        }
    }
}

// Play provided wave through CLI
static void PlayWaveCLI(Wave wave)
{
    float waveTimeMs = (float)wave.frameCount*1000.0/(wave.sampleRate*wave.channels);

    InitAudioDevice();                  // Init audio device
    Sound fx = LoadSoundFromWave(wave); // Load audio wave

    printf("Playing sound [%.2f sec.]. Press ESC to finish.\n", waveTimeMs/1000.0f);

    PlaySound(fx);                      // Play sound
    WaitTime(waveTimeMs);               // Wait while audio is playing
    UnloadSound(fx);                    // Unload sound data
    CloseAudioDevice();                 // Close audio device
}

#if !defined(_WIN32)
// Check if a key has been pressed
static int kbhit(void)
{
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF)
    {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

// Get pressed character
static char getch() { return getchar(); }
#endif
