
pertence([X | _], X).
pertence([_ | Y], Z) :- pertence(Y, Z).

elimina_repetidos([], []).

elimina_repetidos([A | B], L2) :-
    pertence(B, A),
    elimina_repetidos(B, L2).

elimina_repetidos([A | B], [A | L2]) :-
    \+ pertence(B, A),
    elimina_repetidos(B, L2).