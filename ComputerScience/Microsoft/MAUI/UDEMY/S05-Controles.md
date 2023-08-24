<!-- vscode-markdown-toc -->
* 1. [V27. Controles de Presentación](#V27.ControlesdePresentacin)
* 2. [V28. Controles que inician commandos](#V28.Controlesqueiniciancommandos)
* 3. [V29. Controles para establecer valores](#V29.Controlesparaestablecervalores)
* 4. [V30. Controles de edición de texto](#V30.Controlesdeedicindetexto)
* 5. [V31. Controles para indicar actividad](#V31.Controlesparaindicaractividad)
* 6. [V32. Controles para desplegar colecciones](#V32.Controlesparadesplegarcolecciones)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

##  1. <a name='V27.ControlesdePresentacin'></a>V27. Controles de Presentación
- To add **scroll** property to the layout insert the layout into a `ScrollView`:

``` xml
<ScrollView>
	<StackLayout>
	...
	</StackLayout>
</ScrollView>
```

- `BoxView`:

``` xml
<BoxView BackgroundColor="Black"
                 HeightRequest="200"/>
```

- `Label`:

``` xml
<Label Text="DummyLabel" TextColor="Black"
               FontAttributes="Bold" FontSize="Large"
               HorizontalTextAlignment="Center"/>
```

- `Ellipse`:

``` xml
<Ellipse Fill="Red"
         Stroke="DarkRed"
         StrokeThickness="10"
         HeightRequest="200"
         HorizontalOptions="Center"
         WidthRequest="100"/>
```

- `Line`:
  
``` xml
<Line Stroke="Black"
        X1="0"
        Y1="0"
        X2="100"
        Y2="50"
        StrokeThickness="2" />
```
- `Rectangle`
``` xml
<Rectangle Fill="Red"
            Stroke="Black"
            StrokeThickness="15"
            HeightRequest="150"
            HorizontalOptions="Center"
            WidthRequest="150"
            RadiusX="10"
            RadiusY="10" />
```
- `Polygon`
``` xml
<Polygon Fill="LightBlue"
        Points="40,10 70,80 10,50" />
<Polygon Fill="Yellow"
        Points="40,10 70,80 10,50" 
        Stroke="Red"
        StrokeDashArray="1,1"
        StrokeDashOffset="6"
        StrokeThickness="5" />
```
- `Polyline`
``` xml
<Polyline Points="0,0 5,5 15,0 18,60 25,25 "
            Stroke="Red" />
```
- `Path`
``` xml
<Path Aspect="Uniform"
        Data="M 10,100 L 100,100 100,50Z"
        HorizontalOptions="Center"
        Stroke="Black"/>
```
- `Border`
``` xml
<Border Stroke="#C49B33"
        StrokeThickness="4"
        Background="#2B0B98"
        Padding="16,8"
        HorizontalOptions="Center">
        <Border.StrokeShape>
            <RoundRectangle CornerRadius="40,0,0,40" />
        </Border.StrokeShape>
        <Label Text="Welcome to .NET MAUI!"
        	VerticalOptions="Center" 
            HorizontalOptions="Center" 
            TextColor="White"/>
</Border>
```

- `Frame`
``` xml
<Frame Margin="15"
        BackgroundColor="Red"
        Padding="10">
        <Image Source="dotnet_bot.svg"/>
</Frame>
```
- `WebView`
``` xml
<WebView HeightRequest="500"
        Source="https://github.com/LuisCarlosRojasTorres"/>
```

![Alt text](image-18.png)
![Alt text](image-19.png)

##  2. <a name='V28.Controlesqueiniciancommandos'></a>V28. Controles que inician commandos
##  3. <a name='V29.Controlesparaestablecervalores'></a>V29. Controles para establecer valores

##  4. <a name='V30.Controlesdeedicindetexto'></a>V30. Controles de edición de texto

##  5. <a name='V31.Controlesparaindicaractividad'></a>V31. Controles para indicar actividad

##  6. <a name='V32.Controlesparadesplegarcolecciones'></a>V32. Controles para desplegar colecciones

