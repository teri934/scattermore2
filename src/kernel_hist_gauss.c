#include <stdio.h>
#include "header.h"

//blur histogram using kernel of ones
void
kernel_hist_gauss(const unsigned *dim,
	          float *blurred_histogram,
	          const float *histogram,
	          const float *sigma)
{
	const size_t size_out_y = dim[0], size_out_x = dim[1], size = dim[2];
	
	
	float kernel[size*size];
	create_gauss(kernel, size, *sigma);
	
	size_t i;
	for(i = 0; i < size_out_y; ++i)
	{
	  size_t j;
	  for(j = 0; j < size_out_x; ++j)
	  {
	  	blurred_histogram[j*size_out_y + i] = blur(kernel, histogram, dim, j, i); //blurring of given point
	  }
	}    
}