factorial(0, 1).
factorial(N, X) :- M is N - 1, factorial(M, Y), X is Y * N.
% Ask query as factorial(4,X) (to get output 24), AND then PRESS ENTER.
