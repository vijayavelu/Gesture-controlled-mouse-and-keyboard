import serial
import pyautogui                                   

Arduino_Serial = serial.Serial('com3',9600)       

while 1:
    incoming_data = str (Arduino_Serial.readline())
    print (incoming_data)
   if 'Pause' in incoming_data:
        pyautogui.typewrite(['space'],0.2)],0.2)       
    if 'next' in incoming_data:                   
        pyautogui.hotkey('ctrl', 'right')      
         
    if 'previous' in incoming_data:               
        pyautogui.hotkey('ctrl', 'left')      
     
    if 'down' in incoming_data:                   
        #pyautogui.press('down')                   
        pyautogui.scroll(-40) 

    if 'up' in incoming_data:                     
        #pyautogui.press('up')                     
        pyautogui.scroll(40)
        
    if 'change' in incoming_data:                 
        pyautogui.keyDown('alt')                   
        pyautogui.press('tab')
        pyautogui.keyUp('alt')
        
    incoming_data = "";
