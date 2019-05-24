#photodiode + oscilliscope
from picamera import PiCamera
import datetime
import time
import numpy as np
import array
import cv2 as cv

#record the video
T = time.asctime(time.localtime(time.time()))
T = T.replace(" ","_")
T = T.replace(":",".")
size = 32
fps = 120

comment = raw_input("Enter comment for run: ")
comment = comment.replace(" ","_")
time = int(input("Enter number of seconds for run: "))
camera = PiCamera()
camera.resolution = (size, size)
camera.framerate = fps
camera.exposure_mode = 'off'
filename = 'recordings/' + T + "--" + str(time) + 'sec_' + str(fps) + 'fps_' + comment + '.h264'
filename2 = 'recordings/' + T + "--" + str(time) + 'sec_' + comment + '.csv'
print(filename)
print('Begin recording...')
camera.start_recording(filename)
camera.wait_recording(time)
camera.stop_recording()
print('End recording')



#photodiode + oscilloscope
vidcap = cv.VideoCapture(filename)
i = 0
count = 30
height = 2
width = 2
amplitude = 0.0

blank_image = np.zeros((height,width,3), np.uint8 )
blink = cv.cvtColor(blank_image, cv.COLOR_BGR2GRAY)
#intensity = array.array( 'd', [0.0] )
data = open(filename2,"w+")
data.write( "sec,amplitude\r\n")
success = True
print("Writing data...")
while (success):

  #print(i)
  success,image = vidcap.read()
  
  if(success!=1): 
    break
  
  i = i+1
  
  gray = cv.cvtColor(image, cv.COLOR_BGR2GRAY)

  blink[0][0] = gray[size/2, size/2]
  blink[0][1] = gray[size/2, size/2+1]
  blink[1][0] = gray[size/2+1, size/2]
  blink[1][1] = gray[size/2+1, size/2+1]
  
  if ( blink[0][0] == 255 ):
    print( "Saturation!")
  if ( blink[0][1] == 255 ):
    print( "Saturation!")
  if ( blink[1][0] == 255 ):
    print( "Saturation!")
  if ( blink[1][1] == 255 ):
    print( "Saturation!")
    
  
  amplitude = blink[0][0] + blink[0][1] + blink[1][0] + blink[1][1]
  amplitude = float(amplitude)/4.0
  
  # if(i==0):
    # intensity(0,average)
  # else:
    # intensity.append(average)
  
  data.write( str(float(i)/float(fps)) + "," + str(amplitude) + "\r\n" )
  
    


print(filename2)
data.close()



#potentially add fft here


print("That's all folks")
