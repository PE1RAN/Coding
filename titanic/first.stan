//
// This Stan program defines a simple model, with a
// vector of values 'y' modeled as normally distributed
// with mean 'mu' and standard deviation 'sigma'.
//
// Learn more about model development with Stan at:
//
//    http://mc-stan.org/users/interfaces/rstan.html
//    https://github.com/stan-dev/rstan/wiki/RStan-Getting-Started
//

// The input data is a vector 'y' of length 'N'.
data {
  int<lower=0> N;
  int<lower=0> n;
  int<lower=0,upper=1> vive_train[N];
  int<lower=0,upper=1> class1_train[N];
  int<lower=0,upper=1> class1_test[n];
  int<lower=0,upper=1> class2_train[N];
  int<lower=0,upper=1> class2_test[n];
  int<lower=0,upper=1> sex_train[N];
  int<lower=0,upper=1> sex_test[n];
  real age_train[N];
  real age_test[n];
  //real family_train[N];
  //real family_test[n];
  /*
  int<lower=0,upper=1> young_train[N];
  int<lower=0,upper=1> young_test[n];
  int<lower=0,upper=1> old_train[N];
  int<lower=0,upper=1> old_test[n];
  */
}
/*
// The parameters accepted by the model. Our model
// accepts two parameters 'mu' and 'sigma'.
parameters {
  real beta[5];
  real sigma;
  real regr_temp[N];
  real pred_temp[n];
}

transformed parameters {
  real train[N];
  real test[n];
  real<lower=0,upper=1> regr[N];
  real<lower=0,upper=1> pred[n];
  for (i in 1:N) {
    train[i] = beta[1] + beta[2]*class1_train[i] + beta[3]*class2_train[i] + beta[4]*sex_train[i] + beta[5]*age_train[i];// + beta[6]*family_train[i]);// + beta[6]*old_train[i]);// + beta[6]*sib_train[i] + beta[7]*pch_train[i]);
    regr[i] = inv_logit(regr_temp[i]);  
  }
  for (i in 1:n) {
    test[i] = beta[1] + beta[2]*class1_test[i] + beta[3]*class2_test[i] + beta[4]*sex_test[i] + beta[5]*age_test[i];// + beta[6]*family_test[i]);// + beta[6]*old_test[i]);// + beta[6]*sib_test[i] + beta[7]*pch_test[i]);
    pred[i] = inv_logit(pred_temp[i]); 
  }
}

// The model to be estimated. We model the output
// 'y' to be normally distributed with mean 'mu'
// and standard deviation 'sigma'.
model {
  for (i in 1:N) {
    regr_temp[i] ~ normal(train, sigma);
    vive_train[i] ~ bernoulli(regr[i]);
    //if (regr[i] > 0.5) vive_train ~ bernoulli(1);
    //else vive_train ~ bernoulli(0);
  }
  for (i in 1:n) {
    pred_temp ~normal(test,sigma);
  }
}
*/

parameters {
  real intercept;
  real Pclass[2];
  real Sex_Male;
  real Age;
}

transformed parameters {
  real<lower=0,upper=1> regr[N];
  real<lower=0,upper=1> pred[n];
  for (i in 1:N) {
    regr[i] = inv_logit(intercept + Pclass[1]*class1_train[i] + Pclass[2]*class2_train[i] + Sex_Male*sex_train[i] + Age*age_train[i]);// + beta[6]*family_train[i]);// + beta[6]*old_train[i]);// + beta[6]*sib_train[i] + beta[7]*pch_train[i]);
    }
  for (i in 1:n) {
    pred[i] = inv_logit(intercept + Pclass[1]*class1_test[i] + Pclass[2]*class2_test[i] + Sex_Male*sex_test[i] + Age*age_test[i]);// + beta[6]*family_test[i]);// + beta[6]*old_test[i]);// + beta[6]*sib_test[i] + beta[7]*pch_test[i]);
    //pred[i] = inv_logit(pred_temp[i]); 
  }
}

// The model to be estimated. We model the output
// 'y' to be normally distributed with mean 'mu'
// and standard deviation 'sigma'.
model {
  intercept ~ normal(0,1);
  Pclass[1] ~ normal(0,1);
  Pclass[2] ~ normal(0,1);
  Sex_Male ~ normal(0,1);
  Age ~ normal(0,1);
  for (i in 1:N) {
    //regr_temp[i] ~ normal(train, sigma);
    vive_train[i] ~ bernoulli(regr[i]);
    //if (regr[i] > 0.5) vive_train ~ bernoulli(1);
    //else vive_train ~ bernoulli(0);
  }
}


