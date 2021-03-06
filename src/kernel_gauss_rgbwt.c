#include <stdio.h>
#include <math.h>
#include "kernels.h"

//blur data using its RGBWT matrix with gaussian kernel, expands smooth gaussian neighborhoods
void
kernel_gauss_rgbwt(const unsigned *dim,
                   const float *kernel,
                   float *blurred_RGBWT,
                   const float *RGBWT)
{
    const size_t size_out_y = dim[0];
    const size_t size_out_x = dim[1];
    const size_t size_kernel = dim[2];
    const int radius = size_kernel / 2;
    const size_t size_out = size_out_x * size_out_y;

    const size_t offset_R = size_out * 0;
    const size_t offset_G = size_out * 1;
    const size_t offset_B = size_out * 2;
    const size_t offset_W = size_out * 3;
    const size_t offset_T = size_out * 4;

	
    size_t i;
    for(i = 0; i < size_out_y; ++i)
    {
        size_t j;
        for(j = 0; j < size_out_x; ++j)
        {
            size_t offset = j * size_out_y + i;

            int x;
            for(x = -radius; x <= radius; ++x)  //use neighboring pixels inside of circle with generated radius
            {
                int y;
                for(y = -radius; y <= radius; ++y)
                {
                    int x_shift = j + x;
                    int y_shift = i + y;

                    if(x_shift < 0 || x_shift >= size_out_x || y_shift < 0 || y_shift >= size_out_y)
                        continue;

                    size_t offset_shift = x_shift * size_out_y + y_shift;


                    float W = RGBWT[offset_shift + offset_W];       //extract weight and transparency and find
                    float A = 1 - RGBWT[offset_shift + offset_T];
                    float R, G, B;

                    if(RGBWT[offset_shift + offset_W] != 0)	//find R, G, B values
                    {
                        R = RGBWT[offset_shift + offset_R] / W;
                        G = RGBWT[offset_shift + offset_G] / W;
                        B = RGBWT[offset_shift + offset_B] / W;
                    }
                    else
                        R = G = B = 0;

                    int kernel_index = (radius + x) * size_kernel + (radius + y);
                    float gauss_A = A * kernel[kernel_index];


                    blurred_RGBWT[offset + offset_R] += R * gauss_A;
                    blurred_RGBWT[offset + offset_G] += G * gauss_A;
                    blurred_RGBWT[offset + offset_B] += B * gauss_A;
                    blurred_RGBWT[offset + offset_W] += gauss_A;
                    blurred_RGBWT[offset + offset_T] *= 1 - gauss_A;
                }
            }
        }
    }
}
