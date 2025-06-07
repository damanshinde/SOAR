
##  **Modify main.cpp and UDP Sender (C++)**
* Modify main.cpp file from Vicon_cpp_test folder and setup file using `DataStreamClient.h` to connect to Vicon Tracker and forward data via UDP. (Refer to main.cpp file for all changes)
* Connection string
```
std::string host = "192.168.10.2:801";
```
- Also sets up UDP socket targeting the drone IP (e.g., `192.168.8.1`) on port 9000.
- Compiled using:
```
g++ main.cpp -o vicon_client \  
  -I ../ \  
  -L ../ \  
  -lViconDataStreamSDK_CPP
```
- Ran using:
```
LD_LIBRARY_PATH=../ ./vicon_client
```
- The program
	- Receives subject name, segment translation, and rotation from Vicon.
	- Prints data locally.
	- Sends formatted UDP message containing name, position, and rotation to the drone on port 9000

## **Setting up Receiver on Drone**
- Create python script on drone `/home/root/vicon_receiver.py`:
```
import socket  
  
# Create a UDP socket  
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)  
s.bind(("0.0.0.0", 9000))  
print("Listening for Vicon data on UDP port 9000...")  
  
while True:  
    data, addr = s.recvfrom(1024)  
    print("Received:", data.decode())
```
- Run using:
```
python3 vicon_receiver.py
```
- Script opens a listener on port 9000 and prints incoming data over UDP 
