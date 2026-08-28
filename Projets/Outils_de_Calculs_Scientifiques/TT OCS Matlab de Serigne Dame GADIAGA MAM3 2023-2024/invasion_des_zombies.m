global alpha beta gamma;
alpha = 0.005;
beta = 0.01;
gamma = 0.02;
h0 = 500;
z0 = 10;
n0 = 0;
T = 100;
dt = 0.1;
num_steps = round(T / dt);
time_points = linspace(0, T, num_steps + 1);
h_values = zeros(1, num_steps + 1);
z_values = zeros(1, num_steps + 1);
n_values = zeros(1, num_steps + 1);
h_values(1) = h0;
z_values(1) = z0;
n_values(1) = n0;
for i = 1:num_steps
    h_values(i + 1) = h_values(i) + dt * h_prime(h_values(i), z_values(i), n_values(i));
    z_values(i + 1) = z_values(i) + dt * z_prime(h_values(i), z_values(i), n_values(i));
    n_values(i + 1) = n_values(i) + dt * n_prime(h_values(i), z_values(i), n_values(i));
end
figure;
plot(time_points, h_values, 'LineWidth', 2, 'DisplayName', 'Humains');
hold on;
plot(time_points, z_values, 'LineWidth', 2, 'DisplayName', 'Zombies');
plot(time_points, n_values, 'LineWidth', 2, 'DisplayName', 'Zombies neutralisés');
xlabel('Temps');
ylabel('Population');
legend();
title('Simulation d''une invasion de zombies');
grid on;
function dh = h_prime(h, z, n)
    global beta;
    dh = -beta * h * z;
end

function dz = z_prime(h, z, n)
    global alpha beta gamma;
    dz = beta * h * z + gamma * n - alpha * h * z;
end

function dn = n_prime(h, z, n)
    global alpha gamma;
    dn = alpha * h * z - gamma * n;
end
