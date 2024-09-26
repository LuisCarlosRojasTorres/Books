
## C2 - Jetpack Compose Basics
### Declarative vs Imperative
- Imperative: the old xml style.
- Declarative: 
  - Focus on describe the **desirable outcome** rather than specify the step-by-step instructions.
  - UI appearance is defined based on the current state.
  - UI structure, layout and behaviour are described through the UI elements and its properties.
  - more emphasis on *inmutable state* , where the UI is represented by *inmutable data objects*. So: *instead of directly mutating the state, we create new instances of the data objects to reflect the desired changes in the UI*.
  - The framework takes care of updating the UI based on changes in the application state.

#### Composable functions
- It describes how to render a UI
  - These functions must be annotated with the `@Composable` tag.
- Composable functions are pure functions, meaning they don’t have any side effects. i.e. They produce the same output when called several times with the same input.
- They are meant to be reusable. They can be combine to build complex UIs.
- Template:
``` kt
@Composable
fun DummyComposableFunction(dummyName: String) {
  Text(text = "Dummy name example: $dummyName") 
}
```

- `Text` is composable function from the material design 

#### Previews
- IT generates a preview of our composable function or a group of Compose components inside Android Studio
- Template:
 
``` kt
@Preview(showBackground = true)
@Composable
fun DummyComposableFunctionPreview() {
  DummyComposableFunction("Rufo") 
}
```

#### Modifiers
- They:
  - change size, behaviour and appearance (padding, color, shape etc) of composable functions
  - process user input
  - add interactions i.e. clicks etc
- Modifiers do not modify the original composable. They return a new, modified instance. 
  - This ensures our composable remains unchanged and immutable.
- Most Jetpack Compose components from the library allow us to provide a modifier as a parameter. 
  - Example:
  ``` kt 
  @Composable
  fun DummyComposableFunction(dummyName: String, modifier: Modifier = Modifier) {
    Text(modifier = modifier, text = "Dummy name example: $dummyName")
  }
  ``` 
- To add padding to a text:
``` kt
Text(modifier = Modifier.padding(16.dp), text = "Dummy name example: $dummyName") 
```

- They can be chained (using `.`) to add more properties: 
``` kt
Text(modifier = Modifier.fillMaxWidth().padding(16.dp).background(Color.Red), text = "Dummy name example: $dummyName") 
```

- Example: 
``` kt
@Preview(showBackground = true)
@Composable
fun DummyComposableFunctionPreview() {
    DummyComposableFunction("Rufo", modifier = Modifier.fillMaxWidth().padding(5.dp).background(Color.Red))
}
```
### Jetpack Compose layouts
- How compose transforms `state` into `UI`:
  1. Composition:
     - The Compose compiler creates a tree of UI elements. 
       - Each element is a function that represents a UI element. Compose then calls the functions to create the UI tree. 
     - The composition step is responsible for determining which composables need updates and which ones can be reused. 
       - This happens by comparing a previous tree of composables with the new tree and only updating the ones that have changed
  2. Layout:
     - the Compose compiler takes the tree generated in the previous phase and determines its size, position, and layout.
     - each composable is measured and positioned within the layout based on its parent and any constraints set. 
     - Then it creates the final layout tree
     - So, this phase is responsible for determining the final position and size of each UI element on the screen
  3. Drawing:
     - it uses the final layout tree to draw (render) the elements on the screen.

- The layouts available in Jetpack Compose are: `Column`, `Row`, `Box` and `Lists`

#### Column
- Template:
``` kt
Column {
Text(text = "Rufo")
Text(text = "Rufa")
}
```
- Example: 
``` kt
@Composable
fun DummyComposableColumnFunction(dummyName1: String, dummyName2: String,modifier: Modifier = Modifier) {
    Column  {
        Text(modifier = modifier, text = "Dummy name 1 example: $dummyName1")
        Text(modifier = modifier, text = "Dummy name 2 example: $dummyName2")
    }
}

@Preview(showBackground = true)
@Composable
fun DummyComposableColumnFunctionPreview() {
    DummyComposableColumnFunction("Rufo", "Rufa", modifier = Modifier
        .fillMaxWidth()
        .padding(5.dp)
        .background(Color.Red))
}
```

