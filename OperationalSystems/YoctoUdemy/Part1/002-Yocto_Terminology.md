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

##  6. <a name='WhyLayers'></a> V024 Why Layers

##  7. <a name='Findoutlayersusedbybitbakebuildsystem'></a> V025 Find out layers used by bitbake build system

##  8. <a name='Wheretogetlayers'></a> V026 Where to get layers

##  9. <a name='YoctoProjectCompatibleLayers'></a> V027 Yocto Project Compatible Layers

##  10. <a name='Whatisimage'></a> V028 What is image

##  11. <a name='WhatisPackage'></a> V029 What is Package