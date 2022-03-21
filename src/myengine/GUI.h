#include "SDL2/SDL.h"
//#include "SDL2/SDL_ttf.h"

namespace myengine
{
	struct Core;

	struct GUI
	{
		void setColour(SDL_Renderer* _renderer, int _red, int _green, int _blue, int _alpha);
		void drawEmptyRect(SDL_Renderer* _renderer, int _x, int _y, int _w, int _h);
		void drawFilledRect(SDL_Renderer* _renderer, int _x, int _y, int _w, int _h);
		//void drawMessage(SDL_Renderer* _renderer, TTF_Font* _font, SDL_Color _colour, const char* _text, int _x, int _y, int _w, int _h);
	};
}