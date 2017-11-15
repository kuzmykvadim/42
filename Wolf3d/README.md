# Wold3d @ UNIT Factory

<img align="right"  src="https://github.com/kuzmykvadim/42/blob/master/Wolf3d/img/Screen Shot 2017-11-15 at 9.51.45 PM.png"  
width="500px" height="500px" />


Wolf3D is a project is the first step to create a Raycasting program in the 3D graphics curriculum of <a href="http://www.unit.ua" target="_blank" >UNIT Factory</a> [(42 School)](https://en.wikipedia.org/wiki/42_(school)).

At 42, we follow a strict norm in order to teach us to follow style guides. This norm also prevents us from using many built-in functions. In this project, we are limited to using a barebones graphic library called minilibx. This library limits the functionality to creating windows, handling input hooks, and coloring specific pixels.

Ray casting is the most basic of many computer graphics rendering algorithms that use the geometric algorithm of ray tracing. Ray tracing-based rendering algorithms operate in image order to render three-dimensional scenes to two-dimensional images. Geometric rays are traced from the eye of the observer to sample the light (radiance) travelling toward the observer from the ray direction. The speed and simplicity of ray casting comes from computing the color of the light without recursively tracing additional rays that sample the radiance incident on the point that the ray hit. This eliminates the possibility of accurately rendering reflections, refractions, or the natural falloff of shadows; however all of these elements can be faked to a degree, by creative use of texture maps or other methods. The high speed of calculation made ray casting a handy rendering method in early real-time 3D video games.

# :cd: Installation
The project only work on Mac OS X.

It uses the MinilibX, a micro-library that provides an easy way to create a window and push an image on it.
```
make
```

# Usage
	./wolf3d map

# Command List
|                Key               |                Function                 |
| -------------------------------- |:---------------------------------------:|
| <kbd>W</kbd> <kbd>S</kbd>        | look left/right      		     |
| <kbd>A</kbd> <kbd>D</kbd>        | look around    		     	     |
| <kbd>LEFT</kbd> <kbd>RIGHT</kbd> | move camera left/right   		     |


# Map example


```diff
m_width: 20; m_height: 18; pos_x: 4; pos_y: 13;
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0 1 1 1 0 0 0 0 0 1 1 1
1 0 0 1 1 0 0 0 0 1 1 1 0 0 0 0 0 1 1 1
1 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 0 0 1 1 0 0 1 1 0 0 0 0 0 1 1 0 0 0 1
1 0 0 1 1 0 0 1 1 0 0 0 0 0 1 1 0 0 0 1
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 0 0 1 1 0 0 1 1 0 0 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 1
1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 1
1 0 0 0 0 1 1 0 0 0 0 0 0 0 1 1 0 0 0 1
1 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
```
<div>
<img align="right"  src="https://github.com/kuzmykvadim/42/blob/master/Wolf3d/img/Screen Shot 2017-11-15 at 9.49.16 PM.png"  
width="47%" height="500px" />
<img align="left"  src="https://github.com/kuzmykvadim/42/blob/master/Wolf3d/img/Screen Shot 2017-11-15 at 9.51.45 PM.png"  
width="47%" height="500px" />
</div>
