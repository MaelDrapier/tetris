/*
** tetris.h for tetris in /home/spiki/PSU_2016_tetris
**
** Made by etienne.filliat
** Login   <etienne.filliat@epitech.eu>
**
** Started on  Thu Feb 16 17:05:31 2017 etienne.filliat
** Last update Fri Mar 24 10:30:59 2017 mael drapier
*/

#ifndef TETRIS_H_
# define TETRIS_H_

# define RETURN_SUCCESS 0
# define RETURN_FAIL 84
# define NB_FLAGS 11
# define LEVEL_SCORE 40
# define RED_TEXT(x) "\033[31;1m" x "\033[0m"
# define ESC	"^E"
# define SPACE "(space)"
# define USAGE_1 "Usage: "
# define USAGE_2 " [options]\n"
# define USAGE_3 "Options:\n"
# define HELP_H "	--help			"
# define HELP_L "	-l --level={num}	"
# define HELP_KL "	-kl --key-left={K}	"
# define HELP_KR "	-kr --key-right={K}	"
# define HELP_KT "	-kt -- key-turn={K}	"
# define HELP_KD "	-kd --key-drop={K}	"
# define HELP_KQ "	-kq --key-quit={K}	"
# define HELP_KP "	-kp --key-pause={K}	"
# define HELP_MAP "	--map-size={row,col}	"
# define HELP_W "	-w --without-next	"
# define HELP_D "	-d --debug		"
# define DES_H "Display this help\n"
# define DES_L "Start Tetris at level num (def: 1)\n"
# define DES_KL "Move the tetrimino LEFT using the K key (def: left arrow)\n"
# define DES_KR "Move the tetrimino RIGHT using the K key (def: right arrow)\n"
# define DES_KT1 "Turn the tetrimino clockwise 90d "
# define DES_KT2 "using the K key (def: top arrow)\n"
# define DES_KD "DROP the tetrimino using the K key (def: down arrow)\n"
# define DES_KQ "QUIT the game using the K key (def: 'Q' key)\n"
# define DES_KP "PAUSE/RESTART the game using the K key (def: space bar)\n"
# define DES_MAP "Set the numbers of rows and columns of the map (def: 20,10)\n"
# define DES_W "Hide next tetrimino (def: false)\n"
# define DES_D "Debug mode (def: false)\n"
# include "tetris_flags.h"
# include "struct.h"

void		my_putnbr(int nb);
void		init_colors();
void		my_putchar(char c);
void		my_showtab(char **taab);
void		set_canonic(int i);
void		my_putstr(int fd, char *str);
void		print_unseen(int fd, char *str);
void		display_others(t_game *game, int nb, t_tetriminos *tetris);
void		remove_full(t_game *game);
void		replace_full(int count, int y, t_game *game);
char		*remove_spaces(char *line);
char		*my_strcpy(char *dest, char *src);
char		*get_short_flag(char **av, int ac, int x);
char		**create_wndw(char **wndw, t_info info);
char		**create_up_map(char **up_map, t_info info);
char		**enlarge_others(char **draw, int width);
char		**my_str_to_wordtab(char **taab, char *str, int i, int j);
void		show_debug(t_debug *key, t_tetriminos *tetris, int nb_tetri);
int		my_getnbr(char *str);
int		nb_of_tetriminos();
int		my_strlen(char *str);
int		lost(t_game *game);
void		verif_params(char **av, int ac);
int		calc_size(char **draw, int nb);
int		check_end_line(char *str, int i);
int		my_strcmp(char *s1, char *s2, int start);
int		try_right(t_game *game, t_tetriminos tetri);
int		try_left(t_game *game, t_tetriminos tetri);
void		print_unseen(int fd, char *str);
void		option_help(char **av, t_debug *key, int ac);
void		options_left(char **av, t_debug *key, int ac);
void		options_right(char **av, t_debug *key, int ac);
void		options_turn(char **av, t_debug *key, int ac);
void		options_drop(char **av, t_debug *key, int ac);
void		options_quit(char **av, t_debug *key, int ac);
void		options_pause(char **av, t_debug *key, int ac);
void		option_next(char **av, t_debug *key, int ac);
void		option_level(char **av, t_debug *key, int ac);
void		option_debug(char **av, t_debug *key, int ac);
void		option_size(char **av, t_debug *key, int ac);
void		play_tetris(t_tetriminos *tetris, t_debug *key, int nb_tetri);
void		move_tetris(t_game *game, t_tetriminos *tetris);
void		set_game(t_game *game, t_debug *key,
			 t_tetriminos *tetris, int nb_tetri);
void		try_move(char *buf, t_debug *key,
			 t_game *game, t_tetriminos tetri);
int		my_getnbr_in_char(char *av);
int		my_strcmp_debug(char *s1, char *s2, int end);
int		search_flag(char *flag, char **av, int ac);
char		my_getchar(char *av, char *flag);
char		*my_getstr(char *av, char *flag);
void		*my_uber_malloc(int size);
void		*my_mem(void *str, char c, int size);
t_tetriminos	*get_tetriminos(t_tetriminos *tetris);
t_tetriminos	fill_tetri(t_tetriminos tetri, int fd);
t_tetriminos	*my_sort_tetris(t_tetriminos *tetris, int nb_tetri);
t_tetriminos	*check_tetriminos(t_tetriminos *tetris, int nb_tetri);
t_tetriminos	init_tetri(t_tetriminos tetri);
t_tetriminos	*enlarge_tetriminos(t_tetriminos *tetris, int nb_tetri);
t_tetriminos	rotate_tetriminos(t_tetriminos tetri);
t_tetriminos	try_rotate(char *buf, t_debug *key,
			   t_game *game, t_tetriminos tetri);

#endif /* !TETRIS_H_ */
