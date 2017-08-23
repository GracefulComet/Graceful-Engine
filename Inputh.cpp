//
// Creator:: Randall/ Randy Bresaw(handle GracefulComet)
//
// Please Add your name befor you commit   :)
// Contributers::
//
//
//
//
#include "Inputh.h"

InputHandler *InputHandler::s_Instance = 0;

InputHandler::InputHandler() {
  if (SDL_WasInit(SDL_INIT_JOYSTICK) == 0) {
    SDL_InitSubSystem(SDL_INIT_JOYSTICK);
  }
}

void InputHandler::InitialiseJoysticks() {
  if (SDL_NumJoysticks() > 0) {
    for (int i = 0; i < SDL_NumJoysticks(); i++) {
      SDL_Joystick *joy = SDL_JoystickOpen(i);

      if (SDL_JoystickGetAttached(joy)) {
        m_joysticks.push_back(joy);
        if (SDL_JoystickGetAttached(m_joysticks[i])) {
          std::cout << "Opened Joystick " << i << std::endl;

          std::cout << "Name Of Joystick" << SDL_JoystickNameForIndex(i)
                    << std::endl;

          std::cout << "Number of Axies " << SDL_JoystickNumAxes(joy)
                    << std::endl;

          std::cout << "Number of Buttons " << SDL_JoystickNumButtons(joy)
                    << std::endl;

          printf("Number of Balls: %d\n", SDL_JoystickNumBalls(joy));
        } else {
          printf("Couldn't open Joystick 0\n");
        }
      } else {
        std::cout << SDL_GetError();
      }
    }
    SDL_JoystickEventState(SDL_ENABLE);
    m_bJoysticksInitialised = true;
    std::cout << " Initialised " << m_joysticks.size() << "joystick(s)";
  } else {
    m_bJoysticksInitialised = false;
  }
}

void InputHandler::clean() {
  if (m_bJoysticksInitialised) {
    for (int i = 0; i < SDL_NumJoysticks(); i++) {
      SDL_JoystickClose(m_joysticks[i]);
    }
  }
}

void InputHandler::GrabInput() {}

// REmove this later please
void InputHandler::Listen(SDL_Event event) {
  while (SDL_PollEvent(&event) >= 0) {
    if (event.type == SDL_JOYAXISMOTION) {
      if (event.jaxis.which >= 0) {
        std::cout << "axis " << (int)event.jaxis.axis << "is moving"
                  << std::endl;
      }
    }

    if (event.type == SDL_JOYBUTTONDOWN) {

      if (event.jbutton.which >= 0) {
        std::cout << "Button " << (int)event.jbutton.button << " was pressed"
                  << std::endl;
        break;
      }
    }

    if (event.type == SDL_JOYHATMOTION) {
      if (event.jhat.which >= 0) {
        std::cout << "Pad " << (int)event.jhat.value << "was pressed"
                  << std::endl;
      }
    }
    break;
  }
}

void InputHandler::update(SDL_Event event) { Listen(event); }
