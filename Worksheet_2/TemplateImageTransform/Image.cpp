#include "Image.hpp"
#include "stdlib.h"

/* Implementation of ImageData class */
ImageData::ImageData(int width, int height)
{
    this->width = width;
    this->height = height;
    this->image = (int*)malloc(sizeof(int) * width * height);
}

ImageData::~ImageData()
{
    free(this->image);
}

void ImageData::setPixel(int x, int y, int value)
{
    this->image[x + this->width * y] = value;
}

int ImageData::getPixel(int x, int y)
{
    return this->image[x + this->width * y];
}

int ImageData::get_width()
{
    return this->width;
}

int ImageData::get_height()
{
    return this->height;
}
/* End ImageData */



/* Implementation of ImageTransformation class */
ImageData *ImageTransformation::transform(ImageData *old)
{
    int new_width = this->new_width(old);
    int new_height = this->new_height(old);
    auto new_image = new ImageData(new_width, new_height);

    for(int y = 0; y < new_height; ++y)
    {
	for(int x = 0; x < new_width; ++x)
	{
	    new_image->setPixel(x, y, this->new_pixel(old, x, y));
	}
    }
    return new_image;
}
/* End ImageTransformation */



/* Implementation of ImageInvert class */
int ImageInvert::new_width(ImageData *old)
{
    return old->get_width();
}

int ImageInvert::new_height(ImageData *old)
{
    return old->get_height();
}

int ImageInvert::new_pixel(ImageData *old, int x, int y)
{
    return ~old->getPixel(x, y);
}
/* End ImageInvert */



/* Implementation of ImageRotate class */
int ImageRotate::new_width(ImageData *old)
{
    return old->get_width();
}

int ImageRotate::new_height(ImageData *old)
{
    return old->get_height();
}

int ImageRotate::new_pixel(ImageData *old, int x, int y)
{
    return old->getPixel(this->new_height(old) - y, x);
}
/* End ImageRotate */



/* Implementation of ImageScale class */
int ImageScale::new_width(ImageData *old)
{
    return old->get_width() / 2;
}

int ImageScale::new_height(ImageData *old)
{
    return old->get_height() / 2;
}

int ImageScale::new_pixel(ImageData *old, int x, int y)
{
    return old->getPixel(2 * x, 2 * y);
}
/* End ImageScale */
