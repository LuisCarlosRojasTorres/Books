<!-- vscode-markdown-toc -->
* 1. [V049 - Recipe for C Program](#V049-RecipeforCProgram)
* 2. [V050 - Install Keyword](#V050-InstallKeyword)
* 3. [V051 - WORKDIR](#V051-WORKDIR)
* 4. [V052 - OpenEmbedded Variables](#V052-OpenEmbeddedVariables)
* 5. [V053 - Exploring WORKDIR](#V053-ExploringWORKDIR)
* 6. [V054 - Recipe Build in deep](#V054-RecipeBuildindeep)
* 7. [V055 - Recipe Build in deep 2](#V055-RecipeBuildindeep2)
* 8. [V056 - Adding Recipe to Image Root FileSystem](#V056-AddingRecipetoImageRootFileSystem)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

##  1. <a name='V049-RecipeforCProgram'></a>V049 - Recipe for C Program
- Lets say we want to include the following program into the RootFS or into an Image:
  
``` c
#include <studio.h>
int main()
{
    printf("Hello World\n");
    return 0;
}
```

- Steps to follow:
Stage 1: Create a file `userprog.c` with the content above
Stage 2: Create a folder in the folder `recipes-example` called `myhello`
- `mkdir -p recipes-example/myhello`
Stage 3: Create a `files` folder inside this location and copy the `userprog.c` into it
- `mkdir -p recipes-example/myhello/files`
Stage 4: Create a recipe file called `myhello_0.1.bb` with the following content:
- To obtain the `md5` of a license:
  - Go to `poky/meta/files/common-licenses`. There are all the licenses available e.g., MIT , LGPL etc...
  - To calculatethe `md5` use `md5sum`, for example:
    - `md5sum MIT`: ` `
    - `md5sum ADSL`: `7ddd727dfd24eb311bcc7f5fd1f8ff67`
  - `do_install`: copy the compiled program in the `rootfs`
``` console
DESCRIPTION = Dummy description
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/MIT;md5=0835ade698e0bcf8506ecda2f7b4f302"

SRC_URI = "file://userprog.c"

S = "${WORKDIR}"

do_compile(){
   ${CC} userprog.c ${LDFLAGS} -o userprog
}
do_install(){
   install -d ${D}${bindir}
   install -m 0755 userprog ${D}${bindir}
}
```

Stage 5: `bitbake myhello`

- NOTE: What is `S` and `D`
  - `S`: The location in the Build Directory where unpacked recipe source code resides. By default, this directory is `${WORKDIR}/${BPN}-${PV}`, where `${BPN}` is the base recipe name and `${PV}` is the recipe version.
  - `D`: The destination directory. The location in the Build Directory where components are installed by the `do_install` task. This location defaults to `${WORKDIR}/image`

##  2. <a name='V050-InstallKeyword'></a>V050 - Install Keyword
- `install` not only copy files but also changes its ownership and permissions and optionally removes debugging symbols from executables.
  - It is a combination of: `cp`, `chown`, `chmod` and `strip`
    - `cp`:
    - `chown`: used to change the file Owner or group. Whenever you want to change ownership you can use chown command. 
    - `chmod`: used to change the access mode of a file.
    - `strip`: GNU strip discards all symbols from object files `objfile`.  
      - `strip` modifies the files named in its argument, rather than writing modified copies under different names.


##  3. <a name='V051-WORKDIR'></a>V051 - WORKDIR
- The location of the work directory in which the OpenEmbedded build system buils a recipe.
- It is located within the TMPDIR directory structure and is specific to the recipe being built and the system for which it is being built.
- The `WORKDIR` directory is defined as follows:
  - `{TMPDIR}/work/${MULTIMACH_TARGET_SYS}/${PN}/${EXTENDPE}${PV}-${PR}`
  - Where:
    - `TMPDIR`: The top-level build output directory
    - `MULTIMACH_TARGET_SYS`: The target system identifier
    - `PN`: the recipe name
    - `EXTENDPE`: mostly blank
    - `PV`: the recipe version
    - `PR`: the recipe revision

##  4. <a name='V052-OpenEmbeddedVariables'></a>V052 - OpenEmbedded Variables
- Variables:
  - `S`: Contains the unpacked source files for a given recipe.
  - `D`: The destination directory (root directory of where the files are installed, before creating the image).
  - `WORKDIR`: The location where the OpenEmbedded build system builds a recipe (i.e., does the work to create the package).
  - `PN`: The name of the recipe used to build the package.
  - `PV`: The version of the recipe used to build the package.
  - `PR`: The revision of the recipe used to build the package.
- To see the variables of a recipe:
  - `bitbake -e <recipe-folder> | grep ^<OpenEmbeddedVariable>=`
    - e.g., `bitbake -e myhello | grep ^WORKDIR=` 
      - output: `WORKDIR="/home/.../tmp/work/core2-64-poky-linux/myhello/0.1-r0"`
      - it can be compared with the format presented in previous section `{TMPDIR}/work/${MULTIMACH_TARGET_SYS}/${PN}/${EXTENDPE}${PV}-${PR}`
- To see the list of task that will be performed for a given recipe:
  - `bitbake -c listtasks <RecipeName>`


##  5. <a name='V053-ExploringWORKDIR'></a>V053 - Exploring WORKDIR
- After `bitbake myhello` the compiled files are located in `WORKDIR`
- Lets say that `WORKDIR` is `/home/.../tmp/work/core2-64-poky-linux/myhello/0.1-r0` folder from previous section
  - There are many folders and also the `userprog.c` and `userprog` files


##  6. <a name='V054-RecipeBuildindeep'></a>V054 - Recipe Build in deep
- `bitbake <RecipeName>` in steps:
  - `bitbake -c fetch <RecipeName>`: creates the order tasks and logs
    - `run.do_fetch`: script 
  - `bitbake -c unpack <RecipeName>`: files are copied to the working directory e.g. `userprog.c` file
  - `bitbake -c configure <RecipeName>`: TO BE CONTINUED in the following section
##  7. <a name='V055-RecipeBuildindeep2'></a>V055 - Recipe Build in deep 2
- `bitbake -c configure <RecipeName>`: creates two recipes `recipe-sysroot` and `recipe-sysroot-native`
- But what is `sysroot`:
  - `recipe-sysroot-native`: includes the build **dependencies used in the host system** during the build process.
    - It is critical to the cross-compilation process because it encompasses the compiler, linker, build script tools and more.
  - `recipe-sysroot`: the libraries and headers used in the **target code**.
- `bitbake -c compile <RecipeName>`: generates the `userprog` which is the `userprog.c` compiled program
  - BB invoke the C cross-compiler for compiling the `userprog.c` source file.
  - The results of the compilation will be in the folder pointed by the `B` environment variable i.e. in most cases the `S` folder
- `bitbake -c install <RecipeName>`: creates the tree folder `image/usr/bin/userprog` the `bindir` (from V049). It also gives the permissions which can be seen using `ls iamge/usr/bin/userprog -al` (it will return `-rwxr-xr-x`)
  - it specifies where the `userprog` binary should be installed into the `rootfs`
  - it must be noticed that his installation will only happen within a remporary `rootfs` folder within the recipe `WORKDIR`
- `bitbake -c package <RecipeName>`: creates:
  - a `package` folder with the tree folder `package/usr/bin/userprog`
  - a `packages-split`: it contains the previous `package` plus debug package, documentation package etc.
- The last steps are performed doing `bitbake <RecipeName>` which creates the `deploy-rpms`
- 

##  8. <a name='V056-AddingRecipetoImageRootFileSystem'></a>V056 - Adding Recipe to Image Root FileSystem

- `sysroot`:
  - contain neended headers and libraries for generating binaries that run on the target architecture
- `recipe-sysroot-native`: 
  - includes the build dependencies used in the host system during the build process.
  - it is critical to the cross-compilation process because it encompasses the compiler, linker, build script tools and more.
- `recipe-sysroot`: the libraries and headers used in the target code

``` console
require recipes-core/images/core-image-minimal.bb
IMAGE_INSTALL_append += "usbutils"

IMAGE_FEATURES = "ssh-server-dropbear debug-tweaks read-only-rootfs splash tools-debug tools-sdk"

IMAGE_NAME = "myimage"

## Here it is added the recipe
IMAGE_INSTALL_append = "myhello"
```