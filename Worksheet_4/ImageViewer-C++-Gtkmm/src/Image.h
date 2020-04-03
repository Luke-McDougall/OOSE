/* 
 * The Image class represents image metadata -- filename and caption.
 */

#ifndef IMAGE_H
#define	IMAGE_H
#include <stdlib.h>

class String
{
public:
    String(char *str);
    void append(char *str);
    char *c_str();
    void free_data();
private:
    char *ptr;
    size_t len;
    size_t capacity;
};

class ImageInterface
{
public:
    virtual char *get_filename() = 0;
    virtual String get_caption() = 0;
};

class Image : public ImageInterface
{
public:
    // Constructor
    Image(char *filename, char *caption);
    ~Image();
    char *get_filename();
    String get_caption();
private:
    char *filename;
    char *caption;
};

class Date : public ImageInterface
{
public:
    Date(char *date, ImageInterface *next);
    ~Date();
    char *get_filename();
    String get_caption();
private:
    char *date;
    ImageInterface *next;
};

class GPS : public ImageInterface
{
public:
    GPS(int latitude, int longitude, int elevation, ImageInterface *next);
    ~GPS();
    char *get_filename();
    String get_caption();
public:
    int latitude;
    int longitude;
    int elevation;
    ImageInterface *next;
};

class Rating : public ImageInterface
{
public:
    Rating(int stars, ImageInterface *next);
    ~Rating();
    char *get_filename();
    String get_caption();
private:
    int stars;
    ImageInterface *next;
};
#endif
