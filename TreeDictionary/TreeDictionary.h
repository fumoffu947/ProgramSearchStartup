#pragma once


template <class T,class G>
class TreeDictionary {
public:
	//The constructor will not take any arguments
	TreeDictionary();
	// The destructor will have to free all the nodes below (can have dynamic on the stack not the heap)
	~TreeDictionary();

	//This funtion will insert a node with given key to find and given value to store with the key
	bool insert(T key, G value);

	//This method retrievs a value given the key, return null if no value was found
	G get(T key);

	// Erases a value and key given the key, return true if the key was removed
	bool erase(T key);

	// Returns True if the given key exists in hte TreeDictionary
	bool contains(T key);

	//Return the number of keys
	int size();

private:
	//start_node = Null;
	// current_node = Null;
	int size = 0;
	int node_max_size = 5;
};