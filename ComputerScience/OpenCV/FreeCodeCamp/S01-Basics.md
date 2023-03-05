<!-- vscode-markdown-toc -->
* 1. [Basics](#Basics)
	* 1.1. [Reading Images and Video](#ReadingImagesandVideo)
		* 1.1.1. [To open a file](#Toopenafile)
		* 1.1.2. [To open large files](#Toopenlargefiles)
		* 1.1.3. [To open a video](#Toopenavideo)
	* 1.2. [Image Transformations](#ImageTransformations)
	* 1.3. [Drawing Shapes](#DrawingShapes)
	* 1.4. [Put Text on images and video](#PutTextonimagesandvideo)
* 2. [Advanced](#Advanced)
	* 2.1. [Color Spaces](#ColorSpaces)
	* 2.2. [BITWISE operations](#BITWISEoperations)
	* 2.3. [Masking](#Masking)
	* 2.4. [Historgram Computation](#HistorgramComputation)
	* 2.5. [Edge Detection](#EdgeDetection)
* 3. [Faces](#Faces)
	* 3.1. [Face Detection](#FaceDetection)
	* 3.2. [FaCe Recognition](#FaCeRecognition)
	* 3.3. [Deep Computer Vision](#DeepComputerVision)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->
 
##  1. <a name='Basics'></a>Basics
- Install opencv on powershell

``` console
pip install opencv-python
```
###  1.1. <a name='ReadingImagesandVideo'></a>Reading Images and Video

####  1.1.1. <a name='Toopenafile'></a>To open a file 

The following code opens a file and is commented:

``` python 
## 1. Imports OpenCV library 
import cv2 as cv
  
## 2. Read the image with a relative path
img = cv.imread('Photos/cat_large.jpg')
## 3. Show the image on a new window
cv.imshow("i", img)
## 4. This commands wait for a key to close the image window
cv.waitKey(0)
```
- Warning:
  - Visual Code needs to exact path to run the py file.

![Open in Terminal](/ComputerScience/OpenCV/FreeCodeCamp/uploads/001-OpenTerminal.png)

  - This opens the terminal in the right path, then is easy to call the python file to run the code
	
![Open in Terminal](/ComputerScience/OpenCV/FreeCodeCamp/uploads/002-OpenTerminal.png)

####  1.1.2. <a name='Toopenlargefiles'></a>To open large files
- OpenCV do not handle large files so it is necessary to resize the figures.

####  1.1.3. <a name='Toopenavideo'></a>To open a video
The following code opens a file and is commented:

``` python
## 1. Imports OpenCV library 
import cv2 as cv
  

## 2. Select video location
capture = cv.VideoCapture('Videos/dog.mp4')

## 3. Read each frame of the video
while True:
    isTrue, frame = capture.read()

    cv.imshow('Video', frame)
	## 3.2 Wait for a key or for the d key
    if cv.waitKey(20) & 0xFF== ord('d'):
        break

## 4. Release capture pointer
capture.release()git 
## 5. Close video window
cv.destroyAllWindows()
```
 
- After the video is played the following error is shown:
	- This only means that the video player reach the limit of the video and has no more frames	to play.
![Open Video](/ComputerScience/OpenCV/FreeCodeCamp/uploads/003-OpenVideo.PNG)

###  1.2. <a name='ImageTransformations'></a>Image Transformations



###  1.3. <a name='DrawingShapes'></a>Drawing Shapes

###  1.4. <a name='PutTextonimagesandvideo'></a>Put Text on images and video

##  2. <a name='Advanced'></a>Advanced

###  2.1. <a name='ColorSpaces'></a>Color Spaces

###  2.2. <a name='BITWISEoperations'></a>BITWISE operations

###  2.3. <a name='Masking'></a>Masking

###  2.4. <a name='HistorgramComputation'></a>Historgram Computation

###  2.5. <a name='EdgeDetection'></a>Edge Detection

##  3. <a name='Faces'></a>Faces

###  3.1. <a name='FaceDetection'></a>Face Detection

###  3.2. <a name='FaCeRecognition'></a>FaCe Recognition

###  3.3. <a name='DeepComputerVision'></a>Deep Computer Vision
