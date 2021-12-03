import numpy as np
import pyautogui
import cv2
from time import sleep
import requests

x = 940
y = 520
isSent = False

while 1:
    image = pyautogui.screenshot()
    image = cv2.cvtColor(np.array(image), cv2.COLOR_RGB2BGR)
    if(image[y, x, 2] == 255 and image[y, x, 1] == 255 and image[y, x, 0] == 255):
        if(isSent == False):
            requests.get(url = "http://192.168.4.1/on")
        isSent = True
    else:
        if(isSent):
            requests.get(url = "http://192.168.4.1/off")
        isSent = False
    sleep(0.1)