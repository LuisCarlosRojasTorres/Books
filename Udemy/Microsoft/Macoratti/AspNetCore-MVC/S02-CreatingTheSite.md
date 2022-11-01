## V010 - Creating the MVC Project
- Instructions:

1. Create new project
2. Select `ASP.NET Core Web App (Model-View-Controller)`
3. Give a nanme
4. Select the `.NET 6.0` framework
5. No Autentication, No Docker
6. Create

The file `Startup` can be added from another project with older framework.
To do this:
1. Create `Startup.cs` and copy the following code. 
2. Preserve the old `namespace` statement

``` cs
public class Startup
{
    public Startup(IConfiguration configuration)
    {
        Configuration = configuration;
    }

    public IConfiguration Configuration { get; }

    // This method gets called by the runtime. Use this method to add services to the container.
    public void ConfigureServices(IServiceCollection services)
    {
        services.AddControllersWithViews();
    }

    // This method gets called by the runtime. Use this method to configure the HTTP request pipeline.
    public void Configure(IApplicationBuilder app, IWebHostEnvironment env)
    {
        if (env.IsDevelopment())
        {
            app.UseDeveloperExceptionPage();
        }
        else
        {
            app.UseExceptionHandler("/Home/Error");
            // The default HSTS value is 30 days. You may want to change this for production scenarios, see https://aka.ms/aspnetcore-hsts.
            app.UseHsts();
        }
        app.UseHttpsRedirection();
        app.UseStaticFiles();

        app.UseRouting();

        app.UseAuthorization();

        app.UseEndpoints(endpoints =>
        {
            // This expression menas that the default URL routing logic is used.
            endpoints.MapControllerRoute(
                name: "default",
                pattern: "{controller=Home}/{action=Index}/{id?}");
        });
    }
}
```
3. Replace the code in `Program.cs` for:

``` cs
using ProjectName;

public class Program
{
    public static void Main(string[] args)
    {
        CreateHostBuilder(args).Build().Run();
    }

    public static IHostBuilder CreateHostBuilder(string[] args) =>
            Host.CreateDefaultBuilder(args)
                .ConfigureWebHostDefaults(webBuilder =>
                {
                    webBuilder.UseStartup<Startup>();
                });
}
```

4. Delete `Logger` and `Privacy` action methods in `HomeController.cs`
5. Delete the `Privacy` references in `_Layout.cshtml`.

## V011 - Project Structure
- It shows all the folder and files of the project.

# V014 - Creating a Carrousel
A carrousel is inserted in a partial view i.e a view that can be used by another.
1. In `wwwroot`, create a new folder `images`.
2. Add the images that ou want to use in the folder `images`
3. Create a new view, because this view it will be shared its name starts with `_`. Lets say, `_Carrousel.cshtml`
4.  Copy the content below in the view.
``` html
<div id="carouselExampleControls" class="carousel slide" data-bs-ride="carousel">
  <div class="carousel-inner">
    <div class="carousel-item active">
      <img src="..." class="d-block w-100" alt="...">
    </div>
    <div class="carousel-item">
      <img src="..." class="d-block w-100" alt="...">
    </div>
    <div class="carousel-item">
      <img src="..." class="d-block w-100" alt="...">
    </div>
  </div>
  <button class="carousel-control-prev" type="button" data-bs-target="#carouselExampleControls" data-bs-slide="prev">
    <span class="carousel-control-prev-icon" aria-hidden="true"></span>
    <span class="visually-hidden">Previous</span>
  </button>
  <button class="carousel-control-next" type="button" data-bs-target="#carouselExampleControls" data-bs-slide="next">
    <span class="carousel-control-next-icon" aria-hidden="true"></span>
    <span class="visually-hidden">Next</span>
  </button>
</div>
```
5. Modify the `id` of the previous text from `id="carouselExampleControls"` to `id="carouselLanches"`
6. To include the images from root folder, write `~/` in the `src="..."`. e.g. `<img src="~/images/dummyImage.jpeg" class="d-block w-100" alt="...">`
7. This partial view, it will be presented in the main View. To include a partial view the following code shall be added: `<partial name="_Carousel"/>`
8. To comments the code, put the code between `@*` and `*@`.

