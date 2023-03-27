<!-- vscode-markdown-toc -->
* 1. [V021 - What is an Image](#V021-WhatisanImage)
* 2. [V022 - Creating a Custom Image](#V022-CreatingaCustomImage)
* 3. [V023 - What is a Package Group](#V023-WhatisaPackageGroup)
* 4. [V024 - Creating an Image from scratch](#V024-CreatinganImagefromscratch)
* 5. [V025 - Adding a Package to existing Image](#V025-AddingaPackagetoexistingImage)
* 6. [V026 - Reusing an existing Image to create a new Image](#V026-ReusinganexistingImagetocreateanewImage)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

##  1. <a name='V021-WhatisanImage'></a>V021 - What is an Image
- It is a top level recipe
  - it inherits an `image.bbclass`
- When an image is build, an entire Linux distribution is created from source. This includes:
  - Compiler, tools, libraries
  - Root filesystem: Base OS, services, applications etc.
- To see all the images in the project:
  - In poky folder: `$ ls meta*/recipes*/images/*.bb`
  - A list which includes `core-image-minimal` , `core-image-base` and others will be showed.
##  2. <a name='V022-CreatingaCustomImage'></a>V022 - Creating a Custom Image
- To add new packages or functionality
- Two ways:
  - From scratch:
  - Extenting an existing recipe (recomendable)
##  3. <a name='V023-WhatisaPackageGroup'></a>V023 - What is a Package Group
- A package group is a set of packages that can be included on any Image.
  - They are recipe files `.bb` and starts with `packagegroup-`
- If the package group name is added to the `IMAGE_INSTALL` variable, then all the packages defined by the package group will be installed into the root file of your target image.
- the packages groups are located in the subdirectories name `packagegroups`
  - To find the package group for a given `layer`
    1. Go to the `meta-<nameOfLayer>`  folder
    2. Use the command: `$ find recipes-*/ -name 'packagegroups'`. This will show all the folders with `packagegroups` in its name
    3. To see the `.bb` files use `$ ls` in one of the folders found in the previous step
##  4. <a name='V024-CreatinganImagefromscratch'></a>V024 - Creating an Image from scratch
- Inherit the `core-image` bbclass, which provides a set of image features
    - This class is located in `poky/meta/classes/core-image.bbclass` have a look!
- To create a custom image: 
  1. Create an `images` directory in `meta-<NameOfLayer>/recipes-<NameOfRecipe>/images`
  2. Create the `image` recipe: `<NameOfImage>.bb` 
  3. Add content to the image recipe, an example is given below:
    ``` console
    inherit core-image
    IMAGE_INSTALL = "packagegroup-core-boot"
    ```

##  5. <a name='V025-AddingaPackagetoexistingImage'></a>V025 - Adding a Package to existing Image
- Let say we want to add the `usbutils` to the image created in the previous section:
  1.  Edit the `<NameOfImage>.bb` adding the package in the `IMAGE_INSTALL` variable
  2.  The text inside the file shall look like this:
    ``` console
    inherit core-image
    IMAGE_INSTALL = "packagegroup-core-boot"
    IMAGE_INSTALL += "usbutils"
    ```
  3. verify that the package is valid with : `bitbake -e <nameOfImage> | grep ^IMAGE_INSTALL =`
     1. It shall appear the following text: `IMAGE_INSTALL="packagegroup-core-boot usbutils"`
  4. Then run: `bitbake <nameOfImage>`
     1. This will take less time than a normal build because BitBake uses the previous Image build and only add the new package. 


##  6. <a name='V026-ReusinganexistingImagetocreateanewImage'></a>V026 - Reusing an existing Image to create a new Image
- If an image mostly fits our needs, it is recommended to reuse it!!
- So to include `lsusb` (from `usbutils` package)
  1. Create an `images` directory in `meta-<NameOfLayer>/recipes-<NameOfRecipe>/images`
  2. Create the `image` recipe: `<NameOfImage>.bb` 
  3. Add content to the image recipe, an example is given below:
    ``` console
    require recipes-core/images/core-image-base.bb
    IMAGE_INSTALL_append = "usbutils"
    ```