#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include <map>
#include <functional>
#include <cmath>
#include <span>
#include <ranges>
using namespace std;


// Algorithm: a sequence of steps followed to solve a given problem

// Characteristics of algorithms

/// 1- Well-defined input and output
/// 2- Programming language free i.e., pseudocode.
/// 3- Steps of an algorithm should be clear, unambiguous and well-defined
/// 4- Steps of an algorithm should be modular i.e., coherence (no contradiction) and independent (decoupled) -> modularity or separation of concerns
/// 5- Steps of an algorithm should be finely granular (granularity) or low-level (abstraction) i.e., indivisible or they can't be fragmented further
/// 6- Each step of an algorithm should be concerned with one task as opposed to many tasks (activities, phases, processes, etc.) i.e., single responsbility principle (1-1 step-task)
/// 7- Steps of an algorithm are its model: invariant, complexity, non-unique (different sets of steps can be used to achieve the same algorithmic strategy)
/// 8- Algorithm is strategic and abstract in contrast to tactical and concrete implemenetation: algorithms are a goal-orientation strategy and blueprint for tactical-concrete implementations



// Implementations of algorithms: how the steps are implemented

///1- Recursive vs Iterative
///2- Online vs Offline
///3- In-place vs Out-of-place
///4- Deterministic vs Stochastic
///5- Top-down vs Bottom-up
///6- Eager vs Lazy
///7- Abstract (General or Deductive or Implicit-State) vs Concrete (Specific or Inductive or Explicit-State)

// Properties of algorithms:

///1- Speed: convergence rate or efficiency. In DSA, this is replaced by time complexity
///2- Stability: how robust (as opposed to sensitive) the algorithm is to small changes in the input measured by the condition number: residual/error
///3- Precision: the accuracy of the algorithmic result as a percentage
///4- Space Compelxity
///5- Correctness: the algorithm converges.
///6- Conditions: the hypotheses or constraints that the algorithm works under e.g., binary search requires sorted arrays, etc.


// Family of algorithms: DSA, ML/DL, OR, NA, Artificial Life

// Types of algorithms: Sublinear, Logarithmic, Logarithmic-Linear, Linear, Polynomial, Pseudo-Polynomial, Exponential, Superexponential


//Algorithm Design

///1- There is no generic procedure to solve problems i.e., there is no meta-algorithm to create algorithms
///2- Practice designing algorithms (problem-solving theory)
///3- Algorithmic toolbox: brute force, standard tools, heuristics/meta-heuristics, and magic insight
///4- No Free lunch theorem



// Data Structure: a logical organization and efficient organizaiton, storage and fetching of data in a computer.

//Programmatically, data structure is a non-primitive or composite data type i.e., a collection of elements arranged according to an abstract data type (ADT).

//Data Storage: there are two ways to store data in a computer: contiguous/continuous (locality of reference) vs non-continguous/non-continuous
//Data Fetching: pointers storing memory addresses of variables
//Abstract Data Type (ADT): an abstract mathematical model that describes the set of operations and characterstics of the data structure
///Characteristics: Order, Immutability, Replicability, Element Homogeneity, Element Size Homogeneity
///Operations: add/insert, read/access, remove/delete, modify/update, traverse, reverse/invert, sort, search, min/max/sum/mean/size, isEmpty/isFull.

// Types of Data Structures:
///Dynamic vs Static: size changes?
///Linear vs Non-Linear: topology
///Built-in vs External: does it involve user-defined type or library?

// Properties of Data Structures:
///1- Memory Consumption

//Data Structures (Interfaces):

///Array: Static (List) vs Dynamic -> sort and search
///Linked List: Singly, Doubly, Circular
///Queue: Priority Queue, Circular Queue
///Stack
///Graph: Search/Traversal, Path Optimization, Flow Optimization, Assignment, MST, Topological Sorting, Cycles/Tours Optimization, Coloring problems, Planarity problems
///Tree: Search/Traversal
///Hash
///Heap
///Others: Dictionary, Set, Tuple, Tie, Object, Struct, etc.



//Arrays: static data structure that is memory-efficient that stores memory continguously (locality of reference) whose elements are homogeneous

//Due to element homogeneity (determines the step: byte_size_of_element) and contiguous storage (index), array elements can be directly accessed via: element_address = base_address + (index x byte_size_of_element) 'random-access equation' where the base address is the address that the array starts with in memory

// Arrays are costly in terms of insertion or deletion of first element.

// Arrays can be sorted and searched:
vector<int> bubbleSort(vector<int> arr){ //iterative
    int t = 0;
    while (t < arr.size()){
        for (int k = 0; k < arr.size()-t; k++){
            if (arr[k] > arr[k+1]){
                int z = arr[k];
                arr[k] = arr[k+1];
                arr[k+1] = arr[k];
            }
        }
        ++t;
    }

    return arr;

}

vector<int> selectionSort(vector<int> arr){
    int t = 0;
    while (t < arr.size()){
        int m = arr[t];
        for (int k = 1; k < arr.size(); k++){
            if (arr[k] < m){
                arr[t] = arr[k];
                arr[k] = m;
                m = arr[k];
            }
        }
        ++t;
    }

    return arr;
}

