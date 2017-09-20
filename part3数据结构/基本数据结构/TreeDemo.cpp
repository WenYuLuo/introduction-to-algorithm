#include "tree.h"
#include "tree.cpp"
#include <stdlib.h>
#include <time.h>

#define RANDOM(x) (rand() % x) //��ȡ0-x֮��������

int main(){
	int range = 100;
	int size = 10;
	srand((int) time(NULL));
	BinSearchTree<int> bin_tree;
	for (int i = 0; i < size; i++) {
		int rand_num = RANDOM(range);
		printf("%d | ", rand_num);
		bin_tree.Insert(rand_num);
	}
	printf("\n");
	bin_tree.InOrderTreeWalk();
    printf("\n���ֵ�� %d \n", bin_tree.Maximum()->value);
	printf("��Сֵ�� %d \n", bin_tree.Minimum()->value);

	char input_signal[2];
	while (true) {
		int num;
		printf("\n������������֣�");
		scanf("%d", &num);
		TreeNode<int>* searched_node = bin_tree.TreeSearch(num);
		if (searched_node == NULL) {
			printf("δ�ڶ��������ҵ���Ӧ�ڵ�,��������\n");
			continue;
		}
		printf("�ڶ��������ҵ������֣� %d \n", searched_node->value);
		printf("ɾ���ýڵ����������������\n");
		bin_tree.Delete(searched_node);
		bin_tree.InOrderTreeWalk();
		printf("\n�Ƿ������Y\\N��?:");
		scanf("%s", input_signal);
		if (strcmp(input_signal, "Y")==0) continue;
		else break;
	}

	return 0;
}