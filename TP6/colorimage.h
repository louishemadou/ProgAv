#pragma once
#include <Imagine/Graphics.h>
using namespace Imagine;

class ColorImage{
    byte* r;
    byte* g;
    byte* b;
    int w;
    int h;
public:
    int width() const;
    int height() const;
    Color operator ()(int i, int j) const;
    ColorImage(byte* r, byte* g, byte* b, int width, int height);
    ~ColorImage();
    void display() const;
};

QuadTree<Color>* color_encode(const ColorImage & im);

ColorImage color_decode(QuadTree<Color>* qt, int width, int height);
