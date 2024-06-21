%module grafo

%{
#include "grafo.h"
%}

%include "std_vector.i"

%template(vecint) std::vector<int>;
%template(vecvecint) std::vector<std::vector<int>>;

%include "grafo.h"