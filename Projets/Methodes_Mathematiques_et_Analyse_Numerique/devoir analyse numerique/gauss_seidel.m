function [u, res, resn] = gauss_seidel(A, b, x0, niter)
    L = tril(A, -1);
    U = triu(A, 1);
    D = diag(diag(A));
    sol = A \ b; % solution de référence
    u = x0;
    res = [x0];
    resn = [norm(x0 - sol)];
    
    for k = 1:niter
        u = (D - L) \ (U * u + b);
        res = [res u];
        resn = [resn norm(u - sol)];
    end
end

% Test de la fonction gauss_seidel
A=[1 0.1 0.01 0.001 0.001; 1 1 1 1 1; 1 1.5 2.25 3.375 5.0625; 1 2 4 8 16; 1 3 9 27 81];
b = [1 1.5 2.25 3.375 5.0625]’;
x0 = [1 1 1 1 1 ];
niter = 50;

[u_gs, res_gs, resn_gs] = gauss_seidel(A, b, x0, niter);

% Affichage des résultats
disp('Solution finale (Gauss-Seidel) :');
disp(u_gs);

disp('Solutions intermédiaires (Gauss-Seidel) :');
disp(res_gs);

disp('Normes des résidus (Gauss-Seidel) :');
disp(resn_gs);
figure(1)
plot(rap)
legend(’A vous de remplir’)
xlabel(’Nombre d iterations’)
figure(2)
semilogy(resn)
legend(’A vous de remplir’)
xlabel(’Nombre d iterations’)
%la méthode de Gauss-Seidel converge généralement plus rapidement que la méthode de Jacobi, mais cela dépend de la structure de la matrice 
A.
