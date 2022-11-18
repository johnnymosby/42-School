#include "../lib/mlx_osx/mlx.h"

#define NITERATION = 250

typedef struct {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		xlen;
	int		ylen;
	int		sf;		//scaling factor
	void	*mlx;
	void	*win;
}				img_mlx;

void	new_mlx_pixel_put(img_mlx *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}
