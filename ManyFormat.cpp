#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

const int SCREEN_W = 920;
const int SCREEN_H = 540;

SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gDisplay = NULL;

void mainLoop();
bool init();
SDL_Surface* loadSurface(std::string);
bool loadMedia();
void close();

int main(int argc, char* args[])
{
	if(!init())
	{
		printf("Unable to initialize! SDL Error: %s\n", SDL_GetError());
	}
	else
	{
		if(!loadMedia())
		{
			printf("Unable to load media! SDL Error: %s\n", SDL_GetError());
		}
		else
		{
			mainLoop();
		}
	}
	return 0;
}

void mainLoop()
{
	bool quit = false;
	SDL_Event e;
	while(!quit)
	{
		while(SDL_PollEvent(&e))
		{
			if(e.type == SDL_QUIT)
			{
				quit = true;
			}
		}
		SDL_BlitSurface(gDisplay, NULL, gScreenSurface, NULL);
		SDL_UpdateWindowSurface(gWindow);
	}
}

bool init()
{
	bool success = true;

	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Failed to initialize SDL! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		gWindow = SDL_CreateWindow("PNG Load Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_W, SCREEN_H, SDL_WINDOW_SHOWN);
		if(gWindow == NULL)
		{
			printf("Failed to create window! %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			int imgFlags = IMG_INIT_PNG;
			if(!(IMG_Init(imgFlags) & imgFlags))
			{
				printf("Failed to initialize SDL_image! SDL_image Error %s\n", IMG_GetError());
				success = false;
			}
			else
			{
				gScreenSurface = SDL_GetWindowSurface(gWindow);
			}
		}
	}
	return success;
}

SDL_Surface* loadSurface(std::string path)
{
	SDL_Surface* optimizedSurface = NULL;
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if(loadedSurface == NULL)
	{
		printf("Failed to load image at %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		optimizedSurface = SDL_ConvertSurface(loadedSurface, gScreenSurface->format, 0); //Last argument is for compatibility and is ignored.
		if(optimizedSurface == NULL)
		{
			printf("Failed to optmize image loaded from %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
		}
		SDL_FreeSurface(loadedSurface);
	}
	return optimizedSurface; //Remeber, this is a pointer and thus does not cause a memroy leak.
}

bool loadMedia()
{
	bool success = true;
	gDisplay = loadSurface("pngTest.png");
	if(gDisplay == NULL)
	{
		printf("Failed to load pngTest! SDL_image Error: %s\n", IMG_GetError());
		success = false;
	}
	return success;
}

void close()
{
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	SDL_FreeSurface(gDisplay);
	gDisplay = NULL;

	IMG_Quit();
	SDL_Quit();
}
