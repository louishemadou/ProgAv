#include "quadtree/quadtree.h"
#include <Imagine/Graphics.h>
using namespace Imagine;
#include <iostream>
using namespace std;
#include "colorimage.h"

// ColorImage methods //

ColorImage::ColorImage(byte *red, byte *green, byte *blue, int width, int height){
    w = width;
    h = height;
    r = new byte[w*h];
    g = new byte[w*h];
    b = new byte[w*h];
    for(int k=0; k<w*h; k++){
        r[k] = red[k];
        g[k] = green[k];
        b[k] = blue[k];
    }
}

ColorImage::~ColorImage(){
    delete [] r;
    delete [] g;
    delete [] b;
}

int ColorImage::width() const{
    return w;
}

int ColorImage::height() const{
    return h;
}

Color ColorImage::operator ()(int i, int j) const{
    return Color(r[i*w+j], g[i*w+j], b[i*w+j]);
}

void ColorImage::display() const{
    putColorImage(IntPoint2(0,0), r, g, b, w, h);
}

// usefull functions for encoding //

bool all_trees_are_leaves(QuadTree<Color>* qn[4]){
    int compt = 0;
    for(int i=0; i<4; i++){
        if(qn[i]->isLeaf())
            compt++;
    }
    return compt == 4;
}

bool leaves_colors_are_close(QuadTree<Color>* qt[4], int width, int height, int region_size){
    double a = -12./((double) max(width, height));
    double b = 75.;
    double x = (double) region_size;
    double threshold = a*x+b; // linear threshold
    double min[3] = {qt[0]->value().r()-threshold, qt[0]->value().g()-threshold, qt[0]->value().b()-threshold};
    double max[3] = {qt[0]->value().r()+threshold, qt[0]->value().g()+threshold, qt[0]->value().b()+threshold};
    for(int i=0; i<3; i++){ // for all colors
        for(int j=1; j<4; j++){ // for all leaves
           if(qt[j]->value()[i]<min[i] || qt[j]->value()[i]>max[i])
                return false;
        }
    }
    return true;
}

// encode //

QuadTree<Color>* color_encode_recursif(const ColorImage & im, int i0, int j0, int current_size){
    if(current_size==1){
        if(i0<im.height() && j0<im.width())
            return new QuadLeaf<Color>(im(i0,j0));
        else
            return new QuadLeaf<Color>(Color(0, 0, 0));
    }
    current_size = current_size/2;
    QuadTree<Color>* qt[4] = {color_encode_recursif(im, i0, j0, current_size),
                              color_encode_recursif(im, i0, j0+current_size, current_size),
                              color_encode_recursif(im, i0+current_size, j0+current_size, current_size),
                              color_encode_recursif(im, i0+current_size, j0, current_size)};
    if(all_trees_are_leaves(qt) && leaves_colors_are_close(qt, im.width(), im.height(), current_size)){
        if(i0<im.height() && j0<im.width()){
            int r_value = 0;
            int g_value = 0;
            int b_value = 0;
            for(int i=0; i<4; i++){
                r_value += qt[i]->value().r()/4; // mean value of each color component
                g_value += qt[i]->value().g()/4;
                b_value += qt[i]->value().b()/4;
            }
            return new QuadLeaf<Color>(Color(r_value, g_value, b_value));
        }
        else
            return new QuadLeaf<Color>(Color(255,255,255));
    }
    return new QuadNode<Color>(qt);
}

QuadTree<Color>* color_encode(const ColorImage & im){
    int i0 = 0;
    int j0 = 0;
    int N=0;
    int max_size = max(im.width(), im.height());
    while(pow(2,N)<max_size)
        N++;
    return color_encode_recursif(im, i0, j0, pow(2,N));
}

// decode //

void color_decode_recursif(QuadTree<Color>* qt, byte* red, byte* green, byte* blue, int i0, int j0, int current_size, int width, int height){
    QuadTree<Color>* sons[4] = {qt->son(NW), qt->son(NE), qt->son(SE), qt->son(SW)};
    current_size = current_size/2;
    int i0_values[4] = {i0, i0, i0+current_size, i0+current_size};
    int j0_values[4] = {j0, j0+current_size, j0+current_size, j0};
    for(int k=0; k<4; k++){
        QuadTree<Color>* son = sons[k];
        if(son->isLeaf()){
            for(int i=i0_values[k]; i<i0_values[k]+current_size; i++){
                for(int j=j0_values[k]; j<j0_values[k]+current_size; j++){
                    if(i<height && j<width){
                        red[i*width+j] = (int) son->value().r();
                        green[i*width+j] = (int) son->value().g();
                        blue[i*width+j] = (int) son->value().b();
                    }
                }
            }
        }
        else
            color_decode_recursif(son, red, green, blue, i0_values[k], j0_values[k], current_size, width, height);
    }
}

ColorImage color_decode(QuadTree<Color>* qt, int width, int height){
    byte* red = new byte[width*height];
    byte* green = new byte[width*height];
    byte* blue = new byte[width*height];
    int N=0;
    int max_size = max(width, height);
    while(pow(2,N)<max_size)
        N++;
    color_decode_recursif(qt, red, green, blue, 0, 0, pow(2,N), width, height);
    return ColorImage(red, green, blue, width, height);
}
