
## Step 1: Launch Wi-Fi Setup Wizard

Begin by starting the Wi-Fi setup wizard from the terminal:

```bash
voxl2:~$ voxl-wifi wizard
```

You will see output like the following:

```
Wifi is currently set up as follows:
	Current mode: station
	Current ssid: Registered4OSU

Station mode is for connecting to a normal wifi network.
In softap mode, the VOXL will broadcast its own wifi network.
Factory mode will set up softap with the following unique SSID:
	VOXL-00:c0:ca:b3:a5:3f
```


## Step 2: Select Wi-Fi Operation Mode

The wizard will prompt you to choose the desired mode of operation. To connect to an existing Wi-Fi network, choose `station` mode:

```
Please enter the intended Wi-Fi operation
Options:
	1) leave as-is
	2) station
	3) softap
	4) factory
Operation: 2
```


## Step 3: Enter Network SSID

You will then be asked to provide the SSID (network name) of the Wi-Fi you wish to connect to:

```
Please enter the SSID to connect to
SSID: YourNetworkNameHere
```

Enter the network name when prompted. If the network requires authentication, the wizard will guide you to enter the password.
- Current Wifi network is **Registered4OSU** since it does not require GUI or authentication.
- Password: WfqFLrV4bdyJrHcW
- Password expires 2026-04-30

## Step 4: Verify the Internet Connection

After configuring the Wi-Fi settings, validate the connection by pinging a known host (e.g., GitHub):

```bash
voxl2:~$ ping github.com
```

Sample output for a successful connection:

```
PING github.com (140.82.113.4): 56 data bytes
64 bytes from 140.82.113.4: icmp_seq=0 ttl=41 time=26.434 ms
64 bytes from 140.82.113.4: icmp_seq=1 ttl=41 time=19.919 ms
64 bytes from 140.82.113.4: icmp_seq=2 ttl=41 time=20.178 ms
64 bytes from 140.82.113.4: icmp_seq=3 ttl=41 time=19.376 ms
64 bytes from 140.82.113.4: icmp_seq=4 ttl=41 time=20.063 ms
^C
--- github.com ping statistics ---
5 packets transmitted, 5 packets received, 0% packet loss
round-trip min/avg/max/stddev = 19.376/21.194/26.434/2.634 ms
```

This confirms that the VOXL2 drone has successfully connected to the internet via Wi-Fi.
