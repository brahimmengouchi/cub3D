/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 04:16:46 by bmengouc          #+#    #+#             */
/*   Updated: 2023/10/23 04:16:48 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_map_and_exit(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
	printf("Error\nInvalid map line detected.\n");
	exit(EXIT_FAILURE);
}

void	get_map(char *fmap, t_cub3d *vars)
{
	vars->fd = open(fmap, O_RDONLY);
	if (vars->fd < 0)
		message_error();
	vars->all_lines = ft_strdup("");
	while (1)
	{
		vars->line = get_next_line(vars->fd);
		if (vars->line == NULL)
			break ;
		vars->tmp = ft_strdup(vars->all_lines);
		free(vars->all_lines);
		vars->all_lines = ft_strjoin(vars->tmp, vars->line);
		free(vars->line);
		free(vars->tmp);
	}
	if (vars->all_lines[0] == '\0')
	{
		free(vars->all_lines);
		message_error();
	}
	vars->map = ft_split(vars->all_lines, '\n');
	free(vars->all_lines);
	close(vars->fd);
}

int	func2(int line_count, char *line, int *inside_maze, char **all_lines)
{
	int		i;
	char	*tmp;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (line_count >= 6 && line[i] != '\n' && !*inside_maze)
		*inside_maze = 1;
	if (*inside_maze && line_count >= 6 && line[i] == '\n')
	{
		free(line);
		return (0);
	}
	if (*inside_maze)
	{
		if (line_count >= 6)
		{
			tmp = ft_strdup(*all_lines);
			free(*all_lines);
			*all_lines = ft_strjoin(tmp, line);
			free(tmp);
		}
	}
	free(line);
	return (1);
}

char	*func(int fd, int i, int line_count, int inside_maze)
{
	char	*line;
	int		tmp;
	char	*all_lines;

	all_lines = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		i = 0;
		if (line == NULL)
			break ;
		if (line_count < 6 && line[0] == '\n')
		{
			free(line);
			continue ;
		}
		tmp = func2(line_count, line, &inside_maze, &all_lines);
		if (!tmp)
			return (NULL);
		line_count++;
	}
	return (all_lines);
}

void	get_map2(char *fmap, t_cub3d *vars)
{
	char	*all_lines;
	int		i;
	int		line_count;
	int		inside_maze;

	i = 0;
	line_count = 0;
	inside_maze = 0;
	vars->fd = open(fmap, O_RDONLY);
	if (vars->fd < 0)
	{
		free_map(vars->map);
		message_error();
	}
	all_lines = func(vars->fd, i, line_count, inside_maze);
	if (!all_lines)
		free_map_and_exit(vars->map);
	if (all_lines[0] == '\0')
	{
		free(all_lines);
		message_error();
	}
	vars->map2 = ft_split(all_lines, '\n');
	free(all_lines);
	close(vars->fd);
}
