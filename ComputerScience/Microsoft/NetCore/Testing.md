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
-Each method should be tested many times for:
   - Valid input and expected output
   - Boundary values
   - Invalid input
- The easiest way is through methods:
  - Each method has the [Fact] tag, i.e., these methods shall be `true`
  - The methods which verify the the test are from the `Assert` class. There are many methods but the most common are:
    - `Assert.Equal(param1, param2)`: evaluates if `param1` is equal to `param2`
    - `Assert.True(param1, msg = "")`: evaluates if `param1` returns `true`, if not, it will show the `msg` in the description test
    - `Assert.False(param1, msg = "")`: evaluates if `param1` returns `false`, if not, it will show the `msg` in the description test
  - Each function can contain many `Asserts` methods. 
 - An example is presented below:

``` cs
public class UnitTest1
{
    [Fact]
    public void Test1()
    {
        Persona p = new Persona("Rufo", 11);
        Assert.Equal("Rufo", p.getName()) ; // It will PASS
    }

    [Fact]
    public void Test2()
    {
        Persona p = new Persona("Rufo", 11);
        Assert.Equal(11, p.getAge()); // It will PASS
        Assert.Equal("Ru0fo", p.getName()); // You shall NOT PASS
    }
}
```

### Running a test
- If any of the `Asserts` contained in a method fail, the test not pass.
- `Ctrl+R` then press `T`
- Then the results are shown as presented below:

![Test](/ComputerScience/Microsoft/NetCore/uploads/Testing001.PNG)