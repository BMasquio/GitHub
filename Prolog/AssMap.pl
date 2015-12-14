color(green).
color(blue).
color(yellow).
color(red).

neighbor(StateAColor, StateBColor) :-
color(StateAColor), color(StateBColor), StateAColor \= StateBColor.

germany(SH, MV, HH, HB, NI, BE, NW, ST, BB, RP, HE, TH, SN, SL, BW, BY) :- 
neighbor(BW, BY), neighbor(TH, BY), neighbor(HE, BY), neighbor(HE, TH),
neighbor(HE, BW), neighbor(RP, BW), neighbor(RP, HE), neighbor(RP, SL),
neighbor(SN, BY), neighbor(SN, TH), neighbor(NW, RP), neighbor(NW, HE),
neighbor(BB, SN), neighbor(BB, BE), neighbor(ST, TH), neighbor(ST, SN),
neighbor(ST, BB), neighbor(NI, NW), neighbor(NI, HE), neighbor(NI, TH),
neighbor(NI, ST), neighbor(NI, BB), neighbor(NI, HB), neighbor(MV, BB),
neighbor(MV, NI), neighbor(HH, NI), neighbor(SH, MV), neighbor(SH, HH),
neighbor(SH, NI).