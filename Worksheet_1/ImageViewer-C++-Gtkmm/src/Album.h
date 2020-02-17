/*
 * Represents a collection of image metadata.
 */

#ifndef ALBUM_H
#define	ALBUM_H

#include "Image.h"
#include <vector>

class Album 
{
    public:
        Album();
        ~Album();
        // *** Insert your declarations here. ***
        void add_image(Image *img);
        void init_iterator();
        Image *get_image();
        void next_image();
        void prev_image();
        
    private:
        // *** Insert your declarations here. ***
        std::vector<Image*> images;
        std::vector<Image*>::iterator current;
        std::vector<Image*>::iterator first;
        std::vector<Image*>::iterator last;
};

#endif
