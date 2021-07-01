#include "util.hpp"

void backtrace(const RangeList& ranges, const double* xprimes, double* solution){
    int n = ranges.len();
    double first, last;
    solution[n-1] = xprimes[n-1];
    for(int i = n-2; i >= 0; i--){
        solution[i] = solution[i+1];
        for(int j = 0; j < ranges.len(i); j++){
            ranges.index(i, j, first, last);
            if(first <= solution[i+1] && solution[i+1] <= last){
                solution[i] = xprimes[i];
                break;
            }
        }
    }
}

void backtrace(const RangeList* ranges, const int& N, const double* xprimes, double* solution){
    int n = ranges[0].len() + 1;
    int T = N - 1;
    double first, last;
    solution[n-1] = xprimes[n*N-1];
    for(int i = n-2; i >= 0; i--){
        solution[i] = solution[i+1];
        for(int j = 0; j < ranges[T].len(i); j++){
            ranges[T].index(i, j, first, last);
            if(first <= solution[i+1] && solution[i+1] <= last){
                solution[i] = xprimes[i*N+T];
                T--;
                break;
            }
        }
    }
}

