#include <fractol.h>

/*void draw(fractol img)
{
	int	x;
	int	y;
	int iter;
	double z[2] = {0, 0};
	double zdist[2] = {0, 0};


	y = 0;
	while (y < img.ylen)
	{
		x = 0;
		while (x < img.xlen)
		{
			while (iter < NITERATION && (zdist[0] + zdist[1]) < 4.0)
			{

			}
		}
	}
}*/
int	close(img_mlx	img)
{
	mlx_destroy_window(img.mlx, img.win);
	return (0);
}
int	main(void)
{
	img_mlx	img;

	img.xlen = 1280;
	img.ylen = 720;
	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, img.xlen, img.ylen, "Hello world!");
	img.img = mlx_new_image(img.mlx, img.xlen, img.ylen);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);
	new_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	mlx_hook(img.win,  17, 0L, close, &img);
	mlx_loop(img.mlx);
}

/*int	main(int argc, char *argv[])
{
	t_fractol	fr;
	int			test_args;

	test_args = fractol_error(argc, argv);
	mlx_fractol(&fr);
	if (test_args == 1)
		fr.what_fractol = 1;
	if (test_args == 2)
	{
		fr.cr = my_atof(argv[2]);
		fr.ci = my_atof(argv[3]);
		fr.what_fractol = 0;
	}
	mlx_key_hook(fr.mlx_win, handle_keys, &fr);
	mlx_mouse_hook(fr.mlx_win, handle_mouse, &fr);
	mlx_hook(fr.mlx_win, 17, 0L, handle_close, &fr);
	mlx_loop_hook(fr.mlx, render_fr, &fr);
	mlx_loop(fr.mlx);
	return (0);
}*/

//position of mouse
//zoom
//coordinates of the window
//