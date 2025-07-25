#include <SDL3/SDL.h>
#include <cstdio>

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }
    printf("SDL_Init succeeded.\n");
    SDL_Quit();
    return 0;
}
