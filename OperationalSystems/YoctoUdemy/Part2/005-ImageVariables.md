<!-- vscode-markdown-toc -->
* 1. [ V034 - Other Language Support](#V034-OtherLanguageSupport)
* 2. [ V035 - IMAGE_FSTYPES](#V035-IMAGE_FSTYPES)
* 3. [ V036 - Create your own image type](#V036-Createyourownimagetype)
* 4. [ V037 - Different Image Name](#V037-DifferentImageName)
* 5. [ V038 - Image Manifest File](#V038-ImageManifestFile)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

##  1. <a name='V034-OtherLanguageSupport'></a> V034 - Other Language Support
- In the Image recipe:
    - `IMAGE_LINGUAS = "zh-cn"`

##  2. <a name='V035-IMAGE_FSTYPES'></a> V035 - IMAGE_FSTYPES
- It determines the root filesystem image type
- Image formats instructions are located in `meta/classes/image_types.bbclass`
  - e.g., `wic`, `iso` etc
- To know which classes are supported by an image:
  - `$ bitbake -e <NameOfImage> | grep ^IMAGE_FSTYPES=`
- **WARNING!!** Each image can have different FSTYPES!!
  - qemux: `ext4`
  - genericx86-64 `wic`


##  3. <a name='V036-Createyourownimagetype'></a> V036 - Create your own image type
- This is done using inheritance from `image_types`
- It has to define a function named `IMAGE_CMD_<type>`
  - An example is given in `sdcard_image-rpi.bbclass` in `meta-raspberry`

##  4. <a name='V037-DifferentImageName'></a> V037 - Different Image Name
- The name of the ouput image files minus the extention.
  - By default: `IMAGE_NAME = ${IMAGE_BASENAME}-${MACHINE}-${DATETIME}`
  - `IMAGE_NAME = <NameOfImage>`

##  5. <a name='V038-ImageManifestFile'></a> V038 - Image Manifest File
- This file list all the installed packages that make up the image.
- It contains package information on a line-per-package basis as follows:
  - `packagename packagearch version`
- The image class defines the manifest fiel as follows:
  - `IMAGE_MANIFEST = "{DEPLOY_DIR_IMAGE}/${IMAGE_NAME}.rootfs.manifest"`