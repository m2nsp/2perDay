#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_ELEMENT 2000

typedef struct element {
	int key;
} element;

typedef struct {
	element* heap;
	int heap_size;
} HeapType;

// Integer random number generation function between 0 and n-1
int random(int n)
{
	return rand() % n;
}

// Initialization
void init(HeapType* h) {
	h->heap_size = 0;
}

// Insert the item at heap h, (# of elements: heap_size)
void insert_max_heap(HeapType* h, element item)
{
	int i;
	i = ++(h->heap_size);

	// The process of comparing with the parent node as it traverses the tree
	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item; // Insert new node
}

// Delete the root at heap h, (# of elements: heap_size)
element delete_max_heap(HeapType* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		// Find a smaller child node
		if ((child < h->heap_size) &&
			(h->heap[child].key) < h->heap[child + 1].key)
			child++;
		if (temp.key >= h->heap[child].key) break;
		// Move down one level
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

void build_max_heap(HeapType* h) {
	int parent_position;

	for (parent_position = h->heap_size / 2; parent_position >= 1; parent_position--) {
		int left = 2 * parent_position;
		int right = 2 * parent_position + 1;
		int largest = parent_position;

		if ((left <= h->heap_size) && (h->heap[left].key > h->heap[parent_position].key))
			largest = left;

		if ((right <= h->heap_size) && (h->heap[right].key > h->heap[largest].key))
			largest = right;

		if (largest != parent_position) {
			// Swap values if needed
			element temp = h->heap[parent_position];
			h->heap[parent_position] = h->heap[largest];
			h->heap[largest] = temp;

			// Recursively call on the swapped child
			parent_position = largest;

			// Adjust parent position for the next iteration
			parent_position = (parent_position * 2) + 1;
		}
	}
}


//input: heap 'h'
//output: sorted element array 'a'
void heap_sort(HeapType* h, element* a, int n)
{
	int i;

	build_max_heap(h);
	for (i = (n - 1); i >= 0; i--) {
		a[i] = delete_max_heap(h);
	}
}

bool check_sort_results(element* output, int n)
{
	bool index = 1;
	for (int i = 0; i < n - 1; i++)
		if (output[i].key > output[i + 1].key)
		{
			index = 0;
			break;
		}
	return index;
}

void main()
{
	clock_t start_time, end_time;
	double cpu_time_used;

	start_time = clock();

	time_t t1;
	//Intializes random number generator 
	srand((unsigned)time(&t1));

	int input_size = 10;	//10, 100, 1000
	int data_maxval = 10000;

	HeapType* h1 = (HeapType*)malloc(sizeof(HeapType));
	// 'heap' is allocated according to 'input_size'.  heap starts with 1, so 'input_size+1' is used.
	h1->heap = (element*)malloc(sizeof(element) * (input_size + 1));

	// output: sorted result
	element* output = (element*)malloc(sizeof(element) * input_size);



	// Generate an input data randomly
	for (int i = 0; i < input_size; i++)
		h1->heap[i + 1].key = random(data_maxval);	// note) heap starts with 1.
	h1->heap_size = input_size;

	if (input_size < 20) {
		printf("Input data\n");
		for (int i = 0; i < input_size; i++)	printf("%d\n", h1->heap[i + 1].key);
		printf("\n");
	}

	// Perform the heap sort
	heap_sort(h1, output, input_size);

	if (input_size < 20) {
		printf("Sorted data\n");
		for (int i = 0; i < input_size; i++)	printf("%d\n", output[i].key);
		printf("\n");
	}

	// Your code should pass the following function (returning 1)
	if (check_sort_results(output, input_size))
		printf("Sorting result is correct.\n");
	else
		printf("Sorting result is wrong.\n");


	end_time = clock();

	// Calculate the CPU time used
	cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

	printf("CPU time used: %f seconds\n", cpu_time_used);

}