//
// Creator:: Randall/ Randy Bresaw(handle GracefulComet)
//
// Please Add your name befor you commit   :)
// Contributers::
//
//
//
//
#include "TexL.h"

TexL::~TexL() {}

TexL *TexL::s_pInstance = 0;

bool TexL::load(std::string filename, std::string id, SDL_Renderer *pRender) {
  SDL_Surface *pTempSurface = IMG_Load(filename.c_str());

  if (pTempSurface == 0) {
    return false;
  }

  SDL_Texture *pTexture = SDL_CreateTextureFromSurface(pRender, pTempSurface);

  SDL_FreeSurface(pTempSurface);

  if (pTexture != 0) {
    m_textureMap[id] = pTexture;
    return true;
  }

  return false;
}

void TexL::draw(std::string id, int x, int y, int width, int height,
                SDL_Renderer *pRender, SDL_RendererFlip flip) {
  SDL_Rect srcRect;
  SDL_Rect destRect;
  srcRect.x = 0;
  srcRect.y = 0;
  srcRect.w = destRect.w = width;
  srcRect.h = destRect.h = height;
  destRect.x = x;
  destRect.y = y;
  SDL_RenderCopyEx(pRender, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}

void TexL::drawFrame(std::string id, int x, int y, int width, int height,
                     int currentRow, int currentCol, SDL_Renderer *pRender,
                     SDL_RendererFlip flip) {
  SDL_Rect srcRect;
  SDL_Rect destRect;
  srcRect.y = currentRow * width;
  srcRect.x = height * currentCol;
  srcRect.w = destRect.w = width;
  srcRect.h = destRect.h = height;
  destRect.x = x;
  destRect.y = y;
  SDL_RenderCopyEx(pRender, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}
void TexL::LoadWErrorChecking(std::string filename, std::string id,
                              SDL_Renderer *pRender) {
  this->load(filename, id, pRender);
  if (this->load(filename, id, pRender) == true) {
    std::cout << "loaded " << filename << std::endl;
  } else {
    std::cout << "Failed to load " << filename << std::endl;
  }
}