vector<int> insertionSort(vector<int> arr){
    for (int k = 1; k < arr.size(); k++){
        int c = 0; //counter: number of elements who are greater than arr[k] in the arr[0:k-1] sorted subarray
        for (int j = k-1; j > 0; j--){
            if (arr[j] > arr[k-c]){
                int x = arr[k-c];
                arr[k-c] = arr[j];
                arr[j] = x;
                ++c;
            } else { //reached an impasse
                break; //space-reduction heuristic given the subarray is already sorted
            }
        }

    }

    return arr;
}

vector<int> quickSort(vector<int> arr){
    if (arr.size() <= 1){
        return arr;
    }
    int p = arr[arr.size()/2];
    vector<int> larr;
    vector<int> rarr;
    for (int k = 0; k < arr.size(); k++){
        if (arr[k] <= p){
            larr.push_back(arr[k]);
        } else {
            rarr.push_back(arr[k]);
        }
    }

    quickSort(larr).push_back(p);
    quickSort(larr).insert(quickSort(larr).begin(), quickSort(rarr).begin(), quickSort(rarr).end());

    return quickSort(larr);
}

vector<int> mergeSort(vector<int> arr){
    if (arr.size() <= 1){
        return arr;
    }

    if (arr.size() == 2){
        if (arr[0] > arr[1]){
            int x = arr[0];
            arr[0] = x;
            arr[1] = x;
        }
        return arr;
    }

    // return mergeSort(arr[0:arr.size()/2]) + mergeSort(arr[arr.size()/2:arr.size()]);

    // [1,4,3,2,5] -> [1,4], [3,2,5] -> [1,4], [3,2], [5] -> [1,4], [2,3], [5]
}

int decimalSize(int n){ //number of digits
    if (floor(n/10) == 0){
        return 1;
    }

    return 1 + decimalSize(n/10);
}

vector<int> decimalBase(int n){ //Gauss pivot
    int N = decimalSize(n);
    vector<int> digits;
    for (int k = N-1; k >= 0; k--){
        int offset = 0;
        for (int j = N-1; j > k; j--){ //doesn't enter this loop for the leftmost digit i.e., offset remains 0
            offset+= digits[j]*pow(10,j-k);
        }
        int d = floor(n/pow(10,k)) - offset;
        digits.insert(digits.begin()+k, d);
    }

    return digits;
}

// there are two ways to implement the radix sort

//1- start with the rightmost digit -> sort values according to the digit on focus in the array (keep a digit-order-weighted plus-minus balance sheet) -> move to next digit -> repeat until you run out of digits
//2- divide-and-conquer: cluster or group numbers by digit size -> numbers with higher digit size are sorted higher than less -> numbers with same digit size are sorted geometrically starting with leftmost digit i.e., first number to exceed the other's digit is greater e..g, start with leftmost digit, not equal? pick the number with the larger leftmost digit, equal? move to lower digit and repeat

//1 doesn't require equal digit size constraint like 2
//special case: if all array elements are of mutually distinct digit sizes, then just sort by digit sizes.

vector<int> radixSort(vector<int> arr){ //hypothesis: array elements are non-negative integers (no floats)
    //cluster by digit size
    vector<vector<int>> clusters;
    vector<int> visited;
    int c = 0;
    for (int k = 0; k < arr.size()-1; k++){
        if (c==arr.size()) break; //all numbers are clustered
        if (visited[k] == 1) continue; //arr[k] already clustered
        vector<int> k_cluster;
        k_cluster.push_back(arr[k]);
        for (int j = k+1; j < arr.size(); j++){
            if (decimalSize(arr[k] == decimalSize(arr[j])) && visited[j] != 1){
                k_cluster.push_back(arr[j]);
                visited[j] = 1;
                c++;
            }
        }
        clusters.push_back(k_cluster);
    }

    //sort clusters by digit size
    vector<vector<int>> sortedClusters;
    vector<int> auxiliaryArr;
    for (vector<int> k_cluster: clusters){
        auxiliaryArr.push_back(decimalSize(k_cluster[0]));
        auxiliaryArr = selectionSort(auxiliaryArr);
    }
    for (int k = 0; k < auxiliaryArr.size(); k++){
        for (int j = 0; j < clusters.size(); j++){
            if (decimalSize(clusters[j][0]) == auxiliaryArr[k]){
                sortedClusters.insert(sortedClusters.begin()+k,clusters[j]);
                break; //space-reduction because each cluster is known to have a unique size in advance
            }
        }
    }

    //geometric comparison between numbers of the same cluster starting with leftmost: first difference wins all
    for (vector<int> k_cluster: sortedClusters){
        vector<vector<int>> bases;
        for (int j = 0; j < k_cluster.size(); j++){
            bases.push_back(decimalBase(k_cluster[j]));
        }
    }
}

