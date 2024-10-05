## V087 State Recomposition
- `Remember function`:
  - It is Used to create a persistent and rememebered state in JC (jetpack compose)
  - It Allows a composable to maintain its state accross recompositions, even when the composable is recreated (screen is refreshed) ehich happens a lot every single second.
    - recomposition: process of reenerating and updating the UI to reflect changes in the application state or user interactions.
- `mutable state property delegate`:
  - It is used to create a mutable state that can be updated
  - It is used in conjunction with remember funtion to manage changing data.

## V088 Dummy example

``` kt
@Composable
fun DummyExample()
{
    val yourGuess = remember {mutableStateOf(0) }
    val result = remember { mutableStateOf(0)}
    val output = remember{mutableStateOf("None")}
    Column {
        Text(text = "Your Guess:  ${yourGuess.value}")
        Text(text = "Results:  ${result.value}")
        Text(text = "Output:  ${output.value}")

        Button(onClick = { /*TODO*/
            yourGuess.value = Random.nextInt(1,10)
            result.value = Random.nextInt(1,10)

            if(yourGuess.value == result.value){
                output .value = "WIN"
            }
            else{
                output .value = "LOOSE"
            }
        }) {
            Text(text = "Click for take a chance")
        }
    }

}

@Preview(showBackground = true)
@Composable
fun DummyExamplePreview() {
    DummyExample()
}
```

![alt text](V088a.png)