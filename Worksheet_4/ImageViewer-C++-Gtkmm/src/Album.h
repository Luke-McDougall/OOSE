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
        void add_image(ImageInterface *img);
        void init_iterator();
        ImageInterface *get_image();
        void next_image();
        void prev_image();
        
    private:
        // all fields are value objects and will be freed when Album is freed.
        std::vector<ImageInterface*> images;
        std::vector<ImageInterface*>::iterator current;
        std::vector<ImageInterface*>::iterator first;
        std::vector<ImageInterface*>::iterator last;
};

#endif
