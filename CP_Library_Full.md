# CP Library - Guia de Referência para Competições de Programação

**Nível:** Grandmaster | **Versão:** 1.0 | **Linguagem:** C++17 | **Data:** Maio 2026

---

## 📑 Índice

1. [Template Base C++17](#1-template-base-c17)
2. [STL - Standard Template Library](#2-stl---standard-template-library)
3. [Técnicas de Implementação](#3-técnicas-de-implementação)
4. [Grafos](#4-grafos)
5. [Matemática](#5-matemática)
6. [Programação Dinâmica](#6-programação-dinâmica)
7. [Strings](#7-strings)
8. [Debug e Checklist](#8-debug-e-checklist)

---

## 1. Template Base C++17

### Fast I/O + Template Completo

```cpp
#include <bits/stdc++.h>
using namespace std;

// Tipos personalizados
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;

// Macros úteis
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define fi first
#define se second
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define FASTIO ios::sync_with_stdio(0); cin.tie(0)

// Constantes
const int INF = 1e9;
const ll LINF = 1e18;
const ll MOD = 1e9 + 7;
const double EPS = 1e-9;

// Debug (comentar em submissão)
#define DEBUG(x) cerr << #x << " = " << x << "\n"
#define DEBUG2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << "\n"

// Função principal
void solve() {
    // Lógica do problema aqui
}

int main() {
    FASTIO;
    int t = 1;
    cin >> t; // Descomentar se houver múltiplos casos de teste
    while(t--) {
        solve();
    }
    return 0;
}
```

**Complexidade:** O(1) para setup
**Memória:** O(1)

---

## 2. STL - Standard Template Library

### 2.1 Vector

```cpp
vi v = {1, 2, 3};
v.pb(4);              // Adiciona elemento: O(1) amortizado
v.pop_back();         // Remove último: O(1)
v[0];                 // Acesso por índice: O(1)
v.front(); v.back();  // Primeiro/último: O(1)
sort(all(v));         // Ordena: O(n log n)
reverse(all(v));      // Inverte: O(n)
int pos = lower_bound(all(v), 3) - v.begin(); // Primeira posição >= 3: O(log n)
```

### 2.2 Set vs Unordered_Set

```cpp
// SET: Ordenado, sem colisões, mais seguro
set<int> s;
s.insert(5);          // O(log n)
s.erase(5);           // O(log n)
auto it = s.lower_bound(5); // Primeira posição >= 5: O(log n)
auto it = s.upper_bound(5); // Primeira posição > 5: O(log n)

// UNORDERED_SET: Hash, mais rápido em média, risco de colisões
unordered_set<int> us;
us.insert(5);         // O(1) média, O(n) pior caso
us.count(5);          // O(1) média

// ⚠️ AVISO: Unordered_set/map têm colisão em Codeforces com entrada adversarial
// Use set/map quando há dúvida ou use custom hash
```

### 2.3 Map vs Unordered_Map

```cpp
map<int, int> mp;
mp[5] = 10;           // Inserção/acesso: O(log n)
mp.count(5);          // Verifica existência: O(log n)
mp.erase(5);          // Remove: O(log n)

// Iteração ordenada (apenas map)
for(auto [key, val] : mp) {
    cout << key << " " << val << "\n";
}
```

### 2.4 Priority Queue

```cpp
// MAX HEAP (padrão)
priority_queue<int> pq;
pq.push(5);           // O(log n)
int top = pq.top();   // O(1)
pq.pop();             // O(log n)

// MIN HEAP
priority_queue<int, vector<int>, greater<int>> min_pq;
min_pq.push(5);

// Com pares (ordena por primeiro elemento)
priority_queue<pii> pq_pair;
pq_pair.push({10, 1});
```

### 2.5 Lower Bound e Upper Bound

```cpp
vi v = {1, 3, 3, 5, 7};

// lower_bound: primeira posição >= x
int pos1 = lower_bound(all(v), 3) - v.begin(); // pos = 1
// upper_bound: primeira posição > x
int pos2 = upper_bound(all(v), 3) - v.begin();  // pos = 3

// Contar quantas vezes x aparece
int count = upper_bound(all(v), 3) - lower_bound(all(v), 3); // 2
```

**Complexidade:** O(log n) para vector ordenado

---

## 3. Técnicas de Implementação

### 3.1 Prefix Sum (1D)

```cpp
// Cálculo: pref[i] = soma de a[0] até a[i-1]
vi a = {1, 2, 3, 4, 5};
int n = sz(a);
vi pref(n + 1, 0);

for(int i = 0; i < n; i++) {
    pref[i + 1] = pref[i] + a[i];
}

// Soma de a[l] até a[r] em O(1)
auto range_sum = [&](int l, int r) {
    return pref[r + 1] - pref[l];
};

int soma = range_sum(1, 3); // Soma a[1] + a[2] + a[3] = 2 + 3 + 4 = 9
```

**Complexidade:** Pré-processamento O(n), queries O(1)
**Memória:** O(n)

### 3.2 Prefix Sum (2D)

```cpp
// Cálculo: pref2d[i][j] = soma de retângulo (0,0) até (i-1,j-1)
int n = 3, m = 3;
vector<vector<int>> a = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
vector<vector<ll>> pref(n + 1, vector<ll>(m + 1, 0));

for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
        pref[i][j] = a[i-1][j-1] + pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
    }
}

// Soma retângulo: (r1, c1) até (r2, c2)
auto rect_sum = [&](int r1, int c1, int r2, int c2) {
    return pref[r2+1][c2+1] - pref[r1][c2+1] - pref[r2+1][c1] + pref[r1][c1];
};
```

**Complexidade:** Pré-processamento O(n*m), queries O(1)

### 3.3 Two Pointers

```cpp
// Problema: Encontrar subarray com soma = target
int n = 5;
vi a = {1, 2, 3, 4, 5};
int target = 9;

int l = 0, r = 0;
int soma = a[0];
while(r < n) {
    if(soma == target) {
        cout << "Encontrado: [" << l << ", " << r << "]\n";
        break;
    }
    if(soma < target) {
        r++;
        if(r < n) soma += a[r];
    } else {
        soma -= a[l];
        l++;
    }
}
```

**Complexidade:** O(n)
**Uso:** Subarray problems, sequências ordenadas

### 3.4 Sliding Window

```cpp
// Máximo de subarray de tamanho k
int n = 5, k = 3;
vi a = {3, 1, 4, 1, 5};

deque<int> dq; // Armazena índices
int l = 0;

for(int r = 0; r < n; r++) {
    // Remove elementos fora da janela
    while(!dq.empty() && dq.front() < r - k + 1) {
        dq.pop_front();
    }
    // Mantém ordem decrescente no deque
    while(!dq.empty() && a[dq.back()] <= a[r]) {
        dq.pop_back();
    }
    dq.pb(r);
    
    // Resposta quando janela está completa
    if(r >= k - 1) {
        cout << a[dq.front()] << " ";
    }
}
```

**Complexidade:** O(n)
**Uso:** Máximo/mínimo em janela, contagem de elementos

### 3.5 Busca Binária no Valor

```cpp
// Encontrar menor x onde f(x) é verdadeiro
// f(x) deve ser monotônica: falso, falso, ..., verdadeiro, verdadeiro, ...

auto is_possible = [&](ll x) -> bool {
    // Verifica se x satisfaz a condição
    return (x * x >= 100); // Exemplo: x^2 >= 100
};

ll l = 0, r = 1e9;
ll ans = -1;

while(l <= r) {
    ll mid = l + (r - l) / 2;
    if(is_possible(mid)) {
        ans = mid;
        r = mid - 1;
    } else {
        l = mid + 1;
    }
}

cout << "Resposta: " << ans << "\n"; // 10 (menor x onde x^2 >= 100)
```

**Complexidade:** O(log(MAX_VALUE) * O(check))

---

## 4. Grafos

### 4.1 Representação com Lista de Adjacência

```cpp
int n = 5, m = 4;
vector<vi> adj(n); // adj[u] = {v1, v2, ...}

// Adicionar aresta não-direcionada
auto add_edge = [&](int u, int v) {
    adj[u].pb(v);
    adj[v].pb(u);
};

// Entrada
for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    add_edge(u, v);
}
```

### 4.2 DFS (Busca em Profundidade)

```cpp
vector<bool> visited(n, false);
vi order; // Ordem de visita

function<void(int)> dfs = [&](int u) {
    visited[u] = true;
    order.pb(u);
    
    for(int v : adj[u]) {
        if(!visited[v]) {
            dfs(v);
        }
    }
};

dfs(0); // Começar do nó 0
```

**Complexidade:** O(V + E)
**Uso:** Conectividade, ciclos, ordenação topológica

### 4.3 BFS (Busca em Largura)

```cpp
vector<int> dist(n, -1);
queue<int> q;
q.push(0);
dist[0] = 0;

while(!q.empty()) {
    int u = q.front();
    q.pop();
    
    for(int v : adj[u]) {
        if(dist[v] == -1) {
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
}
```

**Complexidade:** O(V + E)
**Uso:** Caminho mais curto em grafos não-ponderados

### 4.4 BFS em Grid (com dx/dy)

```cpp
int n = 5, m = 5;
vector<string> grid(n);
for(int i = 0; i < n; i++) cin >> grid[i];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

vector<vector<int>> dist(n, vector<int>(m, -1));
queue<pii> q;
q.push({0, 0});
dist[0][0] = 0;

while(!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    
    for(int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        // Verificar limites e se já foi visitado
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && dist[nx][ny] == -1 && grid[nx][ny] != '#') {
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
}
```

**Complexidade:** O(n*m)

### 4.5 Dijkstra (Caminho Mínimo com Pesos)

```cpp
const ll INF_DIJKSTRA = 1e18;
vector<vll> dist(n, vector<ll>(n, INF_DIJKSTRA));
// Ou para lista de adjacência com pesos:
// vector<vector<pair<int, ll>>> adj(n);

priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
dist[0] = 0;
pq.push({0, 0});

while(!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();
    
    if(d > dist[u]) continue; // Ignorar se já visitado com distância menor
    
    for(int v = 0; v < n; v++) {
        if(adj[u][v] != INF_DIJKSTRA && dist[u] + adj[u][v] < dist[v]) {
            dist[v] = dist[u] + adj[u][v];
            pq.push({dist[v], v});
        }
    }
}

// Distância do nó 0 para todos os outros está em dist[i]
```

**Complexidade:** O((V + E) log V) com priority queue
**Não funciona com:** Arestas negativas (usar Bellman-Ford)

### 4.6 DSU (Disjoint Set Union) / Union-Find

```cpp
class DSU {
public:
    vector<int> parent, rank;
    
    DSU(int n) : parent(n), rank(n, 0) {
        iota(parent.begin(), parent.end(), 0); // parent[i] = i
    }
    
    // Find com path compression
    int find(int x) {
        if(parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    // Union por rank
    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if(px == py) return false;
        
        if(rank[px] < rank[py]) swap(px, py);
        parent[py] = px;
        if(rank[px] == rank[py]) rank[px]++;
        return true;
    }
};

// Uso
DSU dsu(n);
for(int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    dsu.unite(u, v);
}
```

**Complexidade:** Praticamente O(1) com path compression e union by rank
**Uso:** Detecção de ciclos, MST (Kruskal), componentes conexas

### 4.7 Kruskal (Árvore Geradora Mínima)

```cpp
struct Edge {
    ll w;
    int u, v;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

vector<Edge> edges;
// Preencher edges com peso, origem, destino

sort(all(edges));

DSU dsu(n);
ll mst_weight = 0;
int mst_edges = 0;

for(auto [w, u, v] : edges) {
    if(dsu.unite(u, v)) {
        mst_weight += w;
        mst_edges++;
        if(mst_edges == n - 1) break;
    }
}

cout << "Peso MST: " << mst_weight << "\n";
```

**Complexidade:** O(E log E + E*α(V))
**Usa:** DSU, ordenação de arestas

---

## 5. Matemática

### 5.1 GCD e LCM

```cpp
// GCD (Máximo Divisor Comum) - Euclidiano
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

// LCM (Mínimo Múltiplo Comum)
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b; // Evita overflow
}

// Ou usar __gcd da STL
ll g = __gcd(12LL, 18LL); // 6
ll l = 12LL / g * 18LL;    // 36
```

**Complexidade:** O(log min(a, b))

### 5.2 Exponenciação Rápida (Modular)

```cpp
// a^b mod MOD
ll power(ll a, ll b, ll mod) {
    ll res = 1;
    a %= mod; // Evitar overflow
    while(b > 0) {
        if(b & 1) res = res * a % mod; // Se bit é 1
        a = a * a % mod;
        b >>= 1; // Próximo bit
    }
    return res;
}

// Exemplo: 2^10 mod 1e9+7
ll ans = power(2, 10, MOD); // 1024
```

**Complexidade:** O(log b)
**Uso:** Números grandes, operações modulares

### 5.3 Crivo de Eratóstenes

```cpp
int MAXN = 1e6;
vector<bool> is_prime(MAXN + 1, true);
is_prime[0] = is_prime[1] = false;

for(int i = 2; i * i <= MAXN; i++) {
    if(is_prime[i]) {
        // Marcar múltiplos como não-primos
        for(int j = i * i; j <= MAXN; j += i) {
            is_prime[j] = false;
        }
    }
}

// Verificar se número é primo
if(is_prime[17]) cout << "17 é primo\n";

// Contar primos até n
int count = 0;
for(int i = 2; i <= MAXN; i++) {
    if(is_prime[i]) count++;
}
```

**Complexidade:** O(n log log n)
**Memória:** O(n)

### 5.4 Inverso Modular (Fermat)

```cpp
// Encontrar x tal que (a * x) ≡ 1 (mod p)
// Funciona quando p é primo: a^(-1) ≡ a^(p-2) (mod p)

ll mod_inverse(ll a, ll mod) {
    return power(a, mod - 2, mod);
}

// Exemplo: Inverso de 3 modulo 7
ll inv = mod_inverse(3, 7); // 5 (pois 3*5 ≡ 1 mod 7)

// Usar em divisão modular: (a/b) mod p = (a * b^(-1)) mod p
ll division_mod = (10 * mod_inverse(2, MOD)) % MOD; // 10/2 mod MOD = 5
```

**Complexidade:** O(log MOD) (usando exponenciação rápida)
**Aplicações:** Divisão modular, combinatória modular

---

## 6. Programação Dinâmica

### 6.1 Conceito Básico: Fibonacci

```cpp
// Recursão com memoização
int n = 40;
vector<ll> memo(n + 1, -1);

function<ll(int)> fib = [&](int i) -> ll {
    if(i <= 1) return i;
    if(memo[i] != -1) return memo[i];
    return memo[i] = fib(i - 1) + fib(i - 2);
};

cout << fib(n) << "\n";
```

**Complexidade:** O(n)
**Memória:** O(n)

### 6.2 Knapsack 0/1 (Otimizado)

```cpp
// Problema: Mochila com capacidade W, n itens com peso w[i] e valor v[i]
// Maximizar valor total

int n = 5, W = 10;
vi w = {2, 3, 4, 5, 6};
vi v = {3, 4, 5, 6, 7};

vector<ll> dp(W + 1, 0); // dp[i] = valor máximo com capacidade i

for(int i = 0; i < n; i++) {
    // Percorrer de trás para frente para usar cada item apenas uma vez
    for(int cap = W; cap >= w[i]; cap--) {
        dp[cap] = max(dp[cap], dp[cap - w[i]] + v[i]);
    }
}

cout << "Valor máximo: " << dp[W] << "\n";
```

**Complexidade:** O(n*W)
**Memória:** O(W)
**Variantes:** Knapsack 0/1, unbounded, multidimensional

### 6.3 LIS - Longest Increasing Subsequence (O(n log n))

```cpp
// Encontrar o comprimento da maior subsequência estritamente crescente
vi a = {10, 9, 2, 5, 3, 7, 101, 18};
int n = sz(a);

vi dp; // dp[i] = menor valor que termina com LIS de tamanho i+1

for(int i = 0; i < n; i++) {
    // Encontrar posição onde inserir a[i]
    int pos = lower_bound(all(dp), a[i]) - dp.begin();
    if(pos == sz(dp)) {
        dp.pb(a[i]);
    } else {
        dp[pos] = a[i];
    }
}

cout << "LIS: " << sz(dp) << "\n"; // 4 (2, 3, 7, 101)
```

**Complexidade:** O(n log n)
**Memória:** O(n)
**Nota:** Não reconstrói a sequência; adicionar parent pointer se necessário

---

## 7. Strings

### 7.1 Frequência de Caracteres

```cpp
string s = "hello";

// Usar map
map<char, int> freq;
for(char c : s) freq[c]++;

// Ou usar array (apenas minúsculas)
int cnt[26] = {0};
for(char c : s) cnt[c - 'a']++;

// Encontrar caractere mais frequente
int maxCnt = 0;
char maxChar = 'a';
for(int i = 0; i < 26; i++) {
    if(cnt[i] > maxCnt) {
        maxCnt = cnt[i];
        maxChar = 'a' + i;
    }
}
```

**Complexidade:** O(n) onde n é comprimento da string

### 7.2 Manipulação Básica

```cpp
string s = "hello";

// Transformar maiúscula/minúscula
transform(all(s), s.begin(), ::tolower);
transform(all(s), s.begin(), ::toupper);

// Substring
string sub = s.substr(1, 3); // "ell"

// Encontrar ocorrência
size_t pos = s.find("ll"); // 2
if(pos != string::npos) {
    cout << "Encontrado em " << pos << "\n";
}

// Substituir
string::size_type n = 0;
while((n = s.find("l", n)) != string::npos) {
    s.replace(n, 1, "L");
    n += 1;
}

// Reverter
reverse(all(s));
```

### 7.3 Hashing Básico de Strings

```cpp
// Hash polinomial simples (risco de colisão)
ll hash_string(const string& s, ll base = 31, ll mod = 1e9 + 9) {
    ll hash_val = 0;
    ll pow = 1;
    for(char c : s) {
        hash_val = (hash_val + (c - 'a' + 1) * pow) % mod;
        pow = (pow * base) % mod;
    }
    return hash_val;
}

// Pré-processar para queries rápidas
int n = 5;
string s = "hello";
vector<ll> hash_val(n + 1, 0);
vector<ll> pow_base(n + 1, 1);
ll base = 31, mod = 1e9 + 9;

for(int i = 0; i < n; i++) {
    hash_val[i + 1] = (hash_val[i] + (s[i] - 'a' + 1) * pow_base[i]) % mod;
    pow_base[i + 1] = (pow_base[i] * base) % mod;
}

// Hash de substring [l, r]
auto get_hash = [&](int l, int r) {
    ll res = (hash_val[r + 1] - hash_val[l] + mod) % mod;
    res = res * pow_base[n - l] % mod; // Ajustar posição (cuidado!)
    return res;
};
```

**Complexidade:** O(n) pré-processamento, O(1) query
**Aviso:** Risco de colisão; usar double hashing se necessário

---

## 8. Debug e Checklist

### 8.1 Macros de Debug

```cpp
// Adicionar ao template (comentar em submissão)
#ifdef DEBUG
    #define DEBUG(x) cerr << #x << " = " << x << "\n"
    #define DEBUG_VEC(v) { cerr << #v << " = "; for(auto x : v) cerr << x << " "; cerr << "\n"; }
    #define DEBUG_MAT(m) { for(auto& row : m) { for(auto x : row) cerr << x << " "; cerr << "\n"; } }
    #define TIMER_START auto start = chrono::high_resolution_clock::now();
    #define TIMER_END auto end = chrono::high_resolution_clock::now(); cerr << chrono::duration<double>(end - start).count() << " sec\n";
#else
    #define DEBUG(x)
    #define DEBUG_VEC(v)
    #define DEBUG_MAT(m)
    #define TIMER_START
    #define TIMER_END
#endif
```

### 8.2 Checklist Pré-Submissão

**Verificações Críticas:**
- [ ] **Overflow:** Usar `long long` para somas/produtos
  - `int` range: -2.1e9 a 2.1e9
  - `ll` range: -9.2e18 a 9.2e18
  - Verificar multiplicações: `(a * b) % mod` pode dar overflow
  
- [ ] **Casos Extremos:** 
  - Entrada vazia (n=0)
  - Um elemento (n=1)
  - Todos elementos iguais
  - Máximo/mínimo permitido
  
- [ ] **Índices:**
  - Array começam em 0 ou 1?
  - Limites `i < n` ou `i <= n`?
  - Off-by-one errors em loops
  
- [ ] **Inicialização:**
  - Variáveis globais resetadas entre casos de teste
  - Arrays/vectors com tamanho correto
  - INF maior que possível resposta
  
- [ ] **Input/Output:**
  - Número correto de linhas lidas
  - Formato exato da saída
  - Espaços/quebras de linha
  - Flush se interativo
  
- [ ] **Algoritmo:**
  - Complexidade dentro do limite
  - Casos especiais tratados
  - Lógica correcta em exemplos
  
- [ ] **Compilação:**
  - Sem warnings com `-Wall -Wextra`
  - `#include <bits/stdc++.h>` compila
  - Nenhuma função undefined

---

## 📚 Resumo de Complexidades

| Algoritmo | Tempo | Espaço | Uso |
|-----------|-------|--------|-----|
| Prefix Sum | O(n) | O(n) | Range queries |
| Two Pointers | O(n) | O(1) | Subarrays |
| Sliding Window | O(n) | O(k) | Window queries |
| Binary Search | O(log n) | O(1) | Monotonic search |
| DFS/BFS | O(V+E) | O(V) | Conectividade |
| Dijkstra | O((V+E) log V) | O(V) | Caminho mínimo |
| DSU | O(α(n)) | O(n) | Componentes |
| Kruskal | O(E log E) | O(V) | MST |
| GCD | O(log min(a,b)) | O(1) | Divisores |
| Exponenciação | O(log b) | O(1) | Potências |
| Crivo | O(n log log n) | O(n) | Primos |
| Knapsack 0/1 | O(nW) | O(W) | Otimização |
| LIS | O(n log n) | O(n) | Subsequência |
| String Hash | O(n) | O(n) | Pattern matching |

---

**Dicas Finais:**
1. **Ler problema 2-3 vezes** - entender exatamente o que é pedido
2. **Pensar antes de programar** - desenhar exemplos, identificar padrão
3. **Testar com exemplos** - verificar correctness antes de submeter
4. **Otimizar se timeout** - muitas vezes constant factor importa
5. **Manter calma** - debugging sistemático, não ao acaso

---

**Última actualização:** Maio 2026 | **Autor:** Programador Competitivo | **Licença:** Use livremente em competições