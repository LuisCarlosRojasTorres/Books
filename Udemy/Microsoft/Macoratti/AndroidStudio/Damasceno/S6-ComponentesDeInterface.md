
## 55. Introdução às Constraints
- Permite, organizar a screen a partir de `molas`.

## 56. Configurações de constraints
- Para limpar todos os contraints de um widget: click direito , `clear all constraints on selection`

## 57. Alinhamento pela linha base
- Apara alinhar precisamos no minimo alinhar com os circulos na horizontal e na vertical
- Alinhar na linha base quer dizer na linha base do texto. 
  - Click direito no `widget` (com texto) e click em `Show baseline` click e drag to o baseline do outro elemento.

## 58. Atalhos para alinhamentos

## 59. Utilizando chain

## 60. Linhas guia
- É uma linha (vertical ou horizontal) auxiliar para linhar elementos, logicamente nao é visualizada ao executar o app.
  - Elas podem utilizar valores fixos ou porcentagens. Para mudar isso tem que dar click na bola cinça com o simbolo de seta.
- Para accessar: `Right-Click (on design)/Add Helpers/` ou `Palled menu/ Helpers tab`

## 61. Utilizando Barrier
- É uma tipo de linha guia que contraria a linha gui normal (que é fixa) esta se ajusta ao conteudo. 
- No `Component Tree` os elementos deben ser botados dentro do `Barrier`
- Os elementos externos a barrier podem fazer as referencias geometricas dele com os elementos contidos.
- Outra forma é nos `Attributes`  do widget seleccionar a barrier no combobox de `layout_constraintTop_toBottomOf` ou `layout_constraintEnd_toEndOf` ou `layout_constraintStart_toStartOf`.

## 62. Padding e Margin
- Padding (prenchimento): espaço entre a borda de uma caixa e o conteudo dela
- Margin : é o espaço externo entre elementos

## 63. Unidades de medida
- Pixel: maix pixels num mesmo espaço melhor a qualidade.
- DPI (dot per inch): 
- O problema desta media é que uma imagem de alto dpi se ajusta com a tela: numa tela com pouco dpi ficara gigante e numa de alto depi ficará pequena.
- Solução: Unidade de medida DP. Uma imagem de `50dp x 20dp` ocupará o mesmo espaço, porem a qualidade será alterada para ajustar a tela.
  -   `sp`: pra texto.
   

## 64. Entendendo XML

## 65. Orientação de tela
- É setado por Activity no `AndroidManifest`: `android:screenOrientation` tem varios tipos muito especificos  (ir pra documentação oficial)
``` xml
<activity
  android:name=".MainActivity"
  android:exported="true"
  android:screenOrientation="unspecified">
  
  <intent-filter>
    <action android:name="android.intent.action.MAIN" />
                
    <category android:name="android.intent.category.LAUNCHER" />
  </intent-filter>
</activity>
```
## 66. Pasta values
- `string.xml`: 
  - O melhor é definir aqui o conteudo que vai ser apresentado em botoes e textviews. Com isso 
## 67. Ícones - Vector Asset
- `Right Click on drawable / New / Vector Asset / ` a imagem vai ficar na pasta `drawable`
  - Para mudar o ícone no android manifest:
    - `android:icon="@mipmap/ic_launcher"` (default)
    - mudar para `android:icon="@drawable/nome_do_icon"`

## 68. Temas - parte 1
- Os `Themes` sao asignados no manifest: 
  - `android:theme="@style/Theme.Section6"`
- O tema da app se encontra `/res/values/themes` ele herda de `Theme.Material3.DayNight.NoActionBar`, caso nao se defina nada diferente todas os estilos são puxados do **`parent`**
- Para mudar a cor de um elemento a melhor prática é definar a cor no `colors.xml` 
## 69. Temas - parte 2
- Para ativar o night moode no emulador `Ajustes/Tela/NightMode`

## 70. ScrollView
- Permite incluir mais elementos do que entra na tela.

## 71. Caixa de texto (EditText)
- Ao clickar em `Palette/Text` aparecem diferentes `TextView` e.g. `Plain Text, Password.... Email` etc. A diferença entre elas é o teclado.
  - Nos atributos tem:
    - `hint`: texto traslucido para indicar o que escrever
    - `input type`: permite customizar o teclado de acordo ao tipo de input.
## 72. Caixas de texto (TextInputLayout)

## 73. Eventos de clique + classe R.java
Duas formas:
A primeira é simples, a segunda é caso se precise ter condições para a execução dos métodos.
1. Adicionar um botão
2. Crear método: Todo método que vai estar asociado ao click de um botao DEVE ter como parâmetro `View view` 
   ``` kt
   public void dummyMethod(View view)

   ```
3. Fazendo isso vai aparecer no combobox do `OnClick` do botão.

Utilizando eventos
## 74. Recuperando valores digitados

## 75. Criando interface da Netflix - parte 01

## 76. Criando interface da Netflix - parte 02

