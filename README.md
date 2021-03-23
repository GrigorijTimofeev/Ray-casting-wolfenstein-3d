# Ray-casting-wolfenstein-3d
I made a simple engine on ray casting technology and a parser that check configuration file (with ".cub" extension)

That's how it looks:

<img src="/img/img1.png" width="426" height="320">
<img src="/img/img2.png" width="426" height="320">

# Engine

It place walls and sprites on map. Althow it place different texture on walls depending on player diraction. You can change cealing and floor colours in conf. file as a textures to walls and sprite. 

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
