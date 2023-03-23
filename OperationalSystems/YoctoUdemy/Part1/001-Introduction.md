<!-- vscode-markdown-toc -->
* 1. [Elements of Embedded Linux](#ElementsofEmbeddedLinux)
* 2. [Yocto Project](#YoctoProject)
* 3. [Inputs and Outputs in Yocto](#InputsandOutputsinYocto)
* 4. [Setting up the Build Machine](#SettinguptheBuildMachine)
* 5. [What is POKY](#WhatisPOKY)
* 6. [What is metadataa](#Whatismetadataa)
* 7. [OpenEmbedded Core](#OpenEmbeddedCore)
	* 7.1. [OpenEmbedded Project](#OpenEmbeddedProject)
* 8. [Bitbake](#Bitbake)
* 9. [Meta-yocto-bsp](#Meta-yocto-bsp)
* 10. [Other Poky Repositories](#OtherPokyRepositories)
* 11. [Hello World of Poky](#HelloWorldofPoky)
* 12. [Run generated Image in QEMU](#RungeneratedImageinQEMU)
* 13. [Build and Run QEMU ARM](#BuildandRunQEMUARM)
* 14. [Run QEMU in non graphic mode](#RunQEMUinnongraphicmode)
* 15. [Add Isusb to Yocto Image](#AddIsusbtoYoctoImage)
* 16. [Build and Run Core Image Sato](#BuildandRunCoreImageSato)
* 17. [Challenge](#Challenge)
* 18. [Resources](#Resources)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

##  1. <a name='ElementsofEmbeddedLinux'></a> V001 Elements of Embedded Linux

- Toolchain: The compiler and tools needed to create code for your target device.
- Bootloader: Initialize the HMI and loads the linux kernel
- Kernel: The heart of the system, managing system resources and interfacing with HW.  
- Root filesystem: Contains the libraries and programs that are runned once the kernel has completed its initialization.

##  2. <a name='YoctoProject'></a> V002 Yocto Project
It provides devs create their own custom Linux distributions for any HW architecture.
So, it is possible to create our own Ubuntu for our HMI

##  3. <a name='InputsandOutputsinYocto'></a> V003 Inputs and Outputs in Yocto
- Input: The specification that describes what we want
  - Kernel configuration
  - Hardware name
  - Packages/Binaries to be installed
- Output: A linux based embedded OS with
  - Linux Kernel
  - Root File System
  - Bootloader
  - Device tree
  - Toolchain

##  4. <a name='SettinguptheBuildMachine'></a> V004 Setting up the Build Machine
- 50 Gb of free disc space on a Linux Machine
- Required Packages are described  [HERE](https://docs.yoctoproject.org/ref-manual/system-requirements.html#ubuntu-and-debian)

##  5. <a name='WhatisPOKY'></a> V005 What is POKY
- It is a reference (i.e. example) distribution of Yocto. 
  - Yocto uses Poky to build images!
- It is a combined repository of `OpenEmbedded Core`, `Bitbake`, `meta-yocto-bsp` (`bsp` board support packages) and `documentation`
  - It not contain binary files, it is a wprking example of hot to build your own custom linux distro for targered hw.
- Yocto is the name of the company, POKY are the actual bits downloaded.  
  
##  6. <a name='Whatismetadataa'></a> V006 What is metadata
 `Data that describes and gives information about other data`
 So:
 - It refers to the build instructions:
   -  Configuration files (`.conf`). 
   -  Recipes (`.bb` and `bbappend`)
   -  Classes (`.bbclass`)
   -  Includes (`.inc`)
 - It refers commands and data used to indicate what versions of software are used.
 - Where they are obtained from
 - Semantic versioning of the packages used (including patches)

##  7. <a name='OpenEmbeddedCore'></a> V007 OpenEmbedded Core

###  7.1. <a name='OpenEmbeddedProject'></a> OpenEmbedded Project
- Similar objectives to Yocto.
- It provides a set of metadata for a wide variety of achitectures, features and applications: 
  - Do Not have a reference distribution.
  - Designed to be the foundation for others.

- On the other hand, Yocto focuses on provide *powerful*, *easy-to-use*, *inter-operable*, *well-tested tools*, *metadata* and *board support packages* for a core set of architectures and specific boards.
- HOWEVER, both OpenEmbedded and Yocto share a core collection of metadata called `openembedded-core` or `oe-core`

##  8. <a name='Bitbake'></a> V008 Bitbake
- Same functionality as `make` 
- So, it is a task scheduler that parses python and shell script mixed code.
  - The code parsed generates and runs tasks, which are basically a set of steps ordered according to code dependencies.
  - It reads the `recipes` and follows them by fetching packages, building them and incorporating the results into bootable images.
  - It keeps track of all tasks being processed in order to ensure completion, maximizing the use of processing resources to reduce build time and being predictable.

##  9. <a name='Meta-yocto-bsp'></a> V009 Meta-yocto-bsp
- BSP stands for (Board Support Package)
- It is a collection of information that defines how to support a particular HW device, set of devices, or HW platform.
- It includes information about HW features present on the device and kernel configuration information along with any additional HW drivers required.
- It lists any additional SW components required in addition to a generic Linux SW stack for both essential and optional platform features.
- It maintains several BSPs for:
  - Texas Instruments Beaglebone (`beaglebone`)
  - Freescale `MPC8315E-RDB`
  - Intel x86-based PCs and devices (`genericx86` and `genericx86-64`)
  - Ubiquiti Netwoeks EdgeRouter Lite (`edgerouter`)

NOTE: To develop on different hardware, you will need to complement `POKY` with `HW` Yocto layers.

##  10. <a name='OtherPokyRepositories'></a> V010 Other Poky Repositories
- `meta-poky`: Poky-specific metadata
- Documentation, which contains the Yocto Project source files used to make the set of user manuals.
- So, POKY includes:
  - Some `OE-CORE` components
  - Bitbake
  - demo-BSP's
  - helper scripts to setup environment
  - emulator QEMU to test the image
  
![Reference distribution](/OperationalSystems/YoctoUdemy/Part1/001.PNG)

##  11. <a name='HelloWorldofPoky'></a>  V011 Hello World of Poky
1. Clone the poky repository `git clone git://git.yoctoproject.org/poky`
  - Then `cd poky` and `ls`, the following folders will appear:
    - `bitbake`: task scheduler
    - `meta-poky`: poky metadata
    - `documentation`
2. Checkout the lates `branch/release` : `git checkout <latest release>`
3. Prepare the build environment. Poky provides a script `oe-init-build-env`, which should be used to setup the build environment, including the Bitbake utility to your path: `source poky/oe-init-build-env buildName`
  - Where `buildName` is an optional parameter for the name of the directory where the environment is set. It defaults to `build`
  - This command *moves* you in a build folder and create two files `local.conf`, `bblayers.conf` inside the `conf` folder.
  - If we enter `echo $PATH` in the `buildName` directory it will appear the following commands telling that poky scripts are available:
  ``` console
  /home/redtower02/poky/scripts:
  /home/redtower02/poky/bitbake/bin:
  /home/redtower02/.local/bin:
  /usr/local/sbin:
  /usr/local/bin:
  /usr/sbin:
  /usr/bin:
  /sbin:
  /bin:
  /usr/games:
  /usr/local/games:
  /snap/bin:
  /snap/bin:
  /home/redtower02/.dotnet/tools
  ```
1.  Building Linux Distribution: 
  - `bibake <image_name>`: so one example to test this is `bitbake core-image-minimal` (It will take a long time!).
  - `time bitbake core-image-minimal`
##  12. <a name='RungeneratedImageinQEMU'></a> V012 Run generated Image in QEMU
- Quick Emulator or QEMU is a free and open source software package that performs hardware virtualization.
- The QEMU based machines allow test and development withouth real hardware.
- It has support for: `x86`, `x86-64`, `ARM` and so on.
- Poky provides a script `runqemu` which allow you to start the QEMU using a yocto image
- The command is `runqemu <machine> <zimage> <filesystem>`
  - `runqemu -h` to get help
  - For the image built in the previous section: `runqemu qemux86-64 core-image-minimal`
    - To turn off the emulator use `poweroff`

NOTE: To see all the scripts in poky use the following command `ls ../source/poky/scripts`
##  13. <a name='BuildandRunQEMUARM'></a> V013 Build and Run QEMU ARM
- To build a `core-image-minimal` for `ARM` processors:
  - Edit `./build/conf/local.conf` 
  - Set `MACHINE = qemuarm` and save and close the file (by default `MACHINE = qemux86-64`).
  - Then enter the following commands in terminal
    - `$ source poky/oe-init-build-env`
    - `$ bitbake core-image-minimal`
    - `$ runqemu core-image-minimal`
##  14. <a name='RunQEMUinnongraphicmode'></a> V014 Run QEMU i n non graphic mode
- So far, the `QEMU` was runnin in a window.
- To run `QEMU` in a terminal, use the following command: `runqemu core-image-minimal nographic`
  
##  15. <a name='AddIsusbtoYoctoImage'></a> V015 Add Isusb to Yocto Image
- If we try to use the `lsusb` command in the image from previous section, the console will show the following message `Command Not Found`
  - `lsusb` command: display the information about USB buses and the devices connected to them. The properties displayed are speed, BUS, class, type details, etc.
- So, **How can we add a package to the core-image-minimal?**
  1. Open `local.conf` file and add the recipe name.
     - `IMAGE_INSTALL_append = "usbutils"` for `lsusb`
  2. Then `bitbake core-image-minimal`
##  16. <a name='BuildandRunCoreImageSato'></a> V016 Build and Run Core Image Sato
- `core-image-sato`: is a X11 Window-system-based image with a SATO theme and a GNOME mobile desktop environment.
- `$ bitbake core-image-sato`
- `$ runqemu qemuarm core-image-sato`
##  17. <a name='Challenge'></a>  V017 Challenge
- Nothing
##  18. <a name='Resources'></a> V018 Resources 
- Nothing