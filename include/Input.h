#ifndef INPUT_H
#define INPUT_H
#include <map>
#include <SDL2/SDL.h>


class Input
{
    public:
        Input();
        virtual ~Input();

        // ***************************************
        //            PUBLIC FUNCTIONS
        //****************************************

        void beginNewFrame();
        void keyUpEvent(const SDL_Event &event);
        void keyDownEvent(const SDL_Event &event);

        bool wasKeyPressed(SDL_Scancode key);
        bool wasKeyReleased(SDL_Scancode key);
        bool isKeyHeld(SDL_Scancode key);

    protected:

    private:

        // ***************************************
        //               PRIVATE VARIABLE
        //****************************************

        std::map <SDL_Scancode,bool> m_heldKeys;
        std::map <SDL_Scancode,bool> m_pressedKeys;
        std::map <SDL_Scancode,bool> m_releasedKeys;
};

#endif // INPUT_H
