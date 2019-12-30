#pragma once
#include<iostream>
#include<fstream>
using namespace std;
#include"ArrayGraph.h"
#include"Data.h"

class creat {
public:
	void ArrayGraph_create();
	void ArrayGraph_show();
	void ArrayGraph_add();
	void ArrayGraph_del();
	void ArrayGraph_del_v();
	void ArrayGraph_insert();
	ArrayGraph* getGraph();
private:
	ArrayGraph m;
};
