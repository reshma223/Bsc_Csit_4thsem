% Facts
likes(john, pizza).
likes(john, burger).
likes(john, ice_cream).
likes(mary, pizza).
likes(mary, salad).
likes(mary, ice_cream).

% Rules
friend(X, Y) :- likes(X, Z), likes(Y, Z), X \= Y.

% Queries
?- likes(john, pizza).     % Query: Does John like pizza?
?- friend(john, mary).     % Query: Are John and Mary friends?

