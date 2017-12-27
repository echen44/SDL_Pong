#include "game.h"
#include "SDL.h"
#include "iostream"
#include "graphics.h"
#include "sprite.h"

namespace {
	const int FPS = 60;
}

int TileSize = 32;

Game::Game() {
	SDL_Init(SDL_INIT_EVERYTHING);
	eventLoop();
}
 
Game::~Game() {
	SDL_Quit();
}

void Game::eventLoop() {
	Graphics graphics;
	SDL_Event event;
	Sprite sprite("content/MyChar.bmp", 0, 0, TileSize, TileSize, graphics);
	SDL_SetRenderDrawColor(graphics.getRenderer(), 0x0, 0x0, 0x0, 0x0);
	bool running = true;
	while (running) {
		const int start_time_ms = SDL_GetTicks();
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
				case SDL_KEYDOWN:
					if (event.key.keysym.sym == SDLK_ESCAPE) {
						running = false;
					}
					if (event.key.keysym.sym == SDLK_l) {
					}
					break;
				default:
					break;
			}
		}
		clear(graphics);
		draw(graphics, sprite);
		update(graphics);
		const int elapsed_time_ms = SDL_GetTicks() - start_time_ms;
		SDL_Delay(1000 / FPS - elapsed_time_ms);
		const float seconds_per_frame = (SDL_GetTicks() - start_time_ms) / 1000.0;
		std::cout << (1 / seconds_per_frame) << "\n";
	}
	//while runnings ~ 60 hz
	//handle input handle timer callbacks

	//update player move projectiles check collisions
	//draw() draw everything
}

void Game::clear(Graphics& graphics) {
	graphics.clear();
}

void Game::draw(Graphics& graphics, Sprite& sprite) {
	sprite.draw(graphics, 0, 0);
}

void Game::update(Graphics& graphics) {
	graphics.update();
}