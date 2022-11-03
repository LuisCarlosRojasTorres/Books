## V016 - Domain model

Domain Model are the classes which represent the business logic.

In this example, the main purpose is *Vender lanches*, so we will have:

- Lanche: nome, preço, descr. curta, descr. longa, imagem, imagem minuatura, **categoria**, se é um lanche preferido, se o lanche está disponivel.
- Categoria: nome, descrição.

These will be modelled to generate the `Lanche.cs` and `Categoria.cs` classes.

Using an `ORM Tool` (Object Relational Mapping) , classes can be mapped to DB tables. Microsoft recomends **Entity Framework Core**:
1. It generates DB from the classes
2. First create the classes, then using EF Core DB and tables are generated through `Migrations`.

Advantages:
- DB properties and relationships using C#
- No more SQL
- DB Versioning using Migrations
- Increase productivity.

Conventons:
- An `Id` or `<name>Id` generate a primary key in the table
- Each field will generate a column (with same name) on the table.
- Relationship definitions between entities are defined using *navigation* property.

![Relationships](/Udemy/Microsoft/Macoratti/AspNetCore-MVC/uploads/V016-a.png)

In code:

``` cs
// Categoria.cs
public class Categoria
{
    public int CategoriaId { get; set; }
    public string CategoriaName { get; set; }
    public string Descricao { get; set; }

    public List<Lanche> Lanches { get; set; }
}

// Lanche.cs
public class Lanche
{
    public int LancheId { get; set; }
    public string Nome { get; set; };
    public string DescricaoCurta { get; set; }
    public string DescricaoDetalhada { get; set; }
    public string Preco { get; set; };
    public string ImagemUrl { get; set; }
    public string ImagemThumbnailURL { get; set; }
    public string IsLanchePreferido { get; set; }
    public string EmEstoque { get; set; }

    public string CategoriaId { get; set; }
    public virtual Categoria Categoria { get; set; }
}


```
## V017 - Entity FrameworkCore
A ORM(Object Relational Mapping) permits to operate databases through `C#` code.

- It is a multiplatform Entity Framework (EF6) version.
- Supports: SQLServer, MySql, SQLite, PostGreSql.
- it can be used in: web, mobile, desktop, cloud
- Support `Code-First` and `Database-First` approaches.
  - `Database-First`: We begin with `Database` and using `Scafolding` we get the `Domain Classes`
  - `Code-First`: We begin with `Domain Classes` and using `Migrations` we get the `Database`
    - Improves productivity: is easier to create classes than DBs
    - Control on DB versioning through Migrations
    - Less code needed
    - Easy to test and integrate
- It is installed through `Nugets packages`.
   
### So, how it works?
- LINQ instructions are send to `DbContext`(Database) classes which convert to `SQL` commands to a `DbSet<T>`(Tables).
  - `DbContext` represents Database session:
    - So, it connects to the database.
    - Perform data operations
    - Query and data persistence
    - Data mapping
    - Transactions management
  - `DbSet<T>` represents Tables
    - `<T>` are the class which is converts classes to tables.
    - it uses memory until `SaveChanges()` is changed.

## V018 - EF Core Configuration
- `Tools/Nuget Package Manager/Manage NuGet Packages for Solution...`
- Search for:
  - `Microsoft.EntityFrameworkCore.Design` version `6.0.0`
  - `Microsoft.EntityFrameworkCore.SqlServer` version `6.0.0`
  - `Microsoft.EntityFrameworkCore.Tools` version `6.0.0`

- Create a `Context` folder in the project.
  - Create the `AppDbContext` which inherits from `DbContext`

``` cs
using LanchesMac.Models;
using Microsoft.EntityFrameworkCore;

namespace LanchesMac.Context;

public class AppDbContext : DbContext
{
    public AppDbContext(DbContextOptions<AppDbContext> options) : base(options)
    { 
    }

    //Defining which classes will be mapped to tables
    public DbSet<Categoria> Categorias { get; set; }
    public DbSet<Lanche> Lanches { get; set; }
}
```
- Next step is to define an `ConnectionString`. In `View/OtherWindows/ServerExplorer` you can see the name of the computer (in my case `LAPTOP-5LIB34M2`) then in `appsetthings.json` add:

``` json
"ConnectionStrings": {
    "DefaultConnection": "Data Source=LAPTOP-5LIB34M2//sqlexpress;InitialCatalog=LanchesDatabase;Integrated Security=True"
}
```

- Now in `Startup` , the service is registered in `ConfigureServices`  method:

``` cs

//services.AddDbContext<YourContextClass>(options=>
//  options.UseDBProvider(ConfigurationInstance.GetConnectionString("ConnectionStringName")));

services.AddDbContext<AppDbContext>(options=>
  options.UseSqlServer(Configuration.GetConnectionString("DefaultConnection")));
```

## V019 - Mounting SQL Server

## V020 - Data Annotations

## V021 - EF Core Migrations

## V022 - Data Annotations Atributes

## V023 - Applying Migrations to the Project

## V024 - Filling tables with Migrations

## V025 - Filling Categorias Table with initial data

## V026 - Filling Lanches Table with initial data

## V027 - Repository pattern

## V028 - Implementing Repository pattern to Categoria

## V029 - Implementing Repository pattern to Lanches

## V030 - Registering repository services: Dependency Injection
