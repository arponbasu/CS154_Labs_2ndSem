rev([],X,X).
rev([H|T],X,Y):-rev(T,[H|X],Y).

append(L1,L2,Z):-rev(R,L2,Z), R is rev(L1,[],Z).
