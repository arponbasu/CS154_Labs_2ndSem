min([],0).
min([X],X).
min([H1,H2|C],M) :- H1=<H2, min([H1|C],M).
min([H1,H2|C],M) :- H2=<H1, min([H2|C],M).

% PRESS ENTER AFTER GETTING OUTPUT
