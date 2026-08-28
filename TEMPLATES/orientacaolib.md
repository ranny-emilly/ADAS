# Caderno Tático de Consulta Rápida — ICPC

---

## 1. Template Base e Macros

### 1.1 Fast I/O e Macros Padrão
* **O que faz:** Destrava os buffers de entrada/saída do C++ (`sync_with_stdio(0); cin.tie(0)`) e define atalhos para tipos e constantes (`ll`, `INF`, `pb`).
* **Uso:** **Copy-Paste** obrigatório no topo de todo código da prova.
* **Gatilho:** Evitar TLE em problemas com leitura massiva ($N \ge 10^5$).

### 1.2 Variáveis Globais
* **O que faz:** Estruturas de grafos (`vec[MAX]`, `vis[MAX]`, `dist_vert[MAX]`, `pai[MAX]`) declaradas fora da `main`.
* **Uso:** **Copy-Paste** no escopo global.
* **O que alterar:** Ajustar o valor de `MAX` conforme o limite de vértices/elementos do problema.
* **Gatilho:** Qualquer problema de Grafos ou DP para evitar *Stack Overflow*.

---

## 2. Funções, Recursão e Lambdas

### 2.1 Passagem por Referência (`&`)
* **O que faz:** Passa o endereço de memória para evitar a cópia $\mathcal{O}(N)$ de contêineres pesados.
* **Uso:** **Regra de Escrita**. Sempre usar `const vector<int> &v` ou `string &s` nas assinaturas de funções.
* **Gatilho:** "Função auxiliar dando TLE".

### 2.2 Recursão Simples (Fatorial / Fibonacci)
* **O que faz:** Fatorial ($\mathcal{O}(N)$) e Fibonacci ingênuo ($\mathcal{O}(2^N)$).
* **Uso:** **Adaptar**. Fibonacci só serve para $N \le 30$; para $N$ maior, usar DP.
* **Gatilho:** Testes de força bruta pequenos ou base de transições.

### 2.3 Sobrecarga e Argumentos Padrão
* **O que faz:** Cria funções com valores default à direita.
* **Uso:** **Referência sintática**.

### 2.4 Lambdas e DFS Inline
* **O que faz:** Declara funções anônimas para `sort`, `find_if` ou DFS recursiva inline com `[&]` e `auto self`.
* **Uso:** **Copy-Paste / Adaptar**.
* **O que alterar:** O corpo da função lambda dentro da `main`.
* **Gatilho:** Ordenar structs com múltiplos critérios ou DFS rápida sem criar função global.

---

## 3. Strings e Matrizes

### 3.1 Manipulação de Strings
* **O que faz:** Leitura de linha com `getline(cin, frase)`, fatiamento com `s.substr()`, busca com `s.find()`, conversões (`stoi`, `stoll`, `to_string`) e transformações com `toupper`/`tolower`.
* **Uso:** **Trechos de uso direto**.
* **O que alterar:** Índices e comprimentos no `substr(pos, tam)`.
* **Gatilho:** "Extrair partes de datas/placas", "buscar se uma substring proibida existe".

### 3.2 Matrizes (2D / 3D) e 3.3 Referências em Loops
* **O que faz:** Declaração de grids estáticos globais ou matrizes dinâmicas `vector<vector<int>>`.
* **Uso:** **Trecho direto**. Sempre iterar com `for (auto &linha : mat)`.
* **Gatilho:** Problemas em labirintos, mapas ou tabelas de DP.

### 3.4 Frequência de Caracteres
* **O que faz:** Mapeia caracteres em vetores de inteiros (`c - 'a'` para minúsculas ou `(int)c` para ASCII).
* **Uso:** **Copy-Paste**.
* **Gatilho:** "Contar ocorrências de letras", "identificar se há caracteres repetidos".

### 3.5 String Ordenada (Anagramas)
* **O que faz:** Ordena duas strings com `sort()` e compara se `a == b`.
* **Uso:** **Copy-Paste direto**.
* **Gatilho:** "Verificar se duas palavras são anagramas".

### 3.6 Merge de Dois Vetores Ordenados
* **O que faz:** Intercala duas sequências previamente ordenadas em um terceiro vetor em tempo $\mathcal{O}(N + M)$.
* **Uso:** **Copy-Paste**.
* **Gatilho:** "Unir duas listas de eventos ordenadas sem rodar um novo sort pesado".

