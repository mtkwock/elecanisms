# Master
======

Master repository for ENGR3199 includes C and Python source code and supporting files

## Running Code

In order to use this code for a PIC24FJ128GB206 using Olin's board, read below

My System:
OSX 10.11 El Capitan
Latest homebrew installed

### Setting up system w/ MPLab
* Install xc-16 (The 16-bit compiler compatible with this chip from [microchip](http://www.microchip.com/ "XC Compilers"). Note: must use the XC16 Compiler v1.25 to work!
* Install MPLabX 3.20 from [microchip](http://www.microchip.com/pagehandler/en-us/family/mplabx/ "Microchip mplabx installer")
* Install pyusb's tar file via [walac's github](https://walac.github.io/pyusb/ "PY USB")
  * Extract tar file, navigate into newly created directory and run:
    ```
    python setup.py install
    ```
* Install libusb by running
```
brew install libusb
```

### Setting up MPLabX to compile your code
* From MPLabX, open a new project.  Give it a name ```<PROJECT_NAME>```
  * For setup, choose a PIC-24-FJ-128GB-206 (Without the dashes) as the device (To make it easier to find, choose 16-bit MCUs in the Family filtering section)
  * Choose XC-16 (v1.25) for your compilers
* Import all files necessary for the code
 * Source Files: Include all .c code here, in this case blink.c
 * Header Files: Include all .h code here, in this case: common.h, config.h, timer.c, timer.h, ui.c, and ui.h
  * Linker Files: Include .gld file here, in this case: app_p24FJ128GB206.gld
* From MPLabX, click the hammer button at the top to BUILD the project.  If the output says "Build Successful," then a .hex file will be generated that is used on the board.

### Pushing code to the board
* Navigate to the directory of the github install run bootloadergui.py ```python site_scons/booatloadergui.py```
* Connect the PIC to your computer in bootloader mode.
 * In order to enter bootloader from the device, hold the bootloader button before connecting.
 * Alternatively, hold the bootloader while resetting
* In Bootloader GUI, click "Connect".  It should now be connected to your board.
* Import Hex (Command+I) from MPLabX's build directory ```<USER>/MPLABXProjects/<PROJECT_NAME>/dist/default/production/```  Default name of the hex is: ```<PROJECT_NAME>.X.production.hex```
* In Bootloader GUI, click "Write".
* To see code working, click "Disconnect/Run"


### Minimum requirements for uploading new code through GUI
Assumes MPLabX are both open and the environment is set up through the above.

* Reset board into bootloader mode
* Compile code in MPLabX with Build or Build/Clean
* Load .hex file from bootloadergui.py
* Reconnect device from bootloader gui
* Write code
* Disconnect/Run