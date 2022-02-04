#include <stdio.h>

//colorize histogram with given color palette
void
raster(const unsigned *dim,
       const float *xlim,
       const float *ylim,
       float *matrix,
       const float *rgba,
       const float *xy)
{
	const size_t size_out_y = dim[0], size_out_x = dim[1], n = dim[2], n_col = dim[3], size_out = size_out_x * size_out_y,
	             offset_G = size_out, offset_B = offset_G * 2, offset_A = offset_G * 3;
	             
	const float x_begin = xlim[0], x_end = xlim[1], x_bin = (size_out_x - 1) / (x_end - x_begin),
                    y_begin = ylim[1], y_end = ylim[0], y_bin = (size_out_y - 1) / (y_end - y_begin);
	             
	if(n_col == 1) //one color
	{
		float R = rgba[0];
		float G = rgba[1];
		float B = rgba[2];
		float A = rgba[3];
		  	
		size_t i; size_t x; size_t y;
		for(i = 0; i < n; ++i)
		{
			x = (xy[i] - x_begin) * x_bin;  //get new point coordinates for result raster
			y = (xy[i+n] - y_begin) * y_bin;
			
			if(x >= size_out_x || y >= size_out_y)
				continue;		
				
			size_t offset = x*size_out_y + y;
			matrix[offset] = R;
		  	matrix[offset + offset_G] = G;
		  	matrix[offset + offset_B] = B;
		  	matrix[offset + offset_A] = A;
	        }    
	}

}
