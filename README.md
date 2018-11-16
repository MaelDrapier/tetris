# tetris

This project was my second ncurses project from my first year at EPITECH (2016 - 2017)

The goal of this project was to recreate the [Tetris](https://fr.wikipedia.org/wiki/Tetris) game in a UNIX terminal (with the Gameboy version rules), by using the [ncurses](https://www.gnu.org/software/ncurses/) library.

<br>

Language: **C**

Group size: **2** (me and [**Etienne Filliat**](https://github.com/etiennefilliat))

Project duration: **~1 month** (20/02/2017 - 19/03/2017)

Compilation: **on GNU/Linux via Makefile**

#### Required library: [ncurses](https://www.gnu.org/software/ncurses/)

To install it:

* on Debian / Ubuntu: `sudo apt-get install libncurses5-dev libncursesw5-dev`
* on Arch Linux: `sudo pacman -S ncurses`
* on Fedora: `sudo dnf install ncurses-devel`
* on other distributions, download it on `ftp://ftp.gnu.org/gnu/ncurses/`

<br>

## Usage

```
$> ./tetris -h   
Usage: ./tetris [options]
Options:
	--help			Display this help
	-l --level={num}	Start Tetris at level num (def: 1)
	-kl --key-left={K}	Move the tetrimino LEFT using the K key (def: left arrow)
	-kr --key-right={K}	Move the tetrimino RIGHT using the K key (def: right arrow)
	-kt -- key-turn={K}	Turn the tetrimino clockwise 90d using the K key (def: top arrow)
	-kd --key-drop={K}	DROP the tetrimino using the K key (def: down arrow)
	-kq --key-quit={K}	QUIT the game using the K key (def: 'Q' key)
	-kp --key-pause={K}	PAUSE/RESTART the game using the K key (def: space bar)
	--map-size={row,col}	Set the numbers of rows and columns of the map (def: 20,10)
	-w --without-next	Hide next tetrimino (def: false)
	-d --debug		Debug mode (def: false)
```

<br>

## Tetriminos

A tetris piece is called a **tetrimino**

**You can add, remove or change the tetriminos used by the game.**

A tetrimino is represented by a `.tetrimino` file placed in the `tetriminos` folder.

These files are composed in the following way:
* on the first line, the **size** and **color** of the piece in this format:

`width height color_code\n` (_color_code_ => ncurses capacity’s color number)

* on the _h_ following lines (where _h_ is the height of the tetrimino), the **piece’s shape** composed with asterisks `*` and spaces

### Example of a tetrimino file:

```
$> cat -e tetriminos/inverted_L.tetrimino
2 3 1$
 *$
 *$
**$
```

**You can check all the loaded tetriminos on launch with the** `--debug` **option.**
