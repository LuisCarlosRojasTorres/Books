<!-- vscode-markdown-toc -->
* 1. [Introduction](#Introduction)
* 2. [Learn GDScript](#LearnGDScript)
* 3. [Overview of key Concepts](#OverviewofkeyConcepts)
	* 3.1. [Scenes](#Scenes)
	* 3.2. [Nodes](#Nodes)
	* 3.3. [The scene tree](#Thescenetree)
	* 3.4. [Signals](#Signals)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

##  1. <a name='Introduction'></a>Introduction

##  2. <a name='LearnGDScript'></a>Learn GDScript

##  3. <a name='OverviewofkeyConcepts'></a>Overview of key Concepts

A game is a `tree` of `nodes` that you group together into `scenes`. These notes can communicate using `signals`.

###  3.1. <a name='Scenes'></a>Scenes 
- A scene can be a character, a weapon, a menu in the user interface, a single house, an entire level, or anything you can think of.
- Scenes can be nested, then a `parent-child` relationship is created.


###  3.2. <a name='Nodes'></a>Nodes
- A `scene` is composed of one or more `nodes`.
- THe smallest building block that you arrange into trees.
- Its nomenclature follow the `"nameOfNode"+"2D"` or `"nameOfNode"+"3D"` sintaxis.
  
###  3.3. <a name='Thescenetree'></a>The scene tree

- All scenes are in the `scene tree`, but `scenes` are `trees of nodes`. So the `scene tree` is also a `tree of nodes`.
- Its easier to think of a game in terms of scenes (because they represent characters, weapons, doors or UI).


###  3.4. <a name='Signals'></a>Signals
- `nodes` emits `signals` when some event occurs.
- `signals` permits `nodes` communication