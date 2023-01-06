<!-- vscode-markdown-toc -->
* 1. [What is ASP.NET](#WhatisASP.NET)
* 2. [Making an ASP.NET Core Website](#MakinganASP.NETCoreWebsite)
* 3. [Adding Data to an ASP.NET Core Web Site](#AddingDatatoanASP.NETCoreWebSite)
* 4. [Adding a Service to an ASP.NET Core Web Site](#AddingaServicetoanASP.NETCoreWebSite)
* 5. [Data in a Razor Page](#DatainaRazorPage)
* 6. [Styling a Razor Page](#StylingaRazorPage)
* 7. [Making a Simple API](#MakingaSimpleAPI)
* 8. [Enhancing your Web API - Part1](#EnhancingyourWebAPI-Part1)
* 9. [Enhancing your Web API - Part2](#EnhancingyourWebAPI-Part2)
* 10. [Introducing Blazor: Razor Components](#IntroducingBlazor:RazorComponents)
* 11. [Introducing Blazor: Structure and Debugging](#IntroducingBlazor:StructureandDebugging)
* 12. [Introducing Blazor: Interactivity](#IntroducingBlazor:Interactivity)
* 13. [Publishing a Website to Azure](#PublishingaWebsitetoAzure)
* 14. [Reference](#Reference)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

**Commit format**
``` console 
DOTNET ASPNETCORE <functionality added>`

List of changes:
- Added <something e.g. ch01, fig, vid01, eq01> 
- Fixed <something e.g. ch01, fig, vid01, eq01> 
- Deleted <something e.g. ch01, fig, vid01, eq01>  

List of TODOs
- <verb> + <something e.g. ch01, fig, vid01, eq01> in <somewhere file01, sec1.2.3>
```

##  1. <a name='WhatisASP.NET'></a>What is ASP.NET
- It is an open framework for building secure and fast web apps and services within .NET
- It is cross-platform
- It lets you use razor (`C#` and `HTML`) to make web pages
- Its freee

##  2. <a name='MakinganASP.NETCoreWebsite'></a>Making an ASP.NET Core Website
1. Create a new project
2. Click on `ASP.NET Core Web Aplication` and `Next`
3. Name it `<NameofProject>.WebSite`
4. Then `OK`, and you are done.

### Solution Explorer overview
- `wwwroot` folder: static stuff for graphics, css, js etc.
- `pages`  folfer: for dynamic stuff, razor pages (`.cshtml` files)
##  3. <a name='AddingDatatoanASP.NETCoreWebSite'></a>Adding Data to an ASP.NET Core Web Site

- Including a json file:
  - Create a `data` folder in `wwwroot` then drag and drop the json file there.
  - Create a `models` folder in the project, where it will be created `.cs` files to handle the content of the files.
    - Create a new `class` here (to represent the `json` data) and add variables for each of the fields in the `.json` file
      - One way is write `prop + tab` VSStudio will show `public int MyProperty { get; set; }`
  - Map the `cs` fields with `json`, using the tag `[JsonPropertyName("nameOfVariableInJSON")]`
  - Create a `ToString` method.
    - One easy way to do it is using the `JsonSerializer` showed in the snipped below:
	``` cs
	public override string ToString()
    {
        return JsonSerializer.Serialize<Product>(this);
    }
	```
	- Note: this method is the same than use: `public override string ToString() => JsonSerializer.Serialize<Product>(this)`
- Verify that there are no `compilation errors`, so press `Ctrl + F5`
- Thats all folks!        

##  4. <a name='AddingaServicetoanASP.NETCoreWebSite'></a>Adding a Service to an ASP.NET Core Web Site

- As a waiter in a restaurant, it solves `requests`.
- A service help the code to be maintainable.
- Create a `Services` folder in the project
  - Create a `JsonFileProductService` and copy the code below:
  ``` cs
  public class JsonFileProductService
	{
        public JsonFileProductService(IWebHostEnvironment webHostEnvironment)
        {
            WebHostEnvironment = webHostEnvironment;
        }

        public IWebHostEnvironment WebHostEnvironment { get; }

        private string JsonFileName => Path.Combine(WebHostEnvironment.WebRootPath, "data", "products.json");

        public IEnumerable<Product> GetProducts()
        {
            using var jsonFileReader = File.OpenText(JsonFileName);
            return JsonSerializer.Deserialize<Product[]>(jsonFileReader.ReadToEnd(),
                new JsonSerializerOptions
                {
                    PropertyNameCaseInsensitive = true
                });
        }       
    }
  ```
  - A WebApplications live in a `host` (but they are actually console apps)
  - `webHostEnvironment` is a `service` that 

##  5. <a name='DatainaRazorPage'></a>Data in a Razor Page

##  6. <a name='StylingaRazorPage'></a>Styling a Razor Page

##  7. <a name='MakingaSimpleAPI'></a>Making a Simple API

##  8. <a name='EnhancingyourWebAPI-Part1'></a>Enhancing your Web API - Part1

##  9. <a name='EnhancingyourWebAPI-Part2'></a>Enhancing your Web API - Part2

##  10. <a name='IntroducingBlazor:RazorComponents'></a>Introducing Blazor: Razor Components

##  11. <a name='IntroducingBlazor:StructureandDebugging'></a>Introducing Blazor: Structure and Debugging

##  12. <a name='IntroducingBlazor:Interactivity'></a>Introducing Blazor: Interactivity

##  13. <a name='PublishingaWebsitetoAzure'></a>Publishing a Website to Azure

##  14. <a name='Reference'></a>Reference
[Link of the Playlist](https://www.youtube.com/watch?v=lE8NdaX97m0&list=PLdo4fOcmZ0oW8nviYduHq7bmKode-p8Wy)

