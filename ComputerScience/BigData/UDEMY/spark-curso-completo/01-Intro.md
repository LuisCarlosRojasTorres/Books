




## O que eh

- Ferramenta de **Processamento de Dados**
- Distribuido em um Cluster
  - Rede de Computadores que opera sobre o mesmo objetivo.
  - Dividem o processamento.
    - Se SPARK tem um processamento longo ela divide entre todos os **nos** computadores disponiveis.
- Em memoria (muito rapido)
- Escalavel
- Dados em HDFS (Hadoop Distributed File System i.e. sistema de arquivos distribuido) ou Cloud.
- Suporte a particionamento
  - Cada **no** pode pegar uma parte dos dados, e processar em paralello com outros **nos**
    - Essas partes dos dados sao **replicadas** para ter tolerancia a falhas.
- Replicacao e tolerancia a falhas.
  - Dados sao copiados entre os nos do cluster.
  - Mesmo em cluster um **no** vai ter problema, se tiver so uma copia dos dados o processamento fica comprometido.
    - Se tem replicacao, nao acontece nada pq tem backup.

## Arquitetura e Componentes do SPARK
- Spark SQL
  - Le dados tabulares
  - Pode utilizar SQL
- Spark Streaming
  - Dados struturados
  - Quase em tempo real
- Tungsten (motor de execucao do spark)  
- Machine Learning
  
### Transformacoes e Acoes
- DataFrame: Principal elemento de dados do spark
  - Eh imutavel
  - Ao ser transformados, um novo DataFrame eh criado.
- A transformacao so eh feita cuando uma ACAO eh feita. (Lazy Evaluation)
- Tem dois tipos de transformacao
  - NARROW: dados estao na mesma particao
  - WIDE: dados estaio em mais de uma particao

### Como os dados sao processados
- Os dados estao particionados em **nos**
- Job: Tarefa
- Stage: Divisao do Job
- Task: Menor unidade de trabalho. 
  - Uma por nucleo e por particao.

## SparkContext and SparkSession
- SparkContext:
  - Conexao transparente com o Cluster
- SparkSession:
  - Da accesso ao SparkContext

## Formatos de Big Data
- Descoplados da ferramenta
- Binarios e compactados
- Suportam Schema
  - A metadata esta no proprio dado.
- Podem ser particionados entre discos
  - Redundancia
  - Paralelismo
- Formatos: (os modelos coluna sao melhores para escrita, os linha em leitura).
  - Parquet: Colunar (o default to SPARK)
  - ORC: Colunar
  - Avro: Linha
