
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
fun FirstScreen(modifier: Modifier = Modifier) {
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
fun SecondScreen(modifier: Modifier = Modifier) {
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
## V151

## V152
