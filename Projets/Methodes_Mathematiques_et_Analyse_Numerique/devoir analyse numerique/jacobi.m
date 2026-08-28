function [u, res, resn] = jacobi(A, b, x0, niter)
    D = diag(diag(A));
    E = -tril(A, -1);
    F = -triu(A, 1);
    sol = A \ b; % solution de référence
    u = x0; 
    res = [x0]; 
    resn = [norm(x0 - sol)];
    for k = 1:niter
        u = D* inv((E + F) * u + b);
        res = [res u];
        resn = [resn norm(u - sol)];
    end
end

% Test de la fonction jacobi
A=[1 0.1 0.01 0.001 0.001; 1 1 1 1 1; 1 1.5 2.25 3.375 5.0625; 1 2 4 8 16; 1 3 9 27 81];
b =[1 1.5 2.25 3.375 5.0625]’;
x0 = [1 1 1 1 1 ]';
niter = 50;

[u, res, resn] = jacobi(A, b, x0, niter);

% Affichage des résultats
disp('Solution finale :');
disp(u);

disp('Solutions intermédiaires :');
disp(res);

disp('Normes des résidus :');
disp(resn);
figure(1)
plot(rap)
legend(’A vous de remplir’)
xlabel(’Nombre d iterations’)
figure(2)
semilogy(resn)
legend(’A vous de remplir’)
xlabel(’Nombre d iterations’)
%La variable `resn` contient les normes des résidus à chaque itération de la méthode itérative de Jacobi, permettant d'évaluer la convergence de la méthode vers la solution du système linéaire.


