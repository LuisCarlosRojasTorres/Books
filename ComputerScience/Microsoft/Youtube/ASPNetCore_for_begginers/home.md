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
      - SO, this is a `C#` representation of the data.
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
  - Create a `JsonFileProductService` class and copy the code below:
  ``` cs
  public class JsonFileProductService
	{
        public JsonFileProductService(IWebHostEnvironment webHostEnvironment)
        {
            // [1]
            WebHostEnvironment = webHostEnvironment;
        }

        public IWebHostEnvironment WebHostEnvironment { get; }

        private string JsonFileName => Path.Combine(WebHostEnvironment.WebRootPath, "data", "products.json"); // [2]

        public IEnumerable<Product> GetProducts()
        {
          [3]
            using var jsonFileReader = File.OpenText(JsonFileName);
            return JsonSerializer.Deserialize<Product[]>(jsonFileReader.ReadToEnd(),
                new JsonSerializerOptions
                {
                    PropertyNameCaseInsensitive = true
                });
        }       
    }
  ```
- [1] A WebApplications live in a `host` (but they are actually console apps)
  - `Program.cs` actually is a console app which creates a `host` in `main` function
- [2] this let the service to know where tbe `json` is located
  - A hardcoded pathfile is bad and dangerous, so tHe WebHostEnvironment will know where files are located 
    - `WebHostEnvironment.WebRootPath` returns the `wwwroots` folder of the project
    - `Path.Combine` (from `System.io`) which combines the folders to make a full path
  - `webHostEnvironment` is a `service` that is given to our service ( a `chain of services`)
- [3] Converts the file in an `Product array`
  - It returns an `IEnumerable` to loop along it
- So `JsonFileProductService` is a service that has one job which is to give an array of Product from the `json` file. 
  - **BUT** how the system could know that?
  - How to communicate to `ASP.NET` that there is a new service available? This is achieved as described in the following steps:
  - **NETCORE 6**:
    - Include `using <NameOfProject>.Services` in our specific case will be: `using ContosoCrafts.WebSite.Services;`
    - Then, `builder.Services.AddTransient<NameOfService>();` insert after `builder.Services.AddRazorPages();`
- The code is showed below:
  
``` cs
//Program.cs
using ContosoCrafts.WebSite.Services;

var builder = WebApplication.CreateBuilder(args);

// Add services to the container.
builder.Services.AddRazorPages();
builder.Services.AddTransient<JsonFileProductService>();
//...
```
- NOTE: it is important to `Add` a service in `Program.cs` because:
  - Now ALL the classes which need to declare a service in its constructor, they only to add as parameter. And it will work by `dependency injection` 
##  5. <a name='DatainaRazorPage'></a>Data in a Razor Page

- `Razor page` is `cshtml`file is kind of `C#` and kind of `html`
  - you can use `html` common sintaxis
  - and `@{ }`  for `C#` which is executed in the server-side
- Some keywords:
  - `@page`
  - `@model <nameOfClass>` it refers its `buddy-page` which is a file in `c#` where it is implemented the data that will be presented in the `Razor page` 
  
The `Razor Page` from Index is presented below:

``` cs
public class IndexModel : PageModel
{
  private readonly ILogger<IndexModel> _logger; 
  //[3]
    
  public IndexModel(ILogger<IndexModel> logger) //[1] //[2]
  {
    _logger = logger;
    // [4]
  }

  public void OnGet()
  {
    //[5]

  }
}
```

- [1] Looging is a service that is made available to you in ASP.NET
  - You dont need to create it, you only need to ask for one by simply listing it in your arguments
- [2] So, only asking for a service you get it,  `JSonFileProductService` is service that we want to use. So i will ask for it.
- [3] Variables shall be created to store the outputs of the service.
  - `{get; private set;}`: this to protect the `IEnumerable` from unwanted modifications
- [4] Here the services will be stored as a local variables
- [5] Razor Pages has `OnPost`, `OnPut` methods, all this web stuff. So it also has `OnGet`.
  - `OnGet`: When someone gets this page, this method is called.

The `IndexModel` class implemented is showed below:
  
``` cs 
public class IndexModel : PageModel
{
  private readonly ILogger<IndexModel> _logger;
        
  public JsonFileProductService ProductService; //[3]
  public IEnumerable<Product> Products { get; private set; }

  public IndexModel(ILogger<IndexModel> logger, JsonFileProductService productService) //[1] //[2]
  {
    _logger = logger;
    ProductService= productService; // [4]
  }

  public void OnGet()
  {
    Products = ProductService.GetProducts(); // [5]
  }
}
```

- After the implementation, the `@model` in the Razor page now know about `Products`

So, the next step is to call all the data in the `Razor Page`.  
- A dummy example of how to call this data is showed below:

``` html
@page
@model IndexModel
@{
    ViewData["Title"] = "Home page";
}

<div class="text-center">
    <h1 class="display-4"> Contoso Crafts </h1>
    <p>Learn about <a href="https://docs.microsoft.com/aspnet/core">building Web apps with ASP.NET Core</a>.</p>
</div>

@foreach(var product in Model.Products)
{
    <h2>@product.Title</h2>
    <img src=@product.Image width="500" height="600">
}
```
- This code will show title and figure. However it sucks! So it is necessary to add some style there!
- That's all Folks!
##  6. <a name='StylingaRazorPage'></a>Styling a Razor Page

This is nothing more than a Bootstrap class.
##  7. <a name='MakingaSimpleAPI'></a>Making a Simple API

##  8. <a name='EnhancingyourWebAPI-Part1'></a>Enhancing your Web API - Part1

##  9. <a name='EnhancingyourWebAPI-Part2'></a>Enhancing your Web API - Part2

##  10. <a name='IntroducingBlazor:RazorComponents'></a>Introducing Blazor: Razor Components

##  11. <a name='IntroducingBlazor:StructureandDebugging'></a>Introducing Blazor: Structure and Debugging

##  12. <a name='IntroducingBlazor:Interactivity'></a>Introducing Blazor: Interactivity

##  13. <a name='PublishingaWebsitetoAzure'></a>Publishing a Website to Azure

##  14. <a name='Reference'></a>Reference
[Link of the Playlist](https://www.youtube.com/watch?v=lE8NdaX97m0&list=PLdo4fOcmZ0oW8nviYduHq7bmKode-p8Wy)
[Link of the Repository](https://github.com/dotnet-presentations/ContosoCrafts)

