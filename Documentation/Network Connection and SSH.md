
# 1. Powering On
- Connect battery or power cord to the drone
- Confirm that the blue and green LEDs are on this indicates the drone is on

# 2. Initial USB-C Setup (if password is unknown or needs to be set/reset)

- Connect a USB-C cable from the drone to your computer
- On your Ubuntu terminal, enter:
```bash
adb shell
```
- Set a root password:
```bash
passwd
```
- You will be prompted to enter a new password. (Current Password: 1234567890)
For trouble shooting view [Video tutorial on setting up ADB and VOXL access](https://www.youtube.com/watch?v=QcAgAjAQDvQ) 

# 3. Connect via WiFi
- Disconnect the USB-C cable
- Connect your computer to the drone's hotspot:
	- SSID: `VOXL-00:0:ca:b3:5:3f`
	- Password: `1234567890`

# 4. SSH Into the Drone
In your Ubuntu terminal:
```bash
ssh root@192.168.8.1
```
When prompted, enter the password you set earlier.
If SSH login fails (permission denied), reconnect via USB-C and use abd to reset the password.

# 5. Transferring Files to the Drone
- On your Ubuntu machine locate the files you want to send.
- Use `abd push` only in you're connected via USB-C. This will land you in the superuser.
```
abd push <local_file_path> <target_path_on_drone>
```
Example:
```
adb push test_script.py /home/root/
```
**Note:** When using `adb shell`, you land in the root (`/`) directory and have full superuser access.

- If using WiFi, use SCP (Secure Copy)
```
scp <local_file_path> root@192.168.8.1:/desired/path/on/drone
```
Example:
```
scp test_script.py root@192.168.8.1:/home/root/
```
 **Note:** By default, `scp` places files in `/home/root/`.  
To copy files elsewhere (e.g., system directories like `/etc` or `/usr/local/bin`), you must:

1. First copy the file to `/home/root/` using `scp`.
    
2. Then SSH into the drone and use `mv` with superuser privileges to move the file:
```
ssh root@192.168.8.1 
mv /home/root/your_file /desired/system/path/
```

# 6. Running Python Scripts on the Drone
- SSH into the drone
- Navigate to the directory where the script was copied
- Run the script using the Python version you are using
```
python3 test_script.py
```
