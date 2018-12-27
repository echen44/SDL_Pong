#pragma once
#ifndef SPRITE_H_
#define SPRITE_H_

#include "string"
#include "SDL.h"
#include "game.h"

struct Graphics;

struct Sprite {
	Sprite(const std::string file_path,
		int source_x,
		int source_y,
		int width,
		int height,
		Graphics& graphics
	);

	~Sprite();

	void draw(Graphics& graphics, int x, int y);
private:
	SDL_Texture* sprite_sheet_;
	SDL_Rect source_rect;
};

#endif
