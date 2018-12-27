#pragma once
#ifndef PADDLE_H_
#define PADDLE_H_
#include <string>
#include <memory>

#include "SDL.h"
#include "sprite.h"

//collision rect and sprite rect are the same

struct Sprite;

const int paddleHeight = 80;
const int paddleWidth = 20;

struct Paddle {
	Paddle(Graphics& graphics, int x, int y, int w, int h);
	~Paddle();
	int getPaddleHeight();
	int getPaddleWidth();
	int getPaddleX();
	int getPaddleY();
	void draw(Graphics& graphics, int x, int y);
	//use a seperate rect for collisions for future skeletons
	SDL_Rect collision_rect;
private:
	std::shared_ptr<Sprite> sprite;
};

#endif
