#pragma once
#include<iostream>
#include<string>

struct Edge {
	int dest; //�ߵ���һ����λ��
	int cost; //�ߵ�Ȩֵ
	Edge* next; //��һ���ߵ�ָ��
};

struct sever {
	int number; //��������
	int name; //��������
	string ip; //������ip
};