count([H],[],0).
count([H],[H|T],X):- count([H],T,Y), X is 1+Y.
count([H],[H1|T],Y):- H1 \= H, count([H],T,Y).
