#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "vectorio.h"
#include "settings.h"

double weight[2] = {1.66, -0.35};
double bias = 0.0;

double dotp(double *a, double *b) {
    return a[0] * b[0] + a[1] * b[1];
}

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

double dsigmoid(double x){
	return sigmoid(x)*(1-sigmoid(x));
}
double predict(double *input) {
    return sigmoid(dotp(input, weight) + bias);
}

void compute_gradients(double *input, double target,
                       double *dbias, double *dweight0, double *dweight1,
                       double prediction) {

    double layer1 = dotp(input, weight) + bias;
    double dmse = 2 * (prediction - target);
    double dpred = dsigmoid(layer1);
    double common = dmse * dpred;

    *dbias = common;
    *dweight0 = common * input[0];
    *dweight1 = common * input[1];
}

void update_parameters(double dbias, double dw0, double dw1) {
    bias -= learnRate * dbias;
    weight[0] -= learnRate * dw0;
    weight[1] -= learnRate * dw1;
}

int main() {
	loadSettings("settings.ini");
	vectors arr;
	initArray(&arr);
	readFile(&arr);

	for (size_t i = 0; i < arr.size; ++i) {
        	double input[2] = { arr.data[i].x, arr.data[i].y };
        	double prediction;
        	double dbias, dw0, dw1;

        	int iter = 0;
        	bool hasConverged = false;

        while (!hasConverged && iter < maxIterations) {
            prediction = predict(input);

            if (fabs(prediction - target) < 1e-6) {
                hasConverged = true;
                break;
            }

            compute_gradients(input, target, &dbias, &dw0, &dw1, prediction);
            update_parameters(dbias, dw0, dw1);

            ++iter;
        }

        printf("Vector %zu => Final prediction: %.6f (after %d iterations)\n", i+1, prediction, iter);
    }

    freeArray(&arr);
    return 0;

}
