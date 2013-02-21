#include "stdafx.h"

Game::Game()
{
	windowWidth = 400;
	windowHeight = 400;
}

Game::~Game()
{
}

void Game::SetWindowWidth(int width)
{
	windowWidth = width;
}

void Game::SetWindowHeight(int height)
{
	windowHeight = height;
}

int Game::GetWindowWidth()
{
	return windowWidth;
}

int Game::GetWindowHeight()
{
	return windowHeight;
}

void Game::Initialize(int argc, char* argv[], Game* game)
{
	sgInit(argc, argv, windowWidth, windowHeight, game);
	LoadContent();
}

void Game::LoadContent()
{
	sgStartMainLoop();
}

void Game::Update()
{
	glutPostRedisplay(); // Tell GLUT the scene has changed
}

void Game::Draw2D()
{
}

void Game::Draw3D()
{
}