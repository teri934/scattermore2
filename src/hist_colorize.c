#include <stdio.h>

//colorize histogram with given color palette
void
hist_colorize(const unsigned *dim,
	      float *rgbwt,
	      const float *palette,
	      const float *hist)
{
	const size_t size_out_y = dim[0], size_out_x = dim[1], size_palette = dim[2], size_hist = size_out_y * size_out_x,
	             offset_R = 0, offset_G = size_hist, offset_B = offset_G * 2, offset_W = offset_G * 3, offset_T = offset_G * 4;
	const float bin = 1.0/size_palette;
	
	size_t i;
	for(i = 0; i < size_out_y; ++i)
	{
	  size_t j;
	  for(j = 0; j < size_out_x; ++j)
	  {
	  	float hist_value = hist[j*size_out_y + i];
	  	size_t palette_index = ((size_t)(hist_value / bin));  //determining column in palette
	  	
	  	if(palette_index == size_palette) --palette_index;
	  	
	  	float R = palette[4 * palette_index + 0];
	  	float G = palette[4 * palette_index + 1];
	  	float B = palette[4 * palette_index + 2];
	  	float A = palette[4 * palette_index + 3];
	  	
	  	size_t offset = j*size_out_y + i;
	  	rgbwt[offset + offset_R] = R;
	  	rgbwt[offset + offset_G] = G;
	  	rgbwt[offset + offset_B] = B;
	  	rgbwt[offset + offset_W] = 1;
	  	rgbwt[offset + offset_T] = 1-A;
	  }
	}    

}
