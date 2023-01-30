## Reference

[Tutorial Reference](https://learn.microsoft.com/en-us/dotnet/maui/tutorials/notes-app/?view=net-maui-7.0)

## Customize the app shell

- `MauiProgram.cs`:
  - bootstraps the app
  - it is the cross-platform entry point of the app, which configures and starts the app.
  - The templete startup points to the `App` class defined in the `App.xaml` file
- `App.xaml`: contains the XAML markup 
  - `App.xaml.cs` (children file) instantiates the Shell application (`AppShell` class)
- `AppShell.xaml`and `AppShell.xaml.cs` defines the `AppShell` class, which is used to define visual hierarchy of the app.
- `MainPage.xaml` and `MainPage.xaml.cs`: This is the startup page displayed by the app.

## Add an `about` Page 
1. Right-click on Project
2. `Add/New Item/.NET MAUI ContentPage(XAML)`
3. Add the following code in the `AboutPage.xaml`
   
``` console
<?xml version="1.0" encoding="utf-8" ?>
<ContentPage xmlns="http://schemas.microsoft.com/dotnet/2021/maui"
             xmlns:x="http://schemas.microsoft.com/winfx/2009/xaml"
             x:Class="Notes.AboutPage">
    <VerticalStackLayout Spacing="10" Margin="10">
        <HorizontalStackLayout Spacing="10">
            <Image Source="dotnet_bot.png"
                   SemanticProperties.Description="The dot net bot waving hello!"
                   HeightRequest="64" />
            <Label FontSize="22" FontAttributes="Bold" Text="Notes" VerticalOptions="End" />
            <Label FontSize="22" Text="v1.0" VerticalOptions="End" />
        </HorizontalStackLayout>

        <Label Text="This app is written in XAML and C# with .NET MAUI." />
        <Button Text="Learn more..." Clicked="LearnMore_Clicked" />
    </VerticalStackLayout>
</ContentPage>
```

The code is explained below:
- `x:Class="Notes.AboutPage"` has the following sintaxis "NameProject.NameOfPage"
- `<ContentPage>` is the root object for the AboutPage class.
- `<VerticalStackLayout>` is the only child object of the `<ContentPage>`. 
  - `<ContentPage>` can only have one child object. 
  - The `<VerticalStackLayout>` type can have multiple children. This layout control arranges its children vertically, one after the other.
- `<HorizontalStackLayout>` operates the same as a `<VerticalStackLayout>`, except its children are arranged horizontally.
- `<Image>` displays an image, in this case it's using the `dotnet_bot.png` image that comes with every .NET MAUI project.
- `<Label>` controls display text.
- `<Button>` controls can be pressed by the user, which raise the Clicked event. You can run code in response to the Clicked event.
    - Clicked event, `Clicked="LearnMore_Clicked"`

The Clicked event of the button is assigned to the LearnMore_Clicked event handler, defined in the code-behind file. You'll create this code in the next step.

## Handle the Clicked event
To add a method:
1. Put the mouse in the middle of `Clicked="LearnMore_Clicked"` then `Right-Click/Go To Definition`


## Add image resources
- Any image used in the project shall be moved to `Resources\Images`, any file there is automatically included in the project.

## Modify the app Shell
First of all, WHats is a shell?
- A Page that provides fundamental UI features that most applications require, leaving you to focus on the application's core workload.
- So we need to modify the `AppShell.xaml` to include the new tab.
- Copy the following code there:

``` console
<?xml version="1.0" encoding="UTF-8" ?>
<Shell
    x:Class="Notes.AppShell"
    xmlns="http://schemas.microsoft.com/dotnet/2021/maui"
    xmlns:x="http://schemas.microsoft.com/winfx/2009/xaml"
    xmlns:local="clr-namespace:Notes"
    Shell.FlyoutBehavior="Disabled">

    <TabBar>
        <ShellContent
            Title="Notes"
            ContentTemplate="{DataTemplate local:MainPage}"
            Icon="{OnPlatform 'icon_notes.png', iOS='icon_notes_ios.png', MacCatalyst='icon_notes_ios.png'}" />

        <ShellContent
            Title="About"
            ContentTemplate="{DataTemplate local:AboutPage}"
            Icon="{OnPlatform 'icon_about.png', iOS='icon_about_ios.png', MacCatalyst='icon_about_ios.png'}" />
    </TabBar>

</Shell>
```
The code is explained below:
- `<Shell>` is the root object of the XAML markup.
- `<TabBar>` is the content of the Shell.
  - The TabBar and its children don't represent any user interface elements, but rather the organization of the app's visual hierarchy.
  - Shell takes these objects and produces the user interface for the content, with a bar at the top representing each page
- Two `<ShellContent>` objects inside of the `<TabBar>`. Before you replaced the template code, there was a single `<ShellContent>` object, pointing to the MainPage page.
  - The `ShellContent.Icon` property for each page uses special syntax: `{OnPlatform ...}`. 
    - This syntax is processed when the XAML pages are compiled for each platform, and with it you can specify a property value for each platform. 
      - In this case, every platform uses the icon_about.png icon by default, but iOS and MacCatalyst will use icon_about_ios.png.
  - Each `<ShellContent>` object is pointing to a page to display. This is set by the ContentTemplate property.
  
## Run the app