### 3.7 Palíndromo
* **O que faz:** Validação com dois ponteiros (`l` e `r`) ou via comparação com `reverse()`.
* **Uso:** **Copy-Paste direto**.
* **Gatilho:** "Checar se uma palavra é igual de frente para trás".

---

## 4, 5, 6 e 7. Containers e Iteradores da STL

### 5.1 Vector
* **O que faz:** Inserção no fim (`push_back`), remoção (`pop_back`), ordenação crescente (`sort(begin, end)`) e decrescente (`sort(rbegin, rend)`).
* **Uso:** **Estrutura base da maratona**.

### 5.2 Next Permutation
* **O que faz:** Gera todas as permutações em ordem lexicográfica.
* **Uso:** **Copy-Paste**.
* **O que alterar:** Vetor **obrigatoriamente ordenado** antes do laço `do-while`.
* **Gatilho:** "Testar todas as ordens possíveis de visita para $N \le 10$".

### 5.3 Set e 5.4 Map
* **O que faz:** `set` mantém elementos únicos e ordenados; `map` armazena pares chave-valor.
* **Uso:** **Trechos diretos**.
* **Gatilho:** "Manter conjunto dinâmico ordenado", "contar frequência de strings/valores esparsos".

### 6.1 Stack e 6.2 Queue
* **O que faz:** Pilha (LIFO: `push`, `pop`, `top`) e Fila (FIFO: `push`, `pop`, `front`).
* **Uso:** **Trecho direto**.
* **Gatilho:** `stack` para "parênteses balanceados", `queue` para "processamento em camadas / BFS".

### 7.4 Aritmética de Iteradores
* **O que faz:** `advance(it, k)` para avançar posições em `set`/`map`; `distance(it1, it2)` para calcular o deslocamento.
* **Uso:** **Referência de sintaxe**.

---

## 8. Algoritmos Clássicos e Busca Binária

### 8.1 Busca Binária Manual
* **O que faz:** Procura o índice de um valor exato em vetor ordenado via ponteiros `inicio`, `fim` e `meio`.
* **Uso:** **Copy-Paste**.
* **Gatilho:** "Descobrir se e em qual posição um número está em lista ordenada".

### 8.2 Greedy: Emparelhamento de Extremos
* **O que faz:** Ordena o vetor e pareia o menor elemento com o maior (`tasks[i] + tasks[2n - 1 - i]`).
* **Uso:** **Copy-Paste / Adaptar**.
* **O que alterar:** Adaptar a leitura para $2N$ valores e escolher se a resposta é `maxSum` ou `minSum`.
* **Gatilho:** "Distribuir $2N$ tarefas entre $N$ pessoas minimizando a carga máxima".

### 8.3 Utilitários da STL e 8.4 Upper Bound
* **O que faz:** `lower_bound` ($\ge X$), `upper_bound` ($> X$), `max({a,b,c})`, `reverse()` e `swap()`.
* **Uso:** **Trechos diretos**.
* **Gatilho:** "Quantos produtos da loja custam até $M$ reais?" $\rightarrow$ `upper_bound(...) - begin()`.

### 8.5.1 Binary Search on Answer: Minimizar o Máximo
* **O que faz:** Busca binária para achar o menor teto viável ao dividir um vetor em no máximo $K$ grupos contíguos.
* **Uso:** **Copy-Paste**.
* **O que alterar:** A condição dentro da função `pode()` caso as regras de particionamento mudem.
* **Gatilho:** "Dividir $N$ livros entre $K$ alunos minimizando a página do aluno mais sobrecarregado".

### 8.5.2 Binary Search on Answer: Maximizar o Mínimo
* **O que faz:** Posiciona $K$ itens garantindo a maior distância mínima entre quaisquer dois itens consecutivos.
* **Uso:** **Copy-Paste**.
* **O que alterar:** Condição da função `pode()` de acordo com as coordenadas do problema.
* **Gatilho:** "Alocar $K$ vacas em $N$ estábulos maximizando a distância entre elas".

### 8.6 Two Pointers: Pares
* **O que faz:** Conta pares em vetor ordenado com soma menor que $X$ somando blocos `ans += r - l`.
* **Uso:** **Copy-Paste**.
* **O que alterar:** Trocar a condição `< x` se pedir `\le x` ou pares com diferença fixa.
* **Gatilho:** "Quantos pares de itens têm peso combinado menor que o limite da mochila?".

