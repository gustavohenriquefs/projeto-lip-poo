
tamanho([], X):-
  X =:= 0.

tamanho([_ | B], X):-
  tamanho(B, X - 1).