# Module : Méthodes Mathématiques & Analyse Numérique

Ce dossier rassemble les algorithmes de résolution numérique et les devoirs de mathématiques pour ingénieur développés sous MATLAB.

---

## 📂 Contenu du Dossier

| Sous-dossier | Description & Contenu | Fichiers | Langage / Format |
| :--- | :--- | :--- | :--- |
| **`devoir analyse numerique/`** | Implémentation des méthodes itératives de résolution de systèmes linéaires $Ax = b$. | `jacobi.m` (Méthode de Jacobi)<br>`gauss_seidel.m` (Méthode de Gauss-Seidel)<br>`jacobigauss.m` (Comparaison Jacobi vs Gauss-Seidel) | MATLAB / Octave |
| **`TT2_de_Methode Mathematique pour Ingenieur.../`** | Rapport d'évaluation et devoir de Mathématiques Appliquées pour l'Ingénieur. | `20240208_080140.pdf` | Rapport PDF |

---

## 💡 Principes Mathématiques Réalisés

1. **Méthode de Jacobi** :
   Décomposition de la matrice $A = D - L - U$.
   Calcul de l'itération : $x^{(k+1)} = D^{-1}(b + (L+U)x^{(k)})$.

2. **Méthode de Gauss-Seidel** :
   Utilisation des valeurs déjà mises à jour dans la même itération :
   $x^{(k+1)} = (D-L)^{-1}(b + U x^{(k)})$.

3. **Analyse de Convergence** :
   Étude du rayon spectral des matrices d'itération $\rho(B_J)$ et $\rho(B_{GS})$ pour garantir la convergence vers la solution exacte.