vector<int> countSort(vector<int> arr){ //pseudo-polynomial -> complexity is O(max(arr)) if count array is used but we can reduce that to O(n) through unique values enumeration if count map is used
    map<int,int> reps;
    vector<int> visited;
    vector<int> uniqueArr;
    for (int k = 0; k < arr.size(); k++){
        if (visited[k] == 1) continue;
        uniqueArr.push_back(arr[k]);
        for (int j = 0; j < arr.size(); j++){
            if (arr[k] == arr[j] && visited[j] != 1){
                reps[arr[k]] += 1;
                visited[j] = 1;
            }
        }
    }

    uniqueArr = selectionSort(uniqueArr);

    vector<int> sortedArr;
    for (int k = 0; k < uniqueArr.size(); k++){
        for (int j = 0; j < reps[uniqueArr[k]]; j++){
            sortedArr.push_back(uniqueArr[k]);
        }
    }

    return sortedArr;

}

vector<int> MycountSort(vector<int> arr){ //count how number of elements are greater than current element -> determine index
    // this algorithm approaches the notion of an index from first principles: index in a sorted array is the number of elements lower than the indexed number
    map<int, int> ge;
    vector<int> visited;
    vector<int> uniqueArr;
    for (int k = 0; k < arr.size(); k++){
        if (visited[k] == 1) continue;
        for (int j = 0; j < arr.size(); j++){
            if (k != j && arr[k] < arr[j] && visited[j] != 1){
                ge[arr[k]] += 1;
                visited[j] = 1;
                uniqueArr.push_back(arr[j]);
            }
        }
    }

    vector<int> sortedArr;
    for (int k = 0; k < uniqueArr.size(); k++){
        sortedArr.insert(sortedArr.begin()+ge[uniqueArr[k]], uniqueArr[k]);
    }

    return sortedArr;
}


vector<int> bucketSort(vector<int> arr){ //hypothesis: array elements are floats uniformly distributed between 0 and 1
    vector<vector<int>> bucketArray;
    vector<int> visited;
    for (int k = 0; k < arr.size()-1; k++){
        if (visited[k] == 1) continue;
        int x = floor(arr[k]*10);
        vector<int> k_bucket;
        k_bucket.push_back(arr[k]);
        for (int j = k+1; j < arr.size(); j++){
            if (floor(arr[j]*10) == x && visited[j] != 1){
                k_bucket.push_back(arr[j]);
                visited[j] = 1;
            }
        }
        k_bucket = selectionSort(k_bucket); //otherwise recursively construct another bucket array for each bucket and repeat the process above
        bucketArray.insert(bucketArray.begin()+x, k_bucket); //insert bucket at index x
    }

    vector<int> sortedArr;
    for (vector<int> bucket: bucketArray){
        for (int k = 0; k < bucket.size(); k++){
            sortedArr.push_back(bucket[k]);
        }
    }

    return sortedArr;

}


////Search:

int linearSearch(vector<vector<char>> arr, vector<char> e){
    for (int k = 0; k < arr.size(); k++){
        if (arr[k] == e){
            return k;
        }
    }
    return -1; 
}

int linearSearch(vector<int> arr, int e){
    if (arr.size() == 0) return -1; 
    
    for (int k = 0; k < arr.size(); k++){
        if (arr[k] == e){
            return k;
        }
    }
    return -1; 
}

int binarySearch(vector<int> arr, int e){
    int N = arr.size();
    int low = 0;
    int high = N-1;
    int t = 2;
    while (t < N){
        if (arr[high] == e){
            return high;
        } else if (arr[high] > e){
            high = (high+low)/2;
        } else {
            low = (high+low)/2;
        }

        t*=2;
    }

    return -1;
}

int interpolationSearch(vector<int> arr, int e){ //assuming sorted array + uniformly distributed elements
    // [2,4,5,9]
    // int e = a(1-k) + kb; k >= 0 => e = a - ak + kb => e-a = k(b-a) => k =  e-a/b-a
    int N = arr.size();
    int low = 0;
    int high = N-1;
    int pos = low + (e-arr[low])*(high-low)/arr[high]-arr[low]; //probe position
    while (low <= high && e >= arr[low] && e <= arr[high]){
        if (e == arr[pos]){
            return pos;
        } else if (e > arr[pos]) {
            low = pos + 1;
            pos = low + (e-arr[low])*(high-low)/arr[high]-arr[low]; //probe position
        } else {
            high = pos - 1;
            pos = low + (e-arr[low])*(high-low)/arr[high]-arr[low]; //probe position
        }
    }

    return -1;

}

int jumpSearch(vector<int> arr, int e){ //assuming the array is sorted
    if (arr[0] == e) return 0;
    int m = floor(sqrt(arr.size())); //jump step
    for (int k = m; k < arr.size(); k+=m){
        if (arr[k] > e){
            //linear search
            for (int j = k-m; j < k; j++){
                if (arr[j] == e) return j;
            }
        }
        continue;
    }

    return -1;
}

int exponentialSearch(vector<int> arr, int e){ //assuming a sorted array, works best if N is even
    int N = arr.size();
    for (int k = 1; arr[k] < e; k*=2){
        if (arr[k] == e) return k;
        else if (arr[k] > e){
            // return binarySearch(arr[k/2:k], e);
        }
    }
}

