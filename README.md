master
======

Master repository for ENGR3199 includes C and Python source code and supporting files

## Running Code

In order to use this code for a PIC24FJ128GB206 using Olin's board, read below

My System:
OSX 10.11 El Capitan
Latest homebrew installed

### Setting up system w/ MPLab
1) Install xc-16 (The 16-bit compiler compatible with this chip from [microchip](http://www.microchip.com/ "XC Compilers"). Note: must use the XC16 Compiler v1.25 to work!
2) Install MPLabX 3.20 from [microchip](http://www.microchip.com/pagehandler/en-us/family/mplabx/ "Microchip mplabx installer")
3) Install pyusb's tar file via [walac's github](https://walac.github.io/pyusb/ "PY USB")
    a) Extract tar file, navigate into newly created directory and run:
    '''
    python setup.py install
    '''
4) Install libusb by running
'''
brew install libusb
'''

### Setting up MPLabX to compile your code
5) From MPLabX, open a new project.
    a) For setup, choose a PIC-24-FJ-128GB-206 (Without the dashes) as the device (To make it easier to find, choose 16-bit MCUs in the Family filtering section)
    b) Choose XC-16 (v1.25) for your compilers
6) Import all files necessary for the code
    a) Source Files: Include all .c code here, in this case blink.c
    b) Header Files: Include all .h code here, in this case: common.h, config.h, timer.c, timer.h, ui.c, and ui.h
    c) Linker Files: Include .gld file here, in this case: app_p24FJ128GB206.gld
7) From MPLabX, click the hammer button at the top to BUILD the project.  If the output says "Build Successful," then a .hex file will be generated that is used on the board.

### Pushing code to the board
8) Navigate to the directory of the github install and use python to run the bootloadergui.py.
9) In BOOTLOADER mode, connect your device to your computer.  In order to enter bootloader, hold the bootloader button before connecting.
10) In Bootloader GUI, click "Connect".  It should now be connected to your board.
11) Import Hex (Command+I) from MPLabX's build directory <USER>/MPLABXProjects/<PROJECT_NAME>/dist/default/production/.  Default name of the hex is: <PROJECT_NAME>.X.production.hex
12) In Bootloader GUI, click "Write".  To see code working, click "Disconnect/Run"

