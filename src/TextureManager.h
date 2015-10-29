#ifndef __TEXTUREMANAGER__
#define __TEXTUREMANAGER__

#include <string>
#include <map>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class TextureManager 
{
 public:  

  ~TextureManager() {}; 
  bool load(std::string fileName, std::string id,
	    SDL_Renderer* pRenderer);
  void draw(std::string id, int x, int y, int width, int
	    height, SDL_Renderer* pRenderer, 
	    SDL_RendererFlip flip = SDL_FLIP_NONE);
  void drawFrame(std::string id, int x, int y, int width, int
		 height, int currentRow, int currentFrame, SDL_Renderer*
		 pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
  std::map<std::string, SDL_Texture*> m_textureMap; 
  static TextureManager* Instance()
  {
    if(TextureManager::s_pInstance == 0)
      {
	TextureManager::s_pInstance = new TextureManager();
	return TextureManager::s_pInstance;
      }
    return TextureManager::s_pInstance;
  }

 private:
  TextureManager() {};
  static TextureManager* s_pInstance;  

};

typedef TextureManager TheTextureManager;

#endif
  
