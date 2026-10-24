
## V024 Criando componentes
- Nos projetos os componentes ficam na pasta `components` (nossa... serio?)
- São nomeados com camelcase: `ExemploDummy.js`
- No arquivo é criado uma função que contém o código deste componente.
- A função precisa **ser exportada** para ser reutilizada.

- Podemos editar o `App.jsx`
``` js
import './App.css'

function App() {

  return (
    <div className="app-container">
      <h1>Welcome to S2 Fundamentos</h1>
      <p>Este é um parágrafo de teste.</p>
    </div>
  )
}

export default App
```

Para criar componentes:
- Dentro de `src` criar nova pasta `components`
- Criar novo arquivo `NewComponent.jsx`

``` js 
const FirstComponent = () => {
    // Aqui podemos adicionar lógica do componente, se necessário
  return (
    <div>
      <h2>Primeiro Componente</h2>
    </div>
  )
}

// Exportamos o componente para ser utilizado em outros arquivos
export default FirstComponent
```

## V025 Importando components
- Para reutilizar um componente importamos ele.
- Sintaxis: `import X from './<path-to-file>'`
- Para colocar o componente utilizamos: `<FirstComponent/>`

``` js
import FirstComponent from "./components/NewComponent"
import './App.css'

function App() {

  return (
    <div className="app-container">
      <h1>Welcome to S2 Fundamentos</h1>
      <p>Este é um parágrafo de teste.</p>
      <FirstComponent />
    </div>
  )
}

export default App
```
## V026 Conhecendo o JSX
- JSX é o HTML do React
  - Tem uma diferença: `class` agora é `className`
- Tudo o que estiver dentro do `return( here )` é JSX
- Pode ter apenas um elemento pai.
- Sempre tem que estar dentro de um `<div></div>`
## V027

## V028

## V029

## V030

## V031

## V032



