<!-- vscode-markdown-toc -->
* 1. [What is metadata](#Whatismetadata)
* 2. [What is recipe](#Whatisrecipe)
* 3. [What is configuration file](#Whatisconfigurationfile)
* 4. [What is classes](#Whatisclasses)
* 5. [What is Layers](#WhatisLayers)
* 6. [Why Layers](#WhyLayers)
* 7. [Find out layers used by bitbake build system](#Findoutlayersusedbybitbakebuildsystem)
* 8. [Where to get layers](#Wheretogetlayers)
* 9. [Yocto Project Compatible Layers](#YoctoProjectCompatibleLayers)
* 10. [What is image](#Whatisimage)
* 11. [What is Package](#WhatisPackage)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

##  1. <a name='Whatismetadata'></a> V019 What is metadata
- POKY = Bitbake + Metadata
- Metadata is collection of 
  - Configuration files `.conf`
  - Recipes `.bb` and `.bbappend`
  - Classes `.bbclass`
  - Includes `.inc`


##  2. <a name='Whatisrecipe'></a> V020 What is recipe
> A recipe is a set of instructions that describe how to prepare or make something.

- In Yocto: a recipe is a set of instructions that is read and processed by the bitbake.
- It has `.bb` extension
- It describes (for a given software component):
  - where you get source code
  - which patches to apply
  - configuration options
  - compile options (library dependencies)
  - install
  - license

##  3. <a name='Whatisconfigurationfile'></a> V021 What is configuration file
- It has the `.conf` extension
- Files which hold:
  - global definition of variables
  - user defined variables and 
  - hw configuration information
- They inform the build system to build and put into the image to support a particular platform.
- Types:
  - Machine Configuration Options: for specific machines e.g. Raspberry, Beaglebone etc 
  - Distribution Configuration Options: Each distro has a conf file
  - Compiler tuning options:
  - General Common COnfiguration Options:
  - User Configuration Options (`local.conf`): 

##  4. <a name='Whatisclasses'></a> V022 What is classes
- They are used to abstrack common functionality and share it amongst multiple recipes (`.bb`) files.
- To use a class file, you simple make sure the recipe inherits the class i.e., `inherit classname`.
- It has extension `.bbclass`
- They are usually placed in `classes` directory inside the `meta*` directory.
- Some examples are given:
  - `cmake.bbclass`: handles cmake in recipes.
  - `kernel.bbclass`: handles building kernels. Contains code to build  all kernel trees.
  - `module.bbclass`: provides support for building out-of-tree linux kernal modules.

##  5. <a name='WhatisLayers'></a> V023 What is Layers
- A collection of related recipes
  - Layer are folder which contain recipes.
- They usually follow the name convention `meta-<layername>`
- Poky has the following layers:
  - meta
  - meta-poky
  - meta-skeleton
  - meta-yocto-bsp etc...
##  6. <a name='WhyLayers'></a> V024 Why Layers
- Layers provided a mechanism to isolate meta data according to functionality, for instance BSPs, distribution configuration etc.
- Put all the configuration build into one layer limits and complicates future customization.
- So, because layers are divided by functionality, you can have a:
    - BSP layer
    - GUI layer
    - distro configuration
    - application layer
- Layers allow to wasily add entire sets of metadata and/or replace sets with other sets.
  - e.g., `meta-poky`, is itself a layer applied on top of the OE-Core metadata layer,
  - 
##  7. <a name='Findoutlayersusedbybitbakebuildsystem'></a> V025 Find out layers used by bitbake build system
 ** Which layers are used by POKY build system**?
 - `BBLAYERS`variable present in `build/conf/bblayers.conf` file list the layers which bitbake tries to find.
   - If `bblayers.conf` is not present when you start the build, the OpenEmbedded build system creates a default one from `bblayers.conf.sample`
 - Command to find all layers present: `bitbake-layers show-layers` 
 - Any number of layers can be included in the Yocto Project.

##  8. <a name='Wheretogetlayers'></a> V026 Where to get layers
- Layers in OpenEmbedded `https://layers.openembedded.org/layerindex/branch/master/layers/`
##  9. <a name='YoctoProjectCompatibleLayers'></a> V027 Yocto Project Compatible Layers
- `htps:/www.yoctoproject.org/software-overview/layers/`
- These layers are tested and are fully compatible with yocto project.
- OpenEmbedded layer index contains more layers but the content is less universally validated.


##  10. <a name='Whatisimage'></a> V028 What is image
- It is the top level recipe, it has a description, a license and inherits the `core-image` class
  - It is used alongside the machine definition
    - machine describes the HW used and its capabilities
- It is architecture agnostic and defines how the root filesystem is built, with what packages.
- By default, several images are provided in Poky.
- Command to see all the images available: `ls meta*/recipes*/images/*.bb`

##  11. <a name='WhatisPackage'></a> V029 What is Package
- It is a binary file with name `*.rpm`, `*.deb` etc
- A single recipe produces many packages.
  - All packages that a recipe generated are listed in the recipe `PACKAGES`variable of the recibe `.bb` file.
    - e.g., `PACKAGES =+ dummyPackage1 dummyPackage2 ...`