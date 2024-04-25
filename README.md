*I am working on the steps for Linux and MacOS, I have done setup on Windows 10, Linux, MacOS,
and Windows 11 successfully. In addition to this, I am working on video guides on each of these
setup processes.*


# Steps to set up the programming environment for the Spherometer on a Windows 10 machine.

## Installing GNU Make to use the Makefile on Windows

**1.** Install GNU Make from https://gnuwin32.sourceforge.net/packages/make.htm using the 
"Setup program" option for installing.

**2.** Press the Windows key and type "path" to "Edit the system environment variables."

**3.** In this menu, press "Environment Variables...", then click the row that says "Path" in the upper 
table and then press edit. 

**4.** In here, press "New" and enter this file path "C:\Program Files (x86)\GnuWin32\bin" without the 
quotes. Then, press "Ok" in each menu until the System environment variables windows are all closed.

**5.** To test if this worked, open VSCode as an administrator and open a new terminal. Type the 
command "make --version" and it should respond with the version of GNU Make. You may have to exit 
and reopen VSCode after installing GNU Make for it to work.


## Installing the GCC ARM Compiler on Windows 

**1.** Install gcc-arm-none-eabi-XXXXXXX-win32.exe from the following website 
https://developer.arm.com/downloads/-/gnu-rm.

**2.** Run the installer tool and when it completes, make sure to check the 
"Add path to  environment variable" box and then select "Finish."

**3.** To test if this worked, exit and reopen VSCode as an administrator and open a new terminal. Type
the command "arm-none-eabi-gcc --version" and it should respond with the version of the ARM GCC 
Compiler.


## Installing CMake on Windows

**1.** Install cmake-XXXX-windows-x86_64.msi from the following website https://cmake.org/download/.

**2.** Run the installer tool and check the circle titled "Add CMake to the system PATH for all users." 
Then continue installing by pressing next in each following dialogue.

**3.** To test if this worked, exit and reopen VSCode as an administrator and open a new terminal. Type
the command "cmake --version" and it should respond with the version of CMake.


## Installing the ST-Link Tool on Windows

**1.** Open the following github repository https://github.com/stlink-org/stlink and on the right side 
of the website click on "Release v1.x.x" under the releases tab. This will take you to the releases
page.

**2.** On this releases page, go to version 1.7.0 and download the file titled 
"stlink-1.7.0-x86_64-w64-mingw32.zip" and go to the File Explorer location for it.

**3.** Extract the .zip in your File Explorer downloads open the folder and then copy the folder titled
"stlink-1.7.0-x86_64-w64-mingw32.zip" that contains the "bin" folder. MAKE SURE IT IS THE CORRECT 
FOLDER WHEN EXTRACTED. SOMETIMES DUPLICATES OCCUR AND IT CAN CAUSE A TON OF ISSUES.

**4.** Navigate to the C:/ drive of the laptop and create a new folder titled "stlink", open the new 
folder and paste the copied folder.

**5.** Press the Windows key and type "path" to "Edit the system environment variables."

**6.** In this menu, press "Environment Variables...", then click the row that says "Path" in the upper 
table and then press edit. 

**7.** In here, press "New" and enter this file path  
"C:\stlink\stlink-1.7.0-x86_64-w64-mingw32.zip\bin" without the quotes. Then, press "Ok" in each 
menu until the System environment variables until all windows are all closed.

**8.** To test if this worked, exit and reopen VSCode as an administrator and open a new terminal. Type
the command "stflash --version" and it should respond with the version of the stflash tool.

### VSCode Configuration (You can use any editor you want to if you are familiar with terminal and Make)

**1.** Open VSCode and open a new terminal. If you are unfamiliar with the command terminal, that is 
okay. What this step is for is for getting this repository onto your device.

**2.** In the terminal, type `git clone https://github.com/jakeclarey/STM32F446/`. This should clone the
repository to your device. Within here, open the Makefile.

**3.** In the Makefile at the very top, there is a variable titled `MACOS_LINUX`. If you are using 
MacOS or Linux, set the variable equal to 1, if on Windows, set the variable equal to 0. 

*This is important for the `make clean` rule. The way to clean a directory is different between 
MacOS/Linux and Windows. This variable is here to keep you, the user, out of the Makefile. The Makefile
can be confusing to understand if unfamiliar, and I want this to be as simple as possible.*

**4.** Open the terminal again, type `make all` and this should build the default Blinky project. If it
does not work. Look up the error code you receive and try to debug it. I am unsure about what errors can
occur because I don't run into them as frequently anymore. **One error I am aware of is the 
`missing separator` error. What this means is that somewhere in the code, a `tab` was replaced with a 
`space` which are interpreted differently by GNU Make. To fix this I recommend skimming the file where
tabs should be, and re-entering them, or the painful route, create a new Makefile and type up the same
text as the original one letter-by-letter. Odds are the the painful route is unnecessary.**

**5.** Now in the same terminal, enter `make clean`. This should clear out the !build folder. If it does
not, then the `make clean` selection for your operating system is bugged. To fix it, check and make sure
the `MACOS_LINUX` variable is set properly from step **3.** and then if it remains unworking, check for
information on the error received in the terminal.

## The setup for the environment should be complete after this. 

To build the code, I have included a couple tasks in the .vscode\tasks.json file. To invoke these 
task commands, the default shortcut is Ctrl+Shift+B. 

Explanation of each included task:

Build all will compile and link the code into a .bin, .hex, and .elf file set. These are used for 
uploading/debugging the microcontroller of the device. The files are found in the !build directory.

Build clean will clear the build directory of all files. This is useful for ensuring new code is 
compiled and linked on a new build and this task executes everytime before a Build all task is run.

Flash controller flashes the bin file to the controller. Whoa.. who could have guessed.

DFU controller is another way of flashing the code to the controller. It uses the dfu-util 
toolchain, I have not included steps on installing that on a Windows machine. This is because it 
does not apply to the board of this project by default.

DFU can be configured to work, but it is a lengthy process. DFU is mostly for flashing custom 
hardware. If you would like to know more about testing DFU on a NUCLEO board, I have done it before
and would be happy to explain the steps. 

# Steps to set up the programming environment for the Spherometer on a MacOs machine.

