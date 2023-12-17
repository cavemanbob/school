#include <iostream>

struct node{
	int data;
	node* next;
};
int divpart;

node* NewNode(int idata){
	node *p= new node;
	p->data=idata;
	p->next=nullptr;
	return p;
}
node* Check(int idata, node *root){
	if(root->data==idata){
		return nullptr;
	}
	else if(root->next==nullptr){
		node *p=NewNode(idata);
		root->next=p;
		return p;
	}
	return Check(idata, root->next);
}

node* InitTable(int size, int part){
	node* ar= (node *)calloc(size , sizeof(node));
	divpart=part;
	return ar;
}

int HashTable(int idata, node ar_root[]){
	if(ar_root[idata/divpart].data==0){
		ar_root[idata/divpart]=*NewNode(idata);
		return 0;
	}
	else if(Check(idata, &ar_root[idata/divpart])!=nullptr){
		return 0;
	}
	return 1;
}

int n,x,diff=0;
int main(){
	node* ar=InitTable(10000000, 100);
	std::cin >> n;
	for(;n>0;n--){
		std::cin >> x;
		if(!HashTable(x, ar)) diff++;
	}
	std::cout << std::endl << diff;
	return 0;
}