// Dynamic arrays are hybrid between the dynamicity of linked lists and the contintuity of arrays e.g., ArrayList (Java), List (Python), Vector (C++), Array (php)
// Dynamic arrays implement the List interface along with Linked Lists.
class DynamicArray{ //a dynamic implementation of arrays: it behaves like an array as long as size isn't exceeded. Once exceeded, a new array is created!

    int size; //current size
    vector<int[5]> arrs;     
    inline int static arrayIndexer = 0; 

    DynamicArray(){
        this->size = 0; 
        int arr[5]; //initial inventory array (5 as an array-step example)
        arrs.push_back(arr); 
    }

    void createArray(){ //in case of need for resizing (inventory array size exceeded); a new static array is created
        int arr[5]; //using arrays of 5
        arrs.push_back(arr); 
    }

    void append(int x){ //add at the end
        if (size > 4 + DynamicArray::arrayIndexer*5){  
            this->createArray();      
            DynamicArray::arrayIndexer++; 
        }
        arrs[DynamicArray::arrayIndexer][size] = x;
        this->size++; 

    }

    void add(int x, int index){
        if (index == this->size){
            append(x);
        }
        int lastVal = arrs[floor((this->size-1)/5)][(this->size-1)%5];
        
        for (int k = this->size-1; k >= index+1; k++){ //switching for contininity preservation
            arrs[floor(k/5)][k%5] = arrs[floor(k-1/5)][k-1%5]; //jumps implicitly handled
        }

        //only replace after switching
        arrs[floor(index/5)][index%5] = x; 
        this->size++;   
        
        //append last value
        append(lastVal);
    }

    int get(int i){ //index i
        if (i > this->size - 1){
            return NULL; 
        }
        return arrs[floor(i/5)][i%5]; 
    }

    void set(int i, int newVal){
        if (i > this->size - 1){
            return; 
        }
        arrs[floor(i/5)][i%5] = newVal; 
    }

    void remove(int i){
        if (i > this->size - 1){
            return; 
        }

        arrs[floor(i/5)][i%5] = NULL; 
        this->size--; 

        for (int k = i+1; k < this->size; k++){ //switching for contininity preservation
            arrs[floor(k-1/5)][k-1%5] = arrs[floor(k/5)][k%5]; //jumps implicitly handled
        }
    }

    void clear(){  
        for (int k = 0; k < this->size; k++){
            remove(k); 
        }
    }

    int size(){
        return this->size;
    }

}; 


// Linked List: dynamic data structure with non-contiguous data storage based on data values and link pointers.

// Linked List fix the insertion-deletion cost common in static arrays.


class Node{
    public:
        int value; //data
        Node* pointer; //link to the next node address 

        ~Node(){
            delete pointer;
            pointer = nullptr;
        }
};

class LinkedList{
    public:
        int numNodes; //maximum number of nodes in a LL
        vector<Node> Nodes;

        inline static int counter = 0; 

        LinkedList(int ne){
            this->numNodes = ne;
            this->Nodes = {};
        }

        Node* createNode(int k){
            Node n;
            n.value = k;
            if (counter == numNodes-1){ //tail
                n.value = NULL; 
                n.pointer = nullptr;
                this->Nodes.push_back(n);
                return &n; 
            }

            if (counter == 0){//head
                n.value = NULL;
            }

            counter++;
            n.pointer = createNode(counter);
            this->Nodes.push_back(n);
            return &n; //to avoid using static variables vector<Node>, we modified createNode to return the memory address of the current node
        }

        Node firstNode(){
            return this->Nodes[0]; 
        }

        Node& nthNode(Node& x, int N){
            if (N == 0) return x; 
            if (N == 1){
                return *x.pointer; //next Node 
            }
            return nthNode(*x.pointer,N-1);
        }

        void printList(){

            for (int k = 0; k < this->Nodes.size(); k++){
                Node& x = nthNode(Nodes[0], k); 
                cout << "Node k value: " << x.value << "\n";
            }

        }

        int LLSize(){ //how many nodes not counting head and tail
            return this->Nodes.size() - 2; 
        }

        void traverse(){
            vector<Node> nodes = this->Nodes;
            for (int k = 0; k < nodes.size(); k++){
                cout << nodes[k].value << "\n"; 
            }
        }

        vector<Node> sort(){ //transform the linked list into an array, sort it, and reverse (transform and conquer)
            vector<int> arr; 
            vector<Node> nodes = this->Nodes;
            
            for (int k = 0; k < nodes.size(); k++){
                arr.push_back(nodes[k].value); 
            }
        
            arr = selectionSort(arr);
            Node fn = this->firstNode();
            fn.value = arr[0];
            for (int k = 1; k < this->numNodes; k++){
                this->nthNode(fn, k).value = arr[k]; 
            }
        
            return this->Nodes;
        }

