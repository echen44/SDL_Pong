#include "paddle.h"

Paddle::Paddle(Sprite& sprite, int x, int y, int w, int h) {
	this->sprite = std::make_shared<Sprite>(sprite);
	collision_rect.x = x;
	collision_rect.y = y;
	collision_rect.w = w;
	collision_rect.h = h;
}

Paddle::~Paddle() {
}

int Paddle::getPaddleHeight() {
	return collision_rect.h;
}

int Paddle::getPaddleWidth() {
	return collision_rect.w;
}

int Paddle::getPaddleX() {
	return collision_rect.x;
}

int Paddle::getPaddleY() {
	return collision_rect.y;
}