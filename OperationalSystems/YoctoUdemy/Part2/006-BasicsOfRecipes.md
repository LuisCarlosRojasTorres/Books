<!-- vscode-markdown-toc -->
* 1. [V040 - What is a Recipe](#V040-WhatisaRecipe)
* 2. [V041 - Recipe file Format](#V041-RecipefileFormat)
* 3. [V042 - How to build a Recipe - BitBake](#V042-HowtobuildaRecipe-BitBake)
* 4. [V043 - Recipe Fetch Stage](#V043-RecipeFetchStage)
* 5. [V044 - Recipe Unpack Stage](#V044-RecipeUnpackStage)
* 6. [V045 - Recipe Patch Stage](#V045-RecipePatchStage)
* 7. [V046 - Recipe Licensing](#V046-RecipeLicensing)
* 8. [V047 - Recipe Configure Stage](#V047-RecipeConfigureStage)
* 9. [V048 - Recipe Compile, Install and Package Stage](#V048-RecipeCompileInstallandPackageStage)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

##  1. <a name='V040-WhatisaRecipe'></a>V040 - What is a Recipe
- It is a fundamental component in the Yocto Project environment
- It is a text file `.bb`
- Each software component built by the OpenEmbedded build system requires a recipe to define the component.
- A recipe contains information about single piece of software. Such as:
  - download sources
  - patches applied to the sources (if needed)
  - special configuration options to apply
  - how to compile the source lines
  - how to package the compiled output
- Support for Project based on Autotools CMake and QMake

##  2. <a name='V041-RecipefileFormat'></a>V041 - Recipe file Format
- The name of a recipe follow this format: `<base_name>_<version>.bb`. For example
  - `dropbear_2019.78.bb`
    - base name: `dropbear`
    - version: `2019.78`
  - `tiff_4.0.10.bb`
    - base name: `tiff`
    - version: `4.0.10`
- lower case is recommended
- Do not include reserved suffixes like: `-native`, `-cross`, `-initial`, or `-dev`


##  3. <a name='V042-HowtobuildaRecipe-BitBake'></a>V042 - How to build a Recipe - BitBake
- Bitbake **parses** a recipe and then **generates** a list of tasks that can be executed by steps.
- Command: `$ bitbake basename`
- The most important tasks are (in dependency order i.e., they are executed in order):
	- `do_fetch`: Fetches the source code
	- `do_unpack`: Unpacks the source code into a working directory
	- `do_patch`: Locates patch files and applies them to the source code
	- `do_configure`: COnfigures the source by enabling and disabling any built-time and configuration options for the sw being built
	- `do_compile`: compiles the source in the compilation directory
	- `do_install`: copies the files from the compilation directory to a holding area
	- `do_package`: analyzes the content of the holding area and splits it into subsets based on available packages and files
	- `do_package_write_rpm`: creates the actual rpm packages and places them in the Package Feed area
- Generally the user only need to specify:
  - `do_configure`
  - `do_compile`
  - `do_install`
  - the other tasks are defined (automatically) by the YP build system.
- To execute an specific task of a recipe use the `-c` argument:
  - `$ bitbake -c compile dropbear`
- To list all tasks of a particular recipe
  - `$ bitbake <recipe name> -c listtasks`

##  4. <a name='V043-RecipeFetchStage'></a>V043 - Recipe Fetch Stage
- Fetching source files is the first thing the recipe shall do
- This is controlled by the `SRC_URI` variable
  - Each recipe SHALL have a `SRC_URI` variable which points to the source location.
- Bitbake support fetching source code from `git`, `svn`, `https`, `ftp` etc...
  - The format is the following: `scheme://url;param1;param2`, 
    - Where scheme can be: 
    - `https://` , `git://`, `svn://` for remote locations
    - `file://` for local files
- By default, sources are fetched in `BUILDDIR/downloads`
##  5. <a name='V044-RecipeUnpackStage'></a>V044 - Recipe Unpack Stage

##  6. <a name='V045-RecipePatchStage'></a>V045 - Recipe Patch Stage

##  7. <a name='V046-RecipeLicensing'></a>V046 - Recipe Licensing

##  8. <a name='V047-RecipeConfigureStage'></a>V047 - Recipe Configure Stage

##  9. <a name='V048-RecipeCompileInstallandPackageStage'></a>V048 - Recipe Compile, Install and Package Stage