        void insert(Node x, int index){ //Assuming x is a node with a nullptr pointer value, but has a value of its own.
            int currentSize = this->LLSize();             
            if (index == 0 || index == currentSize+1){ //make it impossible to replace the head and tail to preserve the LL structure
                return;
            }
            Node fn = this->firstNode(); //head
        
            x.pointer = &this->nthNode(fn, index+1); //if index is currentSize of Nodes, then x points to the tail.
            this->nthNode(fn, index).pointer = &x; 
            this->Nodes.insert(Nodes.begin()+index, x);
        }

        void del(int index){
            int currentSize = this->LLSize();             
            if (index == 0 || index == currentSize+1){ //make it impossible to delete the head and tail to preserve the LL structure
                return;
            }

            Node fn = this->firstNode(); //head
        
            this->nthNode(fn, index-1).pointer = &this->nthNode(fn, index+1); //in case a one-element LL, then the head points to tail after the operation

            this->Nodes.erase(Nodes.begin()+index);
            
        }

        int read(int x){ //O(n) in worst-case scenario
            Node fn = this->firstNode(); //head
            for (int k = 1; k < this->numNodes; k++){
                if (x == this->nthNode(fn, k).value){
                    return k-1;
                }
            }
            return -1;
        }
};

// Doubly Linked List
// Circular Linked List

// For stacks, it's more memory-efficient to use arrays except for the edge of case of resizing due to its fixed size.
class Stack: public LinkedList{//LIFO
    public:
        int numNodes; //maximum number of nodes
        Stack(): LinkedList::LinkedList(numNodes){}

        void push(Node x){
            int currentSize = this->LLSize(); 
            this->insert(x, currentSize);
        }

        void pop(){
            int currentSize = this->LLSize(); 
            this->del(currentSize);
        }

        int peek(){
            int currentSize = this->LLSize();             
            Node fn = this->firstNode(); 
            return this->nthNode(fn,currentSize).value;
        }

        bool isEmpty(){
            Node fn = this->firstNode(); //head
            Node& nextNode = *fn.pointer;
            // check if it's tail 
            return nextNode.pointer == nullptr; 
        }

        int size(){
            int currentSize = this->LLSize();             
            return currentSize; 
        }
};

class StackArray{
    public:
        vector<int> arr; 
        
        StackArray(int s){
            this->arr = {}; 
        }

        void push(int x){
            arr.push_back(x); 
        }

        void pop(){
            arr.pop_back(); 
        }

        int peek(){ //returnt the last element (that is about to be popped)
            return arr[arr.size()-1];
        }

        bool isEmpty(){
            return arr.size() == 0; 
        }

        int size(){
            return arr.size(); 
        }


}; 

class Queue: public LinkedList{ //FIFO
    public:
        Queue(int ne): LinkedList::LinkedList(ne){}


        void enqueue(Node x){ //add element at the end (or start)
            int currentSize = this->LLSize();             
            this->insert(x,currentSize); 
        }

        void dequeue(){ //remove element at the start (or end)
            this->del(1);
        }

        int peek(){ //return first element (that is about to get dequeued)
            Node fn = this->firstNode(); 
            return this->nthNode(fn,1).value;
        }

        bool isEmpty(){
            int currentSize = this->LLSize();             
            return currentSize == 0; 
        }

        int size(){
            int currentSize = this->LLSize();             
            return currentSize; 
        }

};

// Priority Queue 
// Circular Queue


// Hash Table is a dynamic, linear and built-in data structure with a non-contiguous data storage with hetergeneous elements that are unordered, non-modifiable (immutable) and non-replicable (unique).

// Hash Table stores the elements of another data structure in element-index N-1 correspondence using hash function: element -> hash code 

// Hash collision: when two or more elements have the same hash code in the hash table or set -> solution: chaining: create a bucket for the hash index in question as a linked list or array.

// Hash table makes search/add/delete operations efficient because each time the hash code is (re)generated on the fly from input element

// Hash Set implementation:

// The elements of a hash set are called buckets i.e., containers of a combination of elements of a given input data structure. Buckets are implemented using linked lists or arrays.
class HashSet{
    public:
        map<int,vector<vector<char>>> hs; //hash set (a form of hash table for storing large number of elements)

        void add(vector<char> x){ 
            int hc = 0; //hash index or hash code
            for (char x: x){ //hash function
                int y = static_cast<int>(x); //downcast using static casting: char -> unicode code point (decimal)
                hc+= y%10; 
            }

            hs[hc].push_back(x); //chaining (hash collision resolution) using array-built buckets
        }

        int search(vector<char> x){
            // regenerate its hash code on the fly
            int hc = 0; 
            for (char x: x){ //hash function
                int y = static_cast<int>(x); //downcast using static casting: char -> unicode code point (decimal)
                hc+= y%10; 
            }
            
            if (hs[hc].size() != 0){ //if the bucket is not empty
                return hc; 
            }

            return -1;
        }
        
