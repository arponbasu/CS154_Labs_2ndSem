rev([],X,X).
rev([H|T],X,Y):-rev(T,[H|X],Y).
% Ask query as rev([1,2,3,4],[],X) to get [4,3,2,1]

