#ifndef SGLDLDATATYPES_H
#define SGLDLDATATYPES_H

#include "../stdafx.h"

struct __declspec(dllexport) Vector3
{
	float x;
	float y;
	float z;

	Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

	static Vector3 Zero() { return Vector3(0.0f, 0.0f, 0.0f); }
};

struct __declspec(dllexport) Quaternion
{
	float w, x, y, z;

	Quaternion(float w, float x, float y, float z) : w(w), x(x), y(y), z(z) {}

	static Quaternion Zero() { return Quaternion(0.0f, 0.0f, 0.0f, 0.0f); }
};

struct __declspec(dllexport) Color
{
	float r, g, b, a;

	Color(float r, float g, float b, float a) : r(r), g(g), b(b), a(a) {}

	static Color White() {	return Color(1.0f, 1.0f, 1.0f, 1.0f);	}
	static Color Black() {  return Color(0.0f, 0.0f, 0.0f, 1.0f);   }
	static Color Red()   {	return Color(1.0f, 0.0f, 0.0f, 1.0f);	}
	static Color Green() {  return Color(0.0f, 1.0f, 0.0f, 1.0f);   }
	static Color Blue()  {  return Color(0.0f, 0.0f, 1.0f, 1.0f);   }
	static Color SkyBlue(){ return Color(0.7f, 0.9f, 1.0f, 1.0f);   }
};

struct __declspec(dllexport) Texture2D
{
	GLuint id;

	Texture2D(const char* source);
};

#endif