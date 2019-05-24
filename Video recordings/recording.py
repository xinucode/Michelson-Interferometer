#---------------------------------------
# Sarah Skinner 5-23-19
# run using the line
#     python3 recording.py
#---------------------------------------

from picamera import PiCamera
import datetime
import time

#timestamp for filename
T = time.asctime(time.localtime(time.time()))
T = T.replace(" ","_")
T = T.replace(":",".")

#coment for filename and length of time
comment = input("Enter comment for run: ")
comment = comment.replace(" ","_")
time = int(input("Enter number of seconds for run: "))
camera = PiCamera()
camera.resolution = (640, 480)
camera.exposure_mode = 'off'
camera.framerate = int(input("Enter framerate (30-90): "))
filename = 'recordings/' + T + "--" + str(time) + 'sec_' + str(camera.framerate) + 'fps_' + comment + '.h264'
camera.shutter_speed = int( 1/(int(camera.framerate)) )
print(filename)
print('Begin recording...')
camera.start_recording(filename)
camera.wait_recording(time)
camera.stop_recording()
print('End recording')
