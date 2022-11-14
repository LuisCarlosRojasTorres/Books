<!-- vscode-markdown-toc -->
* 1. [Nodes and Scenes](#NodesandScenes)
	* 1.1. [Nodes](#Nodes)
	* 1.2. [Scenes](#Scenes)
	* 1.3. [Creating your first scene](#Creatingyourfirstscene)
	* 1.4. [Changing a node's properties](#Changinganodesproperties)
	* 1.5. [Running the scene](#Runningthescene)
	* 1.6. [Setting the main scene](#Settingthemainscene)
* 2. [Creating instances](#Creatinginstances)
	* 2.1. [In practice](#Inpractice)
	* 2.2. [Editing scenes and instances](#Editingscenesandinstances)
	* 2.3. [Scene instances as a design language](#Sceneinstancesasadesignlanguage)
* 3. [Scripting languages](#Scriptinglanguages)
* 4. [Creating your first scripts](#Creatingyourfirstscripts)
* 5. [Listening to player input](#Listeningtoplayerinput)
* 6. [Using Signals](#UsingSignals)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

##  1. <a name='NodesandScenes'></a>Nodes and Scenes

###  1.1. <a name='Nodes'></a>Nodes

- Fundamental building blocks of your game.
- Dozens of kinds i.e can display an image, play a sound, represent a camera etc etc...
- Attributes:
  - Name
  - Editable properties
  - They receive callbaks to update every frame
  - It can be extended with new properties and funcitons
  - They can be added to another `node` as a `child`. (So, they forma a `tree`).

###  1.2. <a name='Scenes'></a>Scenes

- It is a three of `nodes`.
- Once saved, a `scene` works like a new `node` in the editor. So, you can add it as a child of an existing `node`.
- Godot is basically an `scene editor`. It can contain as many scenes as you need.
- The engine always requires a `main scene`.
- Attributes:
  - As a tree, it always has a `root node`
  - You can save them in a `hard drive`
  - You can create many instances from it.

###  1.3. <a name='Creatingyourfirstscene'></a>Creating your first scene

- On the left side of the screen...
- Press the `+` (`Add child note` or `Ctrl+A`)
  
###  1.4. <a name='Changinganodesproperties'></a>Changing a node's properties

- On the right side of the screen...
- The properties of a clicked node are found.

###  1.5. <a name='Runningthescene'></a>Running the scene

- Press `F6`
- Godot ask you to save the scene.

###  1.6. <a name='Settingthemainscene'></a>Setting the main scene 

- `F5` to run our test scene.
- Godot ask you to select a main scene.

##  2. <a name='Creatinginstances'></a>Creating instances

- A `scene` is a collection of `nodes` organized in a tree structure (with a single node as its root)
- A project can be split into a number of scenes.
- `scenes` are save in `.tscn` files (which means *Packed Scenes* because they pack information about your scene)
- An Example:
  - A *ball* can be composed of: `RigidBody2D` node, a `Sprite node` and a `CollisionShape2D`.
  - When a `scene` is saved, it works as a blueprint. (it can be reproduced it, in other scenes this is called `instancing`).

###  2.1. <a name='Inpractice'></a>In practice

- External `projects` can be opened through `Import` button 
- The files has  `.godot` 
- `Instance Child Scene` (`Ctrl+Add+A`)
- To Create more instance of a node:
  - Select the node
  - `Ctrl+D`
  - Move the new instance created

###  2.2. <a name='Editingscenesandinstances'></a>Editing scenes and instances

###  2.3. <a name='Sceneinstancesasadesignlanguage'></a>Scene instances as a design language



##  3. <a name='Scriptinglanguages'></a>Scripting languages


##  4. <a name='Creatingyourfirstscripts'></a>Creating your first scripts


##  5. <a name='Listeningtoplayerinput'></a>Listening to player input


##  6. <a name='UsingSignals'></a>Using Signals