        void remove(vector<char> x){
            // regenerate its hash code on the fly
            int hc = 0; 
            for (char x: x){ //hash function
                int y = static_cast<int>(x); //downcast using static casting: char -> unicode code point (decimal)
                hc+= y%10; 
            }

            if (hs[hc].size() != 0){ //if the bucket is not empty
                int index = linearSearch(hs[hc],x); 
                hs[hc].erase(hs[hc].begin()+index); 
            }
        }

        void clear(){
            for (const auto& [_, val]: hs){
                vector<vector<char>> bucket = val;
                for (vector<char> x: bucket){
                    remove(x); 
                } 
            }
        }

        bool contains(vector<char> x){
            // regenerate its hash code on the fly
            int hc = 0; 
            for (char x: x){ //hash function
                int y = static_cast<int>(x); //downcast using static casting: char -> unicode code point (decimal)
                hc+= y%10; 
            }

            if (hs[hc].size() != 0){ //if the bucket is not empty
                return true;
            }

            return false; 

        }
}; 

class HashMap{
    map<int,string> hm; 

    int hash(int key){ //hash function returns hash code       
        if (key < 10){
            return key; //evenly distributed in this case, otherwise all pour to zero.
        }

        int numDigits = 1;
        int temp = floor(key/10); 
        while (temp != 0){
            numDigits++; 
            temp = floor(key/10);         
        }

        int sumDigits = 0; //miniaturization
        for (int k = 0; k < numDigits; k++){
            int kthDigit = (int)floor(key/pow(10,k))%10;
            sumDigits+= kthDigit;
        }

        return sumDigits%10;
    }

    void put(int key, string value){
        int hashCode = hash(key);
        hm[hashCode] = value; 
    }

    string get(int key){
        int hashCode = hash(key);
        return hm[hashCode]; 
    }

    void remove(int key){
        int hashCode = hash(key);
        hm.erase(hashCode);
    }

    void clear(){
        for (const auto& [key,_]: hm){
            remove(key); 
        }
    }

    bool containsKey(int key){
        vector<int> keys = this->keySet(); 
        for (int k: keys){
            if (key == k) return true;
        }
        return false; 
    }

    vector<int> keySet(){
        vector<int> keys; 
        for (const auto& [key,_]: hm){
            keys.push_back(key);
        }
        return keys; 
    }
    
    
    vector<string> values(){
        vector<string> vals; 
        for (const auto& [_, val]: hm){
            vals.push_back(val);
        }
        return vals; 

    }

    int size(){
        int s = 0;
        for (const auto& [_,_]: hm){
            s++; 
        }
        return s;
    }
};


// A graph is a non-linear, dynamic and non-built-in data structure with homogeneous, mutable and replicable elements (DSA definition)
// A graph is a collection or tuple of vertices (nodes) and edges (binary relations over the set of vertices) denoted as (V,E), governed by an incidence function f: E -> V x V or adjancency function A: V / E -> N
    // Two edges are adjacent if they share or are incident to a common vertex i.e., f(e) \in f(r) or A(e,r) = 1
    // Two vertices are adjacent if they are joined by an edge i.e., A(u,v) = 1 or f(e) = uv for a given edge e. 
    // An edge e and a vertex v are incident if f(e) = vu for a given vertex u.  

// Glossary & Terminology:

// A graph has two fundamental components:
    // Vertices (Nodes): the most rudimentary data points i.e., they contain graph data.
        // Properties: Weight, Degree, Neighborhood.
        // Types: isolated, weighted, source, sink. 
    // Edges: a binary relation over the set of vertices i.e., a link that joins a pair of vetices called its ends.
        // Properties: Weight, Directionality, etc.
        // Types: link (simple edge: arete), loop, parallel, arrow (directed edge: arc)
    // Traversal: 
        // Walk: a sequence of edges such that each edge is adjacent to the previous edge and to the next edge.
            // Open Walk: a walk where the last vertex isn't identical to the first vertex
            // Closed Walk: a wak where the last vertex is identical to the first vertex, forming a cycle or circuit.
            // Undirected Walk: a walk with symmetrical edges between a pair of nodes -> chain.
            // Directed Walk: a walk with asymmetrical edges between a pair of nodes -> chemin.
            // Elementary Walk: a walk where every vertex is visited at most once i.e., either 0 or 1 -> trail
            // Simple Walk: a walk where every edge is visited at most once i.e., either 0 or 1 -> path
            // Eulerian Walk: a walk where every edge is visited exactly once.
            // Hamiltonian Walk: a walk where every vertex is visited exactly once.
            // Cycle: a closed simple walk (closed path): directed or undirected.
            // Circuit: a closed elementary walk (closed trail): directed or undirected.
// A graph has many properties:
    // General: Order, Size, Degree, Connectivity (Connected Components), Topology, Topological Ordering, Cross Number, Embedding
    // Extremal Graph theory: Graph Coloring, Chromatic Number, Chromatic Index, Dominating Set, Clique, Independent Set, Vertex Cover, Matching, Ramsey Number
    // Line Graph
    // Complementary Graph
    // Subgraphs: co-cycle & co-circuit, E(W), induced, partial, spanning tree.
    // Minors
    // Isomorphic Graphs
