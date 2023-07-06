feminino(rita).

feminino(leidiane).

feminino(lara).

feminino(sara).

feminino(francisca).

feminino(clara).

masculino(carlos).

masculino(leo).

masculino(antonio).

masculino(diato).

masculino(romario).

masculino(adriano).

% ---------------
  
progenitor(X, Y):-
  pai(Pai, Y), Pai = X;
  mae(Mae, Y), Mae = X.

% ---------------

pai(antonio, adriano).

pai(antonio, romario).

pai(antonio, diato).

pai(antonio, rita).

pai(antonio, francisca).

pai(diato, lara).

pai(carlos, leo).

pai(romario, clara).

mae(sara, clara).

mae(leidiane, lara).


% ---------------

irmao(X, Y):-
  (
    pai(Pai, X),
    pai(Pai, Y);
    mae(Mae, X),
    mae(Mae, Y)
  ),
  masculino(X),
  X \= Y.

irma(X, Y):-
  feminino(X),
  (
    pai(Pai, X),
    pai(Pai, Y);
    mae(Mae, X),
    mae(Mae, Y)
  ),
  X \= Y.

% ---------------

tio(X, Y):-
  masculino(X),
  (
    mae(MaeIrma, Y),
    irma(MaeIrma, X)
  ).

tio(X, Y):-
  masculino(X),
  (
    pai(PaiIrmao, Y),
    irmao(PaiIrmao, X)
  ).


tia(X, Y):-
  feminino(X),
  (
    pai(PaiIrmao, Y),
    irmao(PaiIrmao, X)
  ).

tia(X, Y):-
  feminino(X),
  (
    mae(MaeIrma, Y),
    irma(MaeIrma, X)
  ).


% ---------------

avof(X, Y):-
  mae(X, T),
  progenitor(T, Y).

avom(X, Y):-
  pai(X, T),
  progenitor(T, Y).

% ---------------

descendente(X, Y):-
  progenitor(Y, X);
  progenitor(T, X),
  progenitor(Y, T).

% ---------------

primo(X, Y):-
  masculino(X),
  progenitor(T, X),
  progenitor(H, Y),
  (
    irmao(T, H);
    irma(T, H)
  ).

prima(X, Y):-
  feminino(X),
  progenitor(T, X),
  progenitor(H, Y),
  (
    irmao(T, H, 0);
    irma(T, H, 0)
  ).