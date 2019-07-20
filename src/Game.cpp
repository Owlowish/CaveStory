#include "Game.h"
#include <SDL2/SDL.h>
#include "Graphics.h"
#include "Input.h"
#include <iostream>


/*
 * CLASS GAME
 *
 * holds all the information of the main game loop
 *
 *
 */


namespace{
    const int FPS = 50;
    const int MAX_FRAME_TIME = 5 * 100/FPS;
}

Game::Game()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    this->gameloop();

}

Game::~Game()
{
    //dtor
}


//******************************************************
//       PRIVATE FUNCTIONS
//*****************************************************


int LAST_UPDATE_TIME = SDL_GetTicks();
//start game loop
void Game::gameloop()
{
    Graphics graphics;
    SDL_Event event;  // manage sdl events
    Input input;

    while(true)
    {
       input.beginNewFrame();

        if (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT) return ;

            if (event.type == SDL_KEYDOWN)
            {
                if (event.key.repeat == 0)  //make sure that the key isn't held down
                {
                    input.keyDownEvent(event);
                }
           }
            else if (event.type == SDL_KEYUP)
            {
                input.keyUpEvent(event);
            }

            if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE)==true) return;

            const int CURRENT_TIME_MS = SDL_GetTicks();
            int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
            this->update(std::min(ELAPSED_TIME_MS,MAX_FRAME_TIME));
            LAST_UPDATE_TIME = CURRENT_TIME_MS;


        }

    }
}

void Game::draw(Graphics &Graphics)
{

}


void Game::update(float elapsedtime)
{

}
