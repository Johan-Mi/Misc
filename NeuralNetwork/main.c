#include <stdlib.h>
#include <math.h>

float sigmoid(float x) {
	return 1 / (1 + exp(x));
}

float sigmoidDerivative(float x) {
/*
	
*/
}

typedef struct {
	float activation;
	float bias;
	unsigned connectionCount;
	float* weights;
} Neuron;

Neuron makeNeuron(float activation, float bias, unsigned connectionCount) {
	return (Neuron){activation, bias, connectionCount, malloc(connectionCount * sizeof(float))};
}

typedef struct {
	unsigned size;
	Neuron* neurons;
} Layer;

Layer makeLayer(unsigned size) {
	return (Layer){size, malloc(size * sizeof(Layer))};
}

void deleteLayer(Layer* layer)  {
	if(layer->neurons) {
		free(layer->neurons);
		layer->neurons = NULL;
	}
}

typedef struct {
	unsigned layerCount;
	Layer* layers;
} NeuralNet;

NeuralNet makeNeuralNet(unsigned layerCount) {
	return (NeuralNet){layerCount, malloc(layerCount * sizeof(Layer))};
}

void deleteNeuralNet(NeuralNet* net) {
	if(net->layers) {
		free(net->layers);
		net->layers = NULL;
	}
}

int main() {


	return EXIT_SUCCESS;
}
