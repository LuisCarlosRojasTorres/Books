<!-- vscode-markdown-toc -->
* 1. [Service-Oriented Architecture](#Service-OrientedArchitecture)
* 2. [Service Principles](#ServicePrinciples)
* 3. [History of Web-based Systems](#HistoryofWeb-basedSystems)
	* 3.1. [Web Application](#WebApplication)
	* 3.2. [Web Services](#WebServices)
* 4. [Web Technologies](#WebTechnologies)
	* 4.1. [Layered](#Layered)
	* 4.2. [XML/HTML/JSON](#XMLHTMLJSON)
	* 4.3. [HTTP](#HTTP)
	* 4.4. [Javascript](#Javascript)
* 5. [Distributed Systems Basics](#DistributedSystemsBasics)
	* 5.1. [Middleware](#Middleware)
	* 5.2. [RPC](#RPC)
	* 5.3. [Object Brokers](#ObjectBrokers)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

##  1. <a name='Service-OrientedArchitecture'></a>Service-Oriented Architecture

In software **deploying a service** menas providing a tool that other software can use.

##  2. <a name='ServicePrinciples'></a>Service Principles

- Component-based and loosely coupled:
- Composable:
- Platform and Language independent:
- Self-describing:
- Self-Advertising:
  
##  3. <a name='HistoryofWeb-basedSystems'></a>History of Web-based Systems

To view a web page:
1. `Web Browser` makes a `request` to the `Web Server` that host the web page.
2. `Web Server` `responds` returning the HTML document that corresponds to the requested web page.
3. `Web Browser` renders this HTML document to the user.

Notes:
- The relation `Web Browser-Web Server` is a `Client-Server` relationship.
- Both the `request` and the `response` are messages in `HTTP protocol` 

###  3.1. <a name='WebApplication'></a>Web Application

- LIke desktop applications, it provides GUIs that allow users to interact with them.
- It runs in the browser 
- It is stored in a remote server
- Platform independent
- It eliminates the need for users to download and maintain application software on a computer.
- It requires Internet access (because communication is through HTTP with a `Web Server` and/or `Application Server`).

###  3.2. <a name='WebServices'></a>Web Services

- When integrated with web applications, real time information can be ussed to create more complex, richer applications.
- It can rely on other services.
- They are reusable components, so information produced by these web services can be used by many different web applications at same time.
- Web Services and Web Applications communicate over the web using open standards like `HTTP`, `XML` and `JSON`.
- `Request` and `Response` of different services is `Asynchronous` i.e. A page composed of many services can be generated while each service is processing request and sending responses.


##  4. <a name='WebTechnologies'></a>Web Technologies

###  4.1. <a name='Layered'></a>Layered

###  4.2. <a name='XMLHTMLJSON'></a>XML/HTML/JSON

###  4.3. <a name='HTTP'></a>HTTP

###  4.4. <a name='Javascript'></a>Javascript


##  5. <a name='DistributedSystemsBasics'></a>Distributed Systems Basics

###  5.1. <a name='Middleware'></a>Middleware

###  5.2. <a name='RPC'></a>RPC

###  5.3. <a name='ObjectBrokers'></a>Object Brokers