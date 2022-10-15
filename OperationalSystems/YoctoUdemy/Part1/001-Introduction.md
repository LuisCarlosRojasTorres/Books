<!-- vscode-markdown-toc -->
* 1. [Elements of Embedded Linux](#ElementsofEmbeddedLinux)
* 2. [Yocto Project](#YoctoProject)
* 3. [Inputs and Outputs in Yocto](#InputsandOutputsinYocto)
* 4. [Setting up the Build Machine](#SettinguptheBuildMachine)
* 5. [What is POKY](#WhatisPOKY)
* 6. [What is metadata](#Whatismetadata)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

##  1. <a name='ElementsofEmbeddedLinux'></a>Elements of Embedded Linux

- Toolchain: The compiler and tools needed to create code for your target device.
- Bootloader: Initialize the HMI and loads the linux kernel
- Kernel: The heart of the system, managing system resources and interfacing with HW.  
- Root filesystem: Contains the libraries and programs that are un once the kernel has completed its initialization.

##  2. <a name='YoctoProject'></a>Yocto Project
It provides devs create their own custom Linux distributions for any HW architecture.
So, it is possible to create our own Ubuntu for our HMI

##  3. <a name='InputsandOutputsinYocto'></a>Inputs and Outputs in Yocto
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

##  4. <a name='SettinguptheBuildMachine'></a>Setting up the Build Machine
- 50 Gb of free disc space on a Linux Machine
- Required Packages are described  [HERE](https://docs.yoctoproject.org/ref-manual/system-requirements.html#ubuntu-and-debian)

##  5. <a name='WhatisPOKY'></a>What is POKY
- It is a reference/example distribution of Yocto. It is a combined repository of `OpenEmbedded Core`, `Bitbake`, `meta-yocto-bsp` (`bsp` board support packages) and `documentation`
- Yocto is the name of the company, POKY are the actual bits downloaded.
  
##  6. <a name='Whatismetadata'></a>What is metadataa
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

## OpenEmbedded Core

### OpenEmbedded Project
- Similar objectives to Yocto.
- It provides a set of metadata for a wide variety of achitectures, features and applications: 
  - Not a reference distribution.
  - Designed to be the foundation for others.

- On the other hand, Yocto focuses on provide *powerful*, *easy-to-use*, *inter-operable*, *well-tested tools*, *metadata* and *board support packages* for a core set of architectures and specific boards.
- HOWEVER, both OpenEmbedded and Yocto share a core collection of metadata called `openembedded-core` or `oe-core`

## Bitbake
- Same functionality as `make` 
- So, it is a task scheduler that parses python and shell script mixed code.
  - The code parsed generates and runs tasks, which are basically a set of steps ordered according to code dependencies.
  - It reads the `recipes` and follows them by fetching packages, building them and incorporating the results into bootable images.
  - It keeps track of all tasks being processed in order to ensure completion, maximizing the use of processing resources to reduce build time and being predictable.

## Meta-yocto-bsp
- It is a collection of information that defines how to support a particular HW device, set of devices, or HW platform.
- It includes information about HW features present on the device and kernal configuration information along with any additional HW drivers required.
- It lists any additional SW components required in addition to a generic Linux SW stack for both essential and optional platform features.
- It maintains several BSPs for:
  - Texas Instruments Beaglebone (`beaglebone`)
  - Freescale `MPC8315E-RDB`
  - Intel x86-based PCs and devices (`genericx86` and `genericx86-64`)
  - Ubiquiti Netwoeks EdgeRouter Lite (`edgerouter`)

NOTE: To develop on different hardware, you will need to complement `POKY` with `HW` Yocto layers.

## Other Poky Repositories
- `meta-poky`: Poky-specific metadata
- Documentation, which contains the Yocto Project source files used to make the set of user manuals.
- So, POKY includes:
  - Some `OE-CORE` components
  - Bitbake
  - demo-BSP's
  - helper scripts to setup environment
  - emulator QEMU to test the image
  
![Reference distribution](/OperationalSystems/YoctoUdemy/Part1/001.PNG)
