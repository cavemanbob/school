#include <iostream>

#define UP_CAPACITY 10
#define MAX_LAYERS_SIZE 20 // This is number of hidden layers +2

using namespace std;

struct node{
	float *Weights;
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
			for(int j=0; j < LayersPtr[i]->High; j++){
				std::cout << "\tNode " << j << " weights: ";
				for(int k=0; k < LayersPtr[i - 1]->High; k++){
					std::cout << " " << GetNodePtr(i,j)->Weights[k];
				}
				std::cout << std::endl;
			}
		}
	}

};

int main(){
	Layers net1;
	net1.CreateLayer(2, 0);
	net1.CreateLayer(2, 2);
	net1.CreateLayer(1, 2);
	net1.PrintNet();
	return 0;
}



