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
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <iostream>
#include <map>
#include <string>

class TexL {
public:
  static TexL *Instance();

  TexL() {
    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if (IMG_Init(imgFlags) != imgFlags) {
      std::cout << IMG_GetError() << std::endl;
    }
  }

  ~TexL();

  bool load(std::string filename, std::string id, SDL_Renderer *pRender);
  void draw(std::string id, int x, int y, int width, int height,
            SDL_Renderer *pRender, SDL_RendererFlip flip);
  void drawFrame(std::string id, int x, int y, int width, int height,
                 int currentRow, int currentFrame, double rotAngle,
                 SDL_Renderer *pRender, SDL_RendererFlip flip);
  //  void drawFrameWRot(std::string id, int x, int y, int width, int height,
  //                 int currentRow, int currentFrame, SDL_Renderer *pRender,
  //                 double angle,SDL_RendererFlip flip);
  void LoadWErrorChecking(std::string filename, std::string id,
                          SDL_Renderer *pRender);

private:
  std::map<std::string, SDL_Texture *> m_textureMap;
  static TexL *s_pInstance;
};

using TheTextureManager = TexL;
