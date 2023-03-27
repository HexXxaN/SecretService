#pragma once
#include <SDL.h>
#include <SDL_image.h>

class WindowRender {
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
public:
	WindowRender(const char* title, int width, int height);
	SDL_Texture* loadTexture(const char* filePath);
	void clear();
	void render(SDL_Texture* texture);
	void display();
	void cleanUp();
};