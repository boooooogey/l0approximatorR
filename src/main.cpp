// [[Rcpp::depends(BH)]]
#include "squarederror.hpp"
#include "poissonerror.hpp"
#include "exponentialerror.hpp"
#include "piecewisefunction.hpp"
#include "range.hpp"
#include "util.hpp"
#include <Rcpp.h>

using namespace Rcpp;

//[[Rcpp::export]]
NumericVector L0PoissonApproximate(NumericVector y, NumericVector l, NumericVector w){
    int n = y.size();
    NumericVector x = NumericVector(n);
    approximate<PoissonError>(n, y.begin(), l.begin(), w.begin(), x.begin());
    return x;
}

//[[Rcpp::export]]
NumericVector L0GaussianApproximate(NumericVector y, NumericVector l, NumericVector w){
    int n = y.size();
    NumericVector x = NumericVector(n);
    approximate<SquaredError>(n, y.begin(), l.begin(), w.begin(), x.begin());
    return x;
}

//[[Rcpp::export]]
NumericVector L0ExponentialApproximate(NumericVector y, NumericVector l, NumericVector w){
    int n = y.size();
    NumericVector x = NumericVector(n);
    approximate<PoissonError>(n, y.begin(), l.begin(), w.begin(), x.begin());
    return x;
}

//[[Rcpp::export]]
NumericVector L0PoissonApproximateN(NumericVector y, int N, NumericVector w){
    int n = y.size();
    NumericVector x = NumericVector(n);
    approximate<PoissonError>(n, y.begin(), N, w.begin(), x.begin());
    return x;
}

//[[Rcpp::export]]
NumericVector L0GaussianApproximateN(NumericVector y, int N, NumericVector w){
    int n = y.size();
    NumericVector x = NumericVector(n);
    approximate<SquaredError>(n, y.begin(), N, w.begin(), x.begin());
    return x;
}

//[[Rcpp::export]]
NumericVector L0ExponentialApproximateN(NumericVector y, int N, NumericVector w){
    int n = y.size();
    NumericVector x = NumericVector(n);
    approximate<PoissonError>(n, y.begin(), N, w.begin(), x.begin());
    return x;
}
