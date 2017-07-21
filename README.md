# RT @ UNIT Factory

<img align="right"  src="https://github.com/kuzmykvadim/42/blob/master/fractal/Screens/Mandelbrot.png" width="40%" />

RT (Ray tracer) is a mile-stone project in the 3D graphics curriculum of <a href="http://www.unit.ua" target="_blank" >UNIT Factory</a> [(42 School)](https://en.wikipedia.org/wiki/42_(school)).

At 42, we follow a strict norm in order to teach us to follow style guides. This norm also prevents us from using many built-in functions. In this project, we are limited to using a barebones graphic library called minilibx. This library limits the functionality to creating windows, handling input hooks, and coloring specific pixels.

In computer graphics, ray tracing is a technique for generating an image by tracing the path of light through pixels in an image plane and simulating the effects of its encounters with virtual objects. The technique is capable of producing a very high degree of visual realism, usually higher than that of typical scanline rendering methods, but at a greater computational cost. This makes ray tracing best suited for applications where the image can be rendered slowly ahead of time, such as in still images and film and television visual effects, and more poorly suited for real-time applications like video games where speed is critical. Ray tracing is capable of simulating a wide variety of optical effects, such as reflection and refraction, scattering, and dispersion phenomena (such as chromatic aberration).

We're a team of four who've realized this project by combing a series of modules and features to make a pretty fun ray tracer. This includes next features:
- Blinn-Phong shading
- Lambert shading
- Cell shading
- Super anti-aliasing
- Fast anti aliasin
- Cartoon effect
- Motion blur
- Visualization of normals
- Visualization of dots
- Draft mode
- Multithreading
- Reflection
- Refraction
- Outline
- JSON format map
\nFilters:
- Sepia
- Black-White
- Darkroom
Primitives:
- Sphere
- Half-sphere
- Disk
- Plane
- Cone
- Cylinder
- CD Disc
- Ellipsoid
	

All input parameters are set in a strictly formatted JSON format. And on this document will explain:
	1. How to write scenes on JSON.
  2. How to add switch on/off something raytrace effects
  3. How set multi spots of lights

# :cd: Installation
The project only work on Mac OS X.

It uses the MinilibX, a micro-library that provides an easy way to create a window and push an image on it.
```
make
```

# Usage
	./rt ./maps/__map__.json

# Command List
|                Key               |                Function                 |
| -------------------------------- |:---------------------------------------:|
| <kbd>+</kbd> <kbd>-</kbd>        | move camera up/down on y axis 	     |
| <kbd>Y</kbd> <kbd>H</kbd>        | look up/down          		     |
| <kbd>W</kbd> <kbd>S</kbd>        | look left/right      		     |
| <kbd>A</kbd> <kbd>D</kbd>        | look around    		     |
| <kbd>UP</kbd> <kbd>DOWN</kbd>    | move camera  up/down	             |
| <kbd>LEFT</kbd> <kbd>RIGHT</kbd> | move camera left/right   		     |
| <kbd>ENTER</kbd>                 | switch off/on lights		     |
| <kbd>F-19</kbd>                  | save image on PPM format to current dir |	     |


## Your map has to extension .json format (JavaScript Object Notation)
A complete map will have the following Elements specified by the user:
```
General options
Light
Objects

```


------
to be continued
