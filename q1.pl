primo(X, N):-
  X =:= 1;
  N > 1,
  \+ X =:= 0, 
  Res is N mod X,
  \+ Res =:= 0,
  primo(X - 1, N).

primo(N):-
  primo(N-1, N).

primos([]).

primos([X | Y]):-
  primo(X),
  primos(Y).