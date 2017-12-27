#include "sprite.h"
#include "graphics.h"
#include "SDL.h"

Sprite::Sprite(const std::string file_path,
	int source_x,
	int source_y,
	int width,
	int height,
	Graphics& graphics
) {
	SDL_Surface* sprite_sheet_surface = SDL_LoadBMP(file_path.c_str());

	// Color key the surface before making it a texture
	SDL_SetColorKey(sprite_sheet_surface, SDL_TRUE, SDL_MapRGB(sprite_sheet_surface->format, 0, 0, 0));
	//
	sprite_sheet_ = SDL_CreateTextureFromSurface(graphics.getRenderer(), sprite_sheet_surface);
	SDL_FreeSurface(sprite_sheet_surface);
	source_rect.x = source_x;
	source_rect.y = source_y;
	source_rect.w = width;
	source_rect.h = height;
}

Sprite::~Sprite() {
	SDL_DestroyTexture(sprite_sheet_);
}

void Sprite::draw(Graphics& graphics, int x, int y) {
	SDL_Rect dest_rect;
	dest_rect.x = x;
	dest_rect.y = y;
	dest_rect.w = source_rect.w;
	dest_rect.h = source_rect.h;
	graphics.renderCopy(sprite_sheet_, &source_rect, &dest_rect);
}