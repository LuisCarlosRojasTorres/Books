
## Instalando Kotlin Compiler para Visual Code
1. Fazer download do compiler zipado no seguinte link: [Compiler](https://github.com/JetBrains/kotlin/releases/tag/v1.9.23)
2. Extrair ele (aparecerá como a pasta `kotlinc`) e deixar numa pasta tipo `C:\\AndroidDevelopment\kotlinc`
3. Adicionar a rota `C:\\AndroidDevelopment\kotlinc\bin` no path das variaveis de entorno.
4. Reiniciar

## Tipos de arquivos Kotlin
- `.kts` (kotlin script files): 
  - Mesma idea do que bash ou python, não necesita a função `main()`. É executada linha a linha;
  - Para rodar se utiliza: `kotlinc -script <filename>.kts` 