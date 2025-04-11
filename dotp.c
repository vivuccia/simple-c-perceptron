#include <stdio.h>

double inputvector[2] = {1.53, 0.15};
double weight1[2] = {1.66, -0.35};

double dotp(double *a, double *b) {
    return a[0] * b[0] + a[1] * b[1];
}

int main(){
printf("%lf\n", dotp(inputvector, weight1));
return 0;
}

// Lost original file but was approximately like this
