void hash_chain_delete(element item, ListNode* ht[]) {
	int hash_value = hash_function(item.key);
	ListNode* node_before = NULL;
	ListNode* node = ht[hash_value];

	for (; node; node_before = node, node = node->link) {
		if (equal(node->item, item)) {
			printf("Found key\n");

			if (node_before)
				node_before->link = node->link;
			else
				ht[hash_value] = node->link;

			free(node); // Free the memory for the node
			return;
		}
	}

	printf("Not found key\n");
}