### 8.7 Greedy: Interval Scheduling
* **O que faz:** Escolhe a maior quantidade de intervalos sem conflito ordenando pelo **menor fim**.
* **Uso:** **Copy-Paste direto**.
* **O que alterar:** Se os intervalos forem inclusivos/exclusivos, trocar `>= ultimo_fim` por `> ultimo_fim`.
* **Gatilho:** "Número máximo de filmes/palestras que uma pessoa consegue assistir inteiras".

### 8.8 Greedy: Problema do Troco
* **O que faz:** Pega o máximo da maior moeda com divisão inteira e resto.
* **Uso:** **Adaptar**. Usar apenas para moedas padrão (1, 5, 10, 25, 50, 100); para sistemas arbitrários, usar DP de Troco.
* **Gatilho:** "Dar troco com a menor quantidade de cédulas em moeda corrente".

---

## 9. Algoritmos da STL e Estruturas Lineares

### 9.1 Buscas e Contagem
* **O que faz:** `count()`, `count_if()`, `find()` e `is_permutation()`.
* **Uso:** **Trechos diretos**.
* **Gatilho:** "Contar quantos números são pares na lista", "testar se um vetor é anagrama do outro".

### 9.2 Ordenação e K-ésimo Elemento
* **O que faz:** `nth_element(arr.begin(), arr.begin() + k, arr.end())`.
* **Uso:** **Trecho direto**.
* **Gatilho:** "Encontrar a mediana de um vetor desordenado em tempo $\mathcal{O}(N)$".

### 9.3 Manipulação e 9.4 Numéricos
* **O que faz:** `unique()` para remover duplicatas de vetor ordenado; `accumulate(..., 0LL)` para somas long long; `iota()` para preencher com sequenciais.
* **Uso:** **Trechos diretos**.
* **Gatilho:** "Limpar repetidos após sort", "inicializar array de pais para DSU".

### 9.5 Monotonic Stack
* **O que faz:** Encontra o primeiro elemento maior ou menor à direita/esquerda em $\mathcal{O}(N)$.
* **Uso:** **Copy-Paste**.
* **O que alterar:** Mudar a comparação `st.top() < a[i]` para `>` se procurar o menor elemento.
* **Gatilho:** "Primeiro dia mais quente no futuro", "maior retângulo sob histograma".

### 9.6 Compressão de Coordenadas
* **O que faz:** Mapeia valores esparsos (até $10^9$) para índices contínuos de $0$ a $K-1$ com `sort`, `unique` e `lower_bound`.
* **Uso:** **Copy-Paste direto**.
* **Gatilho:** "Posições com valores até $10^9$ que precisam servir de índice em SegTree ou BIT".

---

## 10. Técnicas de Arrays

### 10.1 Soma de Prefixos (Prefix Sum)
* **O que faz:** Pré-processa a soma acumulada para responder queries de soma em intervalo $[L, R]$ em $\mathcal{O}(1)$ via `pre[R] - pre[L-1]`.
* **Uso:** **Copy-Paste**. Usar array 1-indexado.
* **Gatilho:** "Várias consultas de soma de elementos entre índices $L$ e $R$".

### 10.2 Array de Diferenças (Difference Array)
* **O que faz:** Aplica somas em faixas $[L, R]$ em $\mathcal{O}(1)$ (`diff[l] += x; diff[r+1] -= x`) e reconstrói o array no final em $\mathcal{O}(N)$.
* **Uso:** **Copy-Paste**.
* **Gatilho:** "Aplicar $Q$ operações de adicionar $X$ no intervalo de índices $[L, R]$ antes de imprimir o vetor final".

### 10.3 Partição com Menor Diferença Absoluta
* **O que faz:** Acha o corte que divide o vetor em dois pedaços com somas mais próximas possíveis.
* **Uso:** **Copy-Paste**.
* **Gatilho:** "Dividir uma lista de pesos em dois pacotes com a menor diferença de peso entre eles".

### 10.4 Two Pointers e 10.5 Sliding Window
* **O que faz:** Janela deslizante para soma mínima de tamanho fixo $K$ e dois ponteiros para janela variável.
* **Uso:** **Copy-Paste / Adaptar**.
* **Gatilho:** "Menor consumo de energia em $K$ dias consecutivos".

---

## 11. Manipulação de Bits

### 11.1 Built-ins e Operações Bitwise
* **O que faz:** Ligar bit (`x |= (1<<i)`), desligar bit (`x &= ~(1<<i)`), alternar (`x ^= (1<<i)`) e contar bits ativos com `__builtin_popcount(x)`.
* **Uso:** **Trechos diretos**.
* **Gatilho:** "Verificar se o $i$-ésimo recurso está ativado", "representar subconjuntos de até 30 elementos".

