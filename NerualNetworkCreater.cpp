#include <iostream>

#define UP_CAPACITY 10
#define MAX_LAYERS_SIZE 20 // This is number of hidden layers +2

using namespace std;

float activition(float x){
	return x>0.5 ? 1.0f : 0.0f;
}


struct node{
	float *Weights;
	float BiasWeight;
};

class Layer{
	public:
	node **NodesPtr;
	int Capacity;
	int High;
	
	Layer(){
		Capacity = 10;
		High = 0;
		node **TempNodesPtr = (node **)malloc(sizeof(node *) * Capacity);
		NodesPtr = TempNodesPtr;
	}

	bool AddNode(node *Node){
			if(High == Capacity){
				node **TempNodesPtr = (node **)malloc(sizeof(node *) * (Capacity + UP_CAPACITY));
				for(int i=0; i<=High; i++)
					TempNodesPtr[i] = NodesPtr[i];
				Capacity += UP_CAPACITY;
				free(NodesPtr); // delete old
				NodesPtr = TempNodesPtr;
			}
			NodesPtr[High] = Node;
			High++;
			return 1;
		}
};


class Layers{
public:
	Layer **LayersPtr;
	int *LayerSize;
	int High;

	Layers(){
		Layer **TempLayersPtr = (Layer **)malloc(sizeof(Layer *) * MAX_LAYERS_SIZE);
		LayersPtr = TempLayersPtr;
		int *TempLayerSize = (int *)malloc(sizeof(int) * MAX_LAYERS_SIZE);
		LayerSize = TempLayerSize;
		High = 0;
	}

	bool CreateLayer(int NewLayerSize, int PreLayerSize){
//		Layer *NewLayer = (Layer *)malloc(sizeof(Layer));
		Layer *NewLayer =  new Layer();
		for(int i=0; i < NewLayerSize; i++){
//			struct node *NewNode = (struct node *)malloc(sizeof(struct node));
			struct node *NewNode = new node;
			float *NewWeights = (float *)malloc(sizeof(float) * PreLayerSize);
			NewNode->Weights = NewWeights;
			for(int j=0; j < PreLayerSize; j++)
				NewNode->Weights[j] = 0.5f; 					//Node making with 0.5f
			NewNode->BiasWeight = 0.5f;
			NewLayer->AddNode(NewNode); 
		}
		LayersPtr[High] = NewLayer;
		LayerSize[High] = NewLayerSize;
		High++;
		return 1;
	}

	node *GetNodePtr(int i, int j){
		return LayersPtr[i]->NodesPtr[j];
	}

	void PrintNet(){
		for(int i=1; i < High; i++){
			std::cout << "Layer " << i + 1 << "\n";
			for(int j=0; j < LayersPtr[i]->High; j++){ //per node
				std::cout << "\tNode " << j << " weights: ";
				for(int k=0; k < LayersPtr[i - 1]->High; k++){
					std::cout << " " << GetNodePtr(i,j)->Weights[k];
				}
				std::cout << std::endl;
			}
		}
	}

	float *FeedForward(float inp[], int size){
		float *Values = (float *)malloc(sizeof(float) * size);
		for(int i=0; i < size; i++) Values[i]=inp[i];
		
		for(int i=1; i < High; i++){ //layer (starts with layer2)
			float *TempValues = (float *)malloc(sizeof(float) * LayersPtr[i]->High);
			for(int j=0; j < LayersPtr[i]->High; j++){ //per node
				float sum = 0;
				for(int k = 0; k < LayersPtr[i-1]->High; k++){
					sum += Values[k] * GetNodePtr(i, j)->Weights[k];
				}
				sum += 1.0f * GetNodePtr(i, j)->BiasWeight;
				TempValues[j] = sum;
			}
			Values = TempValues;
		}
		return Values;
	}

};

int main(){
	Layers net1;
	net1.CreateLayer(2, 0);
	net1.CreateLayer(2, 2);
	net1.CreateLayer(1, 2);
	float inp[] = {1.0f,0.0f};
	float *out = net1.FeedForward(inp , 2);
	std::cout << out[0];
//	net1.PrintNet();
	return 0;
}



