#include <iostream>
#include <vector>

using namespace std;

template <typename K, typename V>
class Entry{
private:
    K key_v;
    V value_v;
public:
    Entry(K key_v, V value_v) {
        this->key_v = key_v;
        this-> value_v = value_v;
    }

    K key() {
        return this->key_v;
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

    void insert(K key_v, V value_v) {
        Entry<K, V> e(key_v, value_v);
        this->heap.push_back(e);
        int i = this->heap.size() - 1;
        while (i > 0 && this->heap[(i-1)/2].key() > key_v) {
            swap(this->heap[i], this->heap[(i-1)/2]);
            i = (i-1)/2;
        }
    }
    
    Entry<K, V> pop() {
        Entry<K, V> toReturn = this->heap[0];
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

    int size(){
        return this->heap.size();
    }
};

int main() {
    minBinaryHeap<int, string> heap;
    heap.insert(10, "A");
    heap.insert(5, "B");
    heap.insert(3, "C");
    heap.insert(4, "E");
    heap.insert(1, "D");

    for (int i = 0; i < 5; i++) {
        Entry<int, string> e = heap.pop();
        cout << "\n" << e.value() << "\n";
    }
}