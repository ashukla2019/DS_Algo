#include<iostream>
#include<list>
using namespace std;

class Hash
{
	int bucket;
	list<int>* table;
	public:
	 Hash(int b)
	 {
		 bucket = b;
		 table = new list<int>[bucket];
	 }
	 int hashFunction(int val)
	 {
		 return(val%bucket);
	 }
	 void insertItem(int val)
	 {
		 int index = hashFunction(val);
		 table[index].push_back(val);
	 }
	 void deleteItem(int item)
	 {
		 int index = hashFunction(item);
		 table[index].remove(item);
	 }
	 void displayHash() 
	 { 
		for (int i = 0; i < bucket; i++)
		{ 
			cout << i; 
			for (auto x : table[i]) 
			cout << " --> " << x; 
			cout << endl; 
		} 
	 }
};

int main() 
{ 
	int arr[] = {3, 10, 13, 20, 25};
	int n = sizeof(arr)/sizeof(arr[0]); 
	Hash h(7); // 7 is count of buckets in 
	// hash table 
	for (int i = 0; i < n; i++) 
	{
		h.insertItem(arr[i]); 
	}

	// delete 12 from hash table 
	h.deleteItem(20); 
	// display the Hash table 
	h.displayHash(); 
	return 0; 
}
