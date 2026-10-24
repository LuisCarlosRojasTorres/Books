
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
      <p>Test generico só pra utilizar o tag.</p>
    </div>
  )
}

export default App
```

Para criar componentes:
- Dentro de `src` criar nova pasta `components`
- Criar novo arquivo `NewComponent.js`

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

## V026

## V027

## V028

## V029

## V030

## V031

## V032



