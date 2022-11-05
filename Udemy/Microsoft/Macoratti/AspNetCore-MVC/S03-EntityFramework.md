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

## V019 - Mounting a ConnectionString on SQL Server
In this project Database and its tables will be created automatically using `Migrations`. To do this we need:
- Environment Configuration (previous video)
- Define a ConnectionString local instance on SQL server.
  - A Connection String is an expression that contains the parameters needed to establish a connection between an app and the DB Server.
  - Its configuration includes:
    - Server instance
    - DBname
    - Authentication details, and other configs
  - Examples:
    - By Authentication:
      - SQL Server Authentication: `Server=ServerName;Database=DatabaseName;User Id=UserName;Password=UserPassword` (who the F will use its password in the code?)
      - Windows Authentication(recommended): `Server=ServerName;Database=DatabaseName;Trusted_Connection=True` (uses your Windows account)
    - By Instance:
      - LocalDB: `Server=(localdb)\MineInstance;IntegratedSecurity=True`
      - SQL Express(recommended): `Data Source=nome_server//sqlexpress;InitialCatalog=Database1;IntegratedSecurity=True`
  - To get the `Server` and `Instance`: In `SQL Server 2019 Configuration Manager` then `Serviços do SQL Server/SQL Server(SQLEXPRESS)`. In its `Right-Click/Properties/Serviço` you can get both, the server(host) and instance(nome).
  - 
## V020 - Data Annotations
- They are attributes that can ve applied to classes and its fields. 
  - To define:
    -  `validation rules` to the `model`
    -  how interfaces shall show this data
  - To specify reltionships between entities in the `model`
  - To OVERWRITE EF-Core conventions.
- `Data annotations` are available in>:
  - `System.ComponentModel.DataAnnotations`
  - `System.ComponentModel.DataAnnotations.Schema`
 - You can use it in:
  - Front-End:
    - `Validation Attributes`: to set validation rules in views e.g. email, data validation.
    - `Exibition Attributes`: how model attributes will be showed.
  - Back-End: 
    - `Data Modelling Attributes`: To specify the format of the fields in a table. The relationship between classes.

### Validation rules in View
- Define attributes to the fields of the classes which belong to the `Model`
- Once the validation rules were set in this class, it will be applied in anywhere the class is used.
- This validation is applied in the `Model` and not in the View
- Main attributes:
  - Required: Property shall be filled with data and do not accept `null` values.
  - Range: sets valid interval value to the field
  - EmailAddress:
  - Phone: Validates telephone format
  - MinLenght:
  - MaxLenght:
  - StringLenght:
  - RegularExpression:
  - Display: Specifies how fields are showed and formatted in View.
  - DisplayFormat: Applies a given format to a property that will be showed in View
- Available at `System.ComponentModel.DataAnnotations`
- Example:

``` cs
public class Lanche
{
  public int LancheId {get; set;}

  [Required]
  [Display(Name = "Name of Lanche")]
  public string Nome { get; set;}

  [Required]
  [Display(Name = "Description of Lanche")]
  [MinLength(20)]
  [MaxLength(200)]
  public string Description { get; set;}
}
```

It is possible to use the `ErrorMessage = "message"` property to improve the data annotations validation. Then if it fails it will show the "message".

``` cs
public class Lanche
{
  public int LancheId {get; set;}
  
  [Required (ErrorMessage="Name is required")]
  [Display(Name = "Name of Lanche")]
  public string Nome { get; set;}

  [Required (ErrorMessage="Description is required")]
  [Display(Name = "Description of Lanche")]
  [MinLength(20, ErrorMessage="Description shall be more than {1} characters")]
  [MaxLength(200, ErrorMessage="Description shall be less than {1} characters")]
  public string Description { get; set;}
}
```

### Data Modelling Attributes

- Main attributes:
  - `Key(*)`: Identifies a property as a primary key in the table.
  - `Table`: Defines the name of the table where the class will be mapped.
  - `Column`: Sets a column to mapped property.
  - `DataType(*)`: sets an additional data type to a property.
  - `ForeignKey`: Set a property as a foreign key.
  - `NotMapped`: To exclude from mapping.
- Available at: `System.ComponentModel.DataAnnotations.Schema`
- Example:

``` cs
[Table("Lanches")] // Lanche class will be mapped to "Lanches" Table
public class Lanche
{
  [Key]
  public int LancheId {get; set;}

  [Required]
  [Display(Name = "Name of Lanche")]
  public string Nome { get; set;}

  [Required]
  [Display(Name = "Description of Lanche")]
  [MinLength(20)]
  [MaxLength(200)]
  public string Description { get; set;}

  [NotMapped] // DateOfCreation will not mapped to Table
  public DateTime DateOfCreation { get; set;}
}
```

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
