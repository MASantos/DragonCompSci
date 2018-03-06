% A Guide Into the RaspberryPi 3
% Miguel A. Santos 
% Sat Nov 11 2017

# Introduction

These notes provide a summary of what we already saw in class (G10 *Introduction to Computer Science*). 

They contain instructions on how to set up and connect to our raspberry pi (RP) and work with it using both
its command-line interface (cli) as well as its (remote) desktop.

In doing so, we are touching on some key ideas of computers:

1. Setting up local computer networks
2. Establishing secure, cryptographic connections between computers
3. Scanning a network to locate other machines connected or to audit ongoing transmissions.
4. Operating System and its management

# The Raspberry Pi 3 kit

For some recommendations on the equipment we will need in this course, you can following 
[this link](http://msantos.sdf.org/G10/RaspberryPi.html).

# Headless setup of your RaspberryPi3

Our goal is to be able to access, manage and use our Raspberry Pi 3 (RP3) directly from our 
laptop, i.e., without the need to connect it to an external monitor, not even using its own
charger.

This notes assume you have installed Raspbian as operating system (OS) of your RP.

In order to do that, we need to go through a few configuration steps. We need to

1. make sure our RP will be accepting connections. This will be required only once.
2. setup our laptop's network configuration.
2. connect and boot your RP. IF you have a Mac without ethernet port, you'll need to buy a USB-to-Ethernet adapter first.
3. find the network address of your RP, namely its IP address. This requires you to install additional
   software (Nmap).
4. Finally, we'll connect and log in to our RP using a secure connection via ssh. Windows users will need
   to install additional software (Putty)

## Enable ssh Connections to your RP

Insert the SD card of your RP in your laptop. Go to the folder ```boot```. There, create a text file called 
```ssh```. It doesn't have to have any content at all.

That's it!

## Setup your laptop network connections

We need to share our wifi from our laptop with the Ethernet (cable) network adapter. The latter is where we will connect our RP to.

### MacOS X

1. Open your ```System Preferences```  application. If you don't see it on your ```Dock```, access ```Launchpad``` and you'll find it there.
2. Go to ```Sharing```.
3. Select the ```Internet Sharing``` menu on the left panel.
4. On the right, make sure you select to _share your connection from your **WIFI** to computers using your **Ethernet**_.

That's it.


### Windows

1. Got to network and sharing control panel
2. On the left, click on adapter drivers
3. You'll then see icons for your Ethernet or local network adapter (ignore the one that says Nmap local) and for your wireless adapter. 
   You may see more. If you have one called "bridge", right-click on it and remove it.
4. Right-click on the wireless adapter icon, go to Properties and there select the Sharing tab.
5. Enable the (first) option of sharing with other computers.
6. If you are given a drop-down list of devices with which to share, choose the Ethernet/local network adapter (not the Nmap local!)

That's it.

## Connect and boot your RP

1. Connect the  ethernet cable to your PR on one side and to your laptop on the other end.
2. Connect the micro-USB end on the RP
2. Finally, insert the other end of the USB cable into your laptop's usb port.

Your RP should start lighting up its green and red LED's.

That's it. 

## Find your RP's IP address

Remark: Any IP address that starts with 169.254.x.y is not an actual, valid IP address. This means, if you see a device or computer with such an address it means it didn't get assigned any valid, working address: such computer would effectively be disconnected!

* **On Windows**: 
    1. Open an admin powershell window (press windows_key+x and select powershell admin)
    1. Type ```ipconfig``` and press enter. The output will be divided into different sections for each network device set up.
    3. Locate the section on your Local Ethernet device (not the Nmap local) and take note of the IP address that it has assigned. 
       This should be something starting with 192.168.x.y or 10.x.y.z, where x,y and z are decimal numbers between 0 and 255. 
       For argument's sake, let's say that the address your ethernet adapter got was 192.168.2.32.
* **On a Mac**: 
    1. Go to launchpad, open ```Other``, click on ```Terminal```.
    2. Type ```ifconfig``` and press enter. The output will be divided into different sections for each network device set up.
    3. Locate any section labeled with "bridge". On of the bridge devices should have an assigned IP. 
       For argument's sake, let's say that the address your ethernet adapter got was 192.168.2.32.
* **On a Linux box**:
    1. Open a terminal window: try pressing your "windows" key or simultaneously ```alt+spacebar```. 
       A search box should become visible. Type in there ```terminal```. 
       If the program is installed you should see either the name ```Terminal``` or ```Konsole```. Select it and press enter.
    2. Type ```ip a```. The output will be divided into different sections for each network device set up.
    3. Locate a section labelled ```en0```, or that starts with something similar, and take note of the IP address assigned to it. Say it was 192.168.2.32

On the command-line interface (cli), i.e., the terminal, issue the command ```sudo nmap -sS 192.168.2.32/24``` (ignore "sudo" in Windows computers).  

It will ask you for a password. If your computer password doesn't work, you'll need the *root* user password (ignore this in Windows computers).

If the RP has a correctly installed and working operating system and we set the network sharing correctly as well, then this command should output information on two systems: our own laptop and the raspberry pi. Identify the IP address of the raspberry pi. Let's assume the address your RP was assigned is 192.168.2.3.
 
Example of an output from an nmap hosts scanning:

	  $ sudo nmap -sS 192.168.2.0/24
	  
	  Starting Nmap 7.60 ( https://nmap.org ) at 2017-11-10 18:47 EST
	  Nmap scan report for 192.168.2.3
	  Host is up (0.00087s latency).
	  Not shown: 998 closed ports
	  PORT   STATE SERVICE
	  22/tcp open  ssh
	  80/tcp open  http
	  MAC Address: B8:27:EB:9B:E9:7C (Raspberry Pi Foundation)
	  
	  Nmap scan report for 192.168.2.1
	  Host is up (0.00014s latency).
	  Not shown: 998 filtered ports
	  PORT   STATE SERVICE
	  22/tcp open  ssh
	  53/tcp open  domain
	  
	  Nmap done: 256 IP addresses (2 hosts up) scanned in 8.85 seconds


## Establish a secure connection with your RP

* **On Windows**: Open the program Putty. Fill in the IP address of your RP (192.168.2.3 in this example) click on connect.
* **On the rest**: From the cli, issue the command ```ssh pi@192.168.2.3``` 

You will be asked for a password. If you haven't modified it before, this should be the default password for this default user on the RP, namely, *raspberry*.

Note, this last ssh command means: establish a secure connection to the computer with IP address 192.168.2.3 as user ```pi``` in that computer. 
If you would try with a random name instead of ```pi```, that password will not work.


# The Linux Shell: Useful Commands in our RP

* **```pwd```**: shows the name of the folder where we currently are at. The command stands for "present working directory". Directory is another word for folder. 
  When you just logged in as user *pi*, you are located in the folder ```/home/pi```. This folder is what's called *your home folder*.
* **```ls```**: lists the names of all visible files and folder within the present working directory. This command name stands for "list"
* **```ls -lFa```**: Is a variation of the previous one. It gives us a list with additional information on **all** in the present folder. For each file it will show information
  on the permission (read, write and execute) for the owner of the file, for the group the file has been assigned to, and for any other user in the system. It will also show the 
  size in bytes, kibibyte (1024 bytes), mibibytes (1024 kibibytes) or Gibibytes  (1024 mibibytes), and a timestamp. Additionally, if the entry is a folder the name is appended with a 
  forward slash (/).

    Example of a list output:

		msantos@masl-pi3:~ $ pwd
		/home/msantos
		msantos@masl-pi3:~ $ ls -lFha
		total 112K
		drwxr-xr-x 19 msantos msantos 4.0K Oct 29 19:01 ./
		drwxr-xr-x  4 root    root    4.0K Aug 19 17:55 ../
		-rw-------  1 msantos msantos 1.2K Nov 10 18:33 .bash_history
		-rw-r--r--  1 msantos msantos  220 Jan 14  2017 .bash_logout
		-rw-r--r--  1 msantos msantos 3.5K Aug 19 17:57 .bashrc
		drwxr-xr-x  6 msantos msantos 4.0K Oct 29 18:36 .cache/
		drwx------ 11 msantos msantos 4.0K Oct 29 18:49 .config/
		drwx------  3 msantos msantos 4.0K Sep 14 11:13 .dbus/
		drwxr-xr-x  2 msantos msantos 4.0K Sep 14 11:13 Desktop/
		drwxr-xr-x  2 msantos msantos 4.0K Sep 14 11:13 Documents/
		drwxr-xr-x  2 msantos msantos 4.0K Sep 14 11:13 Downloads/
		drwx------  2 msantos msantos 4.0K Oct 29 18:36 .gconf/
		drwxr-xr-x  2 msantos msantos 4.0K Sep 14 11:13 .gstreamer-0.10/
		-rw-------  1 msantos msantos   42 Oct 29 18:23 .lesshst
		drwxr-xr-x  2 msantos msantos 4.0K Sep 14 11:13 Music/
		drwxr-xr-x  2 msantos msantos 4.0K Sep 14 11:13 Pictures/
		drwx------  3 msantos msantos 4.0K Oct 29 18:36 .pki/
		-rw-r--r--  1 msantos msantos  675 Jan 14  2017 .profile
		drwxr-xr-x  2 msantos msantos 4.0K Sep 14 11:13 Public/
		drwx------  2 msantos msantos 4.0K Oct 28 14:07 .ssh/
		drwxr-xr-x  2 msantos msantos 4.0K Sep 14 11:13 Templates/
		drwxr-xr-x  3 msantos msantos 4.0K Sep 14 11:13 .themes/
		drwxr-xr-x  2 msantos msantos 4.0K Sep 14 11:13 Videos/
		-rw-------  1 msantos msantos 1.5K Oct 28 14:07 .viminfo
		drwx------  3 msantos msantos 4.0K Oct 29 19:03 .vnc/
		-rw-------  1 msantos msantos  102 Oct 29 19:01 .Xauthority
		-rw-r--r--  1 msantos msantos    0 Oct 28 03:59 .Xresources
		-rw-------  1 msantos msantos 7.4K Oct 29 19:01 .xsession-errors
* **```cd folder-name```**: Change directory into the folder "folder-name". Example:

		msantos@masl-pi3:~ $ pwd
		/home/msantos
		msantos@masl-pi3:~ $ cd Music
		msantos@masl-pi3:~/Music $ pwd
		/home/msantos/Music
* **```cd -```**: (that's a hyphen) This is a variation of the previous one. The effect is to go up one level. Example:

		msantos@masl-pi3:~/Music $  cd -
		/home/msantos
		msantos@masl-pi3:~ $ pwd
		/home/msantos
		msantos@masl-pi3:~ $
* **```cd ```**: Just without any folder name, this commands puts you back in your *home folder*!
* **```touch empty```**: Creates an empty file called *empty*.
* **```echo "hello world"```**: Prints to screen the string "hello world".
* **```echo "hello world" >> empty```**: Diverts the output string "hello world" into the file called *empty*, appending that string to the end of that files previous content (if it had one).
* **```echo "hello world" > empty```**: Diverts the output string "hello world" into the file called *empty*,  overwriting whatever previous content that file had!
* **```cat empty```**: Dump on screen the contents of the file *empty*.
* **```cp empty empty-copy```**:  Creates a copy of the file *empty* in the current folder naming the new copy *empty-copy*.



# Software Management in our RP

The tool to manage the software of our RP is ```apt```. With it we can update software, search for apps, install new software, remove old ones, and much more:

* **Update the database of available software**: Say we've been told a security vulnerability has been recently patched (this means fixed). 
  Before we can install this security update we would need to update the list of software packages available. The command for this is 

    ```sudo apt update```.
 
    If there are indeed update available, you will get a message saying 
 
    > ```n packages can be upgraded. Run 'apt list --upgradable' to see them.```
 
    where n is a number.
* **Search for a software package**: Say we want to see if there is any software available related to *music*. Issue the command 

    ```sudo apt search music``` 

    and we will get a list of programs that deal in any way with music (i.e., music players but also, e.g., programs to convert music files from one format, say mp3, to another, say wav).

    Say we search for a vnc program. 

    ```sudo apt search vnc``` 

    will provide us with a list of all software available that is related to the VNC communication protocol. 
    The actual package name of the software found is listed in green on the left of the screen for each entry. There you may find a program called *tightvncserver* for instance.
* **Install software**:  Say we want to install a software called *tightvncserver*. We would do it by issuing the command 

    ```sudo apt install tightvncserver```.
* **Remove software**: Say we don't want *tightvncserver* anymore. We can uninstall (or remove) it issuing the command 

    ```sudo apt remove tightvncserver```.

# VNC: Remote Desktop 

So far we only connected to our RP using the cli (command line interface). But our RP has as well a graphical desktop interface like any other computer. The question is then, how can we access that desktop without an external monitor? That is, we would like to see the RP's desktop directly on the screen of our laptops. 

The easiest way to do it is using the VNC protocol. Let's see how this works.

In your RP you need to set up a VNC **server**. This is a program that will *export* the RP's desktop to any user connected to the Pi that requests a her/his desktop view. 
After doing so, we will connect to the RP's desktop using a VNC **client** from our laptop.

## Set up a VNC server in your RP

1. In your RP: Install the program tightvncserver.
2. Once installed: Run the vnc server by issuing the command ```tightvncserver```. The first time you run it you will be asked to set up a password. 
   Choose a string between 6-8 characters. You may change it later without any problems. 
   Remember that password.

## Remotely Connecting to your RP's desktop

* **On Windows**: Download the program VNC Viewer, install and run it. When asked for it, provide the IP address of your RP and add the port 5901. That is, issue

    ```192.168.2.3:5901```

* **On MacOS**: Go to ```Finder```, within the menu ```Go```, choose ```Go to Server```. In the "Server address" box, enter ```vnc://pi@192.168.2.3:5901```

That's it!

Note: In case you forgot the VNC password you used previously, you may easily reset your password.

1. In your RP, issue ```vncpasswd```, 
2. enter twice the new password and say no to setting a "view-only" password.
    
That's it.
