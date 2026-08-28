alf = 0.05;
bet = 0.0005;
delt = 0.0005;
gam = 0.2;
l0 = 1500; 
r0 = 100; 
t0 = 0;
t_max = 600;
dt = 1;
dldt = @(l, r) l * (alpha - bet * r);
drdt = @(l, r) r * (delt * l - gam);
runge_kutta = @(h, l, r) [...
    h * dldt(l, r);...
    h * drdt(l, r)];
times = t0:dt:t_max;
pops = zeros(2, numel(times));
pops(:, 1) = [l0; r0];
for i = 2:numel(times)
    k1 = runge_kutta(dt, pops(1, i-1), pops(2, i-1));
    k2 = runge_kutta(dt, pops(1, i-1) + 0.5 * k1(1), pops(2, i-1) + 0.5 * k1(2));
    k3 = runge_kutta(dt, pops(1, i-1) + 0.5 * k2(1), pops(2, i-1) + 0.5 * k2(2));
    k4 = runge_kutta(dt, pops(1, i-1) + k3(1), pops(2, i-1) + k3(2));

    pops(:, i) = pops(:, i-1) + (k1 + 2*k2 + 2*k3 + k4) / 6;
end
figure;
plot(times, pops(1, :), 'b', 'LineWidth', 2, 'DisplayName', 'Lapins');
hold on;
plot(times, pops(2, :), 'r', 'LineWidth', 2, 'DisplayName', 'Renards');
xlabel('Temps');
ylabel('pop');
title('Évolution des pops de lapins et de renards');
legend('Location', 'Best');
grid on;
hold off;
