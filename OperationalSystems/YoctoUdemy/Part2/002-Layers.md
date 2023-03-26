<!-- vscode-markdown-toc -->
* 1. [V013 - What is a Layer](#V013-WhatisaLayer)
* 2. [V014 - Why do we need to create a Layer](#V014-WhydoweneedtocreateaLayer)
* 3. [V015 - Layers in detail](#V015-Layersindetail)
* 4. [V016 - Manually Creating a Layer](#V016-ManuallyCreatingaLayer)
* 5. [V017 - Creating a Layer Using BitBake layers command](#V017-CreatingaLayerUsingBitBakelayerscommand)
* 6. [V018 - Layer Configuration layer.conf](#V018-LayerConfigurationlayer.conf)
* 7. [V019 Script to check Layer Compatibility](#V019ScripttocheckLayerCompatibility)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->



##  1. <a name='V013-WhatisaLayer'></a>V013 - What is a Layer
- It is a logical collection of related recipes.
- Types of layers: `oe-core`, `BSP-Layer`, `Application Layer`
- Its name starts with `meta-`


##  2. <a name='V014-WhydoweneedtocreateaLayer'></a>V014 - Why do we need to create a Layer
- `local.conf` configuration has the following limitations:
  - It is not possible to:
    - Save you own recipes
    - Create your own images
    - Add patches or modify recipes from other people
    - Add a new custom kernel
    - Add a new MACHINE
  - POKY/UPSTREAM layers should not be edited (generates conflicts in updates)


##  3. <a name='V015-Layersindetail'></a>V015 - Layers in detail
- Depending on the type of layer, its content could be different.
- If the layer:
  - **is adding support for a machine**, add the machine configuration in `conf/machine/`
  - **is adding distro policy**, add the distro configuration in `conf/distro/`
  - **introduces new recipes**, put the recipes you need in `recipes-*` subdirectories of the layer directory.
- Inside `meta-<nameOfLayer>` folder there are many `recipe-*` folders
### Recipe directories inside layers
- Layers are splitted into categories
- The most difficult part is deciding in which category your recipe will go.

### Layer Priority
- Each layer has a `priority`, which is used by BitBake to decide which layer takes precedence if there are *recipe files* with the same name in multiple layers.
- THe highest number, the highest priority.

##  4. <a name='V016-ManuallyCreatingaLayer'></a>V016 - Manually Creating a Layer
- Steps:
  1. Create a directory for the layer. E.g., `meta-<NameOfLayer>` 
  2. Create a `conf/layer.conf` (or copy the content of another layer and then edit it for something apropriate)
  3. Update `bblayers.conf` file with the new layer.

##  5. <a name='V017-CreatingaLayerUsingBitBakelayerscommand'></a>V017 - Creating a Layer Using BitBake layers command
1. Verify if the terminal is at the poky folder.
2. Command: `$ bitbake-layers create-layer meta-<NameOfLayer>`
3. This command sets up the subdirectories with 
   - a `layer.conf` configuration file, 
   - a `recipe-example` subdirectory that contains an `example.bb` recipe, a licensing file and a README.
   - It sets a default priority of `6` 
4. Add layer to the project with: `$ bitbake-layers add-layer meta-<NameOfLayer>`
5. Verify that `meta-<NameOfLayer>` is added to project with: `$ bitbake-layers show-layers`  

##  6. <a name='V018-LayerConfigurationlayer.conf'></a>V018 - Layer Configuration layer.conf
- The layer.conf file has the following variables:
  - `BBPATH`: the configuration and classes directory are added to this glocal variable
  - `BBFILES`: the recipes of the layers (`.bb` and `.bbappend`) are added to this global variable
  - `BBFILE_COLLETIONS`: the layer is added to this global variable
  - `BBFILE_PRIORITY_meta-NameOfLayer`:  set as `6`
  - `LAYERSERIES_COMPAT_meta-NameOfLayer` This shows the branch of POKY where the layer was initially created.
##  7. <a name='V019ScripttocheckLayerCompatibility'></a>V019 Script to check Layer Compatibility
- To know if a given layer is compatible with the Yocto Project use the following command:
  - `$ yocto-check-layer meta-NameOfLayer`
