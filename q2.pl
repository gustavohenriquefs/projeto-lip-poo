
n_esimo(0, [A|_], A).

n_esimo(N, L, X):-
  N > 0,
  N2 is N - 1,
  n_esimo(N2, L, X).