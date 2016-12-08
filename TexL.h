#pragma once
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <string>
#include <map>

class TexL {
       public:
	static TexL* Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new TexL();
			return s_pInstance;
		} else {
			return s_pInstance;
		}
	}

	TexL() {
		int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
		if (IMG_Init(imgFlags) != imgFlags) {
			IMG_GetError();
		}
	}

	~TexL();

	bool load(std::string filename, std::string id, SDL_Renderer* pRender);
	void draw(std::string id, int x, int y, int width, int height,
		  SDL_Renderer* pRender, SDL_RendererFlip flip);
	void drawFrame(std::string id, int x, int y, int width, int height,
		       int currentRow, int currentFrame, SDL_Renderer* pRender,
		       SDL_RendererFlip flip);

       private:
	static TexL* s_pInstance;
	std::map<std::string, SDL_Texture*> m_textureMap;
};
typedef TexL TheTextureManager;
