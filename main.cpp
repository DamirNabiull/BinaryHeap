#include <iostream>
#include <vector>

using namespace std;

template <typename K, typename V>
class Entry{
private:
    K* key_v;
    V value_v;
public:
    Entry(K* key_v, V value_v) {
        this->key_v = key_v;
        this-> value_v = value_v;
    }
 
    K key() {
        return *(this->key_v);
    }
 
    V value() {
        return this->value_v;
    }
};
 
template <typename K, typename V>
class minBinaryHeap{
private:
    vector<Entry<K, V>> heap;
 
    int smallestChild(int i) {
        if (this->heap.size() == 1) {
            return 0;
        }
        if (2*i + 1 < this->heap.size()) {
            if (this->heap[2*i+1].key() < this->heap[2*i+2].key()) {
                return (2*i+1);
            } else {
                return (2*i+2);
            }
        } else if (2*i + 1 == this->heap.size()) {
            return (2*i + 1);
        } else {
            return 0;
        }
    }
 
public:
    minBinaryHeap() {}
 
    void insert(K* key_v, V value_v) {
        Entry<K, V> e(key_v, value_v);
        this->heap.push_back(e);
        int i = this->heap.size() - 1;
        while (i > 0 && this->heap[(i-1)/2].key() > *key_v) {
            swap(this->heap[i], this->heap[(i-1)/2]);
            i = (i-1)/2;
        }
    }
 
    V pop() {
        V toReturn = this->heap[0].value();
        this->heap[0] = this->heap[this->heap.size()-1];
        this->heap.pop_back();
        int i = 0;
        int child = smallestChild(i);
        while (child != 0 && this->heap[child].key() < this->heap[i].key()) {
            swap(this->heap[child], this->heap[i]);
            i = child;
            child = smallestChild(i);
        }
        return toReturn;
    }
 
    void sort() {
        for (int j = this->heap.size() - 1; j > 0; j--) {
            int i = j;
            while (i > 0 && this->heap[(i-1)/2].key() > this->heap[i].key()) {
                swap(this->heap[i], this->heap[(i-1)/2]);
                i = (i-1)/2;
            }
        }
    }
 
    int size(){
        return this->heap.size();
    }
};

int main() {
    minBinaryHeap<int, string> heap;
    int a = 10, b = 5, c = 3, e = 4, d = 1;
    heap.insert(&a, "A");
    heap.insert(&b, "B");
    heap.insert(&c, "C");
    heap.insert(&e, "E");
    heap.insert(&d, "D");

    d = 20;

    heap.sort();

    for (int i = 0; i < 5; i++) {
        string e = heap.pop();
        cout << "\n" << e << "\n";
    }
}