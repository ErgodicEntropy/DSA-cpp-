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


// Family of algorithms: DSA, ML/DL, OR, NA, Artificial Life

// Types of algorithms: Sublinear, Logarithmic, Logarithmic-Linear, Linear, Polynomial, Pseudo-Polynomial, Exponential, Superexponential


//Algorithm Design

///1- There is no generic procedure to solve problems i.e., there is no meta-algorithm to create algorithms
///2- Practice designing algorithms
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


////Search: no need to implement linear, binary or n-ary search

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



class HashTable{

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


