// LRU.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<list>
#include<unordered_map>
using namespace std;


// the key-value Pair needed for our project to Store the Data in the class Node.

class Node {
public:
	string key;
	int value;
	Node(string key, int value) {
		this->key = key;
		this->value = value;
	}
};



//the LRUCache class which consists of all the Member functions being used for the the System

class LRUCache {
public:
	int maxSize;
	list<Node> l;
	unordered_map<string, list<Node>::iterator> m;

	LRUCache(int maxSize) {
		this->maxSize = (maxSize > 1) ? maxSize : 1;
	}

	void insertKeyValue(string key, int value) {
		if (m.count(key) != 0) {
			auto it = m[key];
			it->value = value;
		}
		else {
			if (l.size() == maxSize) {
				Node last = l.back();
				m.erase(last.key);	//Removing from Hashmap

				l.pop_back();	//Removing from LinkedList
			}
			Node n(key, value);
			l.push_front(n);
			m[key] = l.begin();
		}
	}

	int* getvalue(string key) {

		if (m.count(key) != 0) {
			auto it = m[key];

			int value = it->value;
			l.push_front(*it);
			l.erase(it);
			m[key] = l.begin();
			return &l.begin()->value;
		}
		return NULL;
	}

	string mostRecentKey() {
		return l.front().key;
	}
};




int main()
{
	LRUCache lru(3);
	lru.insertKeyValue("apple", 20); 
	lru.insertKeyValue("mango", 25);
	lru.insertKeyValue("kiwi", 30);

	// the cache now consists : kiwi -> mango -> apple

	cout << lru.mostRecentKey() << "\n";	//the most recent key is the last updated key

	lru.insertKeyValue("guava", 40);
	cout << lru.mostRecentKey() << "\n";	//last updated -> "guava" so, most recent is "guava"

	int* orders = lru.getvalue("mango");
	if (orders != NULL) {
		cout << "Order of mango " << *orders << "\n";	//number of mangoes we have
	}
	cout << lru.mostRecentKey() << "\n";

	lru.insertKeyValue("kiwi", 20);		//Updating value for kiwi


	//checking which fruits still exist in the Cache
	cout << "\n";

	if (lru.getvalue("apple") == NULL) {
		cout << "apple doesn't exist" << "\n";
	}
	else {
		cout << "Order of apple" << *(lru.getvalue("apple")) << "\n";
	}
	if (lru.getvalue("guava") == NULL) {
		cout << "guava doesn't exist" << "\n";
	}
	else {
		cout << "Order of guava" << *(lru.getvalue("guava")) << "\n";
	}
	if (lru.getvalue("kiwi") == NULL) {
		cout << "kiwi doesn't exist" << "\n";
	}
	else {
		cout << "Order of kiwi " << *(lru.getvalue("kiwi")) << "\n";
	}
	return 0;
}
