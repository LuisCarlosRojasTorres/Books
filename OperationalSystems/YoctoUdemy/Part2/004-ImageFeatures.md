<!-- vscode-markdown-toc -->
* 1. [V027 - Introduction to Image Features](#V027-IntroductiontoImageFeatures)
* 2. [V028 - How Image features actually work](#V028-HowImagefeaturesactuallywork)
* 3. [V029 - Example of Image features](#V029-ExampleofImagefeatures)
* 4. [V030 - Debug Tweaks](#V030-DebugTweaks)
* 5. [V031 - Read Only Root FileSystem](#V031-ReadOnlyRootFileSystem)
* 6. [V032 - Splash Screen](#V032-SplashScreen)
* 7. [V033 - Other Image Features](#V033-OtherImageFeatures)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

##  1. <a name='V027-IntroductiontoImageFeatures'></a>V027 - Introduction to Image Features
- `IMAGE_FEATURES/EXTRA_IMAGE_FEATURES` is a method for customize an Image, enabling or disabling high level Image features.
- `IMAGE_FEATURES/EXTRA_IMAGE_FEATURES` is made to enable special features for an Image.
  - E.g., empty password for root, debug Image, special packages, X11, splash screen etc...
- Use:
  - `IMAGE_FEATURES` from a recipe
  - `EXTRA_IMAGE_FEATURES` from `local.conf`

##  2. <a name='V028-HowImagefeaturesactuallywork'></a>V028 - How Image features actually work
- To understand, lets analyze the `meta/classes/core-image.bbclass`:
1. The class lists the available `IMAGE_FEATURES`.
   1. Most of the `IMAGE_FEATURES` map to package groups
   2. Other resolve as general configuration settings.
2. So, the file looks at the contents of the `IMAGE_FEATURES` variable and then maps or configures the feature accordingly.
3. Based on this information, the build system automatically adds the appropriate packages or configuratiions to the `IMAGE_INSTALL` variable.


##  3. <a name='V029-ExampleofImagefeatures'></a>V029 - Example of Image features
- Lets say, we select the `SSH server`
  - Yocto Project has two SSH Servers: 
    - `Dropbear`:  a minimal SSH server appropriate for resource-contrained environments
      - By default is included in: `core-image-sato`
        - It has `IMAGE_FEATURES += "splash package-management xll-base xll-sato ssh-server-openssh hwcodecs"`
    - `OpenSSH`: well-known standard SSH server implementation
      - By default is included in: `core-image-full-cmdline` and `core-image-lsb`
        - They have `IMAGE_FEATURES += "splash ssh-server-openssh"`
  - The `core-image-minimal` and `core-image-base` image does not contain an SSH server.
        - `core-image-base` only has `IMAGE_FEATURES += "splash"`

##  4. <a name='V030-DebugTweaks'></a>V030 - Debug Tweaks
- `debug-tweaks` permits to access ROOT without password, username: `root`
  - Very useful in implementation phase.
  - Not recommended for production
##  5. <a name='V031-ReadOnlyRootFileSystem'></a>V031 - Read Only Root FileSystem
- Root File System or `rootfs`
  - The root filesystem is at the top of the hierarchical file tree (also known as ‘/’). 
  - The Linux kernel directly mounts rootfs through the configuration argument ‘root=‘. 
  - The root filesystem also has mount points where we can mount other filesystems as well in order to connect them to this filesystem hierarchy.
  - It has a number of directories containing files critical for booting the system and system operations.
  - Content:
    - `/bin`: contains binaries of essential user commands that can be used by all users of the system
      - Here we can find ready-to-execute Linux commands like ls, cp, and echo, and shells like bash and csh. Moreover, /bin also contains the ready-to-run executables that may be required in order to boot or repair a system.
    - `/boot`: files used for booting an operating system, usually kernel images,
    - `/dev`:  where all device files are stored. The device files residing in this directory represent devices attached to our system. 
      - Applications can interact with them using system calls to perform I/O operations. The majority of the device drivers that correspond to the hardware devices are one of two types: block device drivers or character device drivers.
    - `/etc`: Configuration files specific to the local machine are contained here. This directory holds most global config files.
    - `/home`: The /home directory is the default location to create home directories for different users. 
    - `/lib`: The /lib directory contains essential shared libraries for system boot. 
    - `/media`: The /media directory contains subdirectories that are utilized as mount points when we connect any removable media devices to the system. We can find subdirectories or symbolic links to directories representing different removable media devices like CD-ROMs and USB sticks
    - `/mnt`: The /mnt directory is a mount point where we can mount a temporary filesystem that resides on a storage device like a hard-disk drive, USB stick, or CD-ROM. Unlike /media, where the system mounts removable media automatically, under /mnt we need to mount manually. This directory can be empty or may have subdirectories to mount individual devices.
    - `/opt`: The /opt directory contains optional software packages. 
    - `/root`: the home directory of the root user of the system.
    - `/run`: The /run directory stores the system information data describing the system since its booting.
    - and so on...
- So, it is important to have a `read-only rootfs` to:
  - Reduce wear on flash memory
  - eliminate system file corruption
- To do this:
  - Add `IMAGE_FEATURES += "read-only-rootfs"` in your Image recipe, or
  - Add `EXTRA_IMAGE_FEATURES += "read-only-rootfs"` in `local.conf`

NOTE: to know if an image has `read only rootfs`
1. Enter to `root` mode
2. Enter `mount`
3. It will appear the `/dev/root` disk with its description:
   1. `rw` read-write privileges
   2. `ro` read-only privileges


##  6. <a name='V032-SplashScreen'></a>V032 - Splash Screen
- Adding `IMAGE_FEATURES += "splash"` will add a Yocto image while system is loading.
- How to add a custom png image [link](https://dev.to/makame/customize-boot-splash-screen-in-yocto-3bip)?
  1. Clone meta-splash layer in your Poky project: git clone https://github.com/hamzamac/meta-splash.git
  2. Replace the default logo.png image in meta-splash/recipes-core/psplash/files with your logo image with name logo.png (the name can be customized in customize.bb)
  3. Bake your image


##  7. <a name='V033-OtherImageFeatures'></a>V033 - Other Image Features

- To add `GCC` and `G++`:
  - Add `IMAGE_FEATURES += "tools-sdk"` which install a full SDK that runs on the device.