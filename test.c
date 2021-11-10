#include <SDL2/SDL.h>
#include <stdio.h>

int main() {
    SDL_Init(SDL_INIT_VIDEO);
    printf("SDL2 initialized successfully!\n");
    SDL_Quit();
    return 0;
}

