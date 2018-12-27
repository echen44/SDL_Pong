#pragma once
#ifndef GAME_H_
#define GAME_H_
#include <memory>
#include "graphics.h"
struct Graphics;
struct Sprite;
struct Paddle;
struct Ball;

const int TileSize = 32;

struct Game {
	Game();
	~Game();
private:
	std::shared_ptr<Paddle> player1;
	std::shared_ptr<Paddle> player2;
	std::shared_ptr<Ball> ball;
	void eventLoop();
	void update(Graphics& graphics);
	void draw(Graphics& graphics, int player1x, int player1y, int player2x, int player2y);
	void clear(Graphics& graphics);

	void reset_ball();
};

#endif