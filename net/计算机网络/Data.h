#pragma once
#include<iostream>
#include<string>

struct Edge {
	int dest; //边的另一顶点位置
	int cost; //边的权值
	Edge* next; //下一条边的指针
};

struct sever {
	int number; //服务器号
	int name; //服务器名
	string ip; //服务器ip
};