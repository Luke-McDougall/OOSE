#include "Album.h"

Album::Album() 
{
    // I don't know if this would also work c++ has weird syntax sometimes
    // std::vector<Image> images();
    images = std::vector<Image>();
}

Album::~Album()
{
    // *** Insert destructor code here (if needed) ***
}

// *** Insert your method definitions here for Album ***
void Album::add_image(Image img)
{
    images.push_back(img);
}

// Initializes the iterators. Must be called after all images have been loaded.
void Album::init_iterator()
{
    first = images.begin();
    last = --images.end();
    current = first;
}

// Returns the image currently pointed to be the current iterator
Image Album::get_image()
{
    return *current;
}

// Makes the current iterator point to the next Image in the images vector
// unless it's already pointing to the last Image.
void Album::next_image()
{
    if(current < last)
    {
        current++;
    }
}

// Makes the current iterator point to the previous Image in the images vector
// unless it's already pointing to the first Image.
void Album::prev_image()
{
    if(current > first)
    {
        current--;
    }
}
