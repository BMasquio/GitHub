tall(bob, mike).
tall(mike, jim).
tall(jim, george).

taller(A,B) :- tall(A,B).
taller(A,B) :- tall(A,C), taller(C,B).

%The query should be taller( , )