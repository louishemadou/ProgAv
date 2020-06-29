#include "quadtree/quadtree.h"
#include <Imagine/Graphics.h>
using namespace Imagine;
#include <algorithm>
using namespace std;
#include "greyimage.h"

QuadTree<int>* white = new QuadLeaf<int>(255);
QuadTree<int>* black = new QuadLeaf<int>(0);

// Image methods //

Image::Image(byte *tab, int width, int height){
    w = width;
    h = height;
    t = new byte[w*h];
    for(int k=0; k<w*h; k++){
        t[k] = tab[k];
    }
}

Image::~Image(){
    delete [] t;
}

int Image::width() const{
    return w;
}

int Image::height() const{
    return h;
}

int Image::operator ()(int i, int j) const{
    return (int) t[i*w+j];
}

void Image::display() const{
    putGreyImage(IntPoint2(0,0), t, w, h);
}

// useful functions for encoding //

bool all_trees_are_leaves(QuadTree<int>* qn[4]){
    int compt = 0;
    for(int i=0; i<4; i++){
        if(qn[i]->isLeaf())
            compt++;
    }
    return compt==4;
}

bool all_leaves_are_close(QuadTree<int>* qt[4], int width, int height, int region_size){
    double a = -10./((double) max(width, height));
    double b = 75.;
    double x = (double) region_size;
    double threshold = a*x+b; // linear threshold
    int min = qt[0]->value()-threshold;
    int max = qt[0]->value()+threshold;
    for(int i=1; i<4; i++){
        if(qt[i]->value()<min || qt[i]->value()>max)
            return false;
    }
    return true;

}

// encode //

QuadTree<int>* encode_recursif(const Image & im, int i0, int j0, int current_size){
    if(current_size==1) // Creating leaves
        if(i0<im.height() && j0<im.width()){
            int pixel_value = im(i0, j0);
            if(pixel_value == 0)
                return black;
            if(pixel_value == 255)
                return white;
            return new QuadLeaf<int>(pixel_value); // if the pixel is not white nor black
        }
        else
            return new QuadLeaf<int>(255); // out of boundaries, we return a white pixel
    current_size = current_size/2;
    QuadTree<int>* qt[4] = {encode_recursif(im, i0, j0, current_size),
                            encode_recursif(im, i0, j0+current_size, current_size),
                            encode_recursif(im, i0+current_size, j0+current_size, current_size),
                            encode_recursif(im, i0+current_size, j0, current_size)};
    if(all_trees_are_leaves(qt) && all_leaves_are_close(qt, im.width(), im.height(), current_size))
        if(i0<im.height() && j0<im.width()) // merging leaves
            return new QuadLeaf<int>((qt[0]->value()+qt[1]->value()+qt[2]->value()+qt[3]->value())/4);
        else
            return new QuadLeaf<int>(255);
    return new QuadNode<int>(qt);
}

QuadTree<int>* encode(const Image & im){
    white->protect_leaves_from_destruction = true;
    black->protect_leaves_from_destruction = true;
    int i0 = 0;
    int j0 = 0;
    int N=0;
    int max_size = max(im.width(), im.height());
    while(pow(2,N)<max_size) // looking for the power of 2 just above picture dimensions
        N++;
    return encode_recursif(im, i0, j0, pow(2,N));
}

// decode //

void decode_recursif(QuadTree<int>* qt, byte* pixels, int i0, int j0, int current_size, int width, int height){
    QuadTree<int>* sons[4] = {qt->son(NW), qt->son(NE), qt->son(SE), qt->son(SW)};
    current_size = current_size/2;
    int i0_values[4] = {i0, i0, i0+current_size, i0+current_size};
    int j0_values[4] = {j0, j0+current_size, j0+current_size, j0};
    for(int k=0; k<4; k++){ // browsing node
        QuadTree<int>* son = sons[k];
        if(son->isLeaf()){
            for(int i=i0_values[k]; i<i0_values[k]+current_size; i++){
                for(int j=j0_values[k]; j<j0_values[k]+current_size; j++){
                    if(i<height && j<width)
                        pixels[i*width+j] = (int) son->value();
                }
            }
        }
        else
            decode_recursif(son, pixels, i0_values[k], j0_values[k], current_size, width, height);
    }
}

Image decode(QuadTree<int>* qt, int width, int height){
    byte* pixels = new byte[width*height];
    int N=0;
    int max_size = max(width, height);
    while(pow(2,N)<max_size)
        N++;
    decode_recursif(qt, pixels, 0, 0, pow(2,N), width, height);
    return Image(pixels, width, height);
}

// display picture with squares //

void display_with_squares_recursive(QuadTree<int>* qt, int i0, int j0, int current_size, int width, int height, int min_size){
    QuadTree<int>* sons[4] = {qt->son(NW), qt->son(NE), qt->son(SE), qt->son(SW)};
    current_size = current_size/2;
    int i0_values[4] = {i0, i0, i0+current_size, i0+current_size};
    int j0_values[4] = {j0, j0+current_size, j0+current_size, j0};
    for(int k=0; k<4; k++){
        QuadTree<int>* son = sons[k];
        if(son->isLeaf() && current_size > min_size && i0_values[k]<height && j0_values[k]<width)
            drawRect(IntPoint2(j0_values[k], i0_values[k]), current_size, current_size, Color(255-son->value()));
        else if(son->isNode())
            display_with_squares_recursive(son, i0_values[k], j0_values[k], current_size, width, height, min_size);
    }
}

void display_with_squares(QuadTree<int>* qt, int width, int height, int min_size){ // min_size = minimal size of displayed squares
    byte* pixels = new byte[width*height];
    int N=0;
    int max_size = max(width, height);
    while(pow(2,N)<max_size)
        N++;
    decode_recursif(qt, pixels, 0, 0, pow(2,N), width, height);
    Image im(pixels, width, height); // displaying picture
    im.display();
    display_with_squares_recursive(qt, 0, 0, pow(2,N), width, height, min_size); // displaying squares
}
