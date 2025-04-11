#include <stdio.h>
#include <math.h>

double inputvector[2] = {1.53, 0.15};
double weight1[2] = {1.66, -0.35};
double bias[2] = {0, 0};

double dotp(double *a, double *b) {
    return a[0] * b[0] + a[1] * b[1];
}

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

double pred(double *x, double *y, double z) {
    double layer_1 = dotp(x, y) + z;
    double layer_2 = sigmoid(layer_1);
    return layer_2;
}

int main() {
	double prediction =  pred(inputvector, weight1, bias[0]);
	double target = 0.0;
	double mse = pow((prediction-target), 2);
	printf("%f\t%f\n", prediction, mse);
    	return 0;
}
