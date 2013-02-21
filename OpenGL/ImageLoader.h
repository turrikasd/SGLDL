ifndef IMAGE_LOADER_H
#define IMAGE_LOADER_H

class image
{
public:
	Image(char* ps, int w, int h);
	~image();

	char* pixels;
	int width;
	int height;
};

//Image* loadBMP(const char* filename);

#endif