### 11.2 Comparação de Bits (Diferenças com XOR)
* **O que faz:** `__builtin_popcount(a ^ b)` calcula a distância de Hamming (quantos bits diferem entre dois números).
* **Uso:** **Copy-Paste**.
* **Gatilho:** "Contar quantos amigos têm no máximo $K$ preferências diferentes de perfil".

---

## 12 e 14. Grafos: Busca em Profundidade (DFS)

### 12.1 e 14.8 Contar Componentes Conexos
* **O que faz:** Percorre todos os vértices não visitados disparando a DFS e incrementando o contador.
* **Uso:** **Copy-Paste**.
* **Gatilho:** "Contar quantas redes isoladas ou ilhas existem no mapa".

### 12.2 Conectar o Grafo Inteiro (Building Roads)
* **O que faz:** Salva o primeiro vértice de cada componente conexo e imprime as pontes necessárias entre `rep[i]` e `rep[i+1]`.
* **Uso:** **Copy-Paste direto**.
* **Gatilho:** "Menor quantidade de estradas a construir para interligar todas as cidades e quais estradas fazer".

### 14.9 Tamanho de Componente e 14.10 Existe Caminho
* **O que faz:** DFS com retorno de contagem de vértices e checagem de alcançabilidade (`vis[t]`).
* **Uso:** **Copy-Paste**.
* **Gatilho:** "Qual o tamanho da maior mancha/grupo conexo?", "É possível sair de $S$ e chegar em $T$?".

### 14.12 e 14.13 Detecção de Ciclos
* **O que faz:** Detecção de ciclo em grafo não-direcionado (usando o `pai`) e direcionado (usando 3 estados: 0=não visitado, 1=na pilha de recursão, 2=finalizado).
* **Uso:** **Copy-Paste**.
* **Gatilho:** "Verificar se há dependência circular de tarefas".

---

## 13 e 15. Grafos: Busca em Largura (BFS) e Caminhos Mínimos

### 13.1, 15.4 e 15.5 BFS: Distância Mínima e Reconstrução de Caminho
* **O que faz:** Menor caminho em grafos sem pesos (custo uniforme 1) e reconstrução da rota via array `pai` e `reverse()`.
* **Uso:** **Copy-Paste**.
* **O que alterar:** Vértice de origem e destino na chamada.
* **Gatilho:** "Menor número de conexões/voos para ir de uma cidade a outra".

### 13.2 e 15.10 Travessia em Grid 2D (Labirinto com BFS)
* **O que faz:** BFS em matriz usando vetores de direção `dx[] = {-1,1,0,0}` e `dy[] = {0,0,-1,1}` com validação de limites e obstáculos `'#'`.
* **Uso:** **Copy-Paste**.
* **O que alterar:** Caractere de parede na função `valida` e se o grid suporta 4 ou 8 direções.
* **Gatilho:** "Menor número de passos para sair de um labirinto do ponto $S$ ao $E$".

### 15.6 Multi-Source BFS
* **O que faz:** Coloca múltiplas fontes na fila com distância 0 antes do laço da BFS.
* **Uso:** **Copy-Paste**.
* **Gatilho:** "Tempo mínimo para um incêndio/vírus alcançar cada célula do mapa a partir de vários focos iniciais".

### 15.1 Dijkstra com Priority Queue
* **O que faz:** Menor caminho em grafos ponderados com pesos não-negativos usando Min-Heap via sinal negativo.
* **Uso:** **Copy-Paste**.
* **O que alterar:** Se o grafo for não-direcionado, adicionar a aresta nos dois sentidos.
* **Gatilho:** "Menor custo de pedágio/combustível para ir da cidade 1 até todas as outras".

### 15.11 Prim (Árvore Geradora Mínima)
* **O que faz:** Conecta todos os $N$ vértices com o menor peso total acumulado de arestas.
* **Uso:** **Copy-Paste**.
* **Gatilho:** "Construir uma rede elétrica que ligue todas as cidades com o menor custo possível de cabos".

### 15.12 Bellman-Ford
* **O que faz:** Caminho mínimo a partir de uma fonte suportando arestas de peso negativo e detectando ciclos negativos.
* **Uso:** **Copy-Paste**.
* **Gatilho:** "Menor caminho com possibilidade de pesos negativos ou identificar se há ganho infinito (arbitragem)".

