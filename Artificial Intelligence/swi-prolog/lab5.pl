factorial(0, 1).
factorial(N, Result) :-
    N > 0,
    M is N - 1,
    factorial(M, SubResult),
    Result is N * SubResult.
