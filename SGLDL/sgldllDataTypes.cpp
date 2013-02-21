#include "stdafx.h"

Texture2D::Texture2D(const char* source)
{
	Image* image = loadBMP(source);
	id = sgLoadTexture(image);
	delete image;
}