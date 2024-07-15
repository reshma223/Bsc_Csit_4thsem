hanoi(0, _, _, _).
hanoi(N, Source, Destination, Auxiliary) :-
    N > 0,
    M is N - 1,
    hanoi(M, Source, Auxiliary, Destination),
    move(Source, Destination),
    hanoi(M, Auxiliary, Destination, Source).

move(Source, Destination) :-
    write('Move disk from '),
    write(Source),
    write(' to '),
    write(Destination),
    nl.


solve_tower_of_hanoi(NumDisks) :-
    hanoi(NumDisks, left, right, center).factorial(N, Result) :-
    N > 0,
    M is N - 1,
    factorial(M, SubResult),
