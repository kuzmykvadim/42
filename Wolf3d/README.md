# RT @ UNIT Factory

<img align="right"  src="https://github.com/kuzmykvadim/42/tree/master/Wolf3d/img/Screen Shot 2017-11-15 at 9.48.57 PM.png"  />

My first Ray Tracer.
RT (Ray tracer) is a mini-project is the first step to create a Raytracing program in the 3D graphics curriculum of <a href="http://www.unit.ua" target="_blank" >UNIT Factory</a> [(42 School)](https://en.wikipedia.org/wiki/42_(school)).

At 42, we follow a strict norm in order to teach us to follow style guides. This norm also prevents us from using many built-in functions. In this project, we are limited to using a barebones graphic library called minilibx. This library limits the functionality to creating windows, handling input hooks, and coloring specific pixels.

In computer graphics, ray tracing is a technique for generating an image by tracing the path of light through pixels in an image plane and simulating the effects of its encounters with virtual objects. The technique is capable of producing a very high degree of visual realism, usually higher than that of typical scanline rendering methods, but at a greater computational cost. This makes ray tracing best suited for applications where the image can be rendered slowly ahead of time, such as in still images and film and television visual effects, and more poorly suited for real-time applications like video games where speed is critical. Ray tracing is capable of simulating a wide variety of optical effects, such as reflection and refraction, scattering, and dispersion phenomena (such as chromatic aberration).

# :cd: Installation
The project only work on Mac OS X.

It uses the MinilibX, a micro-library that provides an easy way to create a window and push an image on it.
```
make
```

# Usage
	./RTv1 maps/scene2

# Command List
|                Key               |                Function                 |
| -------------------------------- |:---------------------------------------:|
| <kbd>+</kbd> <kbd>-</kbd>        | move camera up/down on y axis 	     |
| <kbd>Y</kbd> <kbd>H</kbd>        | look up/down          		     |
| <kbd>W</kbd> <kbd>S</kbd>        | look left/right      		     |
| <kbd>A</kbd> <kbd>D</kbd>        | look around    		     |
| <kbd>UP</kbd> <kbd>DOWN</kbd>    | move camera  up/down	             |
| <kbd>LEFT</kbd> <kbd>RIGHT</kbd> | move camera left/right   		     |
| 	     |
|  |	     |


# Map example


```diff
LIGHT
light pos: |10, 10, -60|
----------------------
CAMERA
camera pos: |35, 20, 0|
camera rot: /-10, 30/
----------------------
OBJECT
#SPHERE
obj pos: |0, -5, 60|
rad: [8]
rgb: |255, 5, 88|
rot: <0, 0, 0>
----------------------
#CYLINDER
obj pos: |-10, 0, 60|
rad: [5]
rgb: |155, 255, 15|
rot: <10, 0, -30>
--------------------
#CONE
obj pos: |10, -7, 60|
rad: [45]
rgb: |240, 252, 12|
rot: <0, 0, 25>
--------------------
#PLANE
obj pos: |0, -11, 60|
rad: [0]
rgb: |33, 33, 30|
rot: <0, 0, 0>
norm: {0, 1, 0}
--------------------
#PLANE
obj pos: |0, 0, 110|
rad: [0]
rgb: |109, 165, 255|
rot: <0, 0, 0>
norm: {0, 0, -1}
--------------------
```
<div>
<img align="right"  src="https://github.com/kuzmykvadim/42/blob/master/RTv1/img/Screen Shot 2017-11-15 at 9.49.16 PM.png"  
width="47%" height="500px" />
<img align="left"  src="https://github.com/kuzmykvadim/42/blob/master/RTv1/img/Screen Shot 2017-11-15 at 9.51.45 PM.png"  
width="47%" height="500px" />
</div>
