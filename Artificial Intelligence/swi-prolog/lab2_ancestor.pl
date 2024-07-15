female(anjali).
female(anisha).
female(laxmi).
male(santosh).
male(san).
male(raj).
male(mahesh).
parent(laxmi,anjali).
parent(laxmi,anisha).
parent(santosh,anjali).
parent(santosh,raj).
parent(santosh,mahesh).
parent(san,santosh).
mother(M,C):-parent(M,C),female(M).
father(F,C):-parent(F,C),male(F).
grandparent(GP,GC):-parent(GP,X),parent(X,GC).
ancestor(A,D):-parent(A,D).




