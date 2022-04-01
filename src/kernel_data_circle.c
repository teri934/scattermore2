#include <stdio.h>
#include <math.h>

//blur data using its RGBWT matrix with circle kernel
void
kernel_data_circle(const unsigned *dim,
		    float *radius,
	            float *blurred_RGBWT,
	            const float *RGBWT)
{
	const size_t size_out_y = dim[0], size_out_x = dim[1], size_out = size_out_y * size_out_x, offset_R = 0, 
	             offset_G = size_out, offset_B = offset_G * 2, offset_W = offset_G * 3, offset_T = offset_G * 4;
	             
	const int int_radius = ceil(*radius);
	const float squared_radius = (*radius) * (*radius);
	
	size_t i;
	for(i = 0; i < size_out_y; ++i)
	{
	  size_t j;
	  for(j = 0; j < size_out_x; ++j)
	  {
	  	size_t offset = j*size_out_y + i;	

	  	int x;
	  	for(x = -int_radius; x <= int_radius; ++x)   //use neighboring pixels inside of circle with given radius
	  	{
	  	  int y;
	  	  for(y = -int_radius; y <= int_radius; ++y)
	  	  {
	  	  	if(x*x + y*y > squared_radius)   //out from the circle
	  	  		continue;
	  	  		
	  	  	int x_shift = j + x;
	  	  	int y_shift = i + y;
	  	  	
	  	  	if(x_shift < 0 || x_shift >= size_out_x || y_shift < 0 || y_shift >= size_out_y)
	  	  		continue;
	  	  		
	  	  	size_t offset_shift = x_shift*size_out_y + y_shift;				
	  	  	blurred_RGBWT[offset + offset_R] += RGBWT[offset_shift + offset_R];
	  	  	blurred_RGBWT[offset + offset_G] += RGBWT[offset_shift + offset_G];
	  	  	blurred_RGBWT[offset + offset_B] += RGBWT[offset_shift + offset_B];
	  	  	blurred_RGBWT[offset + offset_W] += RGBWT[offset_shift + offset_W];
	  	  	blurred_RGBWT[offset + offset_T] *= RGBWT[offset_shift + offset_T];
	  	  }
	  	}
	  }
	}  
}