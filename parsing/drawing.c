#include "cub3d.h"

int released(int keycode,t_vars *vars)
{
    if (vars->player.w_direction != 0)
    {
        vars->player.w_direction = 0;
    }
    if (vars->player.t_direction != 0)
    {
        vars->player.t_direction = 0;
    }
    return (1);
}

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->img.addr + (y * vars->img.line_length + x * (vars->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void    draw_rays(float ray_angle, t_vars *vars)
{
    int i = 0;
    float x = vars->player.x;
    float y = vars->player.y;
    while (i < 30)
    {
        my_mlx_pixel_put(vars, x, y, 0xF0FFa00);
        x += cos(ray_angle);
        y += sin(ray_angle);
        i++;
    }
}

void    display_rays(t_vars *vars)
{
    int i = 0;
    int NUM_RAYS;
    NUM_RAYS = vars->width;
    int column = 0;
    float ray_angle = vars->player.rotation - (FOV / 2);
    while (column < NUM_RAYS)
    {
       draw_rays(ray_angle, vars);
       ray_angle += FOV / NUM_RAYS;
       column++;
    }
}

typedef struct s_rect
{
    int	x;
    int	y;
    int width;
    int height;
    int color;
}	t_rect;



int render_rect(t_vars *vars, t_rect rect)
{
    int	i;
    int j;

    i = rect.y;
    while (i < rect.y + rect.height)
    {
        j = rect.x;
        while (j < rect.x + rect.width)
            my_mlx_pixel_put(vars, j++, i, rect.color);
        ++i;
    }
    return (0);
}

void    display_minimap(t_vars *vars)
{   
    int i;
    t_rect rect;

    i = 0;
    while (i < vars->height)
    {
        int j = 0;
        while (j < vars->width)
        {
            if (vars->data->map_represent[i][j] == '1')
            {
                rect.x = j * TAILED;
                rect.y = i * TAILED;
                rect.height = TAILED;
                rect.width = TAILED;
                rect.color = 0x718093;
                render_rect(vars, rect);
            }
            else if (vars->data->map_represent[i][j] == '0' || vars->data->map_represent[i][j] == 'N')
            {
                rect.x = j * TAILED;
                rect.y = i * TAILED;
                rect.height = TAILED;
                rect.width = TAILED;
                rect.color = 0xFFFFFFF;
                render_rect(vars, rect);
            }
            j++;
        }
        i++;
    }
}



void draw_circle(t_vars *vars, int centerX, int centerY, int radius, int color)
{
    int x, y;
    
    for (x = -radius; x <= radius; x++) {
        for (y = -radius; y <= radius; y++) {
            if (x * x + y * y <= radius * radius) {
                my_mlx_pixel_put(vars, centerX + x, centerY + y, color);
            }
        }
    }
}

void    draw_line(t_vars *vars)
{
    int i = 0;
    float x = vars->player.x;
    float y = vars->player.y;
    while (i < 20)
    {
        my_mlx_pixel_put(vars, x, y, 0xF0FFa00);
        x += cos(vars->player.rotation);
        y += sin(vars->player.rotation);
        i++;
    }

}

void    draw_player(t_vars *vars)
{
    draw_circle(vars, vars->player.x, vars->player.y, 2,0xFF00000);
    draw_line(vars);
}



void get_x_y(char **represent, t_vars *vars)
{
    int i = 0;
    while (represent[i])
    {
        int j = 0;
        while (represent[i][j])
        {
            if (represent[i][j] == 'N')
            {
                vars->player.x = i * TAILED;
                vars->player.y = j * TAILED;
                return;
            }
            j++;
        }
        
        i++;
    }
}

int    move_player(int keycode, t_vars *vars)
{
    char temp;
    if (keycode == 13)
    {
        vars->player.w_direction = 1;
    }
    else if (keycode == 1)
    {
        vars->player.w_direction = -1;
    }
    else if (keycode == 124)
    {
        vars->player.t_direction = 1;
    }
    else if (keycode == 123)
    {
        vars->player.t_direction = -1;
    }
    return (1);
}
int draw_rect(t_vars *vars, int x, int y, unsigned int color)
{   
    int i = x;
    while (i < x + TAILED) {
        int j = y;
        while (j < y + TAILED) {
            my_mlx_pixel_put(vars, i, j, color);
            j++;
        }
        i++;
    } 
    return (1);
}


int    draw(t_vars *vars)
{
    display_minimap(vars);
    if (vars->data->map_represent[(int)vars->player.x][(int)vars->player.y] != '1')
    {
        vars->player.y += sin(vars->player.rotation) * 1.5 * vars->player.w_direction;
        vars->player.x += cos(vars->player.rotation) * 1.5 * vars->player.w_direction;
        vars->player.rotation += 3 * (M_PI / 180) * vars->player.t_direction;
    }
    draw_player(vars);
    display_rays(vars);
    mlx_put_image_to_window(vars->mlx_ptr, vars->mlx_win, vars->img.img, 0, 0);
    return (1);
}

void    drawing(t_data *data)
{
    t_vars *vars;

    vars = malloc(sizeof(t_vars));
    vars->data = data;
    get_x_y(vars->data->map_represent,vars);

    vars->width = get_columns(vars->data->map_represent);
    vars->height = get_rows(vars->data->map_represent);
    vars->player.rotation = M_PI / 2;
    vars->mlx_ptr = mlx_init();
    vars->mlx_win = mlx_new_window(vars->mlx_ptr, 5120, 2880,"dd");
    vars->img.img = mlx_new_image(vars->mlx_ptr,vars->width * TAILED , vars->height * TAILED);
    vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel, &vars->img.line_length,
								&vars->img.endian);
    vars->player.t_direction = 0;
    vars->player.w_direction = 0;
    mlx_hook(vars->mlx_win,2,0L,move_player,vars);
    mlx_hook(vars->mlx_win,3,0L,released,vars);
    mlx_loop_hook(vars->mlx_ptr, draw,vars);
    mlx_loop(vars->mlx_ptr);
}