---

## 14 e 16. Matemática, Teoria dos Números e Combinatória

### 14.2 a 14.4 Contagem em Intervalos $[L, R]$
* **O que faz:**
  * Total de inteiros: $R - L + 1$
  * Total de pares: $R/2 - (L-1)/2$
  * Total de ímpares: $(R+1)/2 - L/2$
  * Múltiplos de $K$: $R/K - (L-1)/K$
* **Uso:** **Fórmulas diretas em $\mathcal{O}(1)$**.

### 15.21 e 16.1 MDC, MMC e Euclides
* **O que faz:** Máximo divisor comum e mínimo múltiplo comum.
* **Uso:** Em C++17 usar direto `std::gcd(a, b)` e `std::lcm(a, b)`.

### 15.22, 15.23 e 16.2 Primos e Crivo de Eratóstenes
* **O que faz:** `primo(n)` testa primalidade em $\mathcal{O}(\sqrt{N})$; `crivo(n)` pré-computa todos os primos até $10^6$.
* **Uso:** **Copy-Paste**.
* **Gatilho:** "Descobrir se $N$ é primo" ou "responder milhares de consultas sobre números primos até $10^6$".

### 15.24 e 16.3 Fatoração em Primos
* **O que faz:** Decompõe $N$ em pares `(primo, expoente)` em tempo $\mathcal{O}(\sqrt{N})$.
* **Uso:** **Copy-Paste**.
* **Gatilho:** "Quantidade de divisores de $N$", "fatorar um número em fatores primos".

### 15.25 e 16.4 Exponenciação Rápida e Combinação Modular
* **O que faz:** Calcula $A^B \pmod M$ em $\mathcal{O}(\log B)$ e combinações $C(n, k) \pmod{MOD}$ usando Inverso Modular de Fermat.
* **Uso:** **Copy-Paste**.
* **O que alterar:** Ajustar a constante `MOD` (geralmente `1e9+7` ou `998244353`).
* **Gatilho:** "Calcular $\binom{N}{K} \pmod{10^9+7}$ para $N \le 10^6$".

### 15.27 Triângulo de Pascal
* **O que faz:** Preenche matriz de combinações $C[i][j]$ em $\mathcal{O}(N^2)$ sem divisão modular.
* **Uso:** **Copy-Paste**.
* **Gatilho:** "Combinatória para $N \le 2000$ sem módulo primo".

---

## 17. Estruturas de Dados Avançadas

### 17.1 Segment Tree (Point Update & Range Query)
* **O que faz:** Consulta de intervalos (soma, min, max) e atualização de um ponto único em $\mathcal{O}(\log N)$.
* **Uso:** **Copy-Paste**.
* **O que alterar:**
  * Tamanho: `MAXS` precisa cobrir os elementos; `tree` precisa ser `4 * MAXS`;
  * Operação: Linhas 14, 29 e 40 para trocar soma (`+`) por `min()` ou `max()`;
  * Elemento neutro da query: `0` para soma, `INF` para mínimo, `-INF` para máximo.
* **Gatilho:** "Array dinâmico com operações intercaladas de 'alterar valor na posição $X$' e 'somar elementos de $L$ a $R$'".

### 17.2 Disjoint Set Union (DSU / Union-Find)
* **O que faz:** Mantém conjuntos disjuntos com `find_dsu` (com compressão de caminho) e `unite_dsu` (por tamanho).
* **Uso:** **Copy-Paste**.
* **O que alterar:** Chamar `build_dsu(n)` na `main` antes de processar as queries.
* **Gatilho:** "Verificar se dois nós pertencem ao mesmo grupo após várias uniões dinâmicas".

---

## 18. Grafos Avançados

### 18.1 Kruskal (Árvore Geradora Mínima com DSU)
* **O que faz:** Ordena as arestas por peso e usa DSU para conectar a malha sem gerar ciclos em $\mathcal{O}(E \log E)$.
* **Uso:** **Copy-Paste** (exige o código do DSU da seção 17.2).
* **Gatilho:** "Menor custo para interligar todos os pontos quando a entrada é dada diretamente como lista de arestas".

### 18.2 Ordenação Topológica (Kahn's Algorithm)
* **O que faz:** Encontra a ordem de resolução de tarefas em DAGs usando graus de entrada (`grau_entrada`) e `priority_queue` para desempate lexicográfico.
* **Uso:** **Copy-Paste**.
* **Gatilho:** "Determinar a ordem de matérias a cursar respeitando os pré-requisitos".

