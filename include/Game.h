#ifndef GAME_H
#define GAME_H
#include <map>
#include <string>
#include <SDL2/SDL.h>

class Graphics;


class Game
{
    public:
        Game();
        virtual ~Game();

        //load an image in the spriteshee map, if it doesn't already exist
        //return the image from the map
        SDL_Surface *loadImage(const std::string &filePath);

        //draw a rectangle
        void blitSurface(SDL_Texture *source, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);

        //render everthing to the screen
        void flip();

        //clear screen
        void clear();

        //returns the render
        SDL_Renderer* getRenderer()const;



    protected:

    private:

    //************************************************
    //     PRIVATE FUNCTIONS
    //*************************************************

    void gameloop();
    void draw(Graphics &graphics);
    void update(float elapstime);

    std::map<std::string, SDL_Surface*> m_spriteSheets;

};

#endif // GAME_H
