# Module : Outils de Calculs Scientifiques (OCS)

Ce dossier regroupe les projets et travaux pratiques d'Outils de Calculs Scientifiques (MAM3) combinant la programmation en **C** et les simulations en **MATLAB**.

---

## 📂 Contenu des Travaux Pratiques

### 1️⃣ [TT1OCS : Évaluation de Programmation C](./TT1OCS)
- **Description** : Implémentation en C d'algorithmes de calcul numérique et d'analyse de données scientifiques.
- **Fichiers** :
  - `SERIGNE_DAME_GADIAGATp_noté_de OCS.c` : Code source C.
  - `SERIGNE_DAME_GADIAGATp_noté_de OCS.txt` : Résultats et compte-rendu.

### 2️⃣ [TT OCS Matlab de Serigne Dame GADIAGA MAM3 2023-2024](./TT%20OCS%20Matlab%20de%20Serigne%20Dame%20GADIAGA%20MAM3%202023-2024)
- **Description** : Modélisation de systèmes dynamiques, équations différentielles ordinaires (EDO) et représentations graphiques vectorielles.
- **Thématiques & Scripts** :
  - **Schémas d'intégration numérique** :
    - `EEx.m` : Schéma d'Euler Explicite.
    - `EIm.m` : Schéma d'Euler Implicite.
    - `1erpartiett2matlabserignedameGADIAGA.m` & `2emepartiett2matlabserignedameGADIAGA.m` : Analyses théoriques et numériques.
  - **Modèles de Systèmes Dynamiques** :
    - `Equation_Lotka_Volterra.m` : Modèle de prédateur-proie de Lotka-Volterra.
    - `invasion_des_zombies.m` : Modélisation mathématique d'une épidémie/invasion zombie.
  - **Graphiques vectoriels générés** :
    - `euler.eps`, `euler-implicite.eps`, `euler-perturbe.eps`, `graphe_exo2.eps`, `graphe_exo3.eps`.
  - **Rapport Théorique** :
    - `partietheoriquettocsmatlabserignedameGADIAGA.pdf`

---

## 🛠️ Instructions d'Exécution

- **Pour les fichiers C** :
  ```bash
  gcc TT1OCS/SERIGNE_DAME_GADIAGATp_noté_de\ OCS.c -o ocs_c -lm
  ./ocs_c
  ```
- **Pour les scripts MATLAB** :
  Ouvrir MATLAB ou GNU Octave et exécuter les scripts `.m`.
