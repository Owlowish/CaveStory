#include "Input.h"


/*
 * IMPLEMENT KEYBOARD
 *
 *
 */



Input::Input()
{

}

Input::~Input()
{

}


   // ***************************************
   //            PUBLIC FUNCTIONS
   //****************************************


// function called in the begin of each frame to reset the keys no
//longer relevant

void Input::beginNewFrame()
{
    m_releasedKeys.clear();
    m_pressedKeys.clear();
}

//called when a key is pressed
void Input::keyDownEvent(const SDL_Event &event)
{
    this->m_pressedKeys [event.key.keysym.scancode] = true;
    this->m_heldKeys[event.key.keysym.scancode] = true;
}


//this get's called when the key is released

void Input::keyUpEvent(const SDL_Event &event)
{
    this ->m_releasedKeys[event.key.keysym.scancode] = true ;
    this ->m_heldKeys[event.key.keysym.scancode] = false;
}

//check if a key is pressed
bool Input::wasKeyPressed(SDL_Scancode key)
{
    return this->m_pressedKeys[key];
}

bool Input::wasKeyReleased (SDL_Scancode key)
{
    return this->m_releasedKeys[key];
}

bool Input::isKeyHeld(SDL_Scancode key)
{
    return this->m_heldKeys[key];
}



//
//        bool wasKeyPressed(SDL_Scancode key);
//        bool wasKeyReleased(SDL_Scancode key);
//        bool isKeyHeld(SDL_Scancode key);
