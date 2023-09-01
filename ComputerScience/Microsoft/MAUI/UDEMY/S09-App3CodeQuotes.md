<!-- vscode-markdown-toc -->
* 1. [V052. Introducción](#V052.Introduccin)
* 2. [V053. Definiendo la interfaz principal](#V053.Definiendolainterfazprincipal)
* 3. [V054. Trabajando con degradados en net maui](#V054.Trabajandocondegradadosennetmaui)
* 4. [V055. Creando el fondo de la aplicación](#V055.Creandoelfondodelaaplicacin)
* 5. [V056. Generando la frase aleatoria](#V056.Generandolafrasealeatoria)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->



##  1. <a name='V052.Introduccin'></a>V052. Introducción

- Primero se implementa la parte gráfica:

``` xml
<Grid BackgroundColor="Navy">
    <Grid Margin="25" RowDefinitions=".8*,.2*">
        <Label
            FontFamily="MainFont"
            FontSize="50"
            HorizontalTextAlignment="Center"
            Text="Quem tem cu tem medo."
            TextColor="White"
            VerticalOptions="Center" />
        <Button 
            Grid.Row="1" 
            BackgroundColor="Black"
            Opacity=".4"
            Text="Get New Quote" />
    </Grid>
</Grid>
```

- Se adiciona la fuente:

``` cs 
builder
	.UseMauiApp<App>()
	.ConfigureFonts(fonts =>
	{
		fonts.AddFont("OpenSans-Regular.ttf", "OpenSansRegular");
		fonts.AddFont("OpenSans-Semibold.ttf", "OpenSansSemibold");
        fonts.AddFont("Bison.ttf", "MainFont");
    });
```
##  2. <a name='V053.Definiendolainterfazprincipal'></a>V053. Definiendo la interfaz principal

##  3. <a name='V054.Trabajandocondegradadosennetmaui'></a>V054. Trabajando con degradados en net maui

##  4. <a name='V055.Creandoelfondodelaaplicacin'></a>V055. Creando el fondo de la aplicación

##  5. <a name='V056.Generandolafrasealeatoria'></a>V056. Generando la frase aleatoria

