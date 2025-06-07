
## 1. Connect Ethernet Between Machines

- Unplug the Ethernet cable from the wall.
- Plug it into your personal Linux machine.
- This Ethernet connection is plugged into **MX1** port on the Windows machine.
- **MX2** connects to the Vicon camera system.

## 2. Power On and Calibrate Vicon Cameras

- Launch **Vicon Tracker** on the Windows machine.
- Plug in and calibrate the Vicon cameras.

## 3. Assign Static IP Addresses

### On the Windows machine:
- Navigate to: Control Panel → Network and Sharing Center → Change adapter settings
- Right-click on the adapter associated with the MX1 port.
- Go to: Properties → Internet Protocol Version 4 (TCP/IPv4) → Properties
- Set Static IP Address:
-  **IP Address:** `192.168.10.1` 
- **Subnet Mask:** `255:255:255:0` 
- **DNS:** Leave Blank
- **MX2 IP Address:** `192.168.10.2` 
### On your Linux machine:
- Set static IP manually to: `192.168.10.3`
- Confirm connection by running:
```bash
ping 192.168.10.1
```

## 4. **Download and Set Up the Vicon DataStream SDK (C++)**

On Linux machine download the SDK from [Vicon Data Stream SDK] [https://www.vicon.com/software/datastream-sdk/]and extract the archive and navigate to `~/Downloads/ViconDataStreamSDK_1.12.../Release/Linux64/` 

# 5. Create a C++ Test Project Folder
Inside the Release/../Linux64 directory:
```
mkdir vicon_cpp_test
cd vicon_cpp_test
```
Here you will place the provided main.cpp file. 

# 6. Compile the Code

From inside the vicon_cpp_test directory:

```
g++ main.cpp -o vicon_client \
  -I ../ \
  -L ../ \
  -lViconDataStreamSDK_CPP
```

# 7. Run the Executable
Ensure the SDK’s `.so` library is found by setting the `LD_LIBRARY_PATH`:

` LD_LIBRARY_PATH = ../ ./vicon_client
`
# 8. See Live Tracking Data
If everything is working properly, you'll see a terminal output like:
``Pos:[123.4, -567.8, 910.1] Rot:[2.3, 0.0, 0.51]``
