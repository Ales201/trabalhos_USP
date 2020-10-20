sexo(jose,homem).
sexo(joao,homem).
sexo(mario,homem).
sexo(carlos,homem).
sexo(maria,mulher).
sexo(ana,mulher).
sexo(helena,mulher).
sexo(joana,mulher).

progenitor(jose,joao).
progenitor(jose,ana).
progenitor(maria,joao).
progenitor(maria,ana).
progenitor(joao,mario).
progenitor(ana,helena).
progenitor(ana,joana).
progenitor(helena,carlos).
progenitor(mario,carlos).


irmao(X,Y):-
    sexo(X,masculino),
    progenitor(M,X),
    progenitor(M,Y),
    X\= Y.
irma(X,Y):-
    sexo(X,mulher),
    progenitor(M,X),
    progenitor(M,Y),
    X\=Y.

descendente(X,Y):-
    progenitor(X,Y).
descendente(X,Y):-
    progenitor(X,Z),
    descendente(Z,Y).

mae(X,Y):-
    sexo(X,mulher),
    progenitor(X,Y).

pai(X,Y):-
    sexo(X,homem),
    progenitor(X,Y).

avo(X,Z):-
    sexo(X,homem),
    progenitor(X,Y),
    progenitor(Y,Z).
avo(X,Z):-
    sexo(X,mulher),
    progenitor(X,Y),
    progenitor(Y,Z).


tio(X,Y):-
    sexo(X,homem),
    progenitor(A,X),
    progenitor(A,Z),
    progenitor(Z,Y).

primo(Y,H):-
    sexo(X,homem),
    progenitor(A,X),
    progenitor(A,Z),
    progenitor(X,Y),
    progenitor(Z,H).









