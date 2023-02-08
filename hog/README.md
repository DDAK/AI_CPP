## HOG detector in C++

Histogram of Oriented Gradients (HOG) is a computer vision and image processing technique used for object detection. It is based on the idea that the local appearance and shape of an object can be described by the distribution of intensity gradients or edge directions in an image. In the HOG descriptor, an image is divided into small cells and for each cell, the gradient orientations are calculated and grouped into a histogram. These histograms form a feature vector for each cell and for the whole image, which can be used as input to a classifier for object detection. The HOG detector has been widely used in various applications such as pedestrian detection, face detection, and others due to its robustness and efficiency in detecting objects with arbitrary shapes.

## Compiling HOG C++  program
Go into the hog folder and type:

``` bash
mkdir build && cd build 
cmake ..
cmake --build .
```
## Runing the program
That will build hog and you can run from build folder it using 
```
bin\hog
```