# ArduinoYun-TCP-Server

This is a simple TCP Server in Arduino Yun. My friend and I implementd it when we did the special topic and participated in MeiChu-Hackthon. There is a reason below why we wrote this code.

Originally, I just wanted to pass data to my android app or pc from my Arduino Yun via WiFi. However, I surveyed on the Internet and saw other developers almostly use bridge library or make Arduino a client which means other resources pass data to the Arduino.

## Explanation
To run this code, you have to know the IP of your Arduino Yun and put it in the client.py and select a corresponding port. Now, you can use Arduino Yun to pass the data to other side directly!

I pass the data from Arduino to PC via TCP socket, if you want to pass to other resources, just follow the TCP socket implementation in the corresponding platforms.