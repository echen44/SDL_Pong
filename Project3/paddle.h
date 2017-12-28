#pragma once
#ifndef PADDLE_H_
#define PADDLE_H_
#include <string>
#include <memory>
#include "SDL.h"
#include "sprite.h"

//collision rect and sprite rect are the same

struct Sprite;

struct Paddle {
	Paddle(Sprite& sprite, int x, int y, int w, int h);
	~Paddle();
	int getPaddleHeight();
	int getPaddleWidth();
	int getPaddleX();
	int getPaddleY();
private:
	std::shared_ptr<Sprite> sprite;
protected:
	//use a seperate rect for collisions for future skeletons
	SDL_Rect collision_rect;
};

#endif
