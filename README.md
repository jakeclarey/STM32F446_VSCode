*I am working on the steps for Linux and MacOS, I have done setup on Windows 10, Linux, MacOS,
and Windows 11 successfully. In addition to this, I am working on video guides on each of these
setup processes.*

*For Windows 10/11 (possibly 8 have not tested), I have created a separate repository with 
batchfile setup scripts. This is to make the environment setup process easier for an average user
as Windows is typically a nightmare setup-wise.*

The Windows 10/11 batchfile repository can be found here:
https://github.com/jakeclarey/F446RE_WindowsEnvironmentSetupScripts

# What is This
This is a project organization scheme that I use for STM32 development. This specific one is made
for the STM32F446RE microcontroller. I have used other ST MCUs and pretty much just clone this 
project and update it to whatever MCU I decided to go with for a project.

It was initially designed to work on MacOS for register level programming outside of STM32CubeIDE.
I started working with a MacOS machine and needed to do register level programming for class and
have since created this and adapted it to Windows as well (This project has also been tested using
Linux Mint). I enjoyed the customization of VS Code and wanted a way to bring it to the course.

This environment and all its included tasks should be compatible with Windows, MacOS, and Linux.

## Included Tasks

To build the code, I have included a couple tasks in the .vscode\tasks.json file. To invoke these 
task commands, the default shortcut is `Ctrl+Shift+B` (`Cmd+Shift+B` on MacOS). 

Explanation of each included task:

Build all will compile and link the code into a .bin, .hex, and .elf file set. These are used for 
uploading/debugging the microcontroller of the device. The files are found in the !build directory.

Build clean will clear the build directory of all files. This is useful for ensuring new code is 
compiled and linked on a new build and this task executes everytime before a Build all task is run.

Flash controller flashes the main.bin file to the controller. Whoa.. who could have guessed.

# Where are the MacOS or Linux setup Instructions??
I simply have not made them yet. A quick rundown of what packages are needed for MacOS and Linux 
are make, gcc-arm-embedded, stutil (found on a github repository by st-org), and libusb (found 
on a github repository by libusb). Of course, VS Code and a few extensions are also required. Those
extensions being, C/C++ Tools, marus25's Cortex-Debug. The rest of customization is up to the user.