// A graph has many topologies (family of graphs):
    // Directed (Digraph) vs Undirected, Cyclical vs Acyclical (DAG, Path Graph, Cycle Graph), Weighted vs Unweighted
    // Null, Trivial, Finite
    // Simple
    // Empty, Complete (Clique), Bipartite (k-partite)
    // Complete Bipartite, Star
    // Connected (Strongly vs Weakly), Tree
    // k-regular, planar
    // Hypergraph, Multigraph, Pseudograph
    // Eulerian Graph
    // Hamiltonian Graph
    // Turan Graph
    // Petersen Graph
    // Erdos-Renyi Graph
    // Hypercube Graph

int sum(vector<int> arr){
    int s = 0;
    for (int x:arr) s+=x;
    return s; 
}

vector<int> operator-(vector<int> arr1, vector<int> arr2){
    vector<int> diffArr = {};
    for (int x: arr1){
        if (linearSearch(arr2,x) == -1){
            diffArr.push_back(x); 
        }
    }
    return diffArr; 
}

bool replica(vector<int> arr){
    for (int k = 0; k < arr.size()-1; k++){
        for (int j = k+1; j < arr.size(); j++){
            if (arr[k] == arr[j]) return true; 
        }
    }
    return false; 
}

class Graph{
    
    map<int,vector<int>> adjList; //map linking each vertex with its neighborhood dynamic array -> the simplest tabular representation
    vector<int> Nodes;
    int maxDegree; //the maximal degree of the graph shouldn't exceed the maxDegree
    int maxOrder; //number of nodes in the graph shouldn't exceed the max order
    int maxSize; //number of edges in the graph shouldn't exceed the max size
     
    Graph(){
        this->Nodes = {};
    }

    void addNode(int k){
        if (this->getOrder() < maxOrder){
            this->Nodes.push_back(k); 
            return;
        }

        cout << "maximum order reached!";
    }

    void addEdge(int k, int l){
        if (this->getSize() < maxSize && linearSearch(Nodes,k) > 0 && linearSearch(Nodes,l) > 0){ //verify if the graph contains the nodes
            adjList[k].push_back(l);
            adjList[l].push_back(k);
            return;
        }

        cout << "maximum size reached!";
    }

    int nodeDegree(int k){
        return adjList[k].size(); 
    }

    vector<int> nodeNeighborhood(int k){
        return adjList[k]; 
    }

    int getNodeMaxDeg(){
        int maxNode = Nodes[0];
        int DELTA = adjList[Nodes[0]].size();
        for (int n : Nodes){
            if (DELTA < adjList[n].size()){
                maxNode = n;
                DELTA = adjList[n].size();
            }
        }
        return maxNode;        
    }

    int getMaxDegree(){
        int DELTA = adjList[Nodes[0]].size();
        for (int n : Nodes){
            if (DELTA < adjList[n].size()){
                DELTA = adjList[n].size();
            }
        }
        return DELTA;
    }

    int getAvgDegree(){
        int degreeSum = 0;
        for (int n: Nodes){
            degreeSum += nodeDegree(n);
        }
        return degreeSum/this->Nodes.size(); 
        
    }

    int getMinDegree(){
        int delta = adjList[Nodes[0]].size();
        for (int n : Nodes){
            if (delta > adjList[n].size()){
                delta = adjList[n].size();
            }
        }
        return delta;

    }

    int getOrder(){
        return Nodes.size(); 
    }

    int getSize(){
        // handshake lemma
        int degreeSum = 0;
        for (int n: Nodes){
            degreeSum += nodeDegree(n);
        }
        return degreeSum/2; 
    }

    vector<vector<int>> ConnectedComponents(){ //connectivity is a transitive, symmetrical (undirected graph) binary relation
        // a good space reduction heuristic is to start with the node of maximum degree.
        vector<vector<int>> CC;
        int x = getNodeMaxDeg(); 
        vector<int> BFS = this->BFS(x); 
        CC.push_back(BFS); //starting from the assumption that the graph is connected until proven otherwise i.e., size = 1
        vector<int> CBFS = this->Nodes - BFS; 
        while (CBFS.size() != 0){
            CC.push_back(CBFS);
            int node = CBFS[0];
            CBFS = this->Nodes - this->BFS(node);
        }    
        return CC; 
    }

    int nbrConnectedComponents(){
        vector<vector<int>> CC = this->ConnectedComponents();
        return CC.size();
    }

    int connectivity(){
        vector<vector<int>> CC = this->ConnectedComponents();
        return this->getOrder() - CC.size();        
    }
    bool isConnected(){
        vector<vector<int>> CC = this->ConnectedComponents();
        return (CC.size() == 1);
    }

    /// Traversal: DFS, BFS


