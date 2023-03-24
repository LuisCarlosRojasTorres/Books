<!-- vscode-markdown-toc -->
* 1. [V061 What is BSP Layer](#V061WhatisBSPLayer)
* 2. [V062 BSP Layer Naming Convention](#V062BSPLayerNamingConvention)
* 3. [V063 meta-ti Layer](#V063meta-tiLayer)
* 4. [V064 meta-ti vs meta-yocto-bsp](#V064meta-tivsmeta-yocto-bsp)
* 5. [V065 Add meta-ti to yocto build](#V065Addmeta-titoyoctobuild)
* 6. [V066 Build Yocto Image using meta-ti](#V066BuildYoctoImageusingmeta-ti)
* 7. [V067 Flash Yocto Image using wic utility](#V067FlashYoctoImageusingwicutility)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

##  1. <a name='V061WhatisBSPLayer'></a>V061 What is BSP Layer
- A collection of information (metadata) that defines hor to support:
  - A particular hw device
  - set of devices, or
  - hw platform
##  2. <a name='V062BSPLayerNamingConvention'></a>V062 BSP Layer Naming Convention
- Naming convention: `meta-<bsp_Name>`
- To find all the devices supported look into the `conf/machine/*.conf`
- For example: In `meta-yocto-bsp/conf/machine` we can find:
  - `beaglebone-yocto.conf`
  - `edgerouter.conf`
  - `genericx86-64.conf`
  - `genericx86.conf`
  
##  3. <a name='V063meta-tiLayer'></a>V063 meta-ti Layer
- meta-ti is a BSP layer for texas isntrument hw
  - `$ cd sources`
  - `$ git clone git://git.yoctoproject.org/meta-ti` it shall be cloned in a folder which contains `poky`
  - The default branch is `master`, so change the branch to the current branch you are using. i.e.,  `git checkout <nameOfPokyBranch>`
- HW Configuration Supported
  - Beagle Bone Black
  - Beagle Board
  - Panda Board
  - OMAP boards

##  4. <a name='V064meta-tivsmeta-yocto-bsp'></a>V064 meta-ti vs meta-yocto-bsp
- `meta-yocto-bsp`: an introductory BSP, it supports many architectures
- `meta-ti`: official Texas Instruments BSP with advanced features
##  5. <a name='V065Addmeta-titoyoctobuild'></a>V065 Add meta-ti to yocto build
- There are 2 methods to add layers:
  - Manual: edit `conf/bblayers.conf` file and andd the new layer to `BBLAYERS`
  - Automatic:
    - `$ bitbake-layers add-layer <path-to-new-layer>`
      
##  6. <a name='V066BuildYoctoImageusingmeta-ti'></a>V066 Build Yocto Image using meta-ti
Steps:
1. Source the environment script
   1. `source poky/oe-init-build-env`
   2. Add the layer `$ bitbake-layers add-layer <path-to-new-layer>` (layer at same branch than POKY)
2. Open `local.conf` and set `MACHINE` to Beaglebone: `MACHINE = 'beaglebone'`
3. Also add `INHERIT += "rm_work` to save disk space
4. Generate a minimal image
   1. `$ bitbake core-image-minimal`
5. Once the build is finished, you will find the outpu7t images in `$ BUILDDIR/tmp/deploy/images/beaglebone`


##  7. <a name='V067FlashYoctoImageusingwicutility'></a>V067 Flash Yocto Image using wic utility
- `wic` images are SD card images and can be directly written into sd-card
  - `core-image-minimal-beaglebone,wic,xz` is compressed wic image.
- It can be uncompressed using the `unxz` utility
  - `unxz core-image-minimal-beaglebone.wic.xz`
  - `ls -lh core-image-minimal-beaglebone.wic`
- Flash it to the sd card
  - `$ lsblk`
  - `$ sudo dd if=core-image-minimal-beaglebone.wic of=/dev/sdb bs=4096 status=progress && sync`

- NOTE: lsblk  lists  information  about  all  available or the specified block devices.