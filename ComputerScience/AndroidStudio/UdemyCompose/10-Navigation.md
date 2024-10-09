
## V149 and V15 Setting Up 

``` kt
class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContent {
            D10testTheme {
                Surface(modifier = Modifier.fillMaxSize())
                {
                    FirstScreen() // Composable
                }
            }
        }
    }
}
```
- FirstScene.kt
``` kt
@Composable
fun FirstScreen() {
    val name = remember {
        mutableStateOf("")
    }

    Column (modifier = Modifier
        .fillMaxSize()
        .padding(16.dp), verticalArrangement = Arrangement.Center, horizontalAlignment = Alignment.CenterHorizontally)
    {
        Text("This is the First Screen", fontSize = 24.sp)
        Spacer(modifier = Modifier.height(16.dp))
        OutlinedTextField(
            value = name.value, onValueChange = {name.value = it})
        Spacer(modifier = Modifier.height(16.dp))
        Button(onClick = { /*TODO*/ }) {
            Text(text = "Go to second screen")
        }
    }
}
```
- SecondScene.kt
``` kt
@Composable
fun SecondScreen() {
    val name = remember {
        mutableStateOf("")
    }

    Column (modifier = Modifier
        .fillMaxSize()
        .padding(16.dp), verticalArrangement = Arrangement.Center, horizontalAlignment = Alignment.CenterHorizontally)
    {
        Text("This is the Second Screen", fontSize = 24.sp)
        Spacer(modifier = Modifier.height(16.dp))
        Button(onClick = { /*TODO*/ }) {
            Text(text = "Go to second screen")
        }
    }
}
```
## V151 NavController
- Add this to the gradle file:

```
val nav_version = "2.8.0"
implementation("androidx.navigation:navigation-compose:$nav_version")
```

- Creating navigating 
``` kt 
//MainActivity.kt
@Composable
fun MyApp(){
    val navController = rememberNavController()
    NavHost(navController = navController, startDestination = "firstScreen"){
        //Creating route for composable FirstScreen
        composable ( "firstscreen" ){}
        //Creating route for composable SecondScreen
        composable ( "secondscreen" ){}
    }
}
```
- Add lambda parameter for both composables

``` kt 
//FirstScene.kt
@Composable
fun FirstScreen(navigatingToSecond:()-> Unit) {
// ...
        Button(onClick =
        {
            navigatingToSecondScreen() //Call to lambda
        }) {
            Text(text = "Go to second screen")
        }
}
```

``` kt 
//SecondScene.kt
@Composable
fun SecondScreen(navigatingToSecond:()-> Unit) {
// ...
        Button(onClick =
        {
            navigatingToFirstScreen() //Call to lambda
        }) {
            Text(text = "Go to first screen")
        }
}
```

- Add controls to navController
``` kt
@Composable
fun MyApp(){
    val navController = rememberNavController()
    NavHost(navController = navController, startDestination = "firstScreen"){
        composable ( "firstscreen" ){
            FirstScreen {
                navController.navigate(route = "secondscreen")
            }
        }
        composable ( "secondscreen" ){
            SecondScreen {
                navController.navigate(route = "firstscreen")
            }
        }
    }
}
```
## V152




``` kt 
//FirstScene.kt

```