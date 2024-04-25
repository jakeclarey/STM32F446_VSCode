*I am working on the steps for Linux and MacOS, I have done setup on Windows 10, Linux, MacOS,
and Windows 11 successfully. In addition to this, I am working on video guides on each of these
setup processes.*


#Steps to set up the programming environment for the Spherometer on a Windows 10  Laptop.

##Installing GNU Make to use the Makefile on Windows

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


##Installing the GCC ARM Compiler on Windows 

**1.** Install gcc-arm-none-eabi-XXXXXXX-win32.exe from the following website 
https://developer.arm.com/downloads/-/gnu-rm.

**2.** Run the installer tool and when it completes, make sure to check the 
"Add path to  environment variable" box and then select "Finish."

**3.** To test if this worked, exit and reopen VSCode as an administrator and open a new terminal. Type
the command "arm-none-eabi-gcc --version" and it should respond with the version of the ARM GCC 
Compiler.


##Installing CMake on Windows

**1.** Install cmake-XXXX-windows-x86_6**4.**msi from the following website https://cmake.org/download/.

**2.** Run the installer tool and check the circle titled "Add CMake to the system PATH for all users." 
Then continue installing by pressing next in each following dialogue.

**3.** To test if this worked, exit and reopen VSCode as an administrator and open a new terminal. Type
the command "cmake --version" and it should respond with the version of CMake.


Installing the ST-Link Tool on Windows

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

**3.** To test if this worked, exit and reopen VSCode as an administrator and open a new terminal. Type
the command "stflash --version" and it should respond with the version of the stflash tool.


###The setup for the environment should be complete after this. 

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