### 18.3 Menor Ancestral Comum (LCA com Binary Lifting)
* **O que faz:** Responde qual o ancestral comum mais próximo de dois nós em árvore em $\mathcal{O}(\log N)$ por query.
* **Uso:** **Copy-Paste**.
* **O que alterar:** Chamar `dfs_lca(raiz, -1, 0)` antes de responder as consultas `lca(u, v)`.
* **Gatilho:** "Achar a menor distância entre dois nós em uma árvore fixa com muitas consultas".

### 18.4 Fluxo Máximo (Dinic)
* **O que faz:** Calcula o fluxo máximo entre fonte $S$ e sorvedouro $T$ em tempo $\mathcal{O}(V^2 E)$ (ou $\mathcal{O}(E\sqrt{V})$ em grafos bipartidos).
* **Uso:** **Copy-Paste**.
* **O que alterar:** Montar as capacidades chamando `add_edge(origem, destino, capacidade)`.
* **Gatilho:** "Emparelhamento Bipartido Máximo", "capacidade máxima de transporte de água/tráfego entre dois pontos".

---

## 19. Strings Avançadas

### 19.1 Stringstream
* **O que faz:** Quebra uma frase inteira lida em palavras individuais.
* **Uso:** **Trecho direto** (`stringstream ss(linha); while (ss >> palavra) ...`).
* **Gatilho:** "Linha com quantidade desconhecida de palavras/números separados por espaços".

### 19.2 String Hashing (Polynomial Rolling Hash)
* **O que faz:** Converte substrings em valores numéricos para comparar igualdade em $\mathcal{O}(1)$.
* **Uso:** **Copy-Paste**.
* **Gatilho:** "Verificar se duas substrings de posições diferentes são idênticas sem gastar $\mathcal{O}(N)$".

### 19.3 KMP e 19.4 Função Z
* **O que faz:** KMP conta ocorrências de padrão $P$ no texto $T$ em $\mathcal{O}(N+M)$; Função Z acha o maior prefixo coincidente em cada posição em $\mathcal{O}(N)$.
* **Uso:** **Copy-Paste direto**.
* **Gatilho:** "Contar quantas vezes a palavra $P$ aparece dentro de um livro $T$".

### 19.5 Trie (Árvore de Prefixos)
* **O que faz:** Insere strings caractere a caractere e faz buscas rápidas por prefixos compartilhados.
* **Uso:** **Copy-Paste**.
* **O que alterar:** Ajustar o alfabeto se contiver maiúsculas ou números.
* **Gatilho:** "Dicionário com $N$ palavras: descubra se existe alguma palavra que comece com o prefixo $S$".

---

## 20, 21 e 22. Geometria, Teoria dos Jogos e Teste de Estresse

### 20.1 Geometria Computacional Básica
* **O que faz:** `Point` struct com soma, subtração, ordenação, Produto Vetorial (`cross`) para curvas e Área de Polígono (`polygon_area`) pela fórmula do cadarço.
* **Uso:** **Copy-Paste**.
* **Gatilho:** "Determinar se uma curva dobra para a esquerda/direita", "calcular a área exata de um terreno delimitado por pontos no plano".

### 20.2 Suffix Array
* **O que faz:** Cria o vetor $p$ com os índices de todos os sufixos da string ordenados alfabeticamente em $\mathcal{O}(N \log N)$.
* **Uso:** **Copy-Paste**.
* **Gatilho:** "Encontrar a menor rotação cíclica lexicográfica de uma string".

### 21.1 Teoria dos Jogos (Jogo de Nim)
* **O que faz:** Calcula o XOR de todos os tamanhos de pilhas (`xor_sum ^= a`).
* **Uso:** **Copy-Paste direto**.
* **Gatilho:** "Dois jogadores removem qualquer quantidade de pedras de uma pilha por turno. Quem vence com jogo ótimo?" (`xor_sum != 0` $\rightarrow$ Primeiro jogador vence).

### 22. Stress Test
* **O que faz:** Roda até 100.000 testes aleatórios comparando sua solução rápida `a.cpp` com a ingênua `brute.cpp` usando o gerador `gen.cpp` e o script `stress.sh`.
* **Uso:** **Template operacional**.
* **O que alterar:** As regras de geração no `gen.cpp` para respeitar o formato de entrada do problema.
* **Gatilho:** "Solução tomando Wrong Answer (WA) em caso oculto e você não consegue encontrar o erro".

