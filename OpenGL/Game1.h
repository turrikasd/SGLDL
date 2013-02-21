#ifndef GAME1_H
#define GAME1_H

#include "stdafx.h"

class Game1 : Game
{
public:
	void Initialize(int argc, char* argv[]);
	void LoadContent();
	void Update();
	void Draw2D();
	void Draw3D();
};

#endif