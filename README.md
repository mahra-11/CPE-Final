# CPE-Final
User Manual:

This software is designed to help you create the ideal study environment by monitoring key factors that impact focus and productivity. The software integrates heart rate, sound, temperature, and light sensors to provide real-time feedback on your environment and stress levels. It tracks your heart rate to detect moments of stress. Sound sensors monitor noise levels to ensure a quiet, distraction-free space. Temperature sensors adjust the environment for comfort, while light sensors optimize lighting conditions to reduce eye strain. Together, these features work to create a personalized study atmosphere, helping you stay focused, relaxed, and productive.

1. Connect the Device
Plug the Adafruit Circuit Playground into your computer using the provided USB cable.
Ensure the heart sensor is securely wired:
S (Yellow) to Pin #10.
+ (Red) to VBATT.
– (Green) to GND.

2. Wear the Heart Sensor
Attach the heart rate sensor to a fingertip or earlobe.
Ensure it has proper skin contact for accurate readings.

3. Install Necessary Software
Download and install the Arduino IDE.
Add the Adafruit Circuit Playground library from the Library Manager.
Download CoolTerm for data logging and analysis (optional)

4. Upload the Code
Open the provided code file in the Arduino IDE.
Select the correct board and port from the Tools menu.
Upload the code to the device.

5. Start Monitoring
o   Open the Serial Monitor in the Arduino IDE to view real-time data.

6. Data Logging (Optional) 
o   Open CoolTerm
o   Click on Connections -> Options
o   Select the Adafruit device under serial port
o   Click on Connect, when done save file then disconnect.
