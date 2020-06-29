#include <Imagine/Graphics.h>
#include <iostream>
#include "quadtree/quadtree.h"
#include "greyimage.h"
#include "colorimage.h"

using namespace Imagine;
using namespace std;

int main(int argc, char **argv) {
    // Get image file (rectangle horse)
    const char *image_file =
        (argc > 1) ? argv[1] : srcPath("running-horse-rect.png");
    // Load image
    byte* pixels;
    int width, height;
    cout << "Loading image: " << image_file << endl; 
    loadGreyImage(image_file, pixels, width, height);
    // Print statistics
    cout << "Image size: " << width << "x" << height << endl;
    cout << "Number of pixels: " << width*height << endl;
    // Display image
    Window W = openWindow(width, height);
    Image im(pixels, width, height);
    im.display();
    click();
    QuadTree<int>* qt = encode(im);
    cout << "size of original image = " << (int) sizeof(im) << endl;
    cout << "size of compressed image = " << (int) sizeof(qt) << endl;
    // compression rate = 1-size of compressed image/size of original image.
    cout << "decoded image:" << endl;
    Image decoded_im = decode(qt, width, height);
    decoded_im.display();
    click();
    cout << "decoded image with leaves" << endl;
    int min_leaves_size = 8;
    display_with_squares(qt, width, height, min_leaves_size);
    click();
    closeWindow(W);

    // Get image file (grey Lena)
    image_file = srcPath("lena.png");
    cout << "Loading image: " << image_file << endl;
    loadGreyImage(image_file, pixels, width, height);
    // Print statistics
    cout << "Image size: " << width << "x" << height << endl;
    cout << "Number of pixels: " << width*height << endl;
    // Display image
    Window W2 = openWindow(width, height);
    Image im2(pixels, width, height);
    im2.display();
    click();
    QuadTree<int>* qt2 = encode(im2);
    cout << "decoded image:" << endl;
    Image decoded_im2 = decode(qt2, width, height);
    decoded_im2.display();
    click();
    closeWindow(W2);

    // Get image file (color Lena)
    byte* red;
    byte* green;
    byte* blue;
    image_file = srcPath("lena.png");
    cout << "Loading image: " << image_file << endl;
    loadColorImage(image_file, red, green, blue, width, height);
    // Print statistics
    cout << "Image size: " << width << "x" << height << endl;
    cout << "Number of pixels: " << width*height << endl;
    // Display image
    Window W3 = openWindow(width, height);
    ColorImage im3(red, green, blue, width, height);
    im3.display();
    click();
    QuadTree<Color>* qt3 = color_encode(im3);
    cout << "decoded image:" << endl;
    ColorImage decoded_im3 = color_decode(qt3, width, height);
    decoded_im3.display();
    click();
    closeWindow(W3);
    // Get image file (color Lena)
    byte* red2;
    byte* green2;
    byte* blue2;
    image_file = srcPath("zinzins.jpg");
    cout << "Loading image: " << image_file << endl;
    loadColorImage(image_file, red2, green2, blue2, width, height);
    // Print statistics
    cout << "Image size: " << width << "x" << height << endl;
    cout << "Number of pixels: " << width*height << endl;
    // Display image
    Window W4 = openWindow(width, height);
    ColorImage im4(red2, green2, blue2, width, height);
    im4.display();
    click();
    QuadTree<Color>* qt4 = color_encode(im4);
    cout << "decoded image:" << endl;
    ColorImage decoded_im4 = color_decode(qt4, width, height);
    decoded_im4.display();
    click();
    return 0;
}
