<!-- vscode-markdown-toc -->
* 1. [Dynamic Variables](#DynamicVariables)
	* 1.1. [HEAP](#HEAP)
	* 1.2. [Dynamic Arrays](#DynamicArrays)
* 2. [SEVEN CRIMES with Dynamic Variables](#SEVENCRIMESwithDynamicVariables)
* 3. [Dynamic Containers](#DynamicContainers)
	* 3.1. [Linked Lists](#LinkedLists)
	* 3.2. [Binary Search Trees](#BinarySearchTrees)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

Basic variables, arrays and structs have fixed-sized (that is known at compile time).

**Fixed-sized advantages**
- This permits the use memory efficiently.
- Compile machine code can access fixed-sized variables very fast.


**Fixed-sized disadvantages**
- No way to allocate an arbitrarily large data structure in fixed-sized variable.
- Developer must anticipate the largest data in the program, If the given data is smaller, memory is **wasted** otherwise is impossible to allocate.

To solve these inconvenients it is used `dynamic variables`

##  1. <a name='DynamicVariables'></a>Dynamic Variables

<table>
  <tr>
    <td><b>Properties</b></td>
    <td><b>Global variables</b></td>
    <td><b>Local varaiables or block delimited by { ... }</b></td>
    <td><b>Dynamic Variables</b></td>    
  </tr>
  <tr>    
    <td> <b>Memory <br> location</b> </td>
    <td> Single block of memory allocated when the program stars up</td>
    <td> At the top of the <b>stack</b> </td>
    <td> heap </td>    
  </tr>  
  <tr>    
    <td> <b>Rationale</b> </td>
    <td> Variables allocated in compile time </td>
    <td> When execution leaves the block, the storage is popped off the the top of the <b>stack</b>. This storage is efficiently resued the next time execution enters a block scope.</td>
    <td> Only constructed by an executable statement. </td>    
  </tr>
    <tr>    
    <td> <b>Computational <br> cost </b> </td>
    <td> 0 </td>
    <td> Negligible </td>
    <td> Creating and deleting dynamic variables is the most expensive operation in C++. </td>    
  </tr>  
  <tr>    
    <td> <b> Lifetime </b> </td>
    <td> The variables are storaged for the entire life of the program </td>
    <td> When the execution is out of the scope. </td>
    <td> No automatically destroyed when execution exits the block scope or at the end of the program. Only through an executable statement. </td>    
  </tr>  
</table>

###  1.1. <a name='HEAP'></a>HEAP 
It is a collection of unsued memory blocks. Its works as described:

1. When the program request a new dynamic variable, the C++ runtime searches the heap for an appropriately sized block of memory.
2. So the C++ runtime system may:
   1. Return an available block from the heap, OR
   2. Break a larger memory block into two pieces and return one of them, OR
   3. Request a new memory block from the OS.
3. When a program deletes a dynamic variable, its storage is returned to the `heap`'s collection of available memory block, so it can be reused for another dynamic variable.

**NOTE: There is no limit  to the number or size of dynamic variables that can be created**

**ERROR: An exception is THROWN when a request to create a dynamic variable can not be satisfied**

###  1.2. <a name='DynamicArrays'></a>Dynamic Arrays

##  2. <a name='SEVENCRIMESwithDynamicVariables'></a>SEVEN CRIMES with Dynamic Variables

1. Using a Dynamic Variable before Creating it
2. Using a Dynamic Variable after Deleting it
3. Not Deleting a Dynamic Variables
4. Overwriting a pointer to a Dynamic Variable
5. Deleting a Dynamic Variable twice
6. Deleting a Dynamic Array with `delete` instead of `delete[]`
7. Deleting a Dynamic Variable with `delete[]` instead of `delete`
  
##  3. <a name='DynamicContainers'></a>Dynamic Containers

###  3.1. <a name='LinkedLists'></a>Linked Lists
###  3.2. <a name='BinarySearchTrees'></a>Binary Search Trees