# hash-for-names
trabalho final - estrutura de dados I - Ciências da computação

## relatório

### problema

Recebido uma base de dados de primeiros nomes, ler e inserir eles em uma tabela hash com tamanho de 53 com função hash a escolha do dev

### metodologia

Foi utilizado uma estrutura para representar a tabela hash
```C
typedef struct
{
    List *col[HASH_SIZE];
} HashTable;
```
sendo usado um vetor para representar as colunas pois como o tamanho já é previamente definido é mais vantajoso do que usar uma lista principalmente para para quaisquer operações que incluam a chave da coluna

e cada coluna sendo uma lista duplamente ligada, que logo depois de ser atribuido todas as colunas são inicializadas, desvantagem de que quando há muito pouco dado ou que por obséquio uma ou mais colunas não sejam utilizadas seria um desperdício de memória, porém são casos muito extremos e caso isso não fosse feito, a cada inserção se perderia uma verificação se a lista foi inicializada, então nesse caso onde há praticamente total certeza de que todas as colunas serão utilizadas compensa inicializar todas elas logo no começo

### inserção de dados

foi utilizado a base de nomes em um arquivo .txt nesse formato
```
JASMINE
JULIO
HUMBERTO
...
```

e o seguinte código para ler e inserir cada linha das 100.788

```C
while (fgets(line, MAX_STRING_SIZE, fptr))
{
    hashInsert(line, hTable);
}
```

cada linha lida já é inserida na tabela usando a função hash para definir qual posição

### função hash

função hash é utilizada para definir qual posição da tabela hash o dado vai ser alocado utilizando o próprio dado para decidir, por exemplo quando se quer armazenar ints pode se utilizar a seguinte função

> pos = dado % qtdPos

onde a posição é dada pelo resto da divisão do dado, nesse caso inteiro, pela quantidade de posições

para utilizar a função com caracteres a ideia pode ser a mesma só que cada caractere é transformado em seu número ASCII já pré definido em uma tabela, como por exemplo:

![tabela ASCII](https://www.johndcook.com/ascii.png)

e ai há outros dois métodos, o primeiro que é utilizando apenas o primeiro caractere, e o segundo somando todos os caracteres, mostrarei porque segui por outro caminho

#### primeiro caractere

seria basicamente utilizar um método onde a organização seria dada alfabeticamente assim cada posição seria uma letra do alfabeto, dessa forma a tabela não ficaria uniforme justamente porque existem mais nomes com algumas determinadas letras como por exemplo 'A' tem uma maior occorência que 'T' ou 'W' então a tabela ficaria irregular

#### soma dos caracteres

outro método seria somar todos os caracteres e dividir pela quantidade de posições, pegando o resto e usando ele como posição, isso eliminaria o problema com as iniciais tendo mais repetições, porém ainda há um problema que podemos explicar como anagramas, por exemplo os nomes "alan" e "lana" terão a soma igual, outros nomes ocorrem a mesma coisa, ocorrendo os conjuntos de letras ficariam na mesma posição

#### método escolhido

o método escolhido foi colocar um hash padrão como 7, depois a cada soma multiplicar ele por 31, ambos números primos, facilitam que os hashs sejam mais "únicos". Código utilizado a seguir:


```C
int hash = 7;
int size = strlen(data) - 1;
for (int i = 0; i < size; i++) {
    hash = hash*31 + data[i];
}
if (hash < 0) {
    hash *= -1;
}
hash = hash % HASH_SIZE;
return hash;
```

### tratamento de colisão

para quando hajam dois nomes que fiquem na mesma chave, por se tratar de listas então ocorre a inserção na lista utilizando como pivô o último elemento, então todos serão inseridos no final como se fosse uma fila, assim todos os nomes podem ser inseridos independente se já houver nomes nesta chave, assim o limite sendo só a própria memória RAM do sistema

### ordenação

foi requisitado que a ordenação de cada chave ocorresse pelo algoritmo de quick sort ou equivalente, foi escolhido o quick, e para tal foi adaptado o algoritmo de Hoare que consiste em um quick sort porém o pivo é sempre o elemento no meio ou em casos de pares, o próximo, de cada partição e os organizando alfabeticamente. Tudo o que foi feito foi adaptar o funcionamento de vetores para listas

## resultados finais

### a tabela hash foi distribuida de forma uniforme?

após executar o programa e inserir todos os nomes transcrevi os dados para uma planilha do google onde a média é o ideal a ser atingido, ou ao menos chegar o mais próximo, ela é calculada somando todos os nomes e dividindo pelo número de chaves, nesse caso 53. 

![gráfico dos resultados finais](https://i.imgur.com/VPHR3Up.png)

cada coluna representa cada chave e sua respectiva quantidade de nomes armazenada nela, percebe-se que elas se aproximam da linha da média, o importante é que ela se aproxime da linha independente de ser por cima ou baixo. Assim os resultados são satisfatórios