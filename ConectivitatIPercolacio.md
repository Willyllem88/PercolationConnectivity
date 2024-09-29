# Connectivitat i Percolació

## Transició de fase

Una transició de fase d'un graf per a una propietat concreta _Π_ fa referència a un resultat satisfactori d'un procés de percolació aplicat al graf.

Definim un resultat com a satisfactori si, donat que es troba una probabilitat de valor _q_ tal que es compleix la propietat _Π_ al graf _G<sub>q</sub>_ (definim aquesta probabilitat com _q<sub>Π</sub>_), per als grafs amb _G<sub>q'</sub>_ on _q'_ > _q<sub>Π</sub>_ verifiquen la propietat _Π_ i als grafs amb _G<sub>q'</sub>_ on _q'_ < _q<sub>Π</sub>_ no verifiquen la propietat _Π_ (totes dues afirmacions són válides si es compleixen amb una probabilitat prou alta).    

Quan s'ha obtingut aquest resultat, diem que la propietat _Π_ presenta una transició de fase al voltant de _q<sub>Π</sub>_.  

## Grafs aleatoris

Els grafs aleatoris es caracteritzen per basar la seva estructura de node o arestes en probabilitats, a diferència dels grafs deterministes on les connexions entre nodes ja estan definides.

Les probabilitats que s'utilitzen en aquest tipus de grafs solen seguir diferents criteris segons el tipus, d'entre els quals destaquen:

* **Model de Erdös-Rényi**: En aquest model, dins d'un graf _G_, s'afegeix una aresta entre cada parell de nodes amb una probabilitat _p_.

* **Model Small World**: Aquest model utilitza tant models regulats com aleatoris, amb la finalitat de simular xarxes del món real. Es comença amb un graf regular on els nodes tenen arestes amb els seus veïns. Després, mitjançant una probablitat _p_, es formen arestes entre nodes de diferents "xarxes locals". Com més alta sigui aquesta probabilitat, més semblant serà el graf als del model anterior.

## Grafs amb fallides

Denominem una fallida a un graf si un node o una aresta falla. Aquesta fallida es representa per una probabilitat _q_ que defineix el graf i els seus components.

L'estudi d'aquests grafs permet estudiar la estructura i el comportament del graf en funció d'un probabilitat arbitrària de fallida.

Les fallides, tot i normalment ser aleatòries, poden també ser regulades i, per tant, no dependre d'una probabilitat, tot i que d'aquest tipus no en farem servir al projecte.

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

**Grafs Geomètrics Aleatoris (RGG)**:
- **Descripció**: Un graf no dirigit en què els nodes es col·loquen aleatòriament en un espai mètric, connectant dos nodes si la seva distància és menor que un radi definit, r.
- **Aplicació a les xarxes socials**: Els RGG s'utilitzen per modelar xarxes socials humanes, ja que mostren comunitats naturals i una alta modularitat, així com una connexió preferencial entre nodes populars.
- **Representació**: Els nodes es mostregen en un espai [0,1)d, amb connexions basades en la distància euclidiana entre ells, definint una xarxa depenent del paràmetre r.

```pseudo
V := generarMostres(n)  // Genera n mostres en el cub unitari.
per a cada p ∈ V fer
    per a cada q ∈ V\{p} fer
        si distància(p, q) ≤ r llavors
            afegirConnexió(p, q)  // Afegeix l'aresta (p, q) a l'estructura de dades d'arestes.
        fi
    fi
fi
```

### Comparació general

- **Grafo de Barabási-Albert**: La seva característica principal és la presència de "hubs" o nodes centrals amb moltes connexions. És ideal per a estudiar xarxes reals com les socials, on els hubs tenen un paper clau en la connectivitat global.
  
- **Graella Triangular**: Amb sis connexions per node, ofereix una estructura més densa que les graelles quadrades, fet que la fa més robusta davant fallades locals, però encara susceptible a la desconnexió si es perden suficients nodes centrals.

- **Graella Hexagonal**: Ofereix una disposició més simètrica i compacta que la graella triangular, amb un patró de connexions molt regular. Això pot afectar com es distribueixen les falles i la manera en què es fragmenta el graf.

- **Graella Tridimensional**: Més complexa que les versions bidimensionals, aquesta graella permet un estudi de percolació amb major profunditat en les connexions, ja que els nodes tenen més direccions de connexió. Això resulta en un comportament més interessant per a estudis de xarxes de tres dimensions com materials porosos o xarxes neuronals.
