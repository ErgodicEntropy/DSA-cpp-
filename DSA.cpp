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
#include <random>
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
///Operations: add/insert, read/access, remove/delete, modify/update, traverse/pathfind, reverse/invert, sort, search, min/max/sum/mean/size, isEmpty/isFull.

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

//Shuffling

int* FisherYattes(int arr[]){ //aka Knuth shuffling
    int N = sizeof(arr)/sizeof(arr[0]);
    
    // / 1. Obtain a random seed from the hardware
    random_device rd; 
    
    // 2. Initialize the standard mersenne_twister_engine with the seed
    mt19937 gen(rd()); 
    
    int t = N-1;

    // 3. Define the inclusive range [min, max]
    uniform_int_distribution<int> distrib(1, t-1); 
    
    while (t > 0){
        int le = arr[t]; 
        
        // 4. Generate the random number
        int randomIndex = distrib(gen);

        // 5. out-place exchange
        int z = arr[randomIndex];
        arr[randomIndex] = le;
        le = z; 

        t--; 
        uniform_int_distribution<int> distrib(1, t-1); 
    } 
    
    return arr; 
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
    vector<vector<int>> adjMat;
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

    void addEdge(int k, int l, int weight=1){
        if (this->getSize() < maxSize && linearSearch(Nodes,k) >= 0 && linearSearch(Nodes,l) >= 0){ //verify if the graph contains the nodes
            adjList[k].push_back(l);
            adjList[l].push_back(k);
            adjMat[k][l] = weight;
            adjMat[l][k] = weight;
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

    /// Traversal (Path Finding): DFS, BFS, A* (also a short path algorithm)

    //queue: FIFO principle
    vector<int> BFS(int s){ //index of starting node
        int root = Nodes[s]; 
        vector<int> bfs = {root}; 
        vector<int> queue = {root}; //FIRST ELEMENT -> FIRST TO BE OUSTED 
        int t = 1;
        while (t < bfs.size() && bfs.size() < this->getOrder()){ //assuming the graph is connected, otherwise this condition is always true
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

    // A variant implementation of the BFS for testing connectivity of the graph (both strong and weak connectivity), connectivity between two source-destination vertices, and uses a custom adjacency matrix edges[i][j] as a param
    vector<int> BFSPathFinder(int source, vector<vector<int>> edges, vector<int> visited = {}){ //is there a path that connects a source to destination ?
        int root = source; 
        vector<int> bfs = {root}; 
        int t = 1;
        while (t < bfs.size()){ //removed the bfs.size() < n as the connectivity of the graph is not assumed here
            for (int x: Nodes){
                if (edges[root][x] > 0){ //directed neighbors (we don't consider edges[x][root])
                    if (linearSearch(bfs,x) == -1 && linearSearch(visited,x) == -1){ //this line prevents routing loops + replaces visited array implementation: space-time trade-off
                        bfs.push_back(x); //enqueue current root neighbors
                    }
                }
            }
            root = bfs[t]; //update root: didn't use the dequeue() method to preserve all elements in the bfs to be returned, otherwise dequeue the bfs and change while to check for all elements visited.
            t++; 
        }
        // in this case, the bfs can tell you a lot; it can:
            // 1- give you a path of all nodes reachable from the source 
            // 2- As a result of 1, it can tell you whether there is a path between the source and destination (test if both belong to bfs; destination to be precise)
            // 3- it can tell you whether the graph is connected or not (compare bfs size to n)
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


    // A variant implementation of the BFS for testing connectivity of the graph (both strong and weak connectivity), connectivity between two source-destination vertices, and uses a custom adjacency matrix edges[i][j] as a param
    vector<int> DFSPathFinder(int source, vector<vector<int>> edges, vector<int> vis = {}){ //is there a path that connects a source to destination ?
        int root = source;
        vector<int> stack = {root};
        vector<int> dfs = {root}; 
        vector<int> visited;
        visited[root] = 1; 
        int child = root; 
        int k = 1;
        while (dfs.size() < this->getOrder()){
            map<int, vector<int>> adjList;
            int d = 0;
            for (int n: Nodes){
                if (linearSearch(vis, n) == -1 && edges[child][n] > 0) adjList[child].push_back(n); 
            }
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
            if (linearSearch(bfs,e) >= 0) return linearSearch(bfs,e); 
            root = bfs[t]; //update root: didn't use the dequeue() method to preserve all elements in the bfs to be returned, otherwise dequeue the bfs and change while to check for all elements visited.
            t++; 
        }
        return -1;
    }

    ///Shortest Path: Dijkstra, Bellman-Ford, Floyd-Warshall, A*
    int greedyChoice(int currentNode, vector<vector<vector<int>>> dijkstraTable, vector<int> visited){
        int dist = INFINITY;
        int nextNode = NULL; 
        vector<vector<int>> currentNodeDistances = dijkstraTable[currentNode];
        for (int neighbor: adjList[currentNode]){
            if (dist > currentNodeDistances[neighbor][0] && linearSearch(visited, neighbor) == -1){
                    dist = currentNodeDistances[neighbor][0]; 
                    nextNode = neighbor;
            }
        }
        return nextNode; 
    }
    //Dijkstra finds the shortest path from a source node to a destination node and to any other node.
    vector<vector<int>> Dijkstra(int source, int destination){ //Dijkstra algorithm is 'smart' or explorative greedy algorithm = Greedy Choice algorithm (exploitation) + Relaxation (exploration) + Cumulative Distance + Backward Path Construction
        //1- start with all distances as INF except source with 0
        //2- Evaluate neighbors: compute cumulative distance to each neighbor of the current node i.e., distance from the source node to the neighbor = distance between current node and neighbor + cumulatiive residual
        //3- relaxation + replace previous node if possible, else skip => relaxation corrects greedy error i.e., it finds the global minimum from local greedy choices -> exploration
            //3.1- if there is no relaxation, cumulative distance is redundant i.e., it doesn't matter if the standalone greedy algorithm uses it or not.
            //3.2- if there is no relaxation, there is no difference between the forward and backward paths: backward path = forward path (greedy exploitation) + relaxation (exploration)
            //3.3- if there relaxation, then cumulative distance is necessary in case of source-to-destination and source-to-many, but not necessary in many-to-many and many-to-destination
        //4- tabu mechanism: mark the current node as visited never to be evaluated again (final distance: smallest distance path to reach it) 
        //5- greedy local choice: choose the next node with the smallest cumulative distance from the current node -> exploitation
        //6- repeat until all nodes are visited (source-to-many) or the destination node is visited (source-to-destination)
        vector<vector<vector<int>>> dijkstraTable;
        for (int n: Nodes){ //1- start with all distances as INF except source with 0
            if (n!=source) dijkstraTable[source][n] = {(int)INFINITY};
            else dijkstraTable[source][n] = {0}; 
        }
        vector<int> visited;
        vector<vector<int>> shortPath = {{0,source}};
        int sumDist = 0; 
        int currentNode = source;
        int t = 1; 
        while (visited.size() < this->getOrder() && linearSearch(visited, destination) == -1){
            for (int neighbor: adjList[currentNode]){ //2- Evaluate cumulative distance to neighbors
                if (linearSearch(visited,neighbor) == -1){ 
                    int dist = adjMat[currentNode][neighbor] + sumDist; //cumulative distance = current distance + cumulative residual
                    if (dist < dijkstraTable[currentNode][neighbor][0]) dijkstraTable[currentNode][neighbor] = {dist, currentNode}; //3- relaxation + replace previous node if possible, else skip => relaxation corrects greedy error i.e., it finds the global minimum from local greedy choices                
                }
            }   
            visited.push_back(currentNode); //4- tabu mechanism: mark the current node as visited never to be evaluated again (final distance: smallest distance path to reach it)
            currentNode = greedyChoice(currentNode,dijkstraTable,visited); //5- greedy local choice: choose the next node with the smallest cumulative distance from the current node
            for (int n: Nodes){
                if (linearSearch(visited, n) >=0 && dijkstraTable[visited[visited.size()-1]][n][0] == (int)INFINITY){ //keep visited nodes and evaluated then neighbors intact
                    dijkstraTable[currentNode][n] = {(int)INFINITY};
                } else {
                    dijkstraTable[currentNode][n] = dijkstraTable[visited[visited.size()-1]][n]; //recursive inheritance
                }
            }
            sumDist += dijkstraTable[visited[visited.size()-1]][currentNode][0]; //reset of cumulative residual if no better path is found 
            t++; 
        } //6- repeat until all nodes are visited (source-to-many) or the destination node is visited (source-to-destination)Q

        // Forward Path is used to evaluate cumulative distances from the source to any other node including the destination 
        // -> the forward path is not guaranteed to be the shortest path due to greedy choices: it's the path produced by standalone greedy algorithm (i.e., without relaxation)
        // -> the forward path is the shortest path if the greedy choices are safety choices i.e., 'lucky' choices in which case it's identical to the backward path
        // -> the forward path is exploitative (greedy), the backward path is explorative (relaxation)
        // -> the backward path is identical to the forward path in absence of relaxation, the forward path is identical to the backward path in presence of safety choices.

        // Backward Path Construction: starting from the destination and back to the source -> backward paths are the shortest paths
        int node = visited[visited.size()-1]; //starting with destination
        int t = 1;
        while (t < this->getOrder()){
            shortPath.push_back(dijkstraTable[node][node]);
            node = dijkstraTable[node][node][1]; //update the node to its previous node in the backward path
            t++;
        }
        return shortPath; 
    }

    // Bellman Principle (Dynamic Programming) -> principle of optimal substructure: an optimal solution to the problem is also an optimal solution to any subproblem of the problem (the opposite, that an optiumal solution to subproblems is an optima solution to the problem, is not necessarily true due to submodularity of greedy choices (non-linearity), but true under safety choices where greedy local optimality suffices for global optimality due to its modularity (linearity) 'line up)
        // Bellman equation: an equation that results from the Bellman principle (principle of optimal substructure). How to find it? Reverse-Engineering (Backpropagation): solve the reverse problem of going from the problem optimal solution to the subproblem optimal solution, instead of the forward problem
        //1- Assume that you have the optimal solution to the problem
        //2- Derive a subproblem from the problem based on an intermediary pivot or decision
            //2.1- the pivot is chosen as the argmin/argmax of the cumulative objective function = argmin/argmax of the immediate cost/reward + objective function on the subproblem (non-linear & global optimality)
            //Calculating the pivot or decision for the state transition (choosing the optimal subproblem) is exhaustive as it requires backpropagating to examine all possible cases of A(s) (exploration)
            //V(s) = opt_{a \in A(s)}(R(s,a) + V(T(s,a))) [RL=: V(s) =  R(s,a) + gamma * sum(P(s'|s)V(s'))] where:
                // V is the value, policy function or objective function at state s
                // opt is either max or min
                // a is the pivot or decision variable responsible for state transition s -> T(s,a) = s' => A(s) is the decision set of feasible decisions or intermediary pivots to hop on next state
                // s is the current state (current value of the decision variable)
                // R(s,a) is the immediate reward or cost between s and a
                // T(s,a) = s' is the next state after chosing decision a
                // P(s'|s) is the transition probability from current state s to next state s'
        //3- Write down the optimal solution of the problem in terms of the optimal solutions of the subproblems on intermediary pivot
        //4- Treat the subproblem as the problem and repeat
        //5- Implementation: Due to partial observability, it's not possible to determine the subproblem pivot argmin/argmax or state transition (decision a) a priori in practice. Therefore, incremental relaxation is used i.e., loop through the set of feasible decisions A(s), update V(s) only if a better optimal value is found (relaxation) otherwise keep the best value found so far, repeat until A(s) is exhausted: V(s)_{k+1} = opt(V(s)_{k}, opt_{a \in A(s)}(R(s,a) + V(T(s,a))_{k})). The incremental relaxation can be performed in two ways:
            // Iterative Bottom-up (+ tabulation for overlapping subproblems) until the A(s) is exhausted out.
            // Recursive Top-down (+ memoization for overlapping subproblems) until the base case is reached (recursive leap of faith: correctness of recursion). 

    // Bellman principle: For every node v, the set of feasible decisions A(v) = N(v)
    int BellmanFord(int source, int destination){ //Bellman-Ford algorithm handles negative edges unlike the Dijkstra algorithm which doesn't revisit nodes that are marked as visited because, due to positive weights, the cumulative distance can only stay constant or increase.
        // if there is a negative weight cycle, the shortest path doesn't exist unless edge-visit-once constraint is added (simple walk): return -1 -> proof: proof by contradiction + closed walk aggregation invariance: assume there is a shortest path -> traverse the cycle -> short path -> traverse the cycle again -> shorter path -> repeat
        // if the vertex dest can't be reached, then return 10^8
        //1- Initialize distance to all vertices to infinity except source with 0
        //2- Edge Relaxation: for every directed edge from u to its neighbors v (u,v): if d[v] > d[u] + w(u,v), then d[v] = d[u] + w(u,v)
        //3- Greedy choice; choose the neighbor with least cumulative distance (only used as a traversal mechanism as optimality is ensured by the Bellman principle)
        //4- Repeat n-1 times
        //5- Try one more repetition to check for negative weight cycle: if the nth repetition results in a relaxation of the nth edge, if it exists (cycle), i.e., d[N(ln)] > d[ln] + w(N(ln),ln) then there is no short path due to negative weight cycle
        int n = this->getOrder();
        vector<vector<int>> shortPath = {{0,0}}; 
        map<int,int> distance; 
        for (int j: Nodes){
            distance[j] = INFINITY;
        }
        distance[0] = 0; 
        int t = 0;
        int cn = source; 
        vector<int> visited = {cn};
        while (t < n){ //run n-1 relaxations + 1 additional relexation for check
            map<int,int> neighDist; 
            for (int j: adjList[cn]){
                if (j != visited[visited.size()-1] && distance[j] > distance[cn] + adjMat[cn][j]){
                    distance[j] = distance[cn] + adjMat[cn][j]; //relaxation by cumulative distance (Bellman equation; distance[j] = min(distance[j], distance[cn] + weight(cn,j)))
                    if (t == n-1){ //nth edge relaxation implies a negative weight cycle => no short path exist 
                        return -1;
                    }
                }
                neighDist[distance[j]] = j;
            }
            // greedy choice
            int k = INFINITY;
            for (const auto& [key,_]: neighDist){
                if (k > key) k = key;
            }
            cn = Nodes[neighDist[k]]; 
            visited.push_back(cn); 
            shortPath.push_back({cn,k}); 
            t++; 
        }

        if (linearSearch(visited,destination) == -1) return pow(10,8); //destination is unreachable
        else return distance[destination]; 

    }   

    // Bellman principle: For every pair of nodes i and j, the set of feasible decisions A(ij) = k where k is an intermediary node between i and j i.e., k is in the path of i and j
    int FloydWarshall(int source, int destination){
        vector<int> bfs = cycleDetection(0);
        if (replica(bfs)){ //if there is a cycle
            int weightSum = 0; 
            for (int k = 0; k < bfs.size();k++){
                weightSum += adjMat[bfs[k]][bfs[k+1]];
            }
            if (weightSum < 0) return -1; //negative weight cycle
        }
        
        vector<vector<int>> distance;
        for (int i = 0; i < getOrder(); i++){
            for (int j = 0; j < getOrder(); j++){
                if (i == j) distance[i][j] = 0; 
                else if (linearSearch(adjList[i],j) >= 0) distance[i][j] = adjMat[i][j]; //direct nodes
                else distance[i][j] = INFINITY; //intermediary nodes
            }
        }
        for (int k = 0; k < getOrder(); k++){ //k as the pivot i.e., intermediary node for subproblem construction
            for (int i = 0; i < getOrder(); i++){ //sources
                for (int j = 0; j < getOrder(); j++){//destinations
                    if (distance[i][k] != INFINITY && distance[k][j] != INFINITY) distance[i][j] = min(distance[i][j] , distance[i][k] + distance[k][j]); //Bellman equation
                    
                }
            }
        }

        return distance[source][destination]; 
    }

    // Path Finding algorithm on a 2D grid with obstacles
    void Astar(int source, int destination){
        map<int,int> f; //f(n) = g(n) + h(n):= movement cost from source to current node + estimated movement cost from current node to destination

        int cn = source;
        for (int n: adjList[cn]){
            f[n] = adjMat[cn][n]; 
            int h = 0;
            for (int rn: Nodes - adjList[cn]){
                if (rn != cn) h+= 0;
            }
        }
    }

    //Flow Optimization: a linear programming optimization problem where the objective function is the flow to be maximized subject to edge capacity constraints
    //Flow Optimization can be transfer-and-conquered into a linear progrmaming problem and solved with the simplex algorithm
    //Flow Optimization problem is the primal of the dual Minimum Cut problem -> Max-Flow Min-Cut theorem (Strong Duality theorem): the maximum flow that could be transmitted from source to sink is the capacity of the minimum s-t cut.

    //Augmenting Path: a minimal sequence of edges starting from the source and ending in the sink where the weight of each edge is strictly positive i.e., a path of edges that can transmit or push a (additional) flow from source to sink.
    //In linear programming terms:
        // flow is the objective function to be maximized
        // edge  is the decision variable (as many decision variables as total edges in the original graph)
        // constraints:
            // Flow on an edge doesn’t exceed the given capacity of the edge.
            // An incoming flow is equal to an outgoing flow for every vertex except s (0 in-degree) and t (0 out-degree) => every other node is not a sink or source other than s and t.
            // Edges should form an augmenting path from source to sink i.e., minimumn number of edges of strictly positive weight/capacity + first edge adjacent to source and last edge adjacent to sink
            // Interlocking constraints between augmenting paths i.e., set or sequence of edges
        // A combination of augmenting paths is the pivot or vertex of the feasible region. Going from set of augmenting paths to the next is akin to traversing from one vertex of the feasible region to the next

    //Ford-Fulkerson: optimize the flow from a source to a sink subject to edge capacity constraints in a directed weighted network by finding augmenting paths in a residual graph
    //-> the gist of the idea is to continuously push flow through available augmenting paths from source to sink until no flow can be added (i.e., no augmenting path can be found from the source to the sink i.e., all augmenting paths are exhausted)
    // Ford-Fulkerson has no defined augmenting path finding implementation (e.g., random selection, DFS, BFS, etc.): usually uses DFS -> O(E x |f*|) where f* is the maximum flow
    int FordFulkerson(int source, int sink){
        int max_flow = 0;
        //residual graph: the graph that results from subtracting max flow from the original graph edge capacities at each iteration i.e., a graph with edge of residual capacities (0 residual capacity means no edge)
        vector<vector<int>> RG;
        // converting RG to a directed graph via zero-padding based on some regular criterion (e.g., k < j superior-triangular adjacency matrix)
        for (int k = 0; k < getOrder(); k++){
            for (int j = 0; j < getOrder(); j++){
                if (k == j) RG[k][j] = 0;
                else if (k > j){
                    RG[k][j] = this->adjMat[k][j];
                } else {
                    RG[k][j] = 0; //zero-padding
                }
            }
        } 
        //BFS on the residual graph
        vector<int> dfs = DFSPathFinder(source,RG);
        // the condition below is a linear programming constraint: did we exhaust all the constraints or not yet ?
        // the condition expressed in terms of source and sink: as long as the source has exiting edges (strictly positive outdegree) and sink has entering edges (strictly positive in-degree)
        while (dfs.size() != 0 && linearSearch(dfs, sink) >= 0){ //as long as an augmenting path can be found from source to sink in the residual graph
            // naive greedy choice in augmenting path finding (neighbor greedy filtration based on maximum weight on the dfs)
            vector<int> augPath = {source}; //augmenting path (a path graph P_{n} where each consecutive elements are adjacent vertices)
            int currentNode = augPath[0];
            vector<int> visited;
            while (currentNode != sink){
                if (RG[currentNode][sink] > 0){ //if the sink is a neighbor of the current node, break => augmenting path as a minimal sequence of edges
                    augPath.push_back(sink);                     
                    break;
                }
                int weight = 0; 
                vector<int> neighbors; 
                for (int n: dfs){
                    if (linearSearch(adjList[currentNode],n) >= 0 && linearSearch(visited, n) == -1){
                        vector<int> tempBFS = DFSPathFinder(n, RG, visited); //to check whether the greedy choice reaches the sink or not
                        if (weight < RG[currentNode][n] && linearSearch(tempBFS, sink) >= 0){ //maximum edge weight 
                            weight = RG[currentNode][n];
                            neighbors.push_back(n);
                            visited.push_back(n); //mark as visited
                        }                        
                    }
                }
                currentNode = neighbors[neighbors.size()-1];
                augPath.push_back(currentNode); //greedy choice for neighbor granted that it reaches the sink
            }

            // find the maximum flow possible along the augmenting path to add it to the overall maximum flow (maximum flow = bottleneck: the minimum residual capacity along the augmenting path)
            int flow = INFINITY; 
            for (int k = 0; k < augPath.size()-1; k++){
                if (flow > RG[augPath[k]][augPath[k+1]]){ //bottleneck: minimum residual capacity in the residual graph's augmenting path (augPath)
                    flow = RG[augPath[k]][augPath[k+1]]; //maximum flow = f(e) = min(C(e)- f(e)) for all e in augPath
                }
            }
            
            // add it to the overall maximum flow
            max_flow += flow; 
            // update the residual: the residual capacity of each edge is the original capacity of the edge - the flow in the edge; C(e) - f(e)
            for (int k = 0; k < augPath.size()-1; k++){
                RG[augPath[k]][augPath[k+1]] -= flow; //decrement forward edge in the augmenting path
                RG[augPath[k+1]][augPath[k]] += flow; //increment backward edge with residual capacity as the current flow passing from the forward edge which can be undoed -> once the residual capacity of the forward edge is zero or less, backward edge residual capacity is going to reach the original capacity of the forward edge -> used for undo operations (exploration)
                // Some edge combinations are better than others -> the naive greedy choice may not guarantee theoretical maximum flow because it reasons local neighbor-wise, thereby possibly precluding optimal edge combinations (optimal paths)
                // Some augmenting paths are better than others, but the problem is that sub-optimal augmenting paths--constructed with local greedy choice, may preclude globally optimal ones depending on their order of choice
                // undo operation to render naive greedy choice explorative in terms of augmenting path construction -> this makes the use of backward edges in the residual graph
            }
            // compute the augmenting path if it exists
            dfs = DFSPathFinder(source,RG);
            }

        return max_flow;
    }

    // Below, the Edmonds-Karp implementation of the FF is used i.e., BFS path finding -> O(V x E^2).
    int EdmondsKarp(int source, int sink){
        int max_flow = 0;
        //residual graph: the graph that results from subtracting max flow from the original graph edge capacities at each iteration i.e., a graph with edge of residual capacities (0 residual capacity means no edge)
        vector<vector<int>> RG;
        // converting RG to a directed graph via zero-padding based on some regular criterion (e.g., k < j superior-triangular adjacency matrix)
        for (int k = 0; k < getOrder(); k++){
            for (int j = 0; j < getOrder(); j++){
                if (k == j) RG[k][j] = 0;
                else if (k > j){
                    RG[k][j] = this->adjMat[k][j];
                } else {
                    RG[k][j] = 0; //zero-padding
                }
            }
        } 
        //BFS on the residual graph
        vector<int> bfs = BFSPathFinder(source,RG);
        // the condition below is a linear programming constraint: did we exhaust all the constraints or not yet ?
        // the condition expressed in terms of source and sink: as long as the source has exiting edges (strictly positive outdegree) and sink has entering edges (strictly positive in-degree)
        while (bfs.size() != 0 && linearSearch(bfs, sink) >= 0){ //as long as an augmenting path can be found from source to sink in the residual graph
            // naive greedy choice in augmenting path finding (neighbor greedy filtration based on maximum weight on the bfs)
            vector<int> augPath = {source}; //augmenting path (a path graph P_{n} where each consecutive elements are adjacent vertices)
            int currentNode = augPath[0];
            vector<int> visited;
            while (currentNode != sink){
                if (RG[currentNode][sink] > 0){ //if the sink is a neighbor of the current node, break => augmenting path as a minimal sequence of edges
                    augPath.push_back(sink);                  
                    break;
                }
                int weight = 0; 
                vector<int> neighbors; 
                for (int n: bfs){
                    if (linearSearch(adjList[currentNode],n) >= 0 && linearSearch(visited, n) == -1){
                        vector<int> tempBFS = BFSPathFinder(n, RG, visited); //to check whether the greedy choice reaches the sink or not
                        if (weight < RG[currentNode][n] && linearSearch(tempBFS, sink) >= 0){ //maximum edge weight 
                            weight = RG[currentNode][n];
                            neighbors.push_back(n);
                            visited.push_back(n); //mark as visited
                        }                        
                    }
                }
                currentNode = neighbors[neighbors.size()-1];
                augPath.push_back(currentNode); //greedy choice for neighbor granted that it reaches the sink
            }

            // find the maximum flow possible along the augmenting path to add it to the overall maximum flow (maximum flow = the minimum residual capacity along the augmenting path)
            int flow = INFINITY; 
            for (int k = 0; k < augPath.size()-1; k++){
                if (flow > RG[augPath[k]][augPath[k+1]]){ //minimum residual capacity in the residual graph's augmenting path (augPath)
                    flow = RG[augPath[k]][augPath[k+1]]; //maximum flow = f(e) = min(C(e)- f(e)) for all e in augPath
                }
            }
            
            // add it to the overall maximum flow
            max_flow += flow; 
            // update the residual: the residual capacity of each edge is the original capacity of the edge - the flow in the edge; C(e) - f(e)
            for (int k = 0; k < augPath.size()-1; k++){
                RG[augPath[k]][augPath[k+1]] -= flow; //decrement forward edge in the augmenting path
                RG[augPath[k+1]][augPath[k]] += flow; //increment backward edge with residual capacity as the current flow passing from the forward edge which can be undoed -> once the residual capacity of the forward edge is zero or less, backward edge residual capacity is going to reach the original capacity of the forward edge -> used for undo operations (exploration)
                // Some edge combinations are better than others -> the naive greedy choice may not guarantee theoretical maximum flow because it reasons local neighbor-wise, thereby possibly precluding optimal edge combinations (optimal augmenting paths)
                // Some augmenting paths are better than others, but the problem is that sub-optimal augmenting paths--constructed with local greedy choice, may preclude globally optimal ones depending on their order of choice
                // undo operation to render naive greedy choice explorative in terms of augmenting path construction -> this makes the use of backward edges in the residual graph            
            }
            // compute the augmenting path if it exists
            bfs = BFSPathFinder(source,RG);
            }

        return max_flow;
    }

    //Dinic algorithm
     
    
    //Minimum Cut problem: find the minimum cut i.e., cut with the minimum cost (minimum total removed egdge capacities or weights)
    //Variations:
        //1- s-t min cut: the minimum cut it takes to separate a source vertex s from a sink vertex t
        //2- Global min-cut: the minimum cut it takes to partition the graph vertices into two disjoint sets without specifying source and sink
    //Cut: a partition of the graph vertices V into two disjoint sets S and T after cutting or removing edges.
    //Cut-Set: the set of edges that joins an endpoint from S and an endpoint from T (co-cycle [S,T])
    //Minimum Cut: the cut with minimum total edge capacities or weights.


    //Edmonds-Karp algorithm: based in the max-flow min-cut theorem (strong duality theorem): the max flow in a directed weighted network is the min cut of that network
    vector<vector<int>> EdmondsKarpCut(int source, int sink){
        vector<vector<int>> cutSet; //co-cycle [S,T]
        //residual graph: the graph that results from subtracting max flow from the original graph edge capacities at each iteration i.e., a graph with edge of residual capacities (0 residual capacity means no edge)
        vector<vector<int>> RG;
        // converting RG to a directed graph via zero-padding based on some regular criterion (e.g., k < j superior-triangular adjacency matrix)
        for (int k = 0; k < getOrder(); k++){
            for (int j = 0; j < getOrder(); j++){
                if (k == j) RG[k][j] = 0;
                else if (k > j){
                    RG[k][j] = this->adjMat[k][j];
                } else {
                    RG[k][j] = 0; //zero-padding
                }
            }
        } 
        //BFS on the residual graph
        vector<int> bfs = BFSPathFinder(source,RG);
        // the condition below is a linear programming constraint: did we exhaust all the constraints or not yet ?
        // the condition expressed in terms of source and sink: as long as the source has exiting edges (strictly positive outdegree) and sink has entering edges (strictly positive in-degree)
        while (bfs.size() != 0 && linearSearch(bfs, sink) >= 0){ //as long as an augmenting path can be found from source to sink in the residual graph
            // naive greedy choice in augmenting path finding (neighbor greedy filtration based on maximum weight on the bfs)
            vector<int> augPath = {source}; //augmenting path (a path graph P_{n} where each consecutive elements are adjacent vertices)
            int currentNode = augPath[0];
            vector<int> visited;
            while (currentNode != sink){
                if (RG[currentNode][sink] > 0){ //if the sink is a neighbor of the current node, break => augmenting path as a minimal sequence of edges
                    augPath.push_back(sink);                  
                    break;
                }
                int weight = 0; 
                vector<int> neighbors; 
                for (int n: bfs){
                    if (linearSearch(adjList[currentNode],n) >= 0 && linearSearch(visited, n) == -1){
                        vector<int> tempBFS = BFSPathFinder(n, RG, visited); //to check whether the greedy choice reaches the sink or not
                        if (weight < RG[currentNode][n] && linearSearch(tempBFS, sink) >= 0){ //maximum edge weight 
                            weight = RG[currentNode][n];
                            neighbors.push_back(n);
                            visited.push_back(n); //mark as visited
                        }                        
                    }
                }
                currentNode = neighbors[neighbors.size()-1];
                augPath.push_back(currentNode); //greedy choice for neighbor granted that it reaches the sink
            }

            // find the maximum flow possible along the augmenting path to add it to the overall maximum flow (maximum flow = the minimum residual capacity along the augmenting path)
            int flow = INFINITY; 
            for (int k = 0; k < augPath.size()-1; k++){
                if (flow > RG[augPath[k]][augPath[k+1]]){ //minimum residual capacity in the residual graph's augmenting path (augPath)
                    flow = RG[augPath[k]][augPath[k+1]]; //maximum flow = f(e) = min(C(e)- f(e)) for all e in augPath
                }
            }
            
            // update the residual: the residual capacity of each edge is the original capacity of the edge - the flow in the edge; C(e) - f(e)
            for (int k = 0; k < augPath.size()-1; k++){
                RG[augPath[k]][augPath[k+1]] -= flow; //decrement forward edge in the augmenting path
                if (RG[augPath[k]][augPath[k+1]] <= 0){
                    cutSet.push_back({augPath[k],augPath[k+1]});
                }
                RG[augPath[k+1]][augPath[k]] += flow; //increment backward edge with residual capacity as the current flow passing from the forward edge which can be undoed -> once the residual capacity of the forward edge is zero or less, backward edge residual capacity is going to reach the original capacity of the forward edge -> used for undo operations (exploration)
                // Some edge combinations are better than others -> the naive greedy choice may not guarantee theoretical maximum flow because it reasons local neighbor-wise, thereby possibly precluding optimal edge combinations (optimal augmenting paths)
                // Some augmenting paths are better than others, but the problem is that sub-optimal augmenting paths--constructed with local greedy choice, may preclude globally optimal ones depending on their order of choice
                // undo operation to render naive greedy choice explorative in terms of augmenting path construction -> this makes the use of backward edges in the residual graph            
            }
            // compute the augmenting path if it exists
            bfs = BFSPathFinder(source,RG);
            }

        return cutSet;
    }

    //Karger algorithm: A stochastic sampling on Edmond-Karps to find the smallest number of edges that disconnect the graph into two disjoint sets S and T in an undirected & unweighted graph
        //1- Construct a conctract graph as original graph copy
        //2- Pick a random pair of nodes from the contract graph
        //3- Edge contraction: merge the randomly selected nodes into one and remove self-loops -> add each contracted edge to the cut set.
        //4- Repeat until the order of the contract graph is 2
    //The Karger algorithm uses the Monte-Carlo method for random sampling which means that it merely yields an approximate solution (sub-minimum cut)
    vector<vector<int>> Karger(){
        vector<vector<int>> cutSet;
        vector<vector<int>> CG = this->adjMat; //Contract Graph: initially initialized to be an exact copy of the original graph
        int N = CG.size(); 

        map<int, int> visited; 
        // 1. Obtain a random seed from the hardware
        random_device rd; 
        
        // 2. Initialize the standard mersenne_twister_engine with the seed
        mt19937 gen(rd()); 
        
        // 3. Define the inclusive range [min, max]
        uniform_int_distribution<int> distrib(0, N-1);
        
        // Monte-Carlo sampling on the set of vertices
        int k = distrib(gen); //first random node
        int j = distrib(gen); //second random node
        while (k == j){
            int k = distrib(gen); //first random node
            int j = distrib(gen); //second random node
        }
        visited[k] = 1;
        visited[j] = 1;
        
        // edge contraction
        cutSet.push_back({k,j}); //add the edge to the cut set
        CG[k][j] = CG[j][k] = 0; //remove self-loops prior to node merging  
        k = j; //or use the Cantor pairing function: 1/2 (x + y)(x + y + 1) + y
        N--; 

        while (N > 2){ //while the number of vertices is strictly greater than 2 -> halt once it reaches 2
            // Monte-Carlo sampling on the set of vertices
            int k = distrib(gen); //first random node
            int j = distrib(gen); //second random node
            while (k == j || (visited[k] == 1 && visited[j] == 1)){
                int k = distrib(gen); //first random node
                int j = distrib(gen); //second random node
            }
            visited[k] = 1;
            visited[j] = 1;

            // edge contraction
            cutSet.push_back({k,j}); //add the edge to the cut set
            CG[k][j] = CG[j][k] = 0; //remove self-loops prior to node merging  
            k = j; //or use the Cantor pairing function
            N--; 
        }

        return cutSet; 

    }

        
    //Minimum Spanning Tree: Kruskal, Prim
    
    //Spanning Tree is a subgraph in a graph G that is a tree (connected + acylical) that contains all vertices of G => ST is just a dominating set and its edges.
    //Minimal Spanning Tree: a spanning tree that doesn't contain or is a superset of any other spanning tree.
    //Minimum Spanning Tree: a spanning tree with the smallest cumulative weight of edges.
    bool checker(vector<vector<int>> arr, vector<int> target){
        for (vector<int> a: arr){
            if ((a[0] == target[0] && a[1] == target[1]) && (a[0] == target[1] && a[1] == target[0])){
                return true;
            }
        }
        return false; 
    }

    // Krusal algorithm builds the minimum spanning tree edge-by-edge (fit for sparse graphs)
    vector<vector<int>> Kruskal(){//effective number of edges in the subgraph shouldn't exceed n-1 or else it produces a cycle (pigeonhole principle)  
        int n = this->getOrder();
        vector<vector<int>> edges; 
        for (int n: Nodes){
            for (int k: adjList[n]){
                if (checker(edges, {n,k})) edges.push_back({n,k}); 
            }
        }
        vector<int> edgeWeights;
        for (vector<int> edge: edges){
            edgeWeights.push_back(adjMat[edge[0]][edge[1]]);
        }
        edgeWeights = selectionSort(edgeWeights); 
        
        for (int k = 0; k < edgeWeights.size(); k++){
            for (int j = 0; j < edges.size(); j++){
                vector<int> edge = edges[j];
                if (adjMat[edge[0]][edge[1]] == edgeWeights[k]){
                    vector<int> z = edges[k]; 
                    edges[k] = edges[j];
                    edges[j] = z;
                }
            }
        }

        vector<int> disjointSet; //contains the vertices of the graph
        vector<vector<int>> MST; //set that stores the edges (pair of vertices) of the spanning tree 
        int t = 0; 
        while (disjointSet.size() < n || MST.size() < n-1){//no need to check for both conditions: if a graph is connected & acyclical, then n nodes are joined by exactly n-1 edges, no more (due to acyclical) no less (due to connected). 
            vector<int> edge = edges[t];
            MST.push_back(edge);
            if (linearSearch(disjointSet,edge[0]) == -1) disjointSet.push_back(edge[0]);
            if (linearSearch(disjointSet,edge[1]) == -1) disjointSet.push_back(edge[1]);
            t++; 
        }

        return MST;
    }

    // Prim algorithm builds the minimum spanning tree node-by-node (fit for dense graphs)
    vector<int> Prim(){
        vector<int> MST; //the elements of the Prim MST are vertices (nodes) such that two consecutive nodes are necessarily adjacent and joined by the minimum-weight edge of the first node i.e., Prim MST is a minimum-weight path with k vertices and k-1 edges.
        vector<int> outNodes = Nodes - MST; //the algorithm divides the set of nodes into: outNodes: set of nodes outside of the MST, inNodes: set of nodes witin the MST
        while (MST.size() < this->getOrder()){ //this also ensures that no cycles are formed; in a connected graph (m>=n-1), a graph is acylical <=> m = n-1 (m > n-1 are eliminated) 
            int currentNode = outNodes[0]; //center on an unvisited node: tabu mechanism on next chosen nodes
            MST.push_back(currentNode);
            int outNode = currentNode; 
            int distance = INFINITY; 
            for (int n: adjList[currentNode]){
                if (distance > adjMat[currentNode][n] && linearSearch(outNodes, n) >= 0){ //outNodes function also as a tabu mechanism on neighbors (no need for visited[k])
                    distance = adjMat[currentNode][n]; 
                    outNode = n; 
                }
            }
            if (outNode != currentNode) MST.push_back(outNode);
            outNodes = Nodes - MST;
        }        
        return MST; 
    }

    //Assignment: Gale-Shapley 
    //Topological Sorting (DAG)
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


