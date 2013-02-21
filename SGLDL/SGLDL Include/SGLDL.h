#ifndef SGLDL_H
#define SGLDL_H

#include "../stdafx.h"

#include "bmploader.h"
#include "sgldlDataTypes.h"
#include "Game.h"

__declspec(dllexport) void sgInit(int argc, char* argv[], int width, int height, Game* game);
__declspec(dllexport) void sgStartMainLoop();
__declspec(dllexport) void sgClearToGLProjection();
void InitRendering();
void sgUpdate(int value);
void DrawScene();
void HandleKeypress(unsigned char key, int x, int y);
void HandleResize(int w, int h);

__declspec(dllexport) GLuint sgLoadTexture(Image* image);

__declspec(dllexport) void sgDrawTriangle(Vector3 position);
__declspec(dllexport) void sgDrawSquare(Vector3 position, Quaternion rotation, float scale, Color color);
__declspec(dllexport) void sgDrawSquare(Vector3 position, Texture2D texture);
__declspec(dllexport) void sgSetClearColor(Color color);

#endif