    //queue: FIFO principle
    vector<int> BFS(int s){ //index of starting node
        int root = Nodes[s]; 
        vector<int> bfs = {root}; 
        vector<int> queue = {root}; //FIRST ELEMENT -> FIRST TO BE OUSTED 
        int t = 1;
        while (t < bfs.size() && bfs.size() < this->getOrder()){
            for (int x: adjList[root]){ //neighbors
                if (linearSearch(bfs,x) == -1){ //this line prevents routing loops + replaces visited array implementation: space-time trade-off
                    bfs.push_back(x); //enqueue current root neighbors
                    queue.push_back(x); //enqueue current root neighbors
                }
            }
            root = bfs[t]; //update root: didn't use the dequeue() method to preserve all elements in the bfs to be returned, otherwise dequeue the bfs and change while to check for all elements visited.
            queue.erase(queue.begin()); //dequeue element at index 0 i.e., previous root
            t++; 
        }
        return bfs;
    }

    // stack: LIFO principle
    vector<int> DFS(int s){
        int root = Nodes[s];
        vector<int> stack = {root};
        vector<int> dfs = {root}; 
        vector<int> visited;
        visited[root] = 1; 
        int child = root; 
        int k = 1;
        while (dfs.size() < this->getOrder()){
            while (k < adjList[child].size() && adjList[child].size() != 0){ //as long as the child has children
                if (child == root) child = adjList[root][0]; //runs only once
                else child = adjList[child][k]; 
                if (visited[child] != 1){
                    visited[child] = 1; 
                    stack.push_back(child);
                    dfs.push_back(child);
                    k = 1; 
                } else { 
                    k++; 
                    child = stack[stack.size()-1]; //regress back to the last parent 
                }
                stack.pop_back(); 
                child = stack[stack.size()-1]; //regress back to the last parent 
                k = 1; //reset
            }
        }

        return dfs; 
    }

    vector<int> cycleDetection(int s){ //starting index
        int root = Nodes[s]; 
        vector<int> bfs = {root}; 
        map<int,int> parent;
        int t = 1; 
        while (t <bfs.size() && bfs.size() < this->getOrder() + 1){ //search up to n + 1. That +1 is due to the pigeonhole principle: is there a vertex that is visited more than once? i.e., is there a redundant edge that revisits a vertex already in the bfs or visits a new vertex?.
            for (int x: adjList[root]){ //neighbors
                parent[x] = root; //last neighbor that x came from
                if (x != parent[root]){ //this line prevents routing loops + replaces visited array implementation: space-time trade-off
                    bfs.push_back(x); //enqueue current root neighbors
                }
            }
            if (replica(bfs)) return bfs; //bfs is a cycle
            root = bfs[t]; //update root: didn't use the dequeue() method to preserve all elements in the bfs to be returned, otherwise dequeue the bfs and change while to check for all elements visited.
            t++;
        }
        return bfs; 
    }

    bool isCyclical(){ //assuming the graph is connected !
        //By the pigeonhole principle: if m: 0 -> n-1, no cycles exist. Otherwise, at least one cycle exists: cycles are path redundancies (non-injective) i.e., if there are as many edges as vertices or more (m >= n), then surely a vertex is visited more than once i.e., both a start vertex and an end vertex.
        int m = this->getSize();
        int n = this->getOrder();
        return (m >= n);
    }

    /// Search
    int search(int x){ 
        vector<vector<int>> CC = this->ConnectedComponents();
        for (int k = 0; k < CC.size(); k++){
            int val = linearSearch(CC[k],x); 
            if ( val > 0){
                return val;
            }
        }
        return -1; 
    }

    int searchEfficient(int e){
        int root = Nodes[0]; 
        if (e == root) return 0; 
        vector<int> bfs = {root}; 
        int t = 1;
        while (t < bfs.size() && bfs.size() < this->getOrder()){
            for (int x: adjList[root]){ //neighbors
                if (linearSearch(bfs,x) == -1){ //this line prevents routing loops + replaces visited array implementation: space-time trade-off
                    bfs.push_back(x); //enqueue current root neighbors
                }
            }
            if (linearSearch(bfs,e) > 0) return linearSearch(bfs,e); 
            root = bfs[t]; //update root: didn't use the dequeue() method to preserve all elements in the bfs to be returned, otherwise dequeue the bfs and change while to check for all elements visited.
            t++; 
        }
        return -1;
    }

    ///Shortest Path: Dijkstra, Bellman-Ford, Floyd-Warshall

    void Dijkstra(int source, int destination){

    }

    void BellmanFord(int source, int destination){

    }

    void FloydWarshall(int source, int destination){

    }

    void Astar(int source, int destination){

    }
    //Flow Optimization: Ford-Fulkerson, Edmond-Karp, Dinic
    //Assignment: Gale-Shapley 
    //Minimum Spanning Tree: Kruskal, Prim
    //Topological Sorting (DAG)
    //Minimum Cut problems
    //Covering problems
    //Packing problems
    //Eulerian/Hamiltonian Path/Tours
    //Coloring problems
    //Drawing problems: planarity, cross number, etc.
};

ostream& operator<<(ostream& os, const vector<int>& arr){
    for (int k = 0; k < arr.size(); k++){
        os << arr[k] << "\n";
    }
    return os;
}

int main(){

    vector<int> v = {3,2,1,1,3,4,21};

    cout << bubbleSort(v);

    return 0;
}


