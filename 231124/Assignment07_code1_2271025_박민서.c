#include "stdlib.h"
#include "stdio.h"
#include "string.h"

typedef struct data {
	int* id;
	int* score;
} data;

#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )
void selection_sort(data* list, int n)
{
	int i, j, least, temp;
	for (i = 0; i < n - 1; i++) {
		least = i;
		for (j = i + 1; j < n; j++)
			if (list->score[j] < list->score[least]) least = j;
		SWAP(list->score[i], list->score[least], temp);
		SWAP(list->id[i], list->id[least], temp);
	}
}

void selection_sort_stable(data* list, int n)
{
	int i, j, least, temp_id, temp_score;

	for (i = 0; i < n - 1; i++) {
		least = i;

		for (j = i + 1; j < n; j++) {
			// Only update 'least' if the current element is strictly less than the current least
			if (list->score[j] < list->score[least] || (list->score[j] == list->score[least] && list->id[j] < list->id[least])) {
				least = j;
			}
		}

		// Swap only if the elements are not equal
		if (list->score[i] != list->score[least] || list->id[i] != list->id[least]) {
			SWAP(list->score[i], list->score[least], temp_score);
			SWAP(list->id[i], list->id[least], temp_id);
		}
	}
}

int main()
{
	int data_id[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int data_score[] = { 30, 25, 10, 20, 80, 30, 25, 10 };

	int in_size = 8;
	data* input = (data*)malloc(sizeof(data));

	input->id = data_id;
	input->score = data_score;

	//Print out the input data
	printf("Input data\n");
	for (int i = 0; i < in_size; i++)
		printf("%d\t %d\n", input->id[i], input->score[i]);
	printf("\n");

	// Produce the stable sorting results by replacing 'selection_sort' with 'selection_sort_stable'.
	selection_sort_stable(input, in_size);

	//Print out the sorted data
	printf("Sorted data\n");
	for (int i = 0; i < in_size; i++)
		printf("%d\t %d\n", input->id[i], input->score[i]);
	printf("\n");

	return 0;
}
