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
**STAGE 1:**:  `do_fetch`
- Fetching source files is the first thing the recipe shall do
- This is controlled by the `SRC_URI` variable
  - Each recipe SHALL have a `SRC_URI` variable which points to the source location.
- Bitbake support fetching source code from `git`, `svn`, `https`, `ftp` etc...
  - The format is the following: `scheme://url;param1;param2`, 
    - Where scheme can be: 
    - `https://` , `git://`, `svn://` for remote locations
    - `file://` for local files
- By default, sources are fetched in `BUILDDIR/downloads`
- The `do_fetch` tasks uses the prefix of each entry in the `SRC_URI` variable value to determine how to fetch the source code.
- NOTE: Any patch files present, needs to be specified in `SRC_URI`

##  5. <a name='V044-RecipeUnpackStage'></a>V044 - Recipe Unpack Stage
**STAGE 2:**:  `do_unpack`
- All local files in `SRC_URI` are copied into the recipe's working directory in `$BUILDDIR/tmp/work/`
- When extracting a tarball, BitBake expects to find the extracted files in a directory named `<application>-<version>`
  - This is controlled by the `S` variable
  - If the tarball follows the above format, then `S`variable do not need to be defined.
- If the directory has another name, the `S` variable shall be defined.
- If you are fetching from a Source Control Management **SCM** like git or SVN, or your file is local to your machine, **you need to define S**
  - E.g., for git `S = ${WORKDIR}/git`

##  6. <a name='V045-RecipePatchStage'></a>V045 - Recipe Patch Stage
**STAGE 3:**:  `do_patch`
- Sometimes it is necessary to patch code after it has been fetched.
- Patches have `.patch`, `.diff` or compressed version of these suffixes e.g. `.diff.gz`.
- The `do_patch` task automatically applies these patches.
- The build system should be apple to apply patches with the `-p1` option (i.e., one directory level in the path will be stripped off).
- If your patch needs to have more directory levels stripped off, specify the number of levels using the `striplevel` option in the `SRC_URI` entry for the patch.

##  7. <a name='V046-RecipeLicensing'></a>V046 - Recipe Licensing
- A recipe shall have a `LICENSE` and `LIC_FILES_CHKSUM` variables:
- `LICENSE`:
  - it specifies the license for the sw
  - Tipically includes COPYING, LICENSE and README files.
  - If you dont know the license of of a software, look for its license in its source code.
    - Look at the top of a source file.
      - `LICENSE = GPLv2`
  - A collection of licenses are located at `meta/files/common-licenses/`
- `LIC_FILES_CHKSUM`:
  - The OpenEmbedded build system uses this variable to make sure the license text has not changed.
    - If it changed, the build produces an error.
    - Example taht assumes the sw has a copying file:
      - `LIC_FILES_CHKSUM = "file://COPYING;md5=xxx"`


##  8. <a name='V047-RecipeConfigureStage'></a>V047 - Recipe Configure Stage
**STAGE 4:**:  `do_configure`
- It provides a wa of setting build-time configuration options before compilation.
  - This is done running configure scripts with options, or modifying a build configuration file.
    - `Autotools`: `configure.ac` configuration file
    - `CMake`: `CMakeLists.txt` configuration file
    - Otherwise, it is necessary to provide a `do_configure` task in your recipe unless there is nothing to configure.

##  9. <a name='V048-RecipeCompileInstallandPackageStage'></a>V048 - Recipe Compile, Install and Package Stage

**STAGE 5:**:  `do_compile`
- `do_compile` task happens after source is fetched, unpacked and configured.


**STAGE 6:**:  `do_install`
- After compilation completes , BitBakes executes the `do_install` task
- All the built files with their hierarchy are copied to location that will mirror their locations on the target device,

**STAGE 7:**:  `do_package`
- This tasks splits the files produced by the recipe into logical components and package it correctly.
  - Even SW that produces a single binary still have debug symbols, docuentation and other logical components that should be split out.
  