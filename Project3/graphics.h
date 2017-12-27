#pragma once
#ifndef GRAPHICS_H_
#define GRAPHICS_H_

struct SDL_Window;
struct SDL_Surface;
struct SDL_Rect;
struct SDL_Renderer;
struct SDL_Texture;
struct Sprite;

struct Graphics {
	Graphics();
	~Graphics();
	void renderCopy(SDL_Texture* source,
		SDL_Rect* source_rect,
		SDL_Rect* destination_rect);
	SDL_Window* getWindow();
	SDL_Surface* getSurface();
	SDL_Renderer* getRenderer();
	void clear();
	void draw(Sprite& sprite);
	void update();
private:
	SDL_Window* window_;
	SDL_Surface* surface_;
	SDL_Renderer* renderer_;
};

#endif