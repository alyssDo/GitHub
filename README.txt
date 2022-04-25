Alyssa Do - Final Project 

Hello! I hope you enjoyed my project! :)

Extra tidbits about the project down below.

LINK TO YOUTUBE VIDEO:
https://www.youtube.com/watch?v=9WO0OLzr88o

LINK TO SLIDES:
https://docs.google.com/presentation/d/1tv1qO0H8LpV5KwH92ySdjaekhAUEn5nqLrWIo2k_K1k/edit?usp=sharing

LINK TO WHAT PROJECT WAS BASED ON:
https://learn.parallax.com/tutorials/robot/shield-bot/robotics-board-education-shield-arduino/chapter-6-light-sensitive-2

DIFFICULTIES FACED/OVERCAME:
When the project was first completed, we tested it by shining the light onto the photoreceptors. For some reason, the robot wouldn't move until a couple of seconds later, and when it did, it would move straight then be stuck infinitely going around in a circle even when the light was not on the photoreceptors. We discovered that one of the the commands that set the wheel speeds ((maneuver(speedLeft, speedRight, 20);) was indented into the else loop for determining if the robot should move or not when it is exposed to light. This caused the speeds of the wheel to never update depending on where the light was shone. We fixed this by moving it out of the indent for the else loop, so the variables could update properly.

Additionally, we tried to have the robot play a tone before it moved. For some reason, when adding the code to make the robot play the tone in void setup, the robot would play the tone, but it would not move at all. Additionally, after removing the tone code, the robot still wouldn't move. The only way this could be fixed was by rewiring the whole robot. Unfortunately, we did not find the source of this bug in time, so the tone was not included in the final project.


WHAT WAS LEARNED:
For this project, we had to learn about void maneuver, and speedLeft and speedRight. Void maneuver controlls the speed and movement of the wheels; this value is based off of the values of speedLeft and speedRight. These two commands are used to control the speed of their respective wheels, and uses the difference in sensitivity of the light the photoreceptors receive to calculate the values. The difference between the light between the two photoreceptors is known as ndShade.

 
WHAT WAS ENJOYED:
Throughout the whole class, I was able to learn C++ along with Python at the same time. I liked how I was able to use the concepts that I learned in Python, such as for loops, and apply that knowledge to C++. After taking both classes, I think I like C++ more as a coding language (don't worry this isn't an insult to the Python class!!). While I do like the simplicity of Python, there are times where it gets difficult to do complex commands due to that simplicity. C++ did give me a headache sometimes due to the brackets and semicolons, but it felt a lot easier to do complex things due to the seperation between things that are looped/not looped with the different void functions.
