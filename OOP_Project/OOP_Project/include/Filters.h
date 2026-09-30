#ifndef FILTERS_H
#define FILTERS_H

#include "Image_Class.h"

void grayscale_filter(Image& image);
void BW_filter(Image& image);
void darken_lighten_filter(Image& image);
void infrared_filter(Image& image);
void flip_filter(Image& image);
void rotate_filter(Image& image);
void add_frame_filter(Image& image);
void invert_filter(Image& image);

#endif