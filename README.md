# Ray-casting-wolfenstein-3d
I made a simple engine on ray casting technology and a parser that check configuration file (with ".cub" extension)
I used C language

That's how it looks:

<img src="/img/img1.png" width="426" height="320">
<img src="/img/img2.png" width="426" height="320">

# Engine

It place walls and sprites on screen. Also it place different texture on walls depending on player direction. You can change ceiling and floor colours in conf. file as a textures to walls and sprite.

# Parser
 
Map config example 

```
R 640 480

F 220,100,100
C 100,0,255

NO ./textures/cubblestone.xpm
SO ./textures/grey_brick.xpm
WE ./textures/red_brick.xpm
EA ./textures/wood.xpm

S ./textures/barrel.xpm

 1111111111111111111111111111
100000002000000000000001000001
100000000000000000000000000001
111001111111111111111111000001
100000000000001022222221110111
100000000000001022222221000001
10000000000000102222222100N001
100000000000000022222221000001
 1111111111111111111111111111
```

- R  - for resolution
- F and C - floor and ceiling colours
- NO (north) SO (south) WE (west) EA (east) S (sprite) - path to the textures

Then there is a map in which

- 0 - empty space
- 1 - is a wall
- 2 - is a sprite
- N,E,S,W - player and his direction


For the file to be valid map around the player must be closed

# launch

On mac os you should type in terminal
```
make
```
which will compile the program

And
```
./cub3D map.cub
```
to lunch it

You also can make a screenshot of the first frame without running the programs

```
./cub3D map.cub --save
```

It will be saved in bmp format
# Controls

WASD - for move the player through the maze

left and right arrows for turn left and right 
