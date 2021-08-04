rev([],X,X).
rev([H|T],X,Y):-rev(T,[H|X],Y).
palindrome(L):-rev(L,[],L).
