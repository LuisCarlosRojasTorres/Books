## V035 Imagenes publicas no React

- Ficam na pasta `public`
- Tag `img` e com o `/path.jpg`  

``` jsx
function App() {  
  return (
    <div>
      <h1>S3 More content!</h1>
      <img src="/totodile.png" alt="Placeholder" />
    </div>
  )
}

export default App
```

## V036 Imagens no src
- Pasta public pode ser utilizada para armazenar imagens.
- Mas um boa prática é armazenar na pasta `assets` dentro do `src`
  - Utilizando `assets` precisamos importar as imagens. O `src` é dinamico com o nome da importação.

``` jsx
import "./App.css"
import Hero from "./assets/Hero.png"
function App() {
  

  return (
    <div>
      <h1>S3 More content!</h1>
      {/* Local image from public folder */}
      <img src="/totodile.png" alt="Placeholder" />
      {/* Imported image from assets */}
      <img src={Hero} alt="Placeholder" />
    </div>
  )
}

export default App
```
## V037 Hooks
- São recursos do react para realizar diversas funções
  - Salvar e alterar estado de algum dado na applicação.
- Sintaxis: `useSomething` e.g. `useState`
- Podem ser feitos custom hook, ou seja implementados pela gente.
- precisam ser importados.
- Muito úteis

## V038 useState hook
- Dos mais utilizados
- Serve para gerenciar o estado de algum dato. (Se a variavel nao funciona corretamente, o componente nao é re-renderiza)
- Como utilizar?
  - Para guardar o dado definimos o nome da variável 
  - para alterar utilizamos `setName` 

``` jsx
import { useState } from "react";

const ManageData = () => {
    let someValue = 73;

    const [anotherValue, setAnotherValue] = useState(0);

  return (
    <div>
        <div>
            Manage Data Component
            <p>Value {someValue}</p>
            {/* Button to change the value of someValue */}
            {/* This will not actually update the displayed value because React does not track changes to regular variables. */}
            <button onClick={() => (someValue = 100)}> Change Value </button>      
        </div>
      
        <div>
            Manage Data Component
            <p>Value {anotherValue}</p>
            {/* Button to change the value of anotherValue */}
            {/* This will update the displayed value because React tracks changes to state variables. */}
            <button onClick={() => setAnotherValue(100)}>Change Value</button>
        </div>
    </div>
  );
};

export default ManageData;
```
- O primeiro botão nao faz nada. Nao atualiza o valor.
- O segundo sim.

## V039 Renderização de listas
- Renderizar listas de dados no template
- Utiliza dados do tipo array
- Muito util é o `map`
- Logicamente vai ter iteração para mostrar os dados.

### Index dummy

``` js
const ListRender = () => {
    const items = ["Item 1", "Item 2", "Item 3"];
  return (
    <div>
        <div>
            <h2>ListRender</h2>
            <ul>
                {items.map((item, index) => (
                <li key={index}>{item}</li>
                ))}
            </ul>
        </div>
    </div>
  )
}

export default ListRender
```
## V040
## V041
## V042
## V043
## V044
## V045
## V046
## V047
## V048
## V049
## V050



