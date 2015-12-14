male(g11).
male(g12).
male(g21).
male(g14).
male(g13).
male(g22).
male(g31). 
female(g23).
female(g24).
female(g32).
female(g15). 
parent(g21, g11).
parent(g21, g12).
parent(g23, g11).
parent(g23, g12). 
parent(g24, g13).
parent(g24, g14).
parent(g22, g13).
parent(g22, g14). 
parent(g32, g23).
parent(g32, g22).
parent(g31, g23).
parent(g31, g22). 
parent(g22, g15). 

father(F,C) :- male(F), parent(F,C).
mother(M,C) :- female(M), parent(M,C).

brother(B,P) :- male(B), parent(A,B), parent(A,P), B\=P.
sister(S,P) :- female(S), parent(A,S), parent(A,P), S\=P.

uncle(U,P) :- brother(U,X), parent(X,P). aunt(A,P) :- sister(A,X), parent(X,P).

grandfather(G,P) :- father(G,X), parent(X,P). grandmother(G,P) :- mother(G,X), parent(X,P).

cousin(C,P) :- grandfather(G,C), grandfather(G,P), C\=P.
cousin(C,P) :- grandmother(G,C), grandmother(G,P), C\=P.