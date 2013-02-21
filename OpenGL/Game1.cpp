#include "stdafx.h"
#include <iostream>

float rotation = 0.0f;

void Game1::Initialize(int argc, char* argv[])
{
	Game::Initialize(argc, argv, this); // Call base class
}

void Game1::LoadContent()
{
	sgSetClearColor(Color::SkyBlue());

	Game::LoadContent(); // Call base class
}

void Game1::Update()
{
	rotation += 0.5f;
	Game::Update(); // Call base class
}

void Game1::Draw2D()
{
	//sgDrawSquare(Vector3(1.0f, 0, 0), 1.0f, Color::Black());
}

void Game1::Draw3D()
{
	sgDrawSquare(Vector3::Zero(), Texture2D("kebab.bmp"));

	//sgDrawSquare(Vector3(-0.5f, 0.0f, 0.0f), Quaternion(rotation, 0.0f, 1.0f, 0.0f), 0.5f, Color::Black());
	//sgDrawTriangle(Vector3(0.0f, 0.0f, 0.0f));
}