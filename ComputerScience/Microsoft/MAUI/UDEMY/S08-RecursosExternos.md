<!-- vscode-markdown-toc -->
* 1. [V047. Agregando Imágenes al proyecto](#V047.AgregandoImgenesalproyecto)
* 2. [V048. Agregando y utilizando Fuentes](#V048.AgregandoyutilizandoFuentes)
* 3. [V049. Utilizando fuentes de íconos](#V049.Utilizandofuentesdeconos)
* 4. [V050. Agregando otro tipo de archivos](#V050.Agregandootrotipodearchivos)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

##  1. <a name='V047.AgregandoImgenesalproyecto'></a>V047. Agregando Imágenes al proyecto
- Los nombres tienes que ser mayuscykas
- La extension de la imagen no es necesaria (a menos que tengas dos imagenes que se llaman igual)

- Ventajas de png con jpeg es que aceptan transparencia.

``` xml
<StackLayout BackgroundColor="SkyBlue">
    <Image Source="yoctoba.png"/>
</StackLayout>
```

- Se puede user `gif`

``` xml
<StackLayout BackgroundColor="Black">
    <Image Source="loader"
		   IsAnimationPlaying="True" />
</StackLayout>
```

- MAUI acepta imagenes `svg`.
  - Sin embargo pueden aparecer borrosas las imagenes. Esto debido a que se tiene que establecer un tamaño base.
  - Esto es definido en el proyecto, asi el del robot es definido como:

``` xml
<!-- Images -->
		<MauiImage Include="Resources\Images\*" />
		<MauiImage Update="Resources\Images\dotnet_bot.svg" BaseSize="168,208" />
```
- Por tanto copiamos la linea referente al `dotnet_bot.svg` para la nueva iamgen:

``` xml
<!-- Images -->
		<MauiImage Include="Resources\Images\*" />
		<MauiImage Update="Resources\Images\dotnet_bot.svg" BaseSize="168,208" />
		<MauiImage Update="Resources\Images\dummyImage.svg" BaseSize="300,300" />
```

- Tiene una propiedad llamada `TintColor=<ColorPlaceHolder>` que pinta de un colro solido la imagen.

##  2. <a name='V048.AgregandoyutilizandoFuentes'></a>V048. Agregando y utilizando Fuentes
- Las fuentes pueden ser descargadasen formato `.ttf`


``` xml
<StackLayout BackgroundColor="Black">
    <Label 
        FontFamily="OpenSans-Semibold.ttf"
        FontAttributes="Bold,Italic"
        FontSize="50"
        TextColor="White"
        Text="This is a font test"
    />
</StackLayout>
```

- Para no tener que utilizar el nombre completo junto con la extension se puede crear un *alias*.
- Esto se consigue en el main program. Aqui por ejemplo se encuentra las fuentes default:

``` cs
builder
	.UseMauiApp<App>()
	.ConfigureFonts(fonts =>
	{
		fonts.AddFont("OpenSans-Regular.ttf", "OpenSansRegular");
		fonts.AddFont("OpenSans-Semibold.ttf", "OpenSansSemibold");
		fonts.AddFont("<FontNamePlaceholder>.ttf", "<FontAliasPlaceholder>");
	});
```

- Asi puede ser utilizado en el xaml

``` xml
<StackLayout BackgroundColor="Black">
    <Label 
        FontFamily="<FontAliasPlaceholder>"
        FontAttributes="Bold,Italic"
        FontSize="50"
        TextColor="White"
        Text="This is a font test"
    />
</StackLayout>
```

##  3. <a name='V049.Utilizandofuentesdeconos'></a>V049. Utilizando fuentes de íconos
- 
##  4. <a name='V050.Agregandootrotipodearchivos'></a>V050. Agregando otro tipo de archivos
- La carpeta `raw` sirve para incluir `pdfs`, `json`, `office files`.
  - Base de datos??
- Para poder utilizar estos `resources` un template es disponibilizado en `AboutAssets.txt`

``` cs
async Task LoadMauiAsset()
{
	using var stream = await FileSystem.OpenAppPackageFileAsync("AboutAssets.txt");
	using var reader = new StreamReader(stream);

	var contents = reader.ReadToEnd();
}
```

- Este método debe ser copiado en el `MainPage.xml` con el nombre del archivo que queremos leer en el argumento del método `OpenAppApckageFleAsync`

### Ejemplo
- Digamos que queremos leer el archivo `data.json`:

``` json
{
	"Name": "Lobo",
	"Age": 5
}
```

1. Implementar una clase para modelar el `json`

``` cs 
public class Person 
{
    public string Name { get; set; }
    public int Age { get; set; }
}
```

2. Adicionar `using System.Text.Json;` ahora `var p = JsonSerializer.Deserialize<Person>(contents);` ahora `p` va a almacenar los datos.

``` cs 
async Task LoadMauiAsset()
{
    using var stream = await FileSystem.OpenAppPackageFileAsync("data.json");
    using var reader = new StreamReader(stream);

    var contents = reader.ReadToEnd();

    var p = JsonSerializer.Deserialize<Person>(contents);
}
```
3. Implementar `OnAppearing`

``` cs
protected override async void OnAppearing()
{
    base.OnAppearing();
    await LoadMauiAsset();
}
```