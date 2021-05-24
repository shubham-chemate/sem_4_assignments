//============================================================================
// Name        : 21118_DSA_A04.cpp
// Author      : Shubham (Roll No: 21118)
//============================================================================

#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

class Entry {
private:
	int key;
	string val;
public:
	Entry(int k = -1, string v = "$") {
		key = k;
		val = v;
	}
	void PrintEntry() {
		cout << key << " -> " << val << endl;
	}
	friend class HashTable;
};

int getSumOfSqrsOfDigits(int x) {
	int sum = 0;
	while (x != 0) {
		int d = x % 10;
		sum += (d * d);
		x /= 10;
	}
	return sum;
}

int getSumOfDigits(int x) {
	int sum = 0;
	while (x != 0) {
		int d = x % 10;
		sum += d;
		x /= 10;
	}
	return sum;
}

class HashTable {
private:
	Entry ht[MAX_SIZE];
public:
	HashTable() {

	}
	int getHashVal(int x) {
//		int sum_of_squares_of_dig = getSumOfSqrsOfDigits(x);
//		return (sum_of_squares_of_dig % MAX_SIZE);
		return (x % MAX_SIZE);
//		int sum_of_dig = getSumOfDigits(x);
//		return (sum_of_dig % MAX_SIZE);
	}
	int Insert(int key, string val) {
		Entry newEntry = Entry(key, val);
		int hash_val = getHashVal(key);
		int pos = hash_val, no_of_comp = 0;;
		while (ht[pos].key != -1) {
			no_of_comp++;
			pos = (pos+1) % MAX_SIZE;
			if (pos == hash_val) {
				cout << "Hash Table is Full.\n";
				return -1;
			}
		}
		ht[pos] = newEntry;
		return no_of_comp;
	}
	void Search(int key) {
		int hash_val = getHashVal(key);
		int pos = hash_val;
		while (ht[pos].key != -1 && ht[pos].key != key) {
			pos = (pos+1) % MAX_SIZE;
			if (pos == hash_val)
				break;
		}

		if (ht[pos].key == key) {
			cout << "Entry is found.\n";
			ht[pos].PrintEntry();
		}
		else
			cout << "Entry is not found.\n";
	}
	void Delete(int key) {
		int hash_val = getHashVal(key);
		int pos = hash_val;
		while (ht[pos].key != -1 && ht[pos].key != key) {
			pos = (pos+1) % MAX_SIZE;
			if (pos == hash_val)
				break;
		}

		if (ht[pos].key == key) {

			int next = (MAX_SIZE+pos-1) % MAX_SIZE;
			while (ht[next].key == -1 || next != hash_val)
				next = (MAX_SIZE+next-1) % MAX_SIZE;

			ht[pos] = ht[next];
			ht[next].key = -1;
		}
		else
			cout << "Entry is not found.\n";
	}
	void PrintHashTable() {
		cout << "Hash Table contains following entries:\n";
		for (int i = 0; i < MAX_SIZE; i++) {
//			if (ht[i].key != -1)
				cout << i << ": ";
				ht[i].PrintEntry();
		}
	}
};

int main() {
	HashTable ht;
	int keys[] = {5, 6, 55, 555, 66, 666};
	string vals[] = {"A", "B", "C", "D", "E", "F"};

	for (int i = 0; i < 6; i++)
		cout << ht.Insert(keys[i], vals[i]) << " ";
	cout << endl;

	ht.PrintHashTable();
	ht.Delete(5);
	ht.PrintHashTable();
	return 0;
}
