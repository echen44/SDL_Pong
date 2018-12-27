#include "graphics.h"
#include "SDL.h"
#include "game.h"
#include <iostream>

struct Sprite;
const int screenWidth = 640;
const int screenHeight = 480;

Graphics::Graphics(){
	window_ = SDL_CreateWindow(
		"gaem",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		screenWidth,
		screenHeight,
		SDL_WINDOW_RESIZABLE
	);
	surface_ = SDL_GetWindowSurface(window_);
	renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
}

Graphics::~Graphics(){
	SDL_FreeSurface(surface_);
	SDL_DestroyWindow(window_);
}

void Graphics::renderCopy(SDL_Texture* source,
	SDL_Rect* source_rect,
	SDL_Rect* destination_rect){
	SDL_RenderCopy(renderer_, source, source_rect, destination_rect);
}

SDL_Window* Graphics::getWindow(){
	return window_;
}
SDL_Surface* Graphics::getSurface(){
	return surface_;
}

SDL_Renderer* Graphics::getRenderer(){
	return renderer_;
}

void Graphics::clear(){
	SDL_RenderClear(renderer_);
}
void Graphics::draw(Sprite& sprite){

}
void Graphics::update(){
	SDL_RenderPresent(renderer_);
}