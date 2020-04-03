#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Image.h"

String::String(char *str)
{
    this->capacity = this->len = strlen(str) + 1;
    this->ptr = (char*) malloc(sizeof(char) * this->capacity);
    strncpy(this->ptr, str, this->capacity);
}

void String::append(char *str)
{
    size_t str_len = strlen(str);
    if(this->capacity >= (this->len + str_len))
    {
        strncpy(this->ptr + this->len - 1, str, str_len);
        this->len += str_len;
        this->ptr[this->len - 1] = '\0';
    }
    else
    {
        this->capacity = 2 * (this->len + str_len);
        char *new_ptr = (char*) malloc(sizeof(char) * this->capacity);

        strncpy(new_ptr, this->ptr, this->len - 1);
        free(this->ptr);

        this->ptr = new_ptr;
        strncpy(this->ptr + this->len - 1, str, str_len);
        this->len += str_len;
        this->ptr[this->len - 1] = '\0';
    }
}

char *String::c_str()
{
    return this->ptr;
}

void String::free_data()
{
    free(this->ptr);
}

// Image class implementation
Image::Image(char *filename, char *caption)
{
    this->filename = filename;
    this->caption = caption;
}

Image::~Image()
{
    free(filename);
    free(caption);
}

char *Image::get_filename()
{
    return this->filename;
}

String Image::get_caption()
{
    return this->caption;
}
// End Image class

// Date decorator implementation
Date::Date(char *date, ImageInterface *next)
{
    this->date = date;
    this->next = next;
}

Date::~Date()
{
    delete this->next;
    free(date);
}

char *Date::get_filename()
{
    return next->get_filename();
}

String Date::get_caption()
{
    String part = next->get_caption();
    part.append("\n");
    part.append(this->date);

    return part;
}
// End Date class

// GPS decorator implementation
GPS::GPS(int latitude, int longitude, int elevation, ImageInterface *next)
{
    this->latitude = latitude;
    this->longitude = longitude;
    this->elevation = elevation;
    this->next = next;
}

GPS::~GPS()
{
    delete this->next;
}

char *GPS::get_filename()
{
    return next->get_filename();
}

String GPS::get_caption()
{
    char buf[128];
    sprintf(buf, "\nLatitude: %d\nLongitude: %d\nElevation: %d\n",
            this->latitude, this->longitude, this->elevation);
    String part = next->get_caption();
    part.append(buf);
    return part;
}
// End of GPS class

// Implementation of Rating decorator
Rating::Rating(int stars, ImageInterface *next)
{
    this->stars = stars;
    this->next = next;
}

Rating::~Rating()
{
    delete this->next;
}

char *Rating::get_filename()
{
    return next->get_filename();
}

String Rating::get_caption()
{
    String part = next->get_caption();
    char buf[32];
    sprintf(buf, "\nRating: %d stars!\n", this->stars);
    part.append(buf);
    return part;
}
