# Connectivitat i Percolació

Aquest projecte estudia les transicions de fase en grafs aleatoris, centrant-se en la connectivitat a mesura que s'aplica la percolació sobre nodes i arestes. Els models analitzats inclouen:

- **Erdös-Rényi** (grafs aleatoris)
- **Graella quadrada**
- **Graella triangular**
- **Small World** (grafs amb alta agrupació i baixa distància mitjana)
- **Barabási-Albert** (grafs d'escala lliure)

L'objectiu és entendre millor les dinàmiques de connectivitat en xarxes complexes i la seva vulnerabilitat a mesura que es modifica la probabilitat de fallida, _q_.

---

## Compilació i Execució

### Requisits

- **g++** (amb suport per C++17 o superior)
- Un compilador de C++ compatible amb **POSIX** per l’execució de programes amb fils.
- **make** per compilar de forma automàtica i linkar els fitxers

### Compilació

Hi ha dos programes principals a compilar:

1. **main.cpp** (el simulador principal de percolació)
2. **runner.cpp** (l'executor paral·lel que llança instàncies de `./main`)

Per compilar els programes `main` i `runner`:

```bash
make all
```

Si es volgués compilar només un programa també es podria amb:

```bash
make main
make runner
```

### Execució

#### Executar `main`

El programa `main` no llegeix paràmetres de fitxers ni línia de comandes. En comptes d'això, demana els paràmetres directament a l'usuari a través de l'entrada estàndard en temps d'execució.

```bash
./main
```

#### Executar `runner`

El programa `runner` executa múltiples instàncies de `./main` en paral·lel, proporcionant automàticament les dades necessàries per a cada instància.

Per tal de funcionar aquest programa genera fitxers temporals que seran la entrada de cada execució de `main`. Al acabar, `runner` s'encarregarà d'esborrar aquests futxers temporals.

Exemple d'execució:

```bash
./runner ./input.txt
```

On `./input.txt` és un fitxer on cada línia conté els valors que `main` sol·licitarà (per exemple, nombre de nodes i probabilitat de percolació). Cada línia representa un conjunt de dades per a una execució de `main`, i `runner` proporciona aquestes dades de manera automàtica.

#### Exemple de fitxer d'entrada (`input.txt`)

Aquest és un exemple de `input.txt`, on cada línia conté una configuració per a una execució de `main`. Les columnes representen els següents paràmetres:

- **RandomSeed**: La llavor per al generador aleatori.
- **NúmeroMínimNodes**: El nombre mínim de nodes del graf.
- **NúmeroMàximNodes**: El nombre màxim de nodes del graf.
- **NúmeroNodesStep**: Increment dels nodes en cada iteració.
- **IteracionsPerObtenirResultat**: El nombre de vegades que es provarà la configuració d'aquell moment, per probabilita _p_ de percolació i per nombre de vèrtex _n_, per tal de trobar la mitja.
- **PathResultat**: El fitxer on es guardaran els resultats.
- **AlgorismeGeneradorGraf**: L'algoritme utilitzat per generar el graf.
  - **Erdos-Renyi** (p)
  - **Square-Grid**
  - **Triangular-Grid**
  - **Random-Geometric** (r)
  - **Barabasi-Albert** (m0, m)
- **ParàmetresAlgorisme**: Paràmetres addicionals per al generador de graf (opcional segons l'algorisme).

Exemple de contingut de `input.txt`:

```txt
21312   10   100    10   1000    ./data/test1.csv    Erdos-Renyi         0.1
35353   50   500    50   1000    ./data/test2.csv    Random-Geometric    0.3
72479   100  1000   100  100     ./data/test3.csv    Square-Grid
```

- **21312**: Llavor aleatòria (RandomSeed)
- **10**: Nombre mínim de nodes
- **100**: Nombre màxim de nodes
- **10**: Increment de nodes en cada iteració (NúmeroNodesStep)
- **./data/test1.csv**: Fitxer de resultats
- **Erdos-Renyi**: Algoritme generador de grafs
- **0.1**: Paràmetre addicional per a l'algoritme (probabilitat d'aresta en el cas de **Erdos-Renyi**)

---
