#include "game.h"
#include "SDL.h"
#include "iostream"
#include "graphics.h"
#include "sprite.h"
#include "paddle.h"
#include "ball.h"

namespace {
	const int FPS = 60;
}

int player1x = 0;
const int screenWidth = 640;
const int screenHeight = 480;
int player1y = (screenHeight / 2) - (paddleHeight / 2);
int player2x = screenWidth - paddleWidth;
int player2y = (screenHeight / 2) - (paddleHeight / 2);
int ballx;
int bally;

Game::Game() {
	SDL_Init(SDL_INIT_EVERYTHING);
	
	
	eventLoop();
}
 
Game::~Game() {
	SDL_Quit();
}

void Game::eventLoop() {
	SDL_Event event;
	Graphics graphics;
	player1 = std::make_shared<Paddle>(graphics, player1x, player1y, 20, 80);
	player2 = std::make_shared<Paddle>(graphics, player2x, player2y, 20, 80);
	ball = std::make_shared<Ball>(graphics, 0, 0, 32, 32);
	reset_ball();
	ball->x_speed = 5;
	ball->y_speed = 3;
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
					break;
				default:
					break;
			}

		}
		const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
		if (currentKeyStates[SDL_SCANCODE_W]) {
			player1y -= 10;
			if (player1y < 0) {
				player1y = 0;
			}
		}
		else if (currentKeyStates[SDL_SCANCODE_S]) {
			player1y += 10;
			if (player1y > (screenHeight - paddleHeight)) {
				player1y = screenHeight - paddleHeight;
			}
		}/*
		if (currentKeyStates[SDL_SCANCODE_A]) {
			player1x -= 10;
		}
		else if (currentKeyStates[SDL_SCANCODE_D]) {
			player1x += 10;
		}*/

		if (currentKeyStates[SDL_SCANCODE_I]) {
			player2y -= 10;
			if (player2y < 0) {
				player2y = 0;
			}
		}
		else if (currentKeyStates[SDL_SCANCODE_K]) {
			player2y += 10;
			if (player2y > (screenHeight - paddleHeight)) {
				player2y = screenHeight - paddleHeight;
			}
		}
		/*if (currentKeyStates[SDL_SCANCODE_J]) {
			player2x -= 10;
		}
		else if (currentKeyStates[SDL_SCANCODE_L]) {
			player2x += 10;
		}*/
		player1->collision_rect.x = player1x;
		player1->collision_rect.y = player1y;
		player2->collision_rect.x = player2x;
		player2->collision_rect.y = player2y;

		//move ball colliders
		//move x
		ball->collision_rect.x += ball->getBallXSpeed();
		if (ball->collision_rect.x < 0 || ball->collision_rect.x + ball->collision_rect.w > screenWidth) {
			//score
			reset_ball();
		}
		//paddle collide
		else if (ball->collidesWith(player1)){
			if (ball->x_speed > 0) {
				if (player1->getPaddleX() < ball->getBallX()) {
					ball->x_speed++;
				}
				else {
					ball->x_speed *= -1;
				}
			}
			else {
				if (player1->getPaddleX() < ball->getBallX()) {
					ball->x_speed *= -1;
				}
				else {
					ball->x_speed++;
				}
			}
		}
		else if (ball->collidesWith(player2)) {
			if (ball->x_speed > 0) {
				if (player2->getPaddleX() < ball->getBallX()) {
					ball->x_speed++;
				}
				else {
					ball->x_speed *= -1;
				}
			}
			else {
				if (player2->getPaddleX() < ball->getBallX()) {
					ball->x_speed *= -1;
				}
				else {
					ball->x_speed++;
				}
			}
		}
		
		//move y
		ball->collision_rect.y += ball->getBallYSpeed();
		if (ball->collision_rect.y < 0 || ball->collision_rect.y + ball->collision_rect.h > screenHeight) {
			//while (ball->collidesWith(player1) || ball->collidesWith(player2) || ball->collision_rect.y < 0 || ball->collision_rect.y + ball->collision_rect.h > screenHeight) {
			//	ball->collision_rect.y -= ball->getBallYSpeed();
			//	//ball->y_speed *= -1;
			//}
			ball->y_speed *= -1;
		}
		

		ballx = ball->collision_rect.x;
		bally = ball->collision_rect.y;

		clear(graphics);

		draw(graphics, player1x, player1y, player2x, player2y);
		update(graphics);
		const int elapsed_time_ms = SDL_GetTicks() - start_time_ms;
		SDL_Delay(1000 / FPS - elapsed_time_ms);
		const float seconds_per_frame = (SDL_GetTicks() - start_time_ms) / 1000.0;
		//std::cout << (1 / seconds_per_frame) << "\n";
		std::cout << ball->getBallXSpeed() << "\n";
	}
	//while runnings ~ 60 hz
	//handle input handle timer callbacks

	//update player move projectiles check collisions
	//draw() draw everything
}

void Game::clear(Graphics& graphics) {
	graphics.clear();
}

void Game::draw(Graphics& graphics, int player1x, int player1y, int player2x, int player2y) {
	player1->draw(graphics, player1x, player1y);
	player2->draw(graphics, player2x, player2y);
	ball->draw(graphics, ballx, bally);
}

void Game::update(Graphics& graphics) {
	graphics.update();
}

void Game::reset_ball() {
	ballx = (screenWidth / 2) - ball->getBallWidth();
	bally = (screenHeight / 2) - ball->getBallHeight();
	ball->collision_rect.x = (screenWidth / 2) - ball->getBallWidth();
	ball->collision_rect.y = (screenHeight / 2) - ball->getBallHeight();
}