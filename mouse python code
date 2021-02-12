import serial                                      
import pyautogui                                   
Arduino_Serial = serial.Serial('com3',9600)

while 1:
    x=int(Arduino_Serial.readline())
    y=int(Arduino_Serial.readline())
    z=int(Arduino_Serial.readline())
    print(x,y,z)
    if(x>0 or y>0):
        pyautogui.moveTo(1200-(40*x),600-(20*y))
    if (z>0)and(t>0):
        pyautogui.dragTo(1200-(40*x),600-(20*y),button='left')
    elif (z>0):
        pyautogui.click()
        t=z
