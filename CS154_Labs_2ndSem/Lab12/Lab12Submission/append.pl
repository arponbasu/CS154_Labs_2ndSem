rev([],X,X).
rev([H|T],X,Y):-rev(T,[H|X],Y).

myapp(L1,L2,Q):-rev(R,L2,Q), R is rev(L1,[],Q).
