import serial
from Tkinter import *

ser = serial.Serial("/dev/cu.AdafruitEZ-Link0122-SPP", 9600)
returned = "Nothing yet!"

root = Tk()
label = Label(root, text = returned, width = 300)
label.pack()
while True:
    returned = ser.readline()
    root.update_idletasks()
    print returned
