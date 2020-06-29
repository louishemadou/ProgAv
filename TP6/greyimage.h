#pragma once
#include <Imagine/Graphics.h>
using namespace Imagine;

class Image{
    byte* t;
    int w;
    int h;
public:
    int width() const;
    int height() const;
    int operator ()(int i, int j) const;
    Image(byte* t, int width, int height);
    ~Image();
    void display() const;
};

QuadTree<int>* encode(const Image &image);

Image decode(QuadTree<int>* qt, int width, int height);

void display_with_squares(QuadTree<int>* qt, int width, int height, int min_size);