- Columns can also have `modifiers`
``` kt
Column(
  modifier = Modifier
.fillMaxSize()
.padding(16.dp),
verticalArrangement = Arrangement.Center,
horizontalAlignment = Alignment.CenterHorizontally
){
Text(text = "Rufo")
Text(text = "Rufa")
}
```
#### Row 
- Template:
``` kt
Row {
Text(text = "Rufo")
Text(text = "Rufa")
}
```
#### Box 
``` kt
```
#### Lists 
- Compose provides the `LazyColumn` and `LazyRow` components, which can be used to display a list of items. 
  - These components are very efficient and performant.
  - They only render the items that are visible on the screen, rather than rendering all the items at once.
  - These composable functions allow you to define the contents of the list as a function that returns a single item, and then Compose will automatically generate and render the UI elements for each item in the list as they become visible on the screen.  
- LazyColumn example:
``` kt
@Composable
fun DummyComposableListFunction(dummyName: String, modifier: Modifier = Modifier) {
    LazyColumn(
        modifier = Modifier
            .fillMaxSize()
            .background(Color.LightGray)
    ) {
        items(100) {
            Text(
                modifier = modifier,
                text = "$dummyName $it"
            )
        }
    }
}

@Preview(showBackground = true)
@Composable
fun DummyComposableListFunctionPreview() {
    DummyComposableListFunction("Rufo", modifier = Modifier
        .fillMaxWidth()
        .padding(5.dp)
        .background(Color.Red))
}
```

- LazyRow example:
``` kt
@Composable
fun DummyComposableListFunction(dummyName: String, modifier: Modifier = Modifier) {
    LazyRow(
        modifier = Modifier
            .fillMaxSize()
            .background(Color.LightGray)
    ) {
        items(100) {
            Text(
                modifier = modifier,
                text = "$dummyName $it"
            )
        }
    }
}

@Preview(showBackground = true)
@Composable
fun DummyComposableListFunctionPreview() {
    DummyComposableListFunction("Rufa", modifier = Modifier
        .fillMaxWidth()
        .padding(5.dp)
        .background(Color.Green))
}
```
### ConstraintLayout
- Creates responsive layouts with relative positioning.
  - It can use chains, guidelines to position child elements relative to each other.
- To use it add the following dependency to the `build.gradle` file:
- Use Groovy instead of Kotlin for Gradle
```
implementation "androidx.constraintlayout:constraintlayout-compose:1.0.1"
```
``` kt
```
## Material Design

``` kt
```

## Anexo

### C2 Code
- `MainActivity.kt`
``` kt
class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContent {

            DummyComposableListFunction(
                        dummyName = "Rufo",
                        modifier = Modifier
                            .fillMaxWidth()
                            .padding(16.dp)
                            .background(Color.Red)
                    )
                }
            }
        }

@Composable
fun DummyComposableFunction(dummyName: String, modifier: Modifier = Modifier) {
    Text(modifier = modifier, text = "Dummy name example: $dummyName")
}

@Composable
fun DummyComposableColumnFunction(dummyName1: String, dummyName2: String,modifier: Modifier = Modifier) {
    Column  {
        Text(modifier = modifier, text = "Dummy name 1 example: $dummyName1")
        Text(modifier = modifier, text = "Dummy name 2 example: $dummyName2")
    }
}

@Composable
fun DummyComposableListFunction(dummyName: String, modifier: Modifier = Modifier) {
    LazyColumn(
        modifier = Modifier
            .fillMaxSize()
            .background(Color.LightGray)
    ) {
        items(100) {
            Text(
                modifier = modifier,
                text = "$dummyName $it"
            )
        }
    }
}

@Preview(showBackground = true)
@Composable
fun DummyComposableFunctionPreview() {
    DummyComposableFunction("Rufo",modifier = Modifier
        .fillMaxWidth()
        .padding(5.dp)
        .background(Color.Red))
}

@Preview(showBackground = true)
@Composable
fun DummyComposableColumnFunctionPreview() {
    DummyComposableColumnFunction("Rufo", "Rufa", modifier = Modifier
        .fillMaxWidth()
        .padding(5.dp)
        .background(Color.Red))
}

@Preview(showBackground = true)
@Composable
fun DummyComposableListFunctionPreview() {
    DummyComposableListFunction("Rufo", modifier = Modifier
        .fillMaxWidth()
        .padding(5.dp)
        .background(Color.Red))
}
```

### C3 Code

``` kt
```