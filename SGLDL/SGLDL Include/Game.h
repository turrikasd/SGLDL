#ifndef GAME_H
#define GAME_H

#include "stdafx.h"

class Game
{
public:
	__declspec(dllexport) Game();
	__declspec(dllexport) ~Game();

	__declspec(dllexport) virtual void Initialize(int argc, char* argv[], Game* game);
	__declspec(dllexport) virtual void LoadContent();
	__declspec(dllexport) virtual void Update();
	__declspec(dllexport) virtual void Draw2D();
	__declspec(dllexport) virtual void Draw3D();

	__declspec(dllexport) void SetWindowWidth(int width);
	__declspec(dllexport) void SetWindowHeight(int height);
	__declspec(dllexport) int GetWindowWidth();
	__declspec(dllexport) int GetWindowHeight();

protected:
	int windowWidth;
	int windowHeight;
private:
};

#endif