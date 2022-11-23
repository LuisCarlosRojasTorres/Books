<!-- vscode-markdown-toc -->
* 1. [Brackets](#Brackets)
* 2. [Namespaces](#Namespaces)
* 3. [Solution](#Solution)
* 4. [Statement](#Statement)
	* 4.1. [Syntax](#Syntax)
	* 4.2. [Semantics](#Semantics)
* 5. [Variable](#Variable)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

##  1. <a name='Brackets'></a>Brackets
- Parentheses or round brackets: `( )`
- Term braces or Curly brackets: `{ }`
- Square brackets: `[ ]`

##  2. <a name='Namespaces'></a>Namespaces
- `Classes` are grouped into `namespaces` and compiled into `assemblies`. 
- An `assemblie` is a file that can be a `.dll` or an `.exe`
- When a new project is created a default `namespace` is created and used, it is called  `NameOfTheProject` `namespace`
- The `using` directive brings the items in a `namespace` into scope.
- There is no an `1:1` equivalence between an `assembly` and a `namespace`.
  - A single `assembly` can contain classes defined in many `namespaces`
  - A single `namespace` can span between multiple `assemblies`
- IF a `using`  directive appears **grayed-out**, it is not currently used by the application.

##  3. <a name='Solution'></a>Solution
- It has the `.sln` suffix.
- It can contain one or more projects (which has the `csproj` suffix).

##  4. <a name='Statement'></a>Statement
- It is a command that performs an action. e.g:
  - Calculate a value
  - Store a result
  - display a message

###  4.1. <a name='Syntax'></a>Syntax
- Set of rules describing their format and construction. e.g.:
  - An statement shall terminate with a semicolon `(;)`.
- `C#` is a `free-format` language i.e., a `white-space` or a `new-line` are not significant except as a separator.
- `C#` is a `case-sensitive` language i.e., a `dog` and `Dog` are different.

###  4.2. <a name='Semantics'></a>Semantics
- It is the specification of what statement `do`.

##  5. <a name='Variable'></a>Variable
- It is a storage location that holds a value.