## 3.1 Understanding and Creating Layers
### 3.1.1 Creating Your Own Layer
### 3.1.2 Following Best Practices When Creating Layers
### 3.1.3 Making Sure Your Layer is Compatible With Yocto Project
3.1.3.1 Yocto Project Compatible Program Application
3.1.3.2 yocto-check-layer Script
3.1.4 Enabling Your Layer
3.1.5 Appending Other Layers Metadata With Your Layer
3.1.5.1 Overlaying a File Using Your Layer
3.1.5.2 Installing Additional Files Using Your Layer
3.1.6 Prioritizing Your Layer
3.1.7 Managing Layers
3.1.8 Creating a General Layer Using the bitbake-layers Script
3.1.9 Adding a Layer Using the bitbake-layers Script
3.1.10 Saving and restoring the layers setup
## 3.2 Customizing Images
3.2.1 Customizing Images Using local.conf
3.2.2 Customizing Images Using Custom IMAGE_FEATURES and EXTRA_IMAGE_FEATURES
3.2.3 Customizing Images Using Custom .bb Files
3.2.4 Customizing Images Using Custom Package Groups
3.2.5 Customizing an Image Hostname
## 3.3 Writing a New Recipe
3.3.1 Overview
3.3.2 Locate or Automatically Create a Base Recipe
3.3.2.1 Creating the Base Recipe Using devtool add
3.3.2.2 Creating the Base Recipe Using recipetool create
3.3.2.3 Locating and Using a Similar Recipe
3.3.3 Storing and Naming the Recipe
3.3.4 Running a Build on the Recipe
3.3.5 Fetching Code
3.3.5.1 Fetching Code Through Firewalls
3.3.5.2 Limiting the Number of Parallel Connections
3.3.6 Unpacking Code
3.3.7 Patching Code
3.3.8 Licensing
3.3.9 Dependencies
3.3.10 Configuring the Recipe
3.3.11 Using Headers to Interface with Devices
3.3.12 Compilation
3.3.13 Installing
3.3.14 Enabling System Services
3.3.15 Packaging
3.3.16 Sharing Files Between Recipes
3.3.17 Using Virtual Providers
3.3.18 Properly Versioning Pre-Release Recipes
3.3.19 Post-Installation Scripts
3.3.20 Testing
3.3.21 Examples
3.3.21.1 Single .c File Package (Hello World!)
3.3.21.2 Autotooled Package
3.3.21.3 Makefile-Based Package
3.3.21.4 Splitting an Application into Multiple Packages
3.3.21.5 Packaging Externally Produced Binaries
3.3.22 Following Recipe Style Guidelines
3.3.23 Recipe Syntax
## 3.4 Adding a New Machine
3.4.1 Adding the Machine Configuration File
3.4.2 Adding a Kernel for the Machine
3.4.3 Adding a Formfactor Configuration File
## 3.5 Upgrading Recipes
3.5.1 Using the Auto Upgrade Helper (AUH)
3.5.2 Using devtool upgrade
3.5.3 Manually Upgrading a Recipe
3.6 Finding Temporary Source Code
3.7 Using Quilt in Your Workflow
## 3.8 Using a Development Shell
## 3.9 Using a Python Development Shell
## 3.10 Building
### 3.10.1 Building a Simple Image
### 3.10.2 Building Images for Multiple Targets Using Multiple Configurations
#### 3.10.2.1 Setting Up and Running a Multiple Configuration Build
#### 3.10.2.2 Enabling Multiple Configuration Build Dependencies
3.10.3 Building an Initial RAM Filesystem (Initramfs) Image
3.10.3.1 Bundling an Initramfs Image From a Separate Multiconfig
3.10.4 Building a Tiny System
3.10.4.1 Tiny System Overview
3.10.4.2 Goals and Guiding Principles
3.10.4.3 Understand What Contributes to Your Image Size
3.10.4.4 Trim the Root Filesystem
3.10.4.5 Trim the Kernel
3.10.4.6 Remove Package Management Requirements
3.10.4.7 Look for Other Ways to Minimize Size
3.10.4.8 Iterate on the Process
3.10.5 Building Images for More than One Machine
3.10.6 Building Software from an External Source
3.10.7 Replicating a Build Offline
3.11 Speeding Up a Build
## 3.12 Working With Libraries
3.12.1 Including Static Library Files
3.12.2 Combining Multiple Versions of Library Files into One Image
3.12.2.1 Preparing to Use Multilib
3.12.2.2 Using Multilib
3.12.2.3 Additional Implementation Details
3.12.3 Installing Multiple Versions of the Same Library
3.13 Working with Pre-Built Libraries
3.13.1 Introduction
3.13.2 Versioned Libraries
3.13.3 Non-Versioned Libraries
3.13.3.1 Some Background
3.13.3.2 Yocto Library Packaging Overview
3.13.3.3 Example
3.14 Using x32 psABI
3.15 Enabling GObject Introspection Support
3.15.1 Enabling the Generation of Introspection Data
3.15.2 Disabling the Generation of Introspection Data
3.15.3 Testing that Introspection Works in an Image
3.15.4 Known Issues
3.16 Optionally Using an External Toolchain
## 3.17 Creating Partitioned Images Using Wic
### 3.17.1 Background
### 3.17.2 Requirements
3.17.3 Getting Help
3.17.4 Operational Modes
3.17.4.1 Raw Mode
3.17.4.2 Cooked Mode
3.17.5 Using an Existing Kickstart File
3.17.6 Using the Wic Plugin Interface
### 3.17.7 Wic Examples
3.17.7.1 Generate an Image using an Existing Kickstart File
3.17.7.2 Using a Modified Kickstart File
3.17.7.3 Using a Modified Kickstart File and Running in Raw Mode
3.17.7.4 Using Wic to Manipulate an Image
3.18 Flashing Images Using bmaptool
## 3.19 Making Images More Secure
3.19.1 General Considerations
3.19.2 Security Flags
3.19.3 Considerations Specific to the OpenEmbedded Build System
3.19.4 Tools for Hardening Your Image
3.20 Creating Your Own Distribution
3.21 Creating a Custom Template Configuration Directory
3.22 Conserving Disk Space
3.22.1 Conserving Disk Space During Builds
3.22.2 Purging Duplicate Shared State Cache Files
## 3.23 Working with Packages
3.23.1 Excluding Packages from an Image
3.23.2 Incrementing a Package Version
3.23.2.1 Working With a PR Service
3.23.2.2 Manually Bumping PR
3.23.2.3 Automatically Incrementing a Package Version Number
3.23.3 Handling Optional Module Packaging
3.23.3.1 Making Sure the Packaging is Done
3.23.3.2 Satisfying Dependencies
3.23.4 Using Runtime Package Management
3.23.4.1 Build Considerations
3.23.4.2 Host or Server Machine Setup
3.23.4.3 Target Setup
3.23.4.3.1 Using RPM
3.23.4.3.2 Using IPK
3.23.4.3.3 Using DEB
3.23.5 Generating and Using Signed Packages
3.23.5.1 Signing RPM Packages
3.23.5.2 Processing Package Feeds
3.23.6 Testing Packages With ptest
3.23.6.1 Adding ptest to Your Build
3.23.6.2 Running ptest
3.23.6.3 Getting Your Package Ready
3.23.7 Creating Node Package Manager (NPM) Packages
3.23.7.1 Requirements and Caveats
3.23.7.2 Using the Registry Modules Method
3.23.7.3 Using the NPM Projects Code Method
3.23.8 Adding custom metadata to packages
## 3.24 Efficiently Fetching Source Files During a Build
3.24.1 Setting up Effective Mirrors
3.24.2 Getting Source Files and Suppressing the Build
3.25 Selecting an Initialization Manager
3.25.1 Using systemd Exclusively
3.25.2 Using systemd for the Main Image and Using SysVinit for the Rescue Image
3.25.3 Using systemd-journald without a traditional syslog daemon
3.26 Selecting a Device Manager
3.26.1 Using Persistent and Pre-Populated /dev
3.26.2 Using devtmpfs and a Device Manager
3.27 Using an External SCM
3.28 Creating a Read-Only Root Filesystem
3.28.1 Creating the Root Filesystem
3.28.2 Post-Installation Scripts and Read-Only Root Filesystem
3.28.3 Areas With Write Access
3.29 Maintaining Build Output Quality
3.29.1 Enabling and Disabling Build History
3.29.2 Understanding What the Build History Contains
3.29.2.1 Build History Package Information
3.29.2.2 Build History Image Information
3.29.2.3 Using Build History to Gather Image Information Only
3.29.2.4 Build History SDK Information
3.29.2.5 Examining Build History Information
3.30 Performing Automated Runtime Testing
## 3.30.1 Enabling Tests
### 3.30.1.1 Enabling Runtime Tests on QEMU
### 3.30.1.2 Enabling Runtime Tests on Hardware
3.30.1.3 Selecting SystemdbootTarget
3.30.1.4 Power Control
3.30.1.5 Serial Console Connection
### 3.30.2 Running Tests
### 3.30.3 Exporting Tests
### 3.30.4 Writing New Tests
3.30.4.1 Class Methods
3.30.4.2 Class Attributes
3.30.4.3 Instance Attributes
3.30.5 Installing Packages in the DUT Without the Package Manager
3.31 Debugging Tools and Techniques
3.31.1 Viewing Logs from Failed Tasks
3.31.2 Viewing Variable Values
3.31.3 Viewing Package Information with oe-pkgdata-util
3.31.4 Viewing Dependencies Between Recipes and Tasks
3.31.5 Viewing Task Variable Dependencies
3.31.6 Viewing Metadata Used to Create the Input Signature of a Shared State Task
3.31.7 Invalidating Shared State to Force a Task to Run
3.31.8 Running Specific Tasks
3.31.9 General BitBake Problems
3.31.10 Building with No Dependencies
3.31.11 Recipe Logging Mechanisms
3.31.11.1 Logging With Python
3.31.11.2 Logging With Bash
3.31.12 Debugging Parallel Make Races
3.31.12.1 The Failure
3.31.12.2 Reproducing the Error
3.31.12.3 Creating a Patch for the Fix
3.31.12.4 Testing the Build
3.31.13 Debugging With the GNU Project Debugger (GDB) Remotely
3.31.13.1 Using the debuginfod server method
3.31.13.2 Using the gdbserver method
3.31.14 Debugging with the GNU Project Debugger (GDB) on the Target
3.31.15 Other Debugging Tips
3.32 Making Changes to the Yocto Project
3.32.1 Submitting a Defect Against the Yocto Project
3.32.2 Submitting a Change to the Yocto Project
3.32.2.1 Preparing Changes for Submission
3.32.2.2 Using Email to Submit a Patch
3.32.2.3 Using Scripts to Push a Change Upstream and Request a Pull
3.32.2.4 Responding to Patch Review
3.32.2.5 Submitting Changes to Stable Release Branches
3.33 Working With Licenses
3.33.1 Tracking License Changes
3.33.1.1 Specifying the LIC_FILES_CHKSUM Variable
3.33.1.2 Explanation of Syntax
3.33.2 Enabling Commercially Licensed Recipes
3.33.2.1 License Flag Matching
3.33.2.2 Other Variables Related to Commercial Licenses
3.33.3 Maintaining Open Source License Compliance During Your Product’s Lifecycle
3.33.3.1 Providing the Source Code
3.33.3.2 Providing License Text
3.33.3.3 Providing Compilation Scripts and Source Code Modifications
3.33.3.4 Compliance Limitations with Executables Built from Static Libraries
3.33.4 Copying Non Standard Licenses
3.34 Checking for Vulnerabilities
3.34.1 Vulnerabilities in Poky and OE-Core
3.34.2 Vulnerability check at build time
3.34.3 Fixing CVE product name and version mappings
3.34.4 Fixing vulnerabilities in recipes
3.34.5 Implementation details
3.35 Creating a Software Bill of Materials
3.36 Using the Error Reporting Tool
3.36.1 Enabling and Using the Tool
3.36.2 Disabling the Tool
3.36.3 Setting Up Your Own Error Reporting Server
3.37 Using Wayland and Weston
3.37.1 Enabling Wayland in an Image
3.37.1.1 Building Wayland
3.37.1.2 Installing Wayland and Weston
3.37.2 Running Weston