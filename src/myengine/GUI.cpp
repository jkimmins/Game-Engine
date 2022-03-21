#include "GUI.h"

namespace myengine
{
	void GUI::setColour(SDL_Renderer* _renderer, int _red, int _green, int _blue, int _alpha)
	{
		SDL_SetRenderDrawColor(_renderer, _red, _green, _blue, _alpha);
	}
	void GUI::drawEmptyRect(SDL_Renderer* _renderer, int _x, int _y, int _w, int _h)
	{
		SDL_Rect rect;
		rect.x = _x;
		rect.y = _y;
		rect.w = _w;
		rect.h = _h;

		SDL_RenderDrawRect(_renderer, &rect);
	}
	void GUI::drawFilledRect(SDL_Renderer* _renderer, int _x, int _y, int _w, int _h)
	{
		SDL_Rect rect;
		rect.x = _x;
		rect.y = _y;
		rect.w = _w;
		rect.h = _h;

		SDL_RenderFillRect(_renderer, &rect);
	}
	/*
	void GUI::drawMessage(SDL_Renderer * _renderer, TTF_Font * _font, SDL_Color _colour, const char * _text, int _x, int _y, int _w, int _h)
	{
		SDL_Surface* surfaceMessage = TTF_RenderText_Solid(_font, _text, _colour);
		SDL_Texture* message = SDL_CreateTextureFromSurface(_renderer, surfaceMessage);
		SDL_Rect rect;
		rect.x = _x;
		rect.y = _y;
		rect.w = _w;
		rect.h = _h;

		SDL_RenderCopy(_renderer, message, NULL, &rect);
		SDL_FreeSurface(surfaceMessage);
		SDL_DestroyTexture(message);
	}
	*/
}







