# Manual de Sobrevivência MFP

**Guia de referência C++17 para competições, denso em informação e pronto para impressão.**

---

## Índice

1. [Template Base](#1-template-base)
2. [Strings e Caracteres](#2-strings-e-caracteres)
   1. [Somente Maiúsculas/Minúsculas](#21-somente-maiúsculasminúsculas)
   2. [Palíndromos](#22-palíndromos)
   3. [Interpolação/Mistura](#23-interpolaçãomistura)
3. [Mapas e Frequência](#3-mapas-e-frequência)
   1. [Identificar o Diferente](#31-identificar-o-diferente)
   2. [Contagem de Pares](#32-contagem-de-pares)
4. [Grafos](#4-grafos)
   1. [BFS em Grid](#41-bfs-em-grid)
   2. [DFS e Componentes](#42-dfs-e-componentes)
   3. [Ciclos e Árvores](#43-ciclos-e-árvores)
5. [Busca Binária na Resposta](#5-busca-binária-na-resposta)
6. [Bitset e Otimização](#6-bitset-e-otimização)
7. [Matemática e Geometria](#7-matemática-e-geometria)
   1. [Área de Quadrado](#71-área-de-quadrado)
   2. [Exponenciação e GCD](#72-exponenciação-e-gcd)
8. [STL Avançado](#8-stl-avançado)
9. [Grafos Avançados](#9-grafos-avançados)
   1. [Dijkstra](#91-dijkstra)
   2. [DSU - Union-Find](#92-dsu---union-find)
   3. [Kruskal - MST](#93-kruskal---mst)
10. [Programação Dinâmica](#10-programação-dinâmica)
    1. [Fibonacci com Memoização](#101-fibonacci-com-memoização)
    2. [Knapsack 0/1](#102-knapsack-01)
    3. [LIS - Longest Increasing Subsequence](#103-lis---longest-increasing-subsequence)
11. [Recursividade e Algoritmos Clássicos](#11-recursividade-e-algoritmos-clássicos)
    1. [Torre de Hanoi](#111-torre-de-hanoi)
    2. [Princípios de Recursão](#112-princípios-de-recursão)
12. [Verificação de Números Especiais](#12-verificação-de-números-especiais)
    1. [Verificar se é Primo](#121-verificar-se-é-primo)
    2. [Raiz Quadrada Exata](#122-raiz-quadrada-exata)
13. [String Hashing](#13-string-hashing)
14. [Debug e Macros](#14-debug-e-macros)

---

## 1. Template Base

### Padrão de Enunciado
Resolver múltiplos casos de teste com leitura eficiente e usar tipos rápidos para longas somas.

### Descrição Técnica
O template base usa `FASTIO` para leitura/escrita rápida, `ll` para `long long`, macros de iteração e variável `t` para casos de teste. O padrão `t = 1; cin >> t;` garante que o código funcione com ou sem múltiplos casos.

### Código Comentado
```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define pb push_back
#define fi first
#define se second
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i >= (b); i--)

#define FASTIO ios::sync_with_stdio(false); cin.tie(nullptr)

const ll INF = 9e18;

void solve() {
    // Resolver um caso de teste aqui
}

int main() {
    FASTIO;            // Rápido I/O
    int t = 1;
    cin >> t;          // Ler número de casos de teste
    while(t--) {
        solve();
    }
    return 0;
}
```

**Erro Comum:** esquecer `FASTIO` ou `cin.tie(nullptr)` pode tornar o programa lento; `int t = 1; cin >> t;` permite lidar com um único caso ou muitos casos sem alterar a lógica.

---

## 2. Strings e Caracteres

### 2.1 Somente Maiúsculas/Minúsculas

#### Padrão de Enunciado
Dado um texto, normalizar caracteres e usar índices 0-25 para letras.

#### Descrição Técnica
Usar `toupper` e `tolower` para converter e o truque `s[i] - 'a'` para mapear `'a'` a `0`, `'z'` a `25`.

#### Código Comentado
```cpp
string s;
cin >> s;
for(char &c : s) {
    if(isupper(c)) {
        c = tolower(c); // converte para minúscula
    } else {
        c = toupper(c); // converte para maiúscula
    }
}

vector<int> freq(26, 0);
for(char c : s) {
    if('a' <= c && c <= 'z') {
        freq[c - 'a']++; // índice de 0 a 25
    }
}

for(int i = 0; i < 26; i++) {
    if(freq[i] > 0) {
        cout << char('a' + i) << ": " << freq[i] << "\n";
    }
}
```

**Erro Comum:** usar `s[i] - 'A'` em vez de `s[i] - 'a'` sem verificar maiúsculas/minúsculas causa índices errados.

---

### 2.2 Palíndromos

#### Padrão de Enunciado
Determinar se uma string pode ser rearranjada formando um palíndromo.

#### Descrição Técnica
Contar frequências e verificar quantas letras têm contagem ímpar. Pode ser palíndromo se no máximo uma letra tiver contagem ímpar.

#### Código Comentado
```cpp
string s;
cin >> s;
vector<int> freq(26, 0);
for(char c : s) {
    if(isalpha(c)) {
        freq[tolower(c) - 'a']++;
    }
}

int odd = 0;
for(int x : freq) {
    if(x % 2 != 0) odd++;
}

if(odd <= 1) {
    cout << "SIM\n";
} else {
    cout << "NAO\n";
}
```

**Erro Comum:** não resetar o vetor de frequência entre casos de teste leva a resultados errados em `t > 1`.

---

### 2.3 Interpolação/Mistura

#### Padrão de Enunciado
Separar caracteres em posições pares e ímpares para criar duas strings diferentes.

#### Descrição Técnica
Criar duas strings usando índices de posição no vetor ou string original.

#### Código Comentado
```cpp
string s;
cin >> s;
string pares, impares;
for(int i = 0; i < sz(s); i++) {
    if(i % 2 == 0) {
        pares.pb(s[i]); // posições pares
    } else {
        impares.pb(s[i]); // posições ímpares
    }
}

cout << pares << "\n";
cout << impares << "\n";
```

**Erro Comum:** confundir índice de posição com caractere `s[i]` em vez de `i`, especialmente em problemas que pedem 1-based indices.

---

## 3. Mapas e Frequência

### 3.1 Identificar o Diferente

#### Padrão de Enunciado
Entre grupos de três valores iguais, encontrar o valor que aparece apenas uma vez.

#### Descrição Técnica
Usar `map<ll, int>` para contar ocorrências e encontrar o valor com frequência `1`.

#### Código Comentado
```cpp
int n;
cin >> n;
map<ll, int> freq;
for(int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    freq[x]++;
}

for(auto [valor, cont] : freq) {
    if(cont == 1) {
        cout << valor << "\n";
        break;
    }
}
```

**Erro Comum:** usar `map<int, int>` quando os valores podem ser grandes (`10^9` ou `10^12`); `ll` evita overflow em chaves.

---

### 3.2 Contagem de Pares

#### Padrão de Enunciado
Contar quantas vezes cada par de pontos turísticos aparece.

#### Descrição Técnica
Usar `map<pii, int>` ou `map<pair<ll, ll>, int>` para contar conexões entre pares ordenados.

#### Código Comentado
```cpp
int m;
cin >> m;
map<pair<ll, ll>, int> freq;
for(int i = 0; i < m; i++) {
    ll u, v;
    cin >> u >> v;
    if(u > v) swap(u, v); // normalizar par
    freq[{u, v}]++;
}

for(auto [par, cont] : freq) {
    cout << par.first << " " << par.second << " => " << cont << "\n";
}
```

**Erro Comum:** não normalizar pares ordenados resulta em `(u,v)` e `(v,u)` tratados como diferentes.

---

## 4. Grafos

### 4.1 BFS em Grid

#### Padrão de Enunciado
Mover-se em 4 direções num mapa de obstáculos para calcular distâncias mínimas.

#### Descrição Técnica
Usar `dx/dy` e matriz `dist` inicializada com `-1` para BFS em grid. Verificar limites e paredes.

#### Código Comentado
```cpp
int n, m;
cin >> n >> m;
vector<string> grid(n);
for(int i = 0; i < n; i++) cin >> grid[i];

vector<vector<int>> dist(n, vector<int>(m, -1));
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue<pair<int,int>> q;

int sx = 0, sy = 0;
q.push({sx, sy});
dist[sx][sy] = 0;

while(!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    for(int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(dist[nx][ny] != -1) continue;
        if(grid[nx][ny] == '#') continue;
        dist[nx][ny] = dist[x][y] + 1;
        q.push({nx, ny});
    }
}
```

**Erro Comum:** esquecer de inicializar `dist` com `-1` ou de verificar `grid[nx][ny]` antes de inserir na queue.

---

### 4.2 DFS e Componentes

#### Padrão de Enunciado
Contar quantas ilhas ou cidades isoladas existem num grafo não-direcionado.

#### Descrição Técnica
Usar DFS recursivo ou iterativo para marcar componentes conexas.

#### Código Comentado
```cpp
int n, m;
cin >> n >> m;
vector<vector<int>> adj(n);
for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    adj[u].pb(v);
    adj[v].pb(u);
}

vector<bool> vis(n, false);
int componentes = 0;

auto dfs = [&](auto self, int u) -> void {
    vis[u] = true;
    for(int v : adj[u]) {
        if(!vis[v]) self(self, v);
    }
};

for(int i = 0; i < n; i++) {
    if(!vis[i]) {
        componentes++;
        dfs(dfs, i);
    }
}

cout << componentes << "\n";
```

**Erro Comum:** não resetar `vis` entre casos de teste ou usar `int` em grafos muito grandes.

---

### 4.3 Ciclos e Árvores

#### Padrão de Enunciado
Verificar se um grafo tem exatamente `N-1` arestas e é conexo.

#### Descrição Técnica
Usar contagem de arestas e conectividade para determinar se o grafo é árvore.

#### Código Comentado
```cpp
int n, m;
cin >> n >> m;
vector<vector<int>> adj(n);
for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    adj[u].pb(v);
    adj[v].pb(u);
}

if(m != n - 1) {
    cout << "NAO\n";
    return;
}

vector<bool> vis(n, false);
int cnt = 0;
queue<int> q;
q.push(0);
vis[0] = true;
while(!q.empty()) {
    int u = q.front();
    q.pop();
    cnt++;
    for(int v : adj[u]) {
        if(!vis[v]) {
            vis[v] = true;
            q.push(v);
        }
    }
}

if(cnt == n) cout << "SIM\n";
else cout << "NAO\n";
```

**Erro Comum:** lembrar que `m == n-1` é necessário mas não suficiente sem verificar conectividade.

---

## 5. Busca Binária na Resposta

### Padrão de Enunciado
Encontrar o menor tempo ou maior valor possível que satisfaça uma condição, usando uma função `check`.

### Descrição Técnica
Estrutura completa com `low`, `high`, `ans` e `check` que valida a resposta. Exemplo inspirado em problemas de distribuição de pizza ou atletas.

### Código Comentado
```cpp
ll n, k;
cin >> n >> k;
vector<ll> v(n);
for(int i = 0; i < n; i++) cin >> v[i];

auto can = [&](ll x) {
    ll count = 0;
    for(int i = 0; i < n; i++) {
        count += v[i] / x; // quantas fatias cada atleta pode receber
        if(count >= k) return true;
    }
    return false;
};

ll low = 1, high = *max_element(all(v));
ll ans = 0;
while(low <= high) {
    ll mid = low + (high - low) / 2;
    if(can(mid)) {
        ans = mid;
        low = mid + 1; // queremos o maior valor possível
    } else {
        high = mid - 1;
    }
}

cout << ans << "\n";
```

**Erro Comum:** não ajustar `high` corretamente ou esquecer `low <= high` resulta em loop infinito ou resposta errada.

---

## 6. Bitset e Otimização

### Padrão de Enunciado
Verificar se existe subconjunto de valores que soma uma pontuação exata.

### Descrição Técnica
Usar `bitset<MAX>` para operações de soma de subconjuntos muito rápidas e econômicas.

### Código Comentado
```cpp
const int MAXS = 10005;
bitset<MAXS> bs;
bs[0] = 1;
int n;
cin >> n;
for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    bs |= (bs << x); // desloca e adiciona novos valores possíveis
}

int target;
cin >> target;
if(bs[target]) {
    cout << "POSSIVEL\n";
} else {
    cout << "IMPOSSIVEL\n";
}
```

**Erro Comum:** `bitset` não pode ser redimensionado dinamicamente; usar constante adequada e garantir `target < MAXS`.

---

## 7. Matemática e Geometria

### 7.1 Área de Quadrado

#### Padrão de Enunciado
Dadas coordenadas aleatórias de 4 pontos, determinar se formam um quadrado e calcular a área.

#### Descrição Técnica
Usar distâncias quadradas entre pontos para verificar se existem 4 lados iguais e 2 diagonais iguais.

#### Código Comentado
```cpp
using pii = pair<ll, ll>;
vector<pii> pts(4);
for(int i = 0; i < 4; i++) {
    cin >> pts[i].first >> pts[i].second;
}

auto dist2 = [&](const pii &a, const pii &b) {
    ll dx = a.first - b.first;
    ll dy = a.second - b.second;
    return dx*dx + dy*dy;
};

vector<ll> d2;
for(int i = 0; i < 4; i++) {
    for(int j = i + 1; j < 4; j++) {
        d2.pb(dist2(pts[i], pts[j]));
    }
}

sort(all(d2));
if(d2[0] > 0 && d2[0] == d2[1] && d2[1] == d2[2] && d2[2] == d2[3] && d2[4] == d2[5]) {
    ll side = d2[0];
    cout << "AREA = " << side << "\n"; // área do quadrado em termos do lado^2
} else {
    cout << "NAO FORMA QUADRADO\n";
}
```

**Erro Comum:** comparar coordenadas com `==` em ponto flutuante; usar apenas inteiros ou distâncias quadradas para evitar `sqrt`.

---

### 7.2 Exponenciação e GCD

#### Padrão de Enunciado
Resolver problemas de ciclos de tempo ou engrenagens usando exponenciação rápida e máximo divisor comum.

#### Descrição Técnica
Funções rápidas para `gcd` e `power` modular.

#### Código Comentado
```cpp
ll gcd(ll a, ll b) {
    while(b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll mod_pow(ll a, ll b, ll mod) {
    ll res = 1;
    a %= mod;
    while(b > 0) {
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

ll a, b;
cin >> a >> b;
cout << gcd(a, b) << "\n";
cout << mod_pow(a, b, 1000000007) << "\n";
```

**Erro Comum:** esquecer `a %= mod` antes do loop ou usar `int` quando `a` e `b` podem ser até `10^9`.

---

## 8. STL Avançado

### Padrão de Enunciado
Aproveitar containers STL para operações rápidas: set/map ordenados, priority queue para heaps, lower_bound/upper_bound em vetores ordenados.

### Descrição Técnica
A STL oferece estruturas altamente otimizadas. `set` e `map` usam árvores vermelho-preto O(log n); `unordered_set` usa hash (cuidado com colisões em juízes); `priority_queue` implementa heaps; `lower_bound` faz busca binária.

### Código Comentado
```cpp
// SET: Ordenado, O(log n) para insert/erase/find
set<int> s;
s.insert(5);
if(s.count(5)) cout << "Encontrado\n";
auto it = s.lower_bound(5); // Primeira posição >= 5
auto it2 = s.upper_bound(5); // Primeira posição > 5
s.erase(5);

// MAP: Chave-valor ordenado
map<ll, int> freq;
freq[10]++;
for(auto [chave, valor] : freq) {
    cout << chave << " => " << valor << "\n";
}

// PRIORITY QUEUE: Max-heap (padrão)
priority_queue<int> pq;
pq.push(5);
int maior = pq.top();
pq.pop();

// Min-heap
priority_queue<int, vector<int>, greater<int>> min_pq;
min_pq.push(5);

// LOWER_BOUND em vetor
vector<int> v = {1, 3, 3, 5, 7};
int pos = lower_bound(v.begin(), v.end(), 3) - v.begin(); // 1
int cont = upper_bound(v.begin(), v.end(), 3) - lower_bound(v.begin(), v.end(), 3); // 2
```

**Erro Comum:** usar `unordered_set` em Codeforces resulta em TLE por colisão de hash adversarial; preferir `set/map` ou implementar custom hash.

---

## 9. Grafos Avançados

### 9.1 Dijkstra

#### Padrão de Enunciado
Encontrar caminho mínimo num grafo com arestas ponderadas positivas.

#### Descrição Técnica
Usar priority queue com pares (distância, nó) para expandir nós em ordem de proximidade. Verificar se já visitado com distância menor para evitar reprocessamento.

#### Código Comentado
```cpp
int n, m;
cin >> n >> m;
vector<vector<pair<int, ll>>> adj(n);
for(int i = 0; i < m; i++) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w}); // se não-direcionado
}

vector<ll> dist(n, 1e18);
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
dist[0] = 0;
pq.push({0, 0});

while(!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();
    if(d > dist[u]) continue; // Já visitou com distância menor
    for(auto [v, w] : adj[u]) {
        if(dist[u] + w < dist[v]) {
            dist[v] = dist[u] + w;
            pq.push({dist[v], v});
        }
    }
}

for(int i = 0; i < n; i++) {
    cout << dist[i] << " ";
}
```

**Erro Comum:** não verificar `d > dist[u]` resulta em reprocessamento desnecessário; usar `ll` para distâncias grandes.

---

### 9.2 DSU - Union-Find

#### Padrão de Enunciado
Manter componentes conexas e detectar ciclos rapidamente.

#### Descrição Técnica
Usar path compression e union by rank para operações praticamente O(1). Essencial para Kruskal e problemas de conectividade.

#### Código Comentado
```cpp
class DSU {
public:
    vector<int> parent, rank;
    
    DSU(int n) : parent(n), rank(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x) {
        if(parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }
    
    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if(px == py) return false;
        if(rank[px] < rank[py]) swap(px, py);
        parent[py] = px;
        if(rank[px] == rank[py]) rank[px]++;
        return true;
    }
};

DSU dsu(n);
for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    if(dsu.unite(u, v)) {
        cout << "Nova aresta, sem ciclo\n";
    } else {
        cout << "Ciclo detectado!\n";
    }
}
```

**Erro Comum:** não fazer path compression resulta em O(log n) por operação; esquecer `rank` torna a estrutura desbalanceada.

---

### 9.3 Kruskal - MST

#### Padrão de Enunciado
Encontrar árvore geradora mínima de um grafo ponderado.

#### Descrição Técnica
Ordenar arestas por peso e usar DSU para adicionar arestas que não formam ciclo.

#### Código Comentado
```cpp
struct Edge {
    ll w;
    int u, v;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

int n, m;
cin >> n >> m;
vector<Edge> edges(m);
for(int i = 0; i < m; i++) {
    cin >> edges[i].u >> edges[i].v >> edges[i].w;
    edges[i].u--; edges[i].v--;
}

sort(edges.begin(), edges.end());
DSU dsu(n);
ll mst_cost = 0;
int edges_added = 0;

for(auto [w, u, v] : edges) {
    if(dsu.unite(u, v)) {
        mst_cost += w;
        edges_added++;
        if(edges_added == n - 1) break;
    }
}

if(edges_added == n - 1) {
    cout << mst_cost << "\n";
} else {
    cout << "Grafo desconexo\n";
}
```

**Erro Comum:** não verificar se o grafo é conexo (edges_added == n-1); usar `int` para pesos grandes causa overflow.

---

## 10. Programação Dinâmica

### 10.1 Fibonacci com Memoização

#### Padrão de Enunciado
Computar n-ésimo número de Fibonacci de forma eficiente.

#### Descrição Técnica
Usar array de memoização para evitar recomputação em recursão.

#### Código Comentado
```cpp
int n;
cin >> n;
vector<ll> memo(n + 1, -1);

function<ll(int)> fib = [&](int i) -> ll {
    if(i <= 1) return i; // Base: fib(0)=0, fib(1)=1
    if(memo[i] != -1) return memo[i]; // Já calculado
    return memo[i] = fib(i - 1) + fib(i - 2);
};

cout << fib(n) << "\n";
```

**Complexidade:** O(n)
**Erro Comum:** overflow em Fibonacci; `fib(100)` necessita `ll`.

---

### 10.2 Knapsack 0/1

#### Padrão de Enunciado
Mochila com capacidade W, maximizar valor sem exceder peso.

#### Descrição Técnica
DP unidimensional, iterando capacidades de trás para frente para usar cada item uma vez.

#### Código Comentado
```cpp
int n, W;
cin >> n >> W;
vector<int> w(n), v(n);
for(int i = 0; i < n; i++) cin >> w[i] >> v[i];

vector<ll> dp(W + 1, 0); // dp[c] = valor máximo com capacidade c

for(int i = 0; i < n; i++) {
    for(int c = W; c >= w[i]; c--) { // Trás para frente!
        dp[c] = max(dp[c], dp[c - w[i]] + v[i]);
    }
}

cout << dp[W] << "\n";
```

**Complexidade:** O(n*W)
**Erro Comum:** iterar para frente causa uso múltiplo do mesmo item.

---

### 10.3 LIS - Longest Increasing Subsequence

#### Padrão de Enunciado
Encontrar comprimento da maior subsequência estritamente crescente em O(n log n).

#### Descrição Técnica
Manter vetor `dp` com menor valor final para cada tamanho de LIS, usar binary search.

#### Código Comentado
```cpp
int n;
cin >> n;
vector<int> a(n);
for(int i = 0; i < n; i++) cin >> a[i];

vector<int> dp; // dp[i] = menor valor terminando LIS de tamanho i+1

for(int i = 0; i < n; i++) {
    int pos = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
    if(pos == dp.size()) {
        dp.push_back(a[i]);
    } else {
        dp[pos] = a[i];
    }
}

cout << dp.size() << "\n"; // Tamanho da LIS
```

**Complexidade:** O(n log n)
**Erro Comum:** este algoritmo encontra tamanho, não a sequência; adicionar parent pointers se necessário reconstruir.

---

## 11. Recursividade e Algoritmos Clássicos

### 11.1 Torre de Hanoi

#### Padrão de Enunciado
Mover N discos de uma haste para outra seguindo regras: um disco por vez, disco maior nunca sobre o menor.

#### Descrição Técnica
Algoritmo recursivo clássico: mover N-1 discos para haste auxiliar, mover disco N para destino, mover N-1 para destino. Gera $2^N - 1$ movimentos.

#### Código Comentado
```cpp
// Mover n discos da origem para destino, usando auxiliar
function<void(int, char, char, char)> hanoi = [&](int n, char origem, char destino, char auxiliar) {
    if(n == 0) return; // Caso base
    
    hanoi(n - 1, origem, auxiliar, destino); // Mover n-1 para auxiliar
    cout << "Mover disco " << n << " de " << origem << " para " << destino << "\n";
    hanoi(n - 1, auxiliar, destino, origem); // Mover n-1 de auxiliar para destino
};

int n;
cin >> n;
hanoi(n, 'A', 'C', 'B'); // A=origem, C=destino, B=auxiliar
```

**Complexidade:** O($2^n$)
**Saída para n=2:**
```
Mover disco 1 de A para B
Mover disco 2 de A para C
Mover disco 1 de B para C
```
**Erro Comum:** trocar ordem de chamadas causa sequência inválida.

---

### 11.2 Princípios de Recursão

#### Padrão de Enunciado
Resolver problemas dividindo em subproblemas idênticos menores.

#### Descrição Técnica
Todo algoritmo recursivo precisa: **caso base** (quando parar), **progresso** (problema fica menor) e **confiança** (assumir que subproblemas resolvem corretamente).

#### Código Comentado
```cpp
// Exemplo 1: Soma de array
function<ll(vector<int>&, int)> soma = [&](vector<int>& v, int n) -> ll {
    if(n == 0) return 0; // Caso base
    return v[n - 1] + soma(v, n - 1); // Progresso: reduz n
};

// Exemplo 2: Permutações (backtracking)
vector<vector<int>> perms;
vector<int> current;
vector<bool> used;

function<void(int, int)> gen_perms = [&](int depth, int n) {
    if(depth == n) {
        perms.push_back(current);
        return;
    }
    for(int i = 0; i < n; i++) {
        if(!used[i]) {
            used[i] = true;
            current.push_back(i);
            gen_perms(depth + 1, n); // Recur
            current.pop_back();
            used[i] = false; // Backtrack
        }
    }
};

gen_perms(0, 3);
```

**Erro Comum:** esquecer de limpar estado após recur (backtracking) causa resultados duplicados.

---

## 12. Verificação de Números Especiais

### 12.1 Verificar se é Primo

#### Padrão de Enunciado
Determinar se um número é primo (divisível apenas por 1 e por si mesmo).

#### Descrição Técnica
Verificar divisibilidade até $\sqrt{n}$. Para múltiplas queries, usar Crivo de Eratóstenes.

#### Código Comentado
```cpp
// Método 1: Teste simples (para número único)
bool is_prime(ll n) {
    if(n < 2) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false; // Par
    for(ll i = 3; i * i <= n; i += 2) { // Verificar até sqrt(n), apenas ímpares
        if(n % i == 0) return false;
    }
    return true;
}

// Método 2: Crivo de Eratóstenes (para intervalo)
const int MAXN = 1e6;
vector<bool> is_prime_sieve(MAXN + 1, true);
is_prime_sieve[0] = is_prime_sieve[1] = false;

for(int i = 2; i * i <= MAXN; i++) {
    if(is_prime_sieve[i]) {
        for(int j = i * i; j <= MAXN; j += i) {
            is_prime_sieve[j] = false;
        }
    }
}

// Uso
ll x;
cin >> x;
if(is_prime(x)) {
    cout << x << " é primo\n";
} else {
    cout << x << " não é primo\n";
}
```

**Complexidade:** Método 1: O($\sqrt{n}$), Método 2 (Crivo): O($n \log \log n$)
**Erro Comum:** esquecer que 2 é primo; 1 não é primo; começar loop em 3 e incrementar por 2.

---

### 12.2 Raiz Quadrada Exata

#### Padrão de Enunciado
Verificar se um número é quadrado perfeito e encontrar raiz inteira.

#### Descrição Técnica
Usar `sqrt()` com verificação ou busca binária para evitar erros de ponto flutuante.

#### Código Comentado
```cpp
// Método 1: Com sqrt (cuidado com ponto flutuante)
bool is_perfect_square_float(ll n) {
    if(n < 0) return false;
    ll root = (ll)sqrt((double)n);
    // Verificar root-1, root, root+1 por segurança (erros de arredondamento)
    return (root - 1) * (root - 1) == n || root * root == n || (root + 1) * (root + 1) == n;
}

// Método 2: Busca binária (mais seguro)
ll integer_sqrt(ll n) {
    if(n == 0) return 0;
    ll low = 1, high = min(n, (ll)1e9); // sqrt(10^18) < 10^9
    ll ans = 1;
    while(low <= high) {
        ll mid = low + (high - low) / 2;
        if(mid <= n / mid) { // Evita overflow: mid*mid <= n
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

bool is_perfect_square(ll n) {
    ll root = integer_sqrt(n);
    return root * root == n;
}

// Uso
ll x;
cin >> x;
if(is_perfect_square(x)) {
    cout << integer_sqrt(x) << " é raiz de " << x << "\n";
} else {
    cout << x << " não é quadrado perfeito\n";
}
```

**Complexidade:** Método 1: O(1), Método 2: O(log n)
**Erro Comum:** `sqrt(1e18)` resulta em imprecisão; usar divisão para evitar overflow: `mid <= n / mid` em vez de `mid * mid <= n`.

---

## 13. String Hashing

### Padrão de Enunciado
Comparar substrings ou procurar padrões em strings de forma rápida usando hash polinomial.

### Descrição Técnica
Pré-processar string com hash polinomial para queries O(1). Risco de colisão; usar double hashing para segurança.

### Código Comentado
```cpp
const ll BASE = 31;
const ll MOD1 = 1e9 + 7;
const ll MOD2 = 1e9 + 9; // Para double hashing

string s;
cin >> s;
int n = s.length();

vector<ll> hash1(n + 1, 0), hash2(n + 1, 0);
vector<ll> pow1(n + 1, 1), pow2(n + 1, 1);

for(int i = 0; i < n; i++) {
    hash1[i + 1] = (hash1[i] * BASE + (s[i] - 'a' + 1)) % MOD1;
    hash2[i + 1] = (hash2[i] * BASE + (s[i] - 'a' + 1)) % MOD2;
    pow1[i + 1] = (pow1[i] * BASE) % MOD1;
    pow2[i + 1] = (pow2[i] * BASE) % MOD2;
}

// Hash de substring [l, r]
auto get_hash = [&](int l, int r) {
    ll h1 = (hash1[r + 1] - hash1[l] * pow1[r - l + 1]) % MOD1;
    ll h2 = (hash2[r + 1] - hash2[l] * pow2[r - l + 1]) % MOD2;
    if(h1 < 0) h1 += MOD1;
    if(h2 < 0) h2 += MOD2;
    return make_pair(h1, h2);
};

// Uso: comparar substrings
if(get_hash(0, 2) == get_hash(3, 5)) {
    cout << "Substrings iguais\n";
}
```

**Complexidade:** O(n) pré-processamento, O(1) query
**Erro Comum:** não tratar valores negativos; colisão com MOD único em juízes adversariais.

---

## 14. Debug e Macros

### Padrão de Enunciado
Detectar erros rapidamente durante desenvolvimento e checklist antes de submeter.

### Código Comentado
```cpp
// Macros para debug (comentar antes de submeter)
#define DEBUG(x) cerr << #x << " = " << x << "\n"
#define DEBUG_VEC(v) { cerr << #v << ": "; for(auto x : v) cerr << x << " "; cerr << "\n"; }
#define DEBUG_MAP(m) { for(auto [k, v] : m) cerr << k << ":" << v << " "; cerr << "\n"; }

// Timer para detectar TLE
#include <chrono>
auto start = chrono::high_resolution_clock::now();
// ... código ...
auto end = chrono::high_resolution_clock::now();
cerr << chrono::duration<double>(end - start).count() << " sec\n";

// Uso
int ans = 42;
DEBUG(ans); // Imprime: ans = 42
vector<int> v = {1, 2, 3};
DEBUG_VEC(v); // Imprime: v: 1 2 3
```

### Checklist Pré-Submissão
- [ ] Overflow: somas/produtos > $2 \times 10^9$ usam `ll`
- [ ] Casos extremos: n=0, n=1, todos iguais, max/min
- [ ] Off-by-one: loops `i < n` vs `i <= n`, arrays 0-based vs 1-based
- [ ] Inicialização: variáveis globais resetadas entre `t` casos
- [ ] Input/Output: formato exato, espaços, quebras de linha
- [ ] Complexidade: algoritmo cabe no tempo (1-2 segundos ≈ $10^8$ operações)
- [ ] Lógica: verificar manualmente com exemplos
- [ ] Compilação: sem warnings, sem funções undefined

**Erro Comum:** esquecer de comentar macros DEBUG antes de submeter causa saída incorreta.

---

**Dicas Finais:** mantenha o código compacto, legível e com comentários essenciais. Ao imprimir, use um editor de Markdown ou gerador de PDF para garantir boa formatação.