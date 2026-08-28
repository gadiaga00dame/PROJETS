A=[1 0.1 0.01 0.001 0.001; 1 1 1 1 1; 1 1.5 2.25 3.375 5.0625; 1 2 4 8 16; 1 3 9 27 81]
D= -diag(diag(A))
E= -tril(A, -1)
F= -triu(A, 1)
% verification
matrice_somme = D - E - F;
if (matrice_somme == A)
    disp('D - E - F est égal à A.');
else
    disp('D - E - F n''est pas égal à A.');
end
----------------------
% il faut que  le rayon spectral de la matrice d'itération B = M−1N vérifie ρ(B) < 1. Dans ce cas, la suite (xk) converge vers x, solution du syst`eme Ax = b
b = [0.01 1 2.25 4 9];

% Matrice d'itération pour Jacobi
M_jacobi = D;
N_jacobi = M_jacobi - A;
B_jacobi = inv(M_jacobi) * N_jacobi;

% Matrice d'itération pour Gauss-Seidel
M_gs = D - E;
N_gs = F;
B_gs = inv(M_gs) * N_gs;

% Calcul du rayon spectral
spectre_jacobi = max(abs(eig(B_jacobi)));
spectre_gs = max(abs(eig(B_gs)));

% Vérification de la convergence
if spectre_jacobi < 1
    disp('La méthode de Jacobi est convergente.');
else
    disp('La méthode de Jacobi n''est pas convergente.');
end

if spectre_gs < 1
    disp('La méthode de Gauss-Seidel est convergente.');
else
    disp('La méthode de Gauss-Seidel n''est pas convergente.');
end
------------------------



