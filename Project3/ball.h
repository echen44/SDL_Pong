#pragma once
#ifndef BALL_H_
#define BALL_H_
#include <string>
#include <memory>
#include "SDL.h"
#include "sprite.h"
#include "paddle.h"

//collision rect and sprite rect are the same

struct Sprite;

struct Ball {
	Ball(Graphics& graphics, int x, int y, int w, int h);
	~Ball();
	int getBallHeight();
	int getBallWidth();
	int getBallX();
	int getBallY();
	int getBallXSpeed();
	int getBallYSpeed();
	bool collidesWith(std::shared_ptr<Paddle> paddle);
	SDL_Rect collision_rect;
	int x_speed;
	int y_speed;
	void draw(Graphics& graphics, int x, int y);
private:
	std::shared_ptr<Sprite> sprite;
protected:
	//use a seperate rect for collisions for future skeletons
	
	
};

#endif // !BALL_H_
