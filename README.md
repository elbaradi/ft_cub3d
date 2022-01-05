Note: _This was my fifth 42 project, completed February 2021. It was my biggest project at the time, it involved a lot of maths to get the graphics right. I had a lot of fun adding extra features to this project, like custom textures, custom screenshots, audio, shading and a hurt system._

[![Logo](https://github.com/qingqingqingli/readme_images/blob/master/codam_logo_1.png)](https://github.com/qingqingqingli/cub3d)

# cub3d
***This project is a graphic design project, inspired by the famous game [Wolfenstein 3D](http://users.atw.hu/wolf3d/). Creating a "realistic" 3D graphical representation of the inside of a maze from a 2D map, with a first person perspective using Ray-Casting principles.***

## Technical details

- Controls: ```W A S D``` to move, ```left and right arrow``` to change camera angle, ```ESC``` or ```close window``` to exit program
- Reads in a ```.cub``` map file, with map specifications and 2D map design, which are validated by the program before getting into gameplay
- Ceiling and floor color is read from the ```.cub``` file and can be changed
- Walls are textured, customs textures can be added and read from the ```.cub``` file
- Distance-based shading
- Added a soundtrack
- Custom cactus sprites are added, hurt triggers when walking into them
- Program exits when the player dies
- Running the program with ```--save``` as an argument takes a screenshot of the first loaded frame and saves it in the ```screenshot``` folder
- All heap allocated memory space is properly freed
- Allowed functions: ```open```, ```close```, ```read```, ```write```, ```malloc```, ```free```, ```perror```, ```strerror```, ```exit```, all functions of the ```math``` library and the ```MinilibX``` graphic library

## How to run

Run the following commands. This version of the graphic library only works with MacOS. A test map file (```test.cub```) is provided in the ```maps``` directory. Replace ```test.cub``` with a .cub file of your choice

```shell
$ git clone https://github.com/elbaradi/ft_cub3d
$ make bonus
$ ./cub3d maps/test.cub
```

## Gameplay

![ft_cub3d](https://s10.gifyu.com/images/Tijmens_Raytracing_Maze_in_Cdc7ef542a6fc9b70.gif) 

