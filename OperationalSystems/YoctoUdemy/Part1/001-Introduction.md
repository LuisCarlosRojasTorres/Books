## Elements of Embedded Linux

- Toolchain: The compiler and tools needed to create code for your target device.
- Bootloader: Initialize the HMI and loads the linux kernel
- Kernel: The heart of the system, managing system resources and interfacing with HW.  
- Root filesystem: Contains the libraries and programs that are un once the kernel has completed its initialization.

### Yocto Project
It provides devs create their own custom Linux distributions for any HW architecture.
So, it is possible to create our own Ubuntu for our HMI