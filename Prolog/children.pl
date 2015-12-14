hint11([(_,Aburt,fountain,burntsienna)|_], Aburt).
hint11([(_,Aburt,peacock,burntsienna)|_], Aburt).
hint11([(_,Aburt,rainbow,burntsienna)|_], Aburt).
hint11([(_,Aburt,sunset,burntsienna)|_], Aburt).
hint11([_|T], Aburt) :- hint11(T, Aburt).
hint11([],_) :- false.

hint12([(_,Amauve,_,mauve)|_], Amauve).
hint12([_|T], Amauve) :- hint12(T, Amauve).
hint12([],_) :- false.

hint21([(joyce,Ajoyce,_,_)|_], Ajoyce).
hint21([_|T], Ajoyce) :- hint21(T, Ajoyce).
hint21([],_) :- false.

hint22([(_,Arainbow,rainbow,_)|_], Arainbow).
hint22([_|T], Arainbow) :- hint22(T, Arainbow).
hint22([],_) :- false.

hint23([(_,Afountain,fountain,_)|_], Afountain).
hint23([_|T], Afountain) :- hint23(T, Afountain).
hint23([],_) :- false.

hint31([(_,Apeacock,peacock,_)|_], Apeacock).
hint31([_|T], Apeacock) :- hint31(T, Apeacock).
hint31([],_) :- false.

hint32([(mindy,Amindy,_,_)|_], Amindy).
hint32([_|T], Amindy) :- hint32(T, Amindy).
hint32([],_) :- false.

hint33([(_,Aseagreen,_,seagreen)|_], Aseagreen).
hint33([_|T], Aseagreen) :- hint33(T, Aseagreen).
hint33([],_) :- false.

hint41([(_,Acerulean,_,cerulean)|_], Acerulean).
hint41([_|T], Acerulean) :- hint41(T, Acerulean).
hint41([],_) :- false.

hint42([(_,Asunset,sunset,_)|_], Asunset).
hint42([_|T], Asunset) :- hint42(T, Asunset).
hint42([],_) :- false.

hint51([(neil,Aneil,_,_)|_], Aneil).
hint51([_|T], Aneil) :- hint51(T, Aneil).
hint51([],_) :- false.

hint52([(jason,Ajason,_,_)|_], Ajason).
hint52([_|T], Ajason) :- hint52(T, Ajason).
hint52([],_) :- false.

hint53([(_,Agoldenrod,_,goldenrod)|_], Agoldenrod).
hint53([_|T], Agoldenrod) :- hint53(T, Agoldenrod).
hint53([],_) :- false.

age([(_,6,_,_),(_,7,_,_),(_,8,_,_),(_,9,_,_),(_,10,_,_)]).

child1([(amanda,_,_,_)|_]).
child1([_|T]) :- child1(T).
child1([]) :- false.

child2([(jason,_,_,_)|_]).
child2([_|T]) :- child2(T).
child2([]) :- false.

child3([(joyce,_,_,_)|_]).
child3([_|T]) :- child3(T).
child3([]) :- false.

child4([(mindy,_,_,_)|_]).
child4([_|T]) :- child4(T).
child4([]) :- false.

child5([(neil,_,_,_)|_]).
child5([_|T]) :- child5(T).
child5([]) :- false.

picture1([(_,_,flowers,_)|_]).
picture1([_|T]) :- picture1(T).
picture1([]) :- false.

picture2([(_,_,fountain,_)|_]).
picture2([_|T]) :- picture2(T).
picture2([]) :- false.

picture3([(_,_,peacock,_)|_]).
picture3([_|T]) :- picture3(T).
picture3([]) :- false.

picture4([(_,_,rainbow,_)|_]).
picture4([_|T]) :- picture4(T).
picture4([]) :- false.

picture5([(_,_,sunset,_)|_]).
picture5([_|T]) :- picture5(T).
picture5([]) :- false.

crayon1([(_,_,_,burntsienna)|_]).
crayon1([_|T]) :- crayon1(T).
crayon1([]) :- false.

crayon2([(_,_,_,cerulean)|_]).
crayon2([_|T]) :- crayon2(T).
crayon2([]) :- false.

crayon3([(_,_,_,goldenrod)|_]).
crayon3([_|T]) :- crayon3(T).
crayon3([]) :- false.

crayon4([(_,_,_,mauve)|_]).
crayon4([_|T]) :- crayon4(T).
crayon4([]) :- false.

crayon5([(_,_,_,seagreen)|_]).
crayon5([_|T]) :- crayon5(T).
crayon5([]) :- false.


solve(Children) :-
	age(Children),
    child1(Children), child2(Children), child3(Children),
    child4(Children), child5(Children),
    
    picture1(Children), picture2(Children), picture3(Children),
    picture4(Children), picture5(Children),
    
    crayon1(Children), crayon2(Children), crayon3(Children),
    crayon4(Children), crayon5(Children),
    
    hint11(Children, Aburt),
    hint12(Children, Amauve),

    hint21(Children, Ajoyce),
    hint22(Children, Arainbow),
    hint23(Children, Afountain),

    hint31(Children, Apeacock),
    hint32(Children, Amindy),
    hint33(Children, Aseagreen),

    hint41(Children, Acerulean),
    hint42(Children, Asunset),

    hint51(Children, Aneil),
    hint52(Children, Ajason),
    hint53(Children, Agoldenrod),
    Aburt<Amauve,
    Ajoyce>Arainbow, Ajoyce<Afountain,
    Apeacock>Amindy, Apeacock<Aseagreen,
    Asunset<Acerulean, Asunset>Amauve,
    Aneil>Ajason, (Aneil+1)<Agoldenrod.

%Make the query solve(Children) to have the result