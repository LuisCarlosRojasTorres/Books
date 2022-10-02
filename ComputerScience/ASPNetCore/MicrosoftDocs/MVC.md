## Tutorial

The MVC pattern helps you create apps that are more testable and easier to update than traditional monolithic apps.

### Add a controller

- Models (Business logic): Classes that represent the data of the app. The model classes use validation logic to enforce business rules for that data. Typically, model objects retrieve and store model state in a database. (e.g. In this tutorial, a Movie model retrieves movie data from a database, provides it to the view or updates it. Updated data is written to a database.)
- Views (UI logic): components that display the app's user interface (UI). Generally, this UI displays the model data.
- Controllers (Input logic): Classes that:
  - Handles and responds to user input and interaction (e.g. handles URL segments and query-string values, and passes these values to the model). For example:
    - `https://localhost:5001/Home/Privacy`: specifies the `Home` controller and the `Privacy` action.
  - Handle browser requests.
  - Retrieve model data.
  - Call view templates that return a response.

- Every `public` method in a controller is callable as an HTTP endpoint (i.e Um endpoint de um web service é a URL onde seu serviço pode ser acessado por uma aplicação cliente). 

- An `HTTP endpoint` is:
  - a targetable URL in the web application, such as https://localhost:5001/HelloWorld
  - Combines:
    - The protocol used: HTTPS.
    - The network location of the web server, including the TCP port: localhost:5001.
    - The target URI: HelloWorld.

- MVC invokes controller classes, and the action methods within them, depending on the incoming URL. The default URL routing logic used by MVC, uses a format like this to determine what code to invoke:
  - `/[Controller]/[ActionName]/[Parameters]`
  - This is configured in `Startup class ` through the `app.UseEndpoints` method.

For example, for the controller method: 

``` cs
public string sum(int value1 = 1, int value2 = 2)
{
    return HtmlEncoder.Default.Encode($"Result: {value1 + value2}");
}
```

- Can be accessed (for a given `value1 = 3` and `value2 = 5`) through `https://localhost:44327/helloworld/sum?value1=3&value2=5` then the view shows `Result: 8`
  - The URL segment Parameters isn't used.
  - The `value1` and `value2` parameters are passed in the query string.
  - The `?` (question mark) in the above URL is a separator, and the query string follows.
  - The `&` character separates field-value pairs.
- The MVC model binding system automatically maps the named parameters from the query string to parameters in the method. 

### Assing a View
- `Controllers` use `Razor` view files. This cleanly encapsulates the process of generating HTML responses to a client. `Razor` view pages:
  - Have `.cshtml` file extension
  - Create HTML ouput with `C#`
- To a `Controller` return a `View` The index method shall be:
``` cs
public IActionResult Index()
{
    return View(); // Controller's view method
}
```
- This code:
  - Calls the `controller`'s view method
  - Used a `view` template to generate an HTML response

On the other hand:
- Controller methods are referred to as `action` methods. They generally return an `IActionResult` or a class derived from `ActionResult`


For a controller `ControllerName01` a view shall be created in `/View/ControllerName01/Index.cshtml`

``` cs 
@{
    ViewData["Title"] = "Index"; // This is a dictionary!!!
}

<h2>Index</h2>
<p>Hello from our View Template!</p>
```

To see this view navigate to `localhost:{PORT}/ControllerName01`:
- So the `Index` method is called (automatically), which calls the `View()` method.
- The `View()` method calls the `default` view, which has the same name as the **action method**, `Index.cshtml` in this case (from `/View/ControllerName01/Index.cshtml`).

On the other hand `Views/Shared/_Layout.cshtml` : 
- Specifies the layout of the site in one place.
- Apply layout to many pages
- All the code in `_Layout.cshtml` is shared to all the `cshtml` files. `@RenderBody()` is a placeholder where the specific `cshtml` is rendered inside.

There is also the file `_ViewStart.cshtml` sets the layout for all the pages.

### Passing Data from the Controller to the View
- Controller actions are invoked in response to an incoming URL request. So a controller class is where the code is written that handles the incoming browser requests. 
- The controller retrieves data from a data source and decides what type of response to send back to the browser. 
- View templates can be used from a controller to generate and format an HTML response to the browser.

- A controller can use a view template. So the view template generates a dynamic response (which is passed from the controoller to generate the response)
- To do this, the controller puts the data to a `ViewData` dictionary, then the view template can access to it.

- As an example the `IActionResult WhichIsBigger` is implemented:
  - It sets the `ViewData` dictionary with the biggest and lowest values for  two given numbers.
  - A  view template is created `Views/HelloWorld/WhichIsBigger.cshtml`

``` cs 
// Code in Controller
public IActionResult WhichIsBigger(int value1 = 1, int value2 = 2)
{
    if (value1 > value2)
    { 
        ViewData["biggest"] = value1;
        ViewData["lowest"] = value2;
    }
    else {
        ViewData["biggest"] = value2;
        ViewData["lowest"] = value1;
    }
        return View();
}

// Code in View
@{
    ViewData["Title"] = "Passing Data";
}

<title>@ViewData["Title"] </title>

@if ((int)ViewData["biggest"] == (int)ViewData["lowest"])
{
    <h2> Empate </h2>
}
else
{
    <h2> The biggest number is @ViewData["biggest"] </h2>
    <h2> The lowest number is @ViewData["lowest"] </h2>
}
```

- This is nice but the better way is using `Model Approach`.  
