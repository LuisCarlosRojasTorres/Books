import cv2 as cv

## Open a jpeg file
'''
img = cv.imread('Photos/cat_large.jpg')
cv.imshow("i", img)
cv.waitKey(0)
'''  

## Open a video file
'''
capture = cv.VideoCapture(0)

while True:
    isTrue, frame = capture.read()

    cv.imshow('Video', frame)
    if cv.waitKey(20) & 0xFF== ord('d'):
        break

capture.release()
cv.destroyAllWindows()
'''