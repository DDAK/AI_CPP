## Haar cascade in C++

Haar cascade is a machine learning-based object detection method used in computer vision and image processing. It is named after the Haar wavelets, which are mathematical functions that form the basis of the Haar cascade algorithm. The Haar cascade algorithm uses a series of simple rectangular filters to detect objects in an image. The filters are applied to the input image in a sliding window manner, and the output of each filter is combined to make a decision about the presence of an object in the current window. The Haar cascade algorithm is fast, efficient, and has been widely used in various applications, such as face detection, license plate recognition, and others.

## Compiling haar C++  program
Go into the haar folder and type:

``` bash
mkdir build && cd build
conan install ..
cmake ..
cmake --build .
```
This will build the program.
## Runing the program
Download the pretrained cascade detector for opencv git [repo](https://github.com/opencv/opencv/tree/master/data/haarcascades). The opencv repo has many pretrained haar detector and I am using one of those in the example below.

You can run haar program from build folder while passing the pretrained haar cascade file with the path.

For example:
```
bin\haar haarcascade_frontalcatface.xml
```
