## Fundamentals

### Overview

- `Startup`class: 
  - Configures Services required by the app.
  - Defines the app's request handling pipeline (as a series of middleware components).
- The services are registered in `Startup.ConfigureServices`
- The request handling pipeline which is composed as a series of middleware is created adding middleware componentes in `Startup.Configure` method
- A `Host` encapsulates all app resources (e.g. `HTTP` server implementation, Middleware components, Logging, DI services and Configuration)
- The `.NET Generic host` is recommended.
- In `Main()`  the methods ` CreateDefaultBuilder` and `ConfigureWebHostDefaults` methods configure a host with a set of default options.

#### Configuration
- By default, ASP.NET Core apps are configured to read from appsettings.json, environment variables, the command line, and more.
  
#### Environments
- Execution environments, such as Development, Staging, and Production, are a first-class notion in ASP.NET Core.
  
#### Logging
- A logging API that works with a variety of built-in and third-party logging providers (Console, Debug)

#### Routing
- A route is a URL pattern that is mapped to a handler. The handler is typically a Razor page, an action method in an MVC controller, or a middleware