#pragma once
#ifndef GAME_H_
#define GAME_H_

struct Graphics;

struct Sprite;

struct Game {
	Game();
	~Game();
private:
	void eventLoop();
	void update(Graphics& graphics);
	void draw(Graphics& graphics, Sprite& sprite);
	void clear(Graphics& graphics);

};

#endif