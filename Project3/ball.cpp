#include "ball.h"

Ball::Ball(Graphics& graphics, int x, int y, int w, int h) {
	this->sprite = std::make_shared<Sprite>("content/ball.bmp", 0, 0, TileSize, TileSize, graphics);
	collision_rect.x = x;
	collision_rect.y = y;
	collision_rect.w = w;
	collision_rect.h = h;
}

Ball::~Ball() {
}

int Ball::getBallHeight() {
	return collision_rect.h;
}

int Ball::getBallWidth() {
	return collision_rect.w;
}

int Ball::getBallX() {
	return collision_rect.x;
}

int Ball::getBallY() {
	return collision_rect.y;
}

int Ball::getBallXSpeed() {
	return x_speed;
}

int Ball::getBallYSpeed() {
	return y_speed;
}

bool Ball::collidesWith(std::shared_ptr<Paddle> paddle) {
	//calculate sides
	int ball_left = collision_rect.x;
	int ball_top = collision_rect.y;
	int ball_right = collision_rect.x + collision_rect.w;
	int ball_bottom = collision_rect.y + collision_rect.h;

	int paddle_left = paddle->collision_rect.x;
	int paddle_top = paddle->collision_rect.y;
	int paddle_right = paddle->collision_rect.x + paddle->collision_rect.w;
	int paddle_bottom = paddle->collision_rect.y + paddle->collision_rect.h;

	//If any of the sides from ball are outside of paddle
	if (ball_bottom <= paddle_top) {
		return false;
	}

	if (ball_top >= paddle_bottom) {
		return false;
	}

	if (ball_right <= paddle_left) {
		return false;
	}

	if (ball_left >= paddle_right) {
		return false;
	}

	//If none of the sides from ball are outside paddle
	return true;
}

void Ball::draw(Graphics& graphics, int x, int y) {
	sprite->draw(graphics, x, y);
}