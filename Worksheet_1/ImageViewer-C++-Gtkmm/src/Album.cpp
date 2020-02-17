#include "Album.h"

Album::Album() 
{
    // *** Insert initialisation code here (if needed) ***
    images = std::vector<Image*>();
}

Album::~Album()
{
    // *** Insert destructor code here (if needed) ***
    images.~vector();
}

// *** Insert your method definitions here for Album ***
void Album::add_image(Image *img)
{
    images.push_back(img);
}

void Album::init_iterator()
{
    first = images.begin();
    last = --images.end();
    current = first;
}

Image *Album::get_image()
{
    return *current;
}

void Album::next_image()
{
    if(current < last)
    {
        current++;
    }
}

void Album::prev_image()
{
    if(current > first)
    {
        current--;
    }
}
