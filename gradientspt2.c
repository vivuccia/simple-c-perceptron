#include <stdio.h>
#include <math.h>

#define LIMIT 10

double learnrate = 0.1;

double inputvector[2] = {1.53, 0.15};
double weight1[2] = {1.66, -0.35};
double bias = 0.0;

double dotp(double *a, double *b) {
    return a[0] * b[0] + a[1] * b[1];
}

/*Calculates the dot product between input vectors*/

double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

double dsigmoid(double x){
	return sigmoid(x)*(1-sigmoid(x));
}

/*Calculates the sigmoid function and its derivative (dsigmoid)*/



double pred(double *x, double *y, double z) {
    double layer_1 = dotp(x, y) + z;
    double layer_2 = sigmoid(layer_1);
    return layer_2;
}

	double prediction, target, dmse, dpred_dlayer1, dlayer1_dbias, dlayer1_dweight1[2], derr_dbias, derr_dweight1[2];
int i;
	/* Define some important doubles for the next function*/
void gradients(double *a, double *b, double *c){

	dmse=2*(prediction-target);
	/*Derivative of MSE*/
	dpred_dlayer1=dsigmoid(pred(inputvector, weight1, bias));
	dlayer1_dbias = 1.0;
	dlayer1_dweight1[0]=(0*weight1[0])+(1*inputvector[0]);
	dlayer1_dweight1[1]=(0*weight1[1])+(1*inputvector[1]);
	derr_dbias=(
			dmse*dpred_dlayer1*dlayer1_dbias
			);
	for(i=0; i<2; ++i){
		derr_dweight1[i]=(
			dmse*dpred_dlayer1*dlayer1_dweight1[i]
			);
	*a = derr_dbias; 
	*b = derr_dweight1[0];
	*c = derr_dweight1[1];
}
}
void update_parameters(double a, double b, double c){
	bias = bias-(a*learnrate);
	weight1[0]=weight1[0]-(weight1[0]*learnrate);
	weight1[1]=weight1[1]-(weight1[1]*learnrate);	
}

double gbias, weight1_0, weight1_1;

int main() {
	target = 0.12421;
	for(i=0;i<LIMIT;++i){
		prediction =  pred(inputvector, weight1, bias);
		double target = 0.0;

		double mse = pow((prediction-target), 2);
		double dmse = 2*(prediction-target);
	/* Calculates error using MSE and its derivative (dmse)*/
				
	
		printf("Prediction: %f\n", prediction);
		printf("MSE: %f\n", mse);
   		gradients(&gbias, &weight1_0, &weight1_1);
		update_parameters(gbias, weight1_0, weight1_1);

	}
return 0;
}

