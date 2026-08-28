# Module : Génie Logiciel (Programmation C++ et Conception Objet)

Ce dossier rassemble les Travaux Pratiques de Génie Logiciel et de Programmation Orientée Objet (POO) avancée en **C++**.

---

## 📂 Structure des TP et Notions Couvertes

### 🔹 [TP1 : Allocation Dynamique & Tableaux Génériques](./TP1)
- **Notions** : Classes, constructeurs/destructeurs, gestion de la mémoire dynamique (`new[]`/`delete[]`), surcharges d'opérateurs (`[]`).
- **Fichiers** : `array.hpp`, `array.cpp`, `main.cpp`

### 🔹 [TP2 : Algèbre Linéaire & Méthode de la Puissance](./TP2)
- **Notions** : Classes `Vecteur` et `Matrice`, calculs matriciels, surcharges d'opérateurs arithmétiques (`+`, `-`, `*`), méthode de la puissance itérée pour la recherche de valeurs propres.
- **Fichiers** : `vecteur.hpp`, `vecteur.cpp`, `matrice.hpp`, `matrice.cpp`, `puissance.hpp`, `puissance.cpp`, `main.cpp`

### 3️⃣ [TP3 : Héritage & Hiérarchie de Classes](./TP3)
- **Notions** : Héritage simple et multiple, classes d'animaux (`vertebre`, `oiseau`, `volante`), chaînage des constructeurs et gestion de la mémoire.
- **Fichiers** : `vertebre.hpp`, `vertebre.cpp`, `oiseau.hpp`, `oiseau.cpp`, `volante.hpp`, `volante.cpp`, `main.cpp`

### 4️⃣ [TP4 : Méthodes Inlined vs Out-of-line & Ensembles de Points](./TP4)
- **Notions** : Performance et optimisation de fonctions (`inline`), comparaison temps d'exécution/compilation, conteneurs de points (`std::vector<Point>`).
- **Fichiers** : `point_inline.hpp`, `point_outofline.hpp`, `main.cpp`, sous-dossier bonus `TP4_Exo4_Bonus/`

### 5️⃣ [TP5 : Exercices de Synthèse C++](./TP5)
- **Notions** : Pointeurs, références, portée des variables et mécanismes de passage de paramètres.
- **Fichiers** : `main.cpp`

### 6️⃣ [TP6 : Polymorphisme & Méthodes Virtuelles Pures](./TP6)
- **Notions** : Polymorphisme, classes abstraites, méthodes virtuelles pures (`virtual void parler() = 0`), liaisons dynamiques (`felin`, `oiseau`, `vertebre`).
- **Fichiers** : `vertebre.hpp/cpp`, `oiseau.hpp/cpp`, `felin.hpp/cpp`, `main.cpp`

### 7️⃣ [TP7 : Conteneurs STL & Itérateurs (Gestion de Comptes Bancaires)](./TP7)
- **Notions** : Manipulation des conteneurs de la STL (`std::vector`, `std::list`, `std::map`), itérateurs et algorithmes génériques appliqués à la gestion de comptes (`Compte`, `LivretA`).
- **Sous-dossiers** :
  - `vector_index/` : Accès direct par indice
  - `vector_iterator/` : Parcours par itérateur
  - `list/` : Utilisation de listes doublement chaînées
  - `map/` : Conteneur associatif clé-valeur (`std::map`)

---

## 🛠️ Instructions de Compilation

Pour compiler et exécuter n'importe quel TP (ex. TP2) :
```bash
cd TP2
g++ -std=c++17 main.cpp vecteur.cpp matrice.cpp puissance.cpp -o tp2_exec
./tp2_exec
```
