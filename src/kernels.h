#ifndef KERNELS_H_
#define KERNELS_H_
#include <stdio.h>

//main methods
void kernel_square_histogram(const unsigned *dim, const float *kernel, float *blurred_histogram, const float *histogram);
void kernel_gauss_histogram(const unsigned *dim, const float *kernel, float *blurred_histogram, const float *histogram);
void kernel_circle_rgbwt(const unsigned *dim, const float *radius, float *blurred_RGBWT, const float *RGBWT);
void kernel_gauss_rgbwt(const unsigned *dim, const float *kernel, float *blurred_RGBWT, const float *RGBWT);


//helper methods
float apply_kernel(const float *kernel, const float *histogram, const unsigned *dim, const size_t x, const size_t y);

#endif