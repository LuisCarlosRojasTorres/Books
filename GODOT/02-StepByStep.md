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
	* 4.1. [Creating a new script](#Creatinganewscript)
	* 4.2. [Hello world script](#Helloworldscript)
* 5. [Listening to player input](#Listeningtoplayerinput)
* 6. [Using Signals](#UsingSignals)
	* 6.1. [Scene setup](#Scenesetup)
	* 6.2. [Connecting a `signal` in the editor](#Connectingasignalintheeditor)
	* 6.3. [Connecting a `signal` via code](#Connectingasignalviacode)
	* 6.4. [Complete script](#Completescript)
	* 6.5. [Custom signals](#Customsignals)

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
###  4.1. <a name='Creatinganewscript'></a>Creating a new script
To attach a new `script` to a `node`:

1. In left panel `right click` and `Attach Script`
2. In `Attach Node Script` panel, `Template: Empty` 
3. Click in `Create button`

Note: you can acces to documentation of specific words with `Ctrl+click`.

###  4.2. <a name='Helloworldscript'></a>Hello world script

- `func`:
  - `_init()`: class constructor
  - `_process()`: updates position and rotation every frame. Godot uses the variable `delta` (the delta time since the last frame) as an argument.
    - `rotation`: an scalar defined as `theta = theta + angular_velocity * delta_time`
    - `position`: a 2d vector, defined as `position = position + velocity * delta_time`
    - `position`: a 2d vector

- Examples of the functions are presented below:
  
``` console
extends Sprite 

func _init():
  print("pass")

var speed = 400
var angular_speed = PI

func _process(delta):
    rotation += angular_speed * delta

    var velocity = Vector2.UP.rotated(rotation) * speed

    position += velocity * delta
```

##  5. <a name='Listeningtoplayerinput'></a>Listening to player input

There are two ways to process player's input in godot:
1. `InputEvents`: To react to events i.e `space` for jump.
2. `Input` singleton: To check inputs every frame.

An example for the second case is presented below:

``` console

func _process(delta):
	
	var direction = 0
	if Input.is_action_pressed("ui_left"):
		direction = -1
	if Input.is_action_pressed("ui_right"):
		direction = 1
	
	rotation += angular_speed * direction * delta
	# TO move when pressing "up" 
	var velocity = Vector2.ZERO
	if Input.is_action_pressed("ui_up"):
		velocity = Vector2.UP.rotated(rotation)*speed
		
	position += velocity*delta

```

##  6. <a name='UsingSignals'></a>Using Signals

- `signals` are messages that `nodes` **emit** when something specific happens to them.
- Then, `nodes` connected to that `signal` react and call functions.
- `signals` limits coupling and keeps the code flexible.
  
###  6.2. <a name='Connectingasignalintheeditor'></a>Connecting a `signal` in the editor

- Select a `node`
- In the right panel, in `Node` tab, there are a list of `Signals`:
- In case of a `Button node`...
  - Click on `pressed()`, then the `Connect a Signal to a Method` panel appear:
    - Select the `node` that will receive the `signal`
    - the `receiver method` name is created by default
      - `receiver method`: function that godot calls when a `node` `emits` the `signal`.
    - Click on `connect`
  - The function is created in the `script` of the `node` that reacts.


###  6.3. <a name='Connectingasignalviacode'></a>Connecting a `signal` via code

- It is possible to connect signals via code instead of using the editor.
- Important when you create `nodes` or instantiate `scenes` inside of a script.
- The mechanics of `signals` is pretty similar to Qt mechanism.
- The `connect` functions should be created once the node is fully instantiated, one way to do this is implementing the `_ready()` (a built-in rfunction which is called automatically by godot when a node is fully instantiated).
- To select the relative node it is used `Node.get_node("nameOfRelativeNode")` (which search into the childrens of the node and get the node by its name)
- Then to connect function of the children node is called with the following parrameters:
  - `node.connect("nomeOfSignalFunction", self, "nomeOfReactionFunction")`
    - `node`: the node that will emit the signal
    - `"nomeOfSignalFunction"`: the name of the signal 
    - `self`: means that the reactive node that will react is the node where this script is attached.
    - `"nomeOfReactionFunction"`: the function of the reactive node which will be called by the `signal`.
- A little example is presented below

``` console
extends Sprite

var speed = 400
var angular_speed = PI


func _ready():
    var timer = get_node("Timer") # gettting the node
    timer.connect("timeout", self, "_on_Timer_timeout") #Connection


func _process(delta):
    rotation += angular_speed * delta
    var velocity = Vector2.UP.rotated(rotation) * speed
    position += velocity * delta


func _on_Button_pressed():
    set_process(not is_processing())


func _on_Timer_timeout():
    visible = not visible
```

###  6.5. <a name='Customsignals'></a>Custom signals

- To create custom signals, you shall declare it in the script after the `extends` statement:

``` console
extends Node2D
signal signalText #HERE!
```
- Its nomenclature is `signal action_verb_in_past`
- Once created, it appears in `node` tab of the right pannel.
- Then, to `emit` it, you shall to use the `emit_signal("signalText")`