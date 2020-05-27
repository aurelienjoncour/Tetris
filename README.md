# Tetris

- **Usage:** make && ./tetris
- **Mark:** 20/20

**Groupe Member**
- [@vincent-andrieu](https://github.com/vincent-andrieu)
- [@AurelienJoncour](https://github.com/aurelienjoncour)

# Subject
The goal of this project is to recreate the Tetris game in a UNIX terminal, with the Gameboy version rules.
You have to use ncurses.
In the folder of your binary, there must be a tetriminos directory, which contains files that describe the game
pieces.

These files are composed in the following way:
- on the first line, the size and color of the piece in this format: width height color_code\n (the number
of the color corresponds to the ncurses capacity’s color numbers),
- on the h following lines (where h is the height of the tetrimino), the piece’s shape composed with
asterisks (*) and spaces (‘ ’).
For instance, these pieces correspond to the opposite files:

![image](https://imgur.com/nKDX3Xi.png)

The pieces (randomly chosen) fall from the top of the map and pile up on the bottom. Each time a line is completed, it disappears, leaving all of the pieces above it to fall.
The level increases by 1 for every 10 deleted lines. The falling speed increases proportionally to the level.
When it is no longer possible for pieces to fall from the top of the map, the player loses

You can find the rules [here](https://en.wikipedia.org/wiki/Tetris).

When the game begins, the terminal must delete all content. Then, it must show (at least):
- the main map,
- a preview of the next tetrimino to fall,
- current score, high score, current number of completed lines, level, timer.

If the terminal is too small to host the map, the game does’t start; an error message is printed, asking the user to enlarge his/her terminal.

For the gameplay, refer to the following usage:

![images](https://imgur.com/xvgqstI.png)

![images](https://imgur.com/BNdS2pO.png)