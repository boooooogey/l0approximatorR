checkparams <- function(l, w, n){

    if( length(l) != n-1 && length(l) != 1 ) stop(paste0("The length of the lambda vector should be either 1 or ", n-1, "."))

    if( any( l < 0 ) ) stop("Lambda cannot be negative.")
    
    if( !is.null(w) ){
        if( length(w) != n && length(w) != 1 ) stop(paste0("The length of the weight vector should be either 1 or ", n, "."))
        if( any( w < 0 ) ) stop("Weight cannot be negative.")
    }
    else{
        w = 1
    }

    if(length(l) == 1){
        lambda = rep(l,n-1)
    }

    if(length(w) == 1){
        weight = rep(w, n)
    }

    return(list(lambda = lambda, weight = weight))

}

L0Gaussian <- function(y, lambda, weight = NULL){
    n = length(y)
    params = checkparams(lambda, weight, n)
    lambda = params[['lambda']]
    weight = params[['weight']]
    x = L0GaussianApproximate(y, lambda, weight)
    return(x)
}

L0GaussianN <- function(y, N = 2, weight = NULL){
    n = length(y)
    params = checkparams(1, weight, n)
    lambda = params[['lambda']]
    weight = params[['weight']]
    x = L0GaussianApproximateN(y, N, weight)
    return(x)
}

L0Poisson <- function(y, lambda, weight = NULL){
    n = length(y)
    params = checkparams(lambda, weight, n)
    lambda = params[['lambda']]
    weight = params[['weight']]
    x = L0PoissonApproximate(y, lambda, weight)
    return(x)
}

L0PoissonN <- function(y, N = 2, weight = NULL){
    n = length(y)
    params = checkparams(1, weight, n)
    lambda = params[['lambda']]
    weight = params[['weight']]
    x = L0PoissonApproximateN(y, N, weight)
    return(x)
}

L0Exponential <- function(y, lambda, weight = NULL){
    n = length(y)
    params = checkparams(lambda, weight, n)
    lambda = params[['lambda']]
    weight = params[['weight']]
    x = L0ExponentialApproximate(y, lambda, weight)
    return(x)
}

L0ExponentialN <- function(y, N = 2, weight = NULL){
    n = length(y)
    params = checkparams(1, weight, n)
    lambda = params[['lambda']]
    weight = params[['weight']]
    x = L0ExponentialApproximateN(y, N, weight)
    return(x)
}
