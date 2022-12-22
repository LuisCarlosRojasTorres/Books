<!-- vscode-markdown-toc -->
* 1. [Introduction](#Introduction)
* 2. [xUnit](#xUnit)
	* 2.1. [Creating a Project](#CreatingaProject)
	* 2.2. [Referencing a Project](#ReferencingaProject)
	* 2.3. [Creating a test](#Creatingatest)
		* 2.3.1. [Types of `Assert`](#TypesofAssert)
	* 2.4. [Running a test](#Runningatest)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

##  1. <a name='Introduction'></a>Introduction
- It is used `xUnit`


##  2. <a name='xUnit'></a>xUnit
- Framework for unit testing


###  2.1. <a name='CreatingaProject'></a>Creating a Project
1. Create a new Project inside the solution that you want to test
2. Click on `xUnit Test Project`

###  2.2. <a name='ReferencingaProject'></a>Referencing a Project
To test a project, it is necessary to reference a project:
1. Right-Click on Test project  
2. Click on `Add/Project Reference`
3. Click on the check box next to the name of the project that you want to test


###  2.3. <a name='Creatingatest'></a>Creating a test
Each method should be tested many times for:
- Valid input and expected output
- Boundary values
- Invalid input


####  2.3.1. <a name='TypesofAssert'></a>Types of `Assert`
- `Assert.Equal(param1, param2)`:
- `Assert.True(param1)`
- `Assert.False(param1)`


###  2.4. <a name='Runningatest'></a>Running a test