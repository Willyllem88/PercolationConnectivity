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

**Grafo de Barabási-Albert (Model d'adhesió preferencial)**:
- **Descripció**: Aquest model genera grafs on els nodes tendeixen a connectar-se amb altres nodes que ja tenen moltes connexions, creant una estructura amb alguns "nodes centrals" o "hubs". És un model de xarxa amb propietats de distribució de grau segons una llei de potències.
- **Aplicació a la percolació**: En les xarxes d'escala lliure com aquest model, els hubs tenen un impacte desproporcionat en la connectivitat. L’eliminació d’aquests hubs permet analitzar com la xarxa es fragmenta o es manté connectada.
- **Representació**: Es representa com un graf on, en afegir un nou node, aquest es connecta a nodes ja existents amb una probabilitat proporcional al nombre de connexions que aquests ja tenen. Això crea una estructura amb nodes altament connectats i altres amb poques connexions.

**Graelles Triangulars**:
- **Descripció**: Els nodes estan disposats en un patró triangular, on cada node està connectat amb els seus sis veïns més propers, formant triangles entre les seves connexions.
- **Aplicació a la percolació**: Amb més connexions per node que en la graella quadrada, aquest model permet estudiar la percolació en una estructura densa, veient com es descompon la connectivitat en eliminar nodes o arestes.
- **Representació**: Es pot representar com una graella bidimensional, amb nodes en posicions hexagonals compactes, connectats als sis veïns adjacents, de manera que les connexions formen triangles equilàters.

**Graelles Hexagonals**:
- **Descripció**: En aquest model, els nodes estan disposats en una malla hexagonal (com un rusc d’abelles), i cada node està connectat amb tres o sis veïns segons el patró que s'utilitzi.
- **Aplicació a la percolació**: El patró hexagonal ofereix una estructura compacta i simètrica per a l'estudi de la robustesa del graf en eliminar nodes o arestes. A diferència de la graella quadrada, la connectivitat local és diferent a causa de la disposició hexagonal.
- **Representació**: Es representa com una malla de nodes en forma de hexàgon, on cada node està connectat als seus veïns immediats segons la forma hexagonal, mantenint una simetria central.

**Graelles Tridimensionals**:
- **Descripció**: Extensió de la graella quadrada en tres dimensions, on els nodes es disposen en una estructura cúbica. Cada node està connectat amb sis veïns: davant, darrere, esquerra, dreta, a dalt i a baix.
- **Aplicació a la percolació**: Aquest model permet estudiar la percolació en estructures tridimensionals, com ara materials o xarxes complexes. La desconnexió de nodes o arestes es pot observar en una estructura més rica i complexa que les graelles bidimensionals.
- **Representació**: Es pot representar com una matriu tridimensional, on cada node té sis veïns ortogonals, creant una estructura cúbica on les connexions poden eliminar-se per estudiar la fragmentació.

---

## Comparació general

- **Grafo de Barabási-Albert**: La seva característica principal és la presència de "hubs" o nodes centrals amb moltes connexions. És ideal per a estudiar xarxes reals com les socials, on els hubs tenen un paper clau en la connectivitat global.
  
- **Graella Triangular**: Amb sis connexions per node, ofereix una estructura més densa que les graelles quadrades, fet que la fa més robusta davant fallades locals, però encara susceptible a la desconnexió si es perden suficients nodes centrals.

- **Graella Hexagonal**: Ofereix una disposició més simètrica i compacta que la graella triangular, amb un patró de connexions molt regular. Això pot afectar com es distribueixen les falles i la manera en què es fragmenta el graf.

- **Graella Tridimensional**: Més complexa que les versions bidimensionals, aquesta graella permet un estudi de percolació amb major profunditat en les connexions, ja que els nodes tenen més direccions de connexió. Això resulta en un comportament més interessant per a estudis de xarxes de tres dimensions com materials porosos o xarxes neuronals.
