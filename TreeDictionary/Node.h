#pragma once


template <class T, class G>
class Node {
public:
	// The constructor takes the number of keys to store
	Node(int size);
	~Node();

	// Returns if this is a leafnode or not
	bool isLeafNode();

private:
	int node_size = 0;
	T keys[] = nullptr;
	Node  *childe_nodes[] = nullptr;
};