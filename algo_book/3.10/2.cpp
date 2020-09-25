#include <bits/stdc++.h>
using namespace std;

struct list_t{
	int item;
	list_t *next;
};

int main(){
	// Construct list from user input
	int n, x;
	cin>>n>>x;
	list_t *tmp = new list_t{x, nullptr};
	// Head of list
	auto *head = tmp;
	for (int i = 1; i < n; ++i){
		cin>>x;
		list_t *cur = new list_t{x, nullptr};
		tmp->next = cur;
		// tmp becomes tail of list
		tmp = cur;
	}
	// Reverse the direction of list
	if (n > 1){
		// Pointer to current node
		auto *i = head;
		// Pointer to previous node
		head = nullptr;
		// While current node is not the tail node's successor
		while (i != nullptr){
			// Point current node to previous node
			tmp = i->next;
			i->next = head;
			// Set previous node to current node
			head = i;
			// Set current node to the node it pointed to before
			i = tmp;
		}
	}
	// Print reversed list
	while (head != nullptr){
		cout<<head->item<<' ';
		tmp = head;
		head = head->next;
		// Deallocate memory for this node
		delete tmp;
	}
}
