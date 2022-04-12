#ifndef CODE_SWAP_H
#define CODE_SWAP_H

#define Swap(X, Y)  do{ __typeof__ (X) _T = X; X = Y; Y = _T; }while(0)

#endif //CODE_SWAP_H
