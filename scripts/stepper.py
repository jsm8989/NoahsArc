# stepper motor arduino control
# associated with the `sketch_oct05a` ino script

import serial 
arduino = serial.Serial('/dev/ttyACM0', 9600) # sometimes on my laptop it loads as ttyACM1 - watch this
print("Communication successful")

while True:                                             
	resp=input("Press 1 to activate stepper motor: ")  # query servo position
	if resp == "1":
		command = "500".encode('latin-1')
	else:
		print("Unsupported input, motor not activated")
		command = "0".encode('latin-1')
	arduino.write(command)                          # write position to serial port
	motor_status = str(arduino.readline())          # read serial port for arduino echo
	print(motor_status)                             # print arduino echo to console
