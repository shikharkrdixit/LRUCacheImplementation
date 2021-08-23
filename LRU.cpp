// LRU.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<list>
#include<unordered_map>
using namespace std;


// the key-value Pair needed for our project to Store the Data.
// key is the String and value is the Answer (integer) we will be looking for.
class Node {
public:
	string key;
	int value;
	Node(string key, int valu) {
		this->key = key;
		this->value = value;
	}
};




class LRUCache {
public:
	int maxSize;
	list<Node> l;
	unordered_map<string,list<Node>::iterator> m;

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
				m.erase(last.key); //Removing from Hashmap

				l.pop_back(); //Removing from LinkedList
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
	lru.insertKeyValue("mango", 10);
	lru.insertKeyValue("apple", 20);
	lru.insertKeyValue("guava", 30);

	cout << lru.mostRecentKey() << "\n";

	lru.insertKeyValue("mango", 40);
	cout << lru.mostRecentKey() << "\n";

	int* orders = lru.getvalue("mango");
	if (orders != NULL) {
		cout << "Order of mango " << *(orders) << "\n";
	}
	lru.insertKeyValue("banana", 20);

	if (lru.getvalue("apple") == NULL) {
		cout << "apple doesn't exist" << "\n";
	}
	if (lru.getvalue("guava") == NULL) {
		cout << "guava doesn't exist" << "\n";
	}
	if (lru.getvalue("banana") == NULL) {
		cout << "mango doesn't exist" << "\n";
	}
	return 0;
}
