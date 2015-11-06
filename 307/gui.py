import serial, thread
from Tkinter import *

ser = serial.Serial("/dev/cu.AdafruitEZ-Link0122-SPP", 9600)
root = ""
label = ""
returned = "Blank"

##def loopMain(*args):
##    global label, returned, root
##    while True:
##        returned = ser.readline()
##        root.update_idletasks()
##        print returned
            

def interLoop(*args):
    global label, returned, root
    root = Tk()
    label = Label(root, text = returned, width = 300)
    label.pack()
    while True:
        returned = ser.readline()
        root.update_idletasks()
        print returned

thread.start_new_thread(interLoop, (None,))
##thread.start_new_thread(loopMain, (None,))
