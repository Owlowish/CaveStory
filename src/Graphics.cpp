#include "Graphics.h"
#include <SDL2/SDL.h>


/*
 * GRAPHICS CLASS
 *
 * Holds all informations dealing with graphics for the game
 *
 * RESOLUTION : 640x480
*/

Graphics::Graphics()
{
    SDL_CreateWindowAndRenderer(640,480,0,&this->m_window,&this->m_renderer);   //window initilization
    SDL_SetWindowTitle(this->m_window,"CaveStory dev");                         //title
}

Graphics::~Graphics()
{
    SDL_DestroyWindow(this->m_window);
}
