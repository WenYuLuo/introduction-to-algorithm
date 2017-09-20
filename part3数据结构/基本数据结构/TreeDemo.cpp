#include "tree.h"
#include "tree.cpp"
#include <stdlib.h>
#include <time.h>

#define RANDOM(x) (rand() % x) //获取0-x之间的随机数

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
    printf("\n最大值： %d \n", bin_tree.Maximum()->value);
	printf("最小值： %d \n", bin_tree.Minimum()->value);

	char input_signal[2];
	while (true) {
		int num;
		printf("\n请输入待查数字：");
		scanf("%d", &num);
		TreeNode<int>* searched_node = bin_tree.TreeSearch(num);
		if (searched_node == NULL) {
			printf("未在二叉树中找到相应节点,重新输入\n");
			continue;
		}
		printf("在二叉树中找到的数字： %d \n", searched_node->value);
		printf("删除该节点后二叉树遍历结果：\n");
		bin_tree.Delete(searched_node);
		bin_tree.InOrderTreeWalk();
		printf("\n是否继续（Y\\N）?:");
		scanf("%s", input_signal);
		if (strcmp(input_signal, "Y")==0) continue;
		else break;
	}

	return 0;
}