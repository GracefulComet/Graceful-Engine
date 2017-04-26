//
// Creator:: Randall/ Randy Bresaw(handle GracefulComet)
//
// Please Add your name befor you commit   :)
// Contributers::
//
//
//
//
#pragma once
#include "Game.h"
#include <SDL2/SDL.h>
#include <iostream>
#include <vector>

class InputHandler {
public:
  static InputHandler *Instance() {
    if (s_Instance == 0) {
      s_Instance = new InputHandler();
      return s_Instance;
    } else {
      return s_Instance;
    }
  }

  InputHandler();

  ~InputHandler();

  void InitialiseJoysticks();

  bool JoysticksInitialised() { return m_bJoysticksInitialised; }

  void GrabInput(); //



  void Listen(SDL_Event event); //  outputs the last button/axis pressed/moved

  void update(SDL_Event event);

  void clean();

private:
  static InputHandler *s_Instance;

  std::vector<SDL_Joystick *> m_joysticks;
  bool m_bJoysticksInitialised;
};
typedef InputHandler TheInputHandler;
