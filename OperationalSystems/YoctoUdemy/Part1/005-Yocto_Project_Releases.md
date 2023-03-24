<!-- vscode-markdown-toc -->
* 1. [Introduction](#Introduction)
* 2. [Why Poky has codenames](#WhyPokyhascodenames)
* 3. [Types of Releases](#TypesofReleases)
* 4. [Release Lifecycle](#ReleaseLifecycle)
* 5. [Layers and Branches](#LayersandBranches)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

##  1. <a name='Introduction'></a>V056 Introduction
- Naming conventions, Yocto Project and Poky used Semantic Versioning.
  - Additionaly POKY has codenames.
  - They dont share same version number. 
##  2. <a name='WhyPokyhascodenames'></a>V057 Why Poky has codenames

- Major releases: Every 6 month in April and October
- Minor releases: 
  - No particular schedule
  - Driven by the accumulation of enough significant fixes or enhancements to the associated major release.
- Branches of metadata (layers) with the same codename are compatible with each other.
##  3. <a name='TypesofReleases'></a>V058 Types of Releases
- Major releases are divided into **Milestones Releases**
- Milestones releases are used as:
  - checkpoints for our progress
  - preview for the public community
  - to manage changes in the middle of a release
- Each milestone lasts about 4-8 weeks and has one planning week, several development weeks, stabilization weeks and one release week.
- Point releases: is a minor release e.g. `1.0.x`
- Point releases are necessary to addess the following:
  - Issues building on current Linux distribution
  - fix critical bugs and security issues (CVE) for the first 6 monts after release
  - fix security issues for the first year after release


##  4. <a name='ReleaseLifecycle'></a>V059 Release Lifecycle
- There are two possible lifecycles:
  - Initial release -> stable -> community support maintainer-> End Of Life
  - Initial release -> LTS -> community support maintainer-> End Of Life
- Stable and LTS Release Difference
  - Stable releases are maintained for seven months
  - LTS releases are maintained initially for 2 years

##  5. <a name='LayersandBranches'></a>V060 Layers and Branches
- Layers being developed simultaneously by several different parties, the different flavors of yocto and subsequent layers have to be split into branches in Git
- Most BSP layers will only work with OpenEmbedded-Core of the same branch
- Mixing branches among your layers == CONFLICTS
- For example, the so called `bbappends`, sometimes are tied to specific version number and will break the build if those versions are not found in the layers.

So, **Will Branch to choose*:
- Find a compromise between:
  - Getting the latest stable branch
  - Getting the latest branch supported by all layers
- NOTE: yocto branch you decided to use, could not be supported by your current host linux distribution.

