%SERIGN DAME GADIAGA TT OCS/MATLAB

%partie 2

A = -150;
b = 30;
y0 = 1/5 + 1e-10;
h_values = [0.02, 0.01, 0.001];
T = 1;
figure;
hold on;
for h = h_values
    t = 0:h:T;
    y = EIm(y0, h, T, A, b);
    plot(t, y);
end
legend('h = 0.02', 'h = 0.01', 'h = 0.001');
xlabel('t');
ylabel('y(t)');
title('Graphes des résultats obtenus avec le schéma d''Euler implicite');
hold off;
saveas(gcf, 'euler-implicite.eps', 'epsc');
