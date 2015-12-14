girl(ally).
girl(becky).
girl(molly).
girl(norma).
girl(tess).

witch(hortense).
witch(lucretia).
witch(magdalene).
witch(persimmon).
witch(tabitha).

lesson(crackle).
lesson(cauldron).
lesson(fly).
lesson(potions).
lesson(spells).

hint1([(becky,lucretia,_)|_]).
hint1([(becky,magdalene,_)|_]).
hint1([(becky,tabitha,_)|_]).
hint1([_|T]) :- hint1(T).

hint21([(_,persimmon,crackle)|_]).
hint21([(_,persimmon,cauldron)|_]).
hint21([(_,persimmon,fly)|_]).
hint21([(_,persimmon,spells)|_]).
hint21([_|T]) :- hint21(T).

hint22([(_,hortense,crackle)|_]).
hint22([(_,hortense,fly)|_]).
hint22([(_,hortense,potions)|_]).
hint22([(_,hortense,spells)|_]).
hint22([_|T]) :- hint22(T).

hint31([(molly,hortense,_)|_]).
hint31([(molly,persimmon,_)|_]).
hint31([(molly,tabitha,_)|_]).
hint31([_|T]) :- hint31(T).

hint32([(becky,hortense,_)|_]).
hint32([(becky,persimmon,_)|_]).
hint32([(becky,tabitha,_)|_]).
hint32([_|T]) :- hint32(T).

hint33([(norma,hortense,_)|_]).
hint33([(norma,persimmon,_)|_]).
hint33([(norma,tabitha,_)|_]).
hint33([_|T]) :- hint33(T).

hint4([(ally,hortense,_)|_]).
hint4([(ally,persimmon,_)|_]).
hint4([(ally,tabitha,_)|_]).
hint4([(ally,magdalene,_)|_]).
hint4([_|T]) :- hint4(T).

hint51([(molly,lucretia,_)|_]).
hint51([(molly,persimmon,_)|_]).
hint51([(molly,tabitha,_)|_]).
hint51([(molly,magdalene,_)|_]).
hint51([_|T]) :- hint51(T).

hint52([(molly,_,crackle)|_]).
hint52([(molly,_,fly)|_]).
hint52([(molly,_,spells)|_]).
hint52([(molly,_,potions)|_]).
hint52([_|T]) :- hint52(T).

hint53([(ally,_,crackle)|_]).
hint53([(ally,_,cauldron)|_]).
hint53([(ally,_,spells)|_]).
hint53([(ally,_,potions)|_]).
hint53([_|T]) :- hint53(T).

hint61([(molly,_,cauldron)|_]).
hint61([(molly,_,spells)|_]).
hint61([(molly,_,potions)|_]).
hint61([_|T]) :- hint61(T).

hint62([(becky,_,cauldron)|_]).
hint62([(becky,_,spells)|_]).
hint62([(becky,_,potions)|_]).
hint62([_|T]) :- hint62(T).

hint63([(norma,_,cauldron)|_]).
hint63([(norma,_,spells)|_]).
hint63([(norma,_,potions)|_]).
hint63([_|T]) :- hint63(T).

question([(ally,W1,L1),(molly,W2,L2),(becky,W3,L3),(tessa,W4,L4),(norma,W5,L5)]) :-
    witch(W1), witch(W2), witch(W3), witch(W4), witch(W5),
    lesson(L1), lesson(L2), lesson(L3), lesson(L4), lesson(L5),
    W1 \= W2, W1 \= W3, W1 \= W4, W1 \= W5,
	W2 \= W3, W2 \= W4, W2 \= W5,
	W3 \= W4, W3 \= W5,
	W4 \= W5,
	L1 \= L2, L1 \= L3, L1 \= L4, L1 \= L5,
	L2 \= L3, L2 \= L4, L2 \= L5,
	L3 \= L4, L3 \= L5,
	L4 \= L5.

solve(Girls) :-
	question(Girls),
	hint1(Girls),
	hint21(Girls),
	hint22(Girls),
	hint31(Girls),
	hint32(Girls),
	hint33(Girls),
	hint4(Girls),
	hint51(Girls),
	hint52(Girls),
	hint53(Girls),
	hint61(Girls),
	hint62(Girls),
	hint63(Girls).

%Make the query solve(Girls) to have the result