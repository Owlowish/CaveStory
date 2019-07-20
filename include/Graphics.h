#ifndef GRAPHICS_H
#define GRAPHICS_H

//***************************
//  FORWARD IMPLENMENTATION
//***************************

struct SDL_Window;
struct SDL_Renderer;


class Graphics
{
    public:
        Graphics();
        virtual ~Graphics();

    protected:

    private:
        //******************************************
        //         PRIVATE VARIABLES
        //******************************************

        SDL_Window* m_window;
        SDL_Renderer* m_renderer;

};

#endif // GRAPHICS_H
