class ImageData
{
public:
    ImageData(int width, int height);
    ~ImageData();
    void setPixel(int x, int y, int value);
    int getPixel(int x, int y);
    int get_width();
    int get_height();
private:
    int *image;
    int width;
    int height;
};

class ImageTransformation
{
public:
    ImageData *transform(ImageData *old_image);
    virtual int new_width(ImageData *old);
    virtual int new_height(ImageData *old);
    virtual int new_pixel(ImageData *old, int x, int y);
};

class ImageScale : public ImageTransformation
{
public:
    int new_width(ImageData *old);
    int new_height(ImageData *old);
    int new_pixel(ImageData *old, int x, int y);
};

class ImageInvert : public ImageTransformation
{
public:
    int new_width(ImageData *old);
    int new_height(ImageData *old);
    int new_pixel(ImageData *old, int x, int y);
};

class ImageRotate : public ImageTransformation
{
public:
    int new_width(ImageData *old);
    int new_height(ImageData *old);
    int new_pixel(ImageData *old, int x, int y);
};
