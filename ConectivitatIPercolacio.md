# Conectivitat i Percolaciò

(BELDA)

## Transició de fase

## Grafs aleatoris

## Grafs amb fallides

(GUILLEM)

## Percolaciò

La percolació en un graf consisteix en eliminar o desactivar nodes o arestes, i es mesura com això afecta la connectivitat global del graf. Quan desactivem una aresta o node direm que ha tingut una fallida.

En termes generals, l'objectiu és estudiar com el graf passa d'estar completament connectat a parcialment o totalment desconnectat a mesura que es treuen alguns dels seus components. Quan parlem de percolació, considerem una probabilitat p que determina si una component del graf (node o aresta) es desactiva aleatòriament.

Aquest mecanisme és important per a l'estudi de xarxes complexes, ja que ens ajuda a comprendre com de robust o vulnerable és el sistema que volem analitzar.

* **Percolaciò per nodes**: Cada node té una probabilitat p de ser desactivat. Un cop fet això, s'analitza com ha canviat la connectivitat del graf.

* **Percolaciò per arestes**: En aquest cas, les arestes es desactiven en lloc dels nodes. Això també afecta la connectivitat, ja que les connexions directes entre nodes es perden.

* **Obtencio de graf percolat**: Després d'aplicar el procés de percolació (sobre nodes o arestes), s'obté un graf percolat, que és la versió modificada del graf original, amb una connectivitat reduïda i, possiblement, components desconnectats.

## Transició de fase al voltant de Π → En el cas del projecte la propietat serà la connectivitat

Donat un graf _G(V,E)_ connex i un paràmetre _q ∈ [0, 1]_ que representa la probabilitat de no fallida d'un element del graf (aresta o node), un cop s'aplica la percolació obtindrem _G<sub>q</sub>_. 

En el context del projecte, la propietat _Π_ que voldrem analitzar serà el nombre de components connexes que tindrà _G<sub>q</sub>_. Estudiarem com aquestes varien a mesura que modifiquem _q_.

(MARC)

## Altres models de graf

**Graelles triangluars**:

The triangular grid graph T_n is the lattice graph obtained by interpreting the order-(n+1) triangular grid as a graph, with the intersection of grid lines being the vertices and the line segments between vertices being the edges. Equivalently, it is the graph on vertices (i,j,k) with i,j,k being nonnegative integers summing to n such that vertices are adjacent if the sum of absolute differences of the coordinates of two vertices is 2.

A triangular grid, also called an isometric grid (Gardner 1986, pp. 209-210), is a grid formed by tiling the plane regularly with equilateral triangles. 

**Graelles tridimensionals**:

**Altre model de graf aleatòri**:

1. Hexagonal Lattice

## Bibliografia

## Coses interesants (treure al presentar)
[Random Graph description](https://www.math.cmu.edu/~af1p/BOOK.pdf)

[YT - Random Graph explanation](https://www.youtube.com/watch?v=mc6lrywc0Zc)

[YT - Percolation](https://www.youtube.com/watch?v=a-767WnbaCQ)