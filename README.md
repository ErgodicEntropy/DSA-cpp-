# Data Structures and Algorithms Course Notes

In computer science, data structures and algorithms are essential topics that every programmer needs to learn. Data structures are a way to store and organize data, while algorithms are a sequence of steps to solve a problem.

## 1. Data Structures

### Definition

A data structure is a way to logically organize, store and fetch data in a computer so that it can be used efficiently. In programming terms, a data structure is an *abstract* non-primitive or composite data type i.e., a collection of elements arranged according to an abstract data type (ADT).

Each programming language has its own implementation of each data structure interface.  

### Types

- Linear vs Non-linear: elements arranged in a linear structure (arrays, queues, stack, etc.) vs non-linear structure (graph, tree, heap, etc.)
- Dynamic vs Static: size allocation or size known in runtime (variable-size) vs compile-time (fixed-size).
- Built-in vs Not Built-in (imported, user-defined, etc.)

### Data Storage and Fetch:

- Data Storage is how data structures store data. There are two ways that data structures store data: Contiguous/Continuous (Locality of Reference) vs Non-Contiguous/Continuous (Non-Locality of Reference) in terms of **Memory Address and Indexing**
- Data Fetch is how data structures retrieve data.
    
    → Both data storage and fetch are possible thanks to pointers ie; bit strings representing memory address that can be stored in memory or used in the program 
    

### Data Structure Properties

- Abstract Properties
    - Array: dimension (the nesting depth e.g., matrix is a 2D array, etc.), shape, etc.
    - Graphs: degree, topology, etc.
    - Tree: degree, levels, depth, etc.
- Implementation Properties
    - Memory: how much memory does a data structure implementation consume or allocates.

### Abstract Data Type: How Data is Organized

An abstract data type (ADT) is a mathematical model or abstract class (interface to be precise) of a data structure that defines constraints on its elements and the operations that can be performed on them, without specifying the internal implementation details (data storage, processing and retrieval, programming languages). In other words, an ADT provides a logical description of how data structures can be manipulated without revealing the underlying implementation.

- **Data values**
1. Type Homogeneity vs Type Heterogeneity
2. Element Size Homogeneity vs Element Size Heterogeneity
3. Replication
4. Modification
5. Order
- **Operations**

Data structures have several operations that can be performed on them, generally including:

1. Search/Contains: search for any data element in a data structure.
2. Sort: sort the elements either in ascending or descending order.
3. Traversal (Path Finding): traverse the elements of a data structure.
4. Reverse/Invert & Shuffle: reverse or invert a data structure order or shuffle it.
5. Min/Max/Sum/Mean/Size: aggregate functions if applicable.
6. isEmpty/isFull
7. Insertion/Add: insert new data elements in the data structure e.g., append, prepend, insert(index, element).
8. Read/Get: access a specific element in the data structure
9. Update/Set: modify or replace the existing elements from the data structure.
10. Delete/Remove: delete the data elements from the data structure e.g., remove(element), clear().

These operations are irreducible i.e., they aren’t the combination of other operations.

These operations are implemented the algorithms of a given data structure. More precisely, each operation of a data structure comprises many algorithms to implement it each with its own properties. In other words, algorithms are models with respect to each data structure operation: invariant, non-unique, and each with a given complexity. 

**Arrays**

A static, linear and built-in data structure with a contiguous or continuous data storage (locality of reference) with homogeneous elements (both type and size) that are ordered, modifiable and replicable. Arrays are memory-efficient, hence they can be used to model stacks.

There is a dynamic implementation of the array data structure by creating a new one each time resizing is needed (array size exceeded). Examples of this are ArrayList (java), Vector (C++), List (Python), Array (JS). This dynamic array implements the List interface along with Linked Lists with the following operations: add, get, set, remove, clear, size.

In terms of implementation across various languages, there are 3 types of array declarators:

- Static Array
    - incomplete array declarator: int[] arr (java), int arr[] (C/C++: requires initialization for size inference unless int arr[] is a function/method param in which it’s a pointer storing memory address of its first element), etc.
    - fixed-size array declarator: int[] arr = new int [3] (java), int arr[3] (C/C++), etc.
- Dynamic Array
    - variable-size array declarator: int[] arr = new [N] (java), int arr[N] (only valid in later versions of C/C++)

An array can be:

- searched: linear, binary, n-ary, jump, interpolation, exponential.
- sorted: selection, bubble, insertion, quick, merge, count, radix, bucket
- traversed
- reversed
- min/max/sum/mean/count
- accessed directly/randomly: element_address = array_address + (index x size_of_element) due to continuity and homogeneity of size.
- insert: inserting an element in the end is fine but in the beginning requires a shift of array’s length times.
- delete; same as insert
- modify

**Linked Lists**

A dynamic, linear and non-built-in data structure with a non-contiguous data storage with homogeneous elements (size and type) that are ordered, replicable and modifiable. Linked lists, due to their non-continuous use of pointers, are memory-inefficient. A linked list is used to model stacks, queues, and many other data structures.

A linked list can be:

- searched
- sorted: transform-and-conquer using array sorting algos
- traversed
- reversed
- accessed/read: access element in O(n) in worst-case.
- inserted: insert an element in O(1) both in best-case (end) and worst-case (start)
- deleted: delete an element in O(1) both in best-case (end) and worst-case (start)
- modified

There are 3 types of linked lists:

- Singly: a collection of nodes and each node is an aggregation of data value and a link pointer storing the memory address of the next node, with head having null value and link pointing to the first node, and tail having null value and nullptr pointer.
- Doubly: a collection of nodes and each node is an aggregation of data value and 2 link pointers storing the memory address of the next node and previous node respectively, with head having null value and next-link pointing to the first node and prev-link to nullptr, and tail having null value, prev-link pointing to last node and nullptr next-link pointer.
- Circular: A linked list where the tail loops back to the head as it link points to the head node.
    - Singly
    - Doubly

**Stacks**

A linear, dynamic and non-built-in data structure with non-contiguous data storage based on the LIFO principle (Last-In-First-Out) with homogeneous elements (size and type) that are ordered, replicable and modifiable. 

A stack is better implemented using linked lists, hence the use of head and tail pointers. However, it's more memory-efficient to use arrays except for the edge of case of resizing due to its fixed size.

A stack can be:

- peeked: return last element
- push: add or insert an element at the end of the stack.
- pop: remove or delete the last element of the stack.
- isEmpty
- Size

**Queues**

A linear, dynamic and non-built-in data structure with non-contiguous data storage based on the FIFO principle (First-In-First-Out) with homogeneous elements (size and type) that are ordered, replicable and modifiable. 

Much like graph theory covers graphs, queue theory covers queues.

A queue is a specific implementation of linked lists, hence the use of head and tail pointers.

A queue can be:

- enqueued: insert or add element at the end (or at the start).
- dequeued: remove or delete element at the start (or at the end).
- peek: return the element about to be dequeued.
- isEmpty: check if the queue is empty or not.
- size: return the number of the elements in the queue.

There are 3 types of queues:

- Simple Queue
- Priority Queue
- Circular Queue

**Hash Tables**

A linear, dynamic and non-built-in data structure with non-contiguous data storage with unordered, immutable and unique heterogeneous elements.  Hash tables are not indexed-based but hash code based which are (re)generated on the fly in each operation from the input element characteristics.

In hash tables, there is a 1..N-1 association or correspondence between elements and hash codes, i.e., each element is associated to one hash code (hence the unicity), a hash code can be associated to 1..N elements.  

Hash tables are more efficient than arrays or linked lists in terms of insertion, delete and search because they generate the hash code (corresponding index in the hash table) from the underlying characteristics of the input element on the fly. The efficiency of hash tables is dependent on how close the hash function is to being bijective.

The hash function tries to strike a balance or trade-off between insert/delete/search/get operations efficiency (bijection: each hash code associated to only one element) and memory usage efficiency (10 hash codes with modulo-10) → Pigeonhole principle.

Hash table is initiated with as 10 placeholders (0-9) initiated to None. 

The elements of a hash table are called buckets, modeled as arrays or linked lists, to prevent possible hash collisions through chaining (the pigeonhole principle).  

A hash table is implemented using:

- Set: collection of unordered, unique and immutable elements.
    - Hash Set
        - Hash Code: the index of the input element in the hash table as generated by the hash function.
        - Hash Function: a prior operation done on the input element (for int-conversion and/or miniaturization) + modulo 10 to generate the hash code. Hash function uses modular arithmetic (mod-10) for memory efficiency. e.g., char conversion to Unicode code point + 10 modulo, big-int → sum its digits (miniaturize) → 10 modulo.
        - Bucket: container (array or linked list) used to prevent hash collisions by storing elements with the same hash code.
        - Hash Collision: when two or more input elements share the same hash code → chaining for resolution: buckets as arrays or linked lists storing such elements.
        - Operations
            - add()
            - search()
            - remove()
            - clear()
            - contains()
            - size()
    - TreeSet: a sorted hash set (same ADT).
    - LinkedHashSet: an ordered hash set (same ADT).
- Map: collection of unordered, immutable and replicable entries (values are replicable, but keys are unique)
    - Hash Map
        - Entry: key-value pair.
        - key: unique identifier of the entry.
        - value: the value corresponding to a given key.
        - hash code: generated from the key.
        - Operations:
            - put()
            - get()
            - remove()
            - clear()
            - containsKey()
            - keySet()
            - values()
            - size()
    - TreeMap: a sorted hash map (same ADT).
    - LinkedHashMap: an ordered hash map (same ADT)

**Graphs**

DSA definition: graphs are a non-linear, dynamic and non-built-in data structure with unordered, mutable and replicable elements.

Discrete Mathematics/Operations Research definition: a graph is a collection or tuple of edges (links) and vertices (nodes) (V,E) governed by the incidence function $\psi(e) = \{v_1,v_2\} \space \forall v_1, v_1 \in V, e \in E$  or adjacency function $\theta(v_1,v_2)$ = 1 if $v_1$ and $v_2$ are incident to a common edge i.e., adjacent, 0 otherwise (same function can be applied to edges).

Graph theory is the mathematical theory that describes graphs from a discrete mathematics perspective. There are many sub-branches of graph theory: Algebraic, Spectral, Topological, Geometric, Random (e.g., Percolation theory), Extremal (e.g., Ramsey theory), Algorithmic (e.g., DSA, OR, etc.).

**+ Glossary & Terminology:**

Graph components:

- Nodes (Vertices)
    - Properties:
        - Degree: the number of neighborhoods + 2 if loop edge.
            - In-Degree: number of directed edges entering the node.
            - Out-Degree: number of directed edges leaving the node.
            - Handshake Lemma: $\Sigma_{v \in V(G)}d(v) = 2|E(G)|$
            - $|S =\{v \in V(G),\ d(v) = 2k +1 \}| = 2k’$
        - Weight
        - Neighborhood: the set of vertices connected or adjacent to the current vertex. This can extend to the neighborhood of a subset of vertices S in V.
    - Type:
        - weighted vs non-weighted
        - isolated: a node with degree equal to zero.
        - sink: a node with in-degree larger than its out-degree in a directed graph.
        - source: a node with in-degree smaller than its out-degree in a directed graph.
- Edges (Links): a binary relation between vertices where it’s said to join to pair of vertices called its ends.
    - Properties: weight, directionality
    - Type:
        - link (arete): a simple edge with distinct ends (bijective incident function) ⇒ $e = \{v_1, v_2\}$
        - loop: if its ends (incident vertices) are identical
        - parallel: if it shares the same ends with another edge.
        - weighted vs non-weighted
        - arrow: directed edge (arc)
    
    → Traversal
    
    - walk: a sequence of edges $e_i$ where each edge $e_i$ is adjacent to $e_{i-1}$ and $e_{i+1}$ with repetition.
        - open walk: a walk where the start and last vertices are distinct.
        - closed walk: a walk where the start and last vertices are identical.
        - undirected walk: chain (open) - cycle (closed)
        - directed walk: chemin (open) - circuit (closed)
        
        → length of a walk is the number of edges in the walk.
        
        → k-walk is a walk with length k. 
        
        → a walk is odd or even according to the parity of its length k.
        
    - trail: an elementary walk i.e., visits all vertices at most 1 time (0 or 1).
        - Hamiltonian trail: a trail that visits all vertices exactly once.
    - path: a simple walk i.e., visits all edges at most 1 time (0 or 1).
        - Eulerian path: a path that visits all edges exactly once → By the enter and exit logic: the number of nodes with odd degree should be 0 or 2  (Königsberg bridge problem).
    - cycle: a closed path i.e., the last vertex is the start index.
    - circuit: a closed trail or a directed closed path i.e., the last vertex is the start index.
    - tour: a circuit or a cycle.
        - Eulerian tour: a tour that visits all edges exactly once and back to the start vertex →  By the enter and exit logic: the number of nodes with odd degree should be 0 (or out-degree = in-degree in case of directed graph).
        - Hamiltonian tour: a tour that visits all vertices exactly once and back to the start vertex e.g., TSP.

Graph properties:

- Order
- Size
    
    → Dense Graph: a graph with too many edges to node ratio i.e., $m \geq n$
    
    → Sparse Graph: a graph with few edges to node ratio i.e., $m \leq n-1$
    
- Degree
    - Minimum Degree: the smallest degree in the graph denoted as $\delta(G)$
    - Maximum Degree: the largest degree in the graph denoted as $\Delta(G)$.
    - Average Degree: the average degree in the graph denoted as $d(G) = \frac{\Sigma_{v \in V(G)} d(v)}{|V(G)|}$
- Connectivity → Connected Component: set of vertices where any pair of vertices are connected via a path.
- Topology: edge distribution over the vertices, or, how are the vertices physically and logically linked (order + size + which vertices are adjacent to which vertices or incident to which edges and vice versa) e.g., bus, ring, star, extended star, hierarchical, mesh (full or partial). For a graph with order n, there are $2^{\frac{n(n-1)}{2}}$ topologies.
- Topological Ordering: ordering vertices such that for each edge $(u,v)$ $u$ comes before $v$ in the graph. Only possible if the graph is acyclic i.e., it doesn’t contain a subgraph that is a cycle.
- Crossing Number
- Embedding
- Graph Coloring: the coloring of graph vertices or edges such that no two pair of adjacent vertices or edges share the same color.
    - Four Color theorem: Every planar graph can be colored with 4 colors i.e., $\chi(G)=4$.
    - Brooks theorem: For every graph with a maximum degree $\Delta(G)$ can be colored with $\Delta(G)$ colors except if it is a complete graph/clique $K_n$ or an odd cycle $C_{2k+1}$.
- Chromatic Number $\chi(G)$: the minimum number of colors required to color the graph vertices.
- Chromatic Index $q(G)$: the minimum number of colors required to color the graph edges.
- Dominating Set: set of vertices where each vertex not in the set is adjacent to at least one vertex in the set → Any vertex is either in the dominating set or adjacent to at least one vertex in the set.
    - Minimal Dominating Set: a dominating set that can’t contain or get reduced to other dominating sets.
    - Minimum Dominating Set: a dominating set with the smallest number of vertices.
    - Dominating Number $\gamma(G)$: the number of vertices in the minimum dominating set.
- Clique: set of vertices where each vertex is adjacent to any other in the set.
    - Maximal Clique: a clique that can’t be contained within or extended to a larger clique.
    - Maximum Clique: a clique with the largest number of vertices.
    - Clique Number $\omega(G)$: the number of vertices in the maximum clique.
    - $\theta(G)$: minimum number of cliques required to cover all vertices of G.
- Independent Set (Stable): set of vertices where no pair of vertices are adjacent i.e., every edge of G is incident to at most one vertex in the IS.
    - Maximal Independent Set: an independent set isn’t contained within or extended to a larger independent set.
    - Maximum Independent Set: an independent set with the largest number of vertices.
    - Independence Number $\alpha(G)$: the number of vertices in the maximum independent set.
- Vertex Cover (Transversal): set of vertices C such that every edge of G is incident to at least one vertex in C.
    - Minimal Vertex Cover: a vertex cover that doesn’t contain a smaller vertex cover.
    - Minimum Vertex Cover: a vertex cover with the smallest number of vertices.
    - Vertex Cover Number $\beta(G)$: number of vertices in the minimum vertex cover.
- Matching (Couplage): set of edges without a common vertex.
    - Maximal Matching: a matching that can’t be contained within or extended to a larger matching.
    - Maximum Matching: a matching with the largest number of edges.
    - Matching number $\kappa(G)$: the number of edges in a maximum matching.
    
    → $\alpha(G) + \beta(G) = n$
    
    → $\chi(G) \cdot \alpha(G) \geq n$
    
    → $\alpha(G) = \omega(\overline{G})$
    
    → $\alpha(G) = \kappa(L(G))$
    
    → $\kappa(G) \leq \beta(G)$ (equality if G is bipartite due to Konig theorem)
    
    → $\theta(G) = \chi(\overline{G})$
    
    → $q(G) \geq \Delta(G)$
    
    → $\chi(G) \geq \omega(G)$
    
    → $\theta(G) \geq \alpha(G)$
    
    → $\chi(G) \leq 2$ if the graph is bipartite.
    
    → Mantel theorem: A graph G with n vertices without triangles $C_3$has at most $\lfloor \frac{n^{2}}{4} \rfloor$ edges.
    
    → Turan theorem:  A graph G with n vertices without (r+1)-cliques $K_{r+1}$ has at most $\lfloor (1-\frac{1}{r}) \frac{n^{2}}{2} \rfloor$ edges.
    
    → If a graph G doesn’t have a $K_r$ ⇒ G doesn’t have $K_s \space \forall s \geq r$.
    
- Ramsey Number $R(k,l)$: the minimum number of vertices in a graph so that the graph either has an independence set of size $k$ or a clique of size $l$.
    - Ramsey theorem: $R(k,l) \leq R(k-1,l) + R(k,l-1)$
- Line Graph $L(G)$
- Complementary Graph $\overline{G}$
- Subgraph: a graph on a subset of the set of vertices or edges or both of the original graph.
    - Co-cycle [W, V/W]: set of edges that joins an end in W with an end outside of W.
    - Co-circuit: a directed co-cycle with either zero out-degree or zero in-degree.
    - E(W): set of edges that joins both ends from W.
    - Induced: a graph (W,E(W)) on subset of G vertices W with their edges E(W).
    - Partial: a graph (V,F) on subset of G edges F $\subseteq$ E(G)
        
        → Any induced subgraph is a partial subgraph but the opposite is not necessarily true.
        
    - Spanning Tree: a subgraph of G that is a tree that contains all vertices of G.
        - Minimal Spanning Tree: a spanning tree that can’t contain another spanning tree.
        - Minimum Spanning Tree: a spanning tree with the smallest weight of edges (in contrast to the smallest number of edges because any tree has exactly $n-1$ edges, no more due to acylicity, no less due to connectedness).
- Minor: a graph that can be formed from deleting edges, deleting vertices or contracting edges of the original graph G. Minors are more general than subgraphs.
- Forbidden Graphs: a hereditary graph classes that can’t contain an exact copy of forbidden substructures as induced subgraphs, minors or topological minors.
    - Planar Graphs: a graph is planar if and only if it doesn’t contain $K_5$ or $K_{3,3}$ ($T_{2,3}$) → Kuratowski theorem
    - Bipartite Graphs: graphs that don’t contain odd cycles $C_{2k+1}$.
    - Trees: connected graphs that don’t contain cycles $C_k$.
    - Perfect Graphs: a graph is perfect if and only if it doesn’t contain odd cycles (holes) or their complements (antiholes) of length 5 or greater → Strong Perfect Graph theorem.
    - Chordal Graphs: a graph is chordal (triangulated) if and only if it doesn’t contain induced cycles of length 4 or greater.
- Isomorphic Graph: A graph $G$ and $H$ are isomorphic if there exists two bijections $\theta$ and $\phi$ such that $\theta: V(G) → V(H)$ and $\phi: E(G) → E(H)$ such that $\psi_G(e_G) = u_Gv_G$, it follows that $\psi_H(\phi(e_G)) = \theta(u_G)\theta(v_G)$

Family of graphs (topology classes):

- Directed (Digraph) vs Undirected
- Weighted vs Non-Weighted
- Cyclic vs Acyclic: a cyclical graph has at least one cycle in it i.e., $m \geq n$ (vertex is visited more than once i.e., both a start vertex and an end vertex) or it has redundant paths (or edges) by the pigeonhole principle (non-injective incidence function) i.e., non-unique paths between any pair of vertices.
    - Directed Acyclic Graph (DAG): a directed graph without cycle.
    - Path Graph $P_n$: simple graph that forms a path: a sequence of distinct $n$ vertices $v_1, v_2,…,v_n$ and distinct $n-1$ edges $(v_1,v_2), (v_2,v_3),…(v_{n-1},v_n)$.
    - Cycle Graph $C_n$: a simple graph that forms a cycle i.e., a closed path: a sequence of distinct $n$ vertices $v_1, v_2,…,v_n$ and distinct $n$ edges $(v_1,v_2), (v_2,v_3),…(v_{n-1},v_n), (v_n,v_1)$ i.e., start and last vertices are identical.
- Finite: a graph with a finite vertex and edge set.
- Null: a graph with zero vertices and edges.
- Trivial: a graph with one vertex.
- Simple: a graph with no loops or parallel edges.
- Complete (Clique $K_n$): a simple graph where any two vertices are adjacent i.e., V(V- 1)/2 undirected edges or V(V-1) directed edges.
- Empty: a graph in which no two vertices are adjacent (empty edge set).
- Bipartite: a graph where the vertex set can be partitioned into two subsets X and Y (parts of the bipartite graph) such that every edge of the graph has one end in X and one end in Y: (X,Y) is called the bipartition of the graph. A bipartite graph is also a graph where no odd cycles exist. This generalizes to k-partite graph.
    - Double Counting technique: a combinatorial technique used to calculate the size of a bipartite graph based on symmetry exploitation.
    - König theorem: In a bipartite graph, $\beta(G) = \kappa(G)$.
    - Hall theorem: For a bipartite graph $G = (L \cup R, E)$:
        - there exists a matching that is incident to the vertices of L if and only if $\forall S \subseteq L$ $|S| \leq |N(S)|$ → proof: cardinality for injective function existence.
        - there exists a perfect matching if and only if there are no obstacles i.e., set of vertices left undermatched or overmatched i.e., each vertex is matched to exactly one other vertex.
    - Perfect Matching (Complete Matching or 1-factor): a matching i.e., set of edges that form a one-to-one correspondence between the parts of the bipartite graph (parts of equal size).
- Complete Bipartite Graph: Any vertex in X is adjacent to any vertex in Y: $K_{s,r}$.
- Star: a complete bipartite graph where |X| = 1 but |Y| ≠ 1.
- Regular: a graph where all vertices have the same degree k (k-regular).
- Connected: a graph where every bipartition of its vertex set into nonempty subsets or parts X and Y, there is at least one edge that has an end in X and an end in Y, otherwise disconnected. Or that a path can be found between any two vertices X and Y. Or that there is one connected component.
    - Strongly Connected
    - Weakly Connected
    - #Connected Components ≥ $|V| - |E|$
- Tree: a connected graph without cycles, or, a connected graph of n vertices with n-1 edges, a graph with a unique path between any two pair of vertices.
    - Arborescence: a directed tree with a root r such that $d_{in}(r) = 0$ and $\forall v \in V(T) \space d_{in}(v)=1$
    - Any tree is bipartite.
- Planar: a graph that can be drawn such that no edges cross or intersect each others except in their common ends (incident vertices): such drawing is called the planar embedding of the graph.
    - Face (denoted as F) of a planar drawing: a region bounded by the edges of a planar graph → there is always one infinitely large outer face in any planar graph.
    - Euler Characteristic Formula: V - E + F = 2.
    - Given a planar graph $G_p$, $\exists v \in V(G_p)$, $d(v) \leq 5$
    - For every planar graph, $m \leq 3(n-2)$ $\forall n \geq 3$.
    - For every bipartite planar graph, $m \leq 2(n-2)$ $\forall n \geq 4$.
- Hypergraph: a graph where an edge (hyperedge) connects a subset of vertices i.e., 2 or more vertices.
- Multigraph: a graph where parallel edges are allowed.
- Pseudograph: a graph where self-loops are allowed.
- Euler Graph: a graph with an Eulerian tour or path.
- Hamiltonian Graph: a graph with a Hamiltonian tour or path.
- Turan graph $T_{k,n}$: a simple complete k-partite graph such that its order n is uniformly distributed across its parts $X_k$ → $T_{k,n} = K_{\underbrace{{n,n,n, \cdot\cdot\cdot,n}}_{k \space \text{times}}}$
- Pedersen Graph
- Cayley Graph
- Hypercube Graph
- Erdos-Renyi Graph (Random Graph)

Graph representations:

- Visual: graph drawing
- Tabular
    - Incidence Matrix: $M_G$ = $(m_{ve})$ where $m_{ve}$ is the number of times (0, 1 or 2) that a vertex $v$ and an edge $e$ are incident (loops count as 2)
    - Adjacency Matrix: $A_G$ = $(a_{uv})$ where $a_{uv}$ is the number of edges (0, 1 or 2 or more) joining vertices $u$ and $v$ (loops count as 2).
    - Adjacency List: $N(v)$ = the neighbors of vertex $v$ i.e., adjacent vertices sharing at least an edge with $v$ (e.g., map of index-list pairs with list as linked list or dynamic array)
    - Edge List: list down the edges of the graph in the form of pairs of nodes (e.g., 1x2 matrix)

## 2. Algorithms

### Definition

An algorithm is a sequence of steps, instructions, commands or statements that can be followed to solve a problem. Algorithms can be deterministic or stochastic. Deterministic algorithms produce the same output for a given input, while stochastic algorithms produce different outputs for a given input due to randomness.

**Representation**

An algorithm is visually represented by

- Flowchart
- Activity Diagram (control flow diagram)
- State-Machine Diagram
- Decision Tree
- Circuit (Logic Gates)

### Characteristics

- Input and Outputs should be well-defined and unequivocal.
- Each step in the algorithm should be clear, unambiguous, unequivocal and well-defined.
- Each step in the algorithm should be fine-grained (granularity) or low-level (abstraction).
- Each step in the algorithm should be independent or separate (no overlap, loosely coupled) and coherent (no contradiction, annulation or negation between steps) → modularity (separation of concerns)
- Each step in the algorithm should be concerned with one task: the smallest modular unit that can’t be further fragmented into sub-steps—a step is a task, not an activity or phase or process → single responsibility principle.
- Steps of an algorithm are its model: invariant, complexity, non-unique (different sets of steps can be used to achieve the same algorithmic strategy)
- Algorithms are strategic and abstract model in contrast to tactical and concrete implementations: the algorithm is a goal-orientation blueprint with many tactical-concrete implementations.
- The algorithm shouldn’t include computer code: it should be programming language free (pseudocode)

### Implementations

Algorithms can be divided into several main types based on their implementation, including:

- **In Place (memoryless):** converts the input into an output without allocating extra memory for input processing i.e. O(1) constant space complexity
- **Out-of-Place:** converts the input into an output by allocating extra memory for input processing i.e. space complexity that depends on the input size n
- **Online (Local):** processes the input piece-by-piece in a serial fashion according to the order the input is fed to it without having the entire input available ab ovo (horizon effect) → competitive online algorithm is one that matches the performance of its offline counterpart
- **Offline (Global):** processes the entire input ab ovo before computing an output
- **Deterministic:** produces the same output for the same input every time
- **Stochastic:** produces different output for the same input from a sampled possibility space
- **Recursive:** produces an output based on a recursive relation and base case (recursion tree)
- **Iterative:** produce an output based on a for or while loop
- **Bottom-Up:** processes the input from its simple components bottom-up.
- **Top-Down:** processes the input as a whole down to its simple components top-down.
- **Abstract (Implicit State):** when the input value is not known in advance → category-induction based algorithmic implementation based on a general pattern, abstract rule or underlying structure (penultimate step, proved conjecture, codified as formula/relation (equation/inequality) implemented by recursion or iteration) that abstracts or compresses all concrete instances or examples through redundancy elimination (deductive or general)
- **Concrete (Explicit State):** algorithm implemented for a specific, concrete instance or example ⇒ directly implementable as no abstraction is needed (inductive or specific) but at the cost of redundancy and noise (memory-inefficient as it uses auxiliary space).
    - Strong: input value is known in advance e.g., array of size 4, integer 2 as input, etc.
    - Weak (Hybrid): input is stored in a variable of any data type; simple/primitive or non-primitive/composite (data structure)
- **Eager:** compute things immediately & cache them until you need them (if at all)→ space-consuming.
    - Compile-Time Caching (Strong): needed values known in advance → no computation involved or computation is performed at compile-time or program startup e.g., precomputation (caching an relevant or needed values in advance in a variable prior to program execution or runtime)
    - Runtime Caching (Weak): compute on demand or on the fly the first time only and cache values until needed e.g., DP overlapping subproblems tabulation (iterative/bottom-up) or memoization (recursive/top-down).
- **Lazy:** compute things on demand or on the fly without caching → time-consuming.

### Properties

Algorithms have several properties that determine their effectiveness, including:

- Correctness (Halting): the ability to produce the correct output for a given input (usually Existence theorems)
- Stability: the ability to produce the same output for the same input, even if the input is slightly different (well-conditioned algorithms: low condition number)
- Precision: accuracy of convergence: exact vs approximate solution.
- Time Complexity (Speed or Convergence rate): the amount of time it takes to execute the algorithm → Time Complexity is asymptotic in terms of input size + worst-case scenario.
- Space Complexity: the amount of memory required to execute the algorithm and the accuracy of the output (call stack size) → Extra Memory and Auxiliary Space
- Conditions: the hypotheses or constraints that the algorithm works under e.g., binary search requires sorted arrays, etc. → the need to regularize the problem hypothesis (the given).

### Family of Algorithms

1. DSA algorithms: sorting algorithms, search algorithms, Brute Force, Divide-and-Conquer, Dynamic Prog, Greedy Algorithm
2. Numerical Analysis algorithms: root-finding algorithms, numerical quadrature, SVD, etc
3. ML/DL algorithms: linear regression, SVM, clustering, etc
4. Operations Research algorithms: Genetic Programming, Simulated Annealing, Tabu Search, etc.
5. Artificial Life algorithms: population algorithms, swarm intelligence algorithms, etc

### Types of Algorithms (Complexity Class): Analysis of Algorithms

#### Big O Notation

Big O notation is a mathematical notation used to describe the time complexity of an algorithm. It describes the upper bound of the growth rate of the algorithm's running time in relation to the input size. Time complexity is the amount of time it takes for an algorithm to execute as a function of the input size.

Big O notation is usually used to describe how an algorithm's running time grows as the input size grows. It is commonly used to compare the efficiency of different algorithms. 

#### Time vs Space Complexity

Time complexity describes how the running time of an algorithm grows with the input size, while space complexity describes how the amount of memory required by an algorithm grows with the input size.

In general, algorithms with lower time complexity and space complexity are more efficient than those with higher complexity.

#### Runtime Analysis:

- Runtime analysis is the process of calculating runtime T(n)
- Runtime analysis is not exactly accurate as it abstracts several factors such as memory management system and low-level functioning of the computer eg; assignment = 1 operation (but it’s actually more than that low-level wise)
- Runtime analysis is different from the number of lines of code
- Runtime depends on the computer machine hardware, CPU architecture, Compiler/Interpreter, programming language used, Memory Hierarchy…etc (in practice, it’s quite difficult to know all these things)
- Accurate Runtime is hard to compute because it involves a lot of factor. Therefore, we need to find a way to compute runtime without these details **(Asymptotic Notation, Big O Notation)**

→ **Asymptotic Notation: First, all details will abstracted in a constant multiple (eg; instead of T(n)= 2n+2, it’s going to be T(n) = kn ). However, this is not enough. What we need to measure runtime as a scale with the input size ie; how runtime changes asymptotically in a way that constant multiples can’t capture in the sense where the difference between scales is large enough**

**The following inequality is essential:** 

$$
log(n) < \sqrt{n} < n < nlog(n) < n^2 < n^3...etc < 2^n
$$

→ **Big O Notation:**

- **Definition:**
    
    $$
    f(x)=O(g(x))⟺∃ N,c such that ∀n>N, we have f(x)<c⋅g(x).
    $$
    
- **Intuition:** f(x) = O(g(x)) entails that the ratio f(x)/g(x) is bounded, which means that **f have lower growth rate compare to that of g** after abstract specific details (constants multiples) about each function ie; *roughly same nature (in terms of domination) but not same specifics*
- **Advantages:**  Clarifies growth rate visually, Clear up notations (algebraically easy to manipulate)
- **Warning:**
    - Big O notation abstracts a lot of important information and details that are necessary to figure out runtime practically: **IT’S NOT PRACTICAL**
    - Big O notation is only asymptotic in nature ie; only make sense for very very large input size (that may not be practical in terms of hardware functionality)

There exists other notations as well such that Small o (Strict Domination), Equivalence…etc

- **Worst Case vs Best Case scenario:** It’s preferrable to lean more towards the worst case scenario when evaluating the time complexity or space complexity of an algorithm since worst-case scenario is more of an accurate measure of algorithmic efficiency than best-case scenario (which leaves so much room for chance)
- **Average Case scenario:** it’s the scenario that happens when averaging a sufficient number of trials

→ Case scenarios are determined by the algorithm, and not by the data structure (eg; what is Best case or Worst case for Linear Search is not necessarily the same case for Binary search)

**Types of Runtime:** 

- **Logarithmic**
- **Sublinear**
- **Linear**
- **Linear-Logarithmic**
- **Polynomial**
- **Pseudo-Polynomial (polynomial in numeric value of the input [number of elements, max magnitude] but exponential in input length ie; number of bits required to represent the input) eg; Primality test, 0-1 Knapsack problem ⇒ Weak/Strong NP-hardness and NP-completeness (if the input is unary-encoded, pseudo-polynomial = polynomial)**
- **Exponential**
- **Superexponential**

#### No-Free Lunch Theorem:

- Any two algorithms are equivalent when their performances are average on all possible problems of the same class
    - Consequence: There is no best algorithm, there is only a worse or better algorithm depending on the context, specifics and scope of the problem/task

### Stress Testing:

- Theory: Rules and Exceptions (Bugs): For every rule or algorithm, there is an exception or bug. That’s why we need Stress Testing.
- Definition and Motivation: Infinite loop test based on comparing the algorithm correctness with its naive version (Brute-Force) that halts only when the answers are mismatched (with high probability chance that the optimized version will yield the wrong answer), either first time (Geometric distribution) or kth time (Pascal distribution) depending on the threshold. Stress Testing is motivated by the fact that Brute-Forcing Naive algorithm, although slow,  is certainly guaranteed correctness, while the optimized algorithm is not as much. Because Brute-Forcing doesn’t alter the problem statement with additional hypotheses (it is mere symbolization of the problem statement), and that these additional hypotheses are the core of failure for the optimized case due to their mismatch with problem statement —> **Trade-off between Speed (Optimization) and Correctness**
- Type: Stochastic or Deterministic (Input Samples), Finite or Infinite
- Parameters: Max Iterations, Tolerance (difference in answers), Threshold (number of wrong answers)…etc
- Kolmogorov complexity: Stress Testing is a program. This program is more efficient if its length is closer to its Kolmogorov complexity —> Occam’s razor: inefficiency or efficiency loss is a result of compensating for additional, redundant hypotheses that contributed to relatively greater length.
- Stress Testing Confounded Cases: Manual Test, Integer Overflow, Time Limit exceeded

The alternative algorithm doesn’t have to be naive!

—> **The purpose of Stress Testing is to guide Debugging and Bugs-Fixing** 

### Algorithm Design

- There is no generic procedure to create algorithms.
- Practice designing algorithms using Problem Solving theory.
- Algorithmic toolbox: Common tools used in algorithm design (Greedy, Divide-and-Conquer, Dynamic Programming)
- No Free Lunch theorem

### Algorithm Toolbox

1. **Naive Algorithm (Naive Approach)**: Literally transform the problem statement into symbolic language with minor modifications → Often slow (they are often Exhaustive/Brute-Force)
2. **Algorithm by Standard Tools:** Make sure to figure out if Greedy, DnC or DP or any Metaheuristic (Genetic algo, Simulated Annealing, Tabu Search…etc) can work make the naive algorithm better
3. **Algorithm Optimization:** Improve existing algorithm via heuristics (search space reduction, search space filtration…etc) based on the properties of the problem/algorithm (not to be confused with metaheuristics which are independent of the problem) → **Common techniques: Parametrization, Pre-Computation, Memoization, Tabulation, Sorting, Search Space Reduction, etc.** Examples: Fibonacci problem (Recursion → Memoization), GCD problem (Last Common Divisor → Euclid algorithm)
4. **Magic Algorithm:** Unique Insight into the problem (Penultimate Step)

### Difference between Algorithms, Heuristics and Metaheuristics:

- Algorithms solve a problem by following a sequence of steps and rules (deterministic or stochastic). **[Traditional Programming, Apriori approach, Top-down]**
- Heuristics solve a problem (usually just improve on existing algorithms) without need for rules or steps, but by finding a hint or insight about the problem or via trial-and-error and adaptation that eases out computational requirements (Parametrization, Modeling, Regularization, Space reduction, Sorting…etc) **[Estimation theoretic Programming, Aposteriori approach, Bottom-up]**

→ Machine Learning Algorithms (and especially Unsupervised Learning, RL) can be used to create heuristics

- Metaheuristics are heuristics about heuristics. They are strategies or tools (non-standard) that solve the problem the same way they would solve any other problem, and thus independent of the properties of the problem.

### Examples

There are many types of algorithms, including:

- Search algorithms (Linear, Binary, Ternary, Jump, Exponential, Interpolation, DFS, BFS, A*, Branch-and-Bound, Prune and Search)
- Sorting algorithms (Insertion, Selection, Bubble, Merge, Quick, Heap): Comparison-based Sorting (at least performs O(nlogn) comparisons in worst-case scenario because it examines all n! cases) vs Non-Comparison based Sorting (can perform linearly)

# Data Structures

[Static Arrays](https://app.notion.com/p/Static-Arrays-f6e33c522d314986a77d86fc6c81cd54?pvs=21)

[Dynamic Arrays](https://app.notion.com/p/Dynamic-Arrays-96929041d157459084549ca81e8bdad4?pvs=21)

[Linked Lists:](https://app.notion.com/p/Linked-Lists-353f80c5ad3549a7abd9c81bd84d1838?pvs=21)

[Stacks](https://app.notion.com/p/Stacks-f194b1f2c60f445f8453ad9b46488b73?pvs=21)

[Queues](https://app.notion.com/p/Queues-f44a6994a9e6407e9e3695cfa3c12782?pvs=21)

[Trees](https://app.notion.com/p/Trees-32a8dc63049e48ecab7a45f4d861070a?pvs=21)

[Tries](https://app.notion.com/p/Tries-d03b5b2641764e61b44109a88915d912?pvs=21)

[Heap](https://app.notion.com/p/Heap-5d2045ba2b5847ab8cd6b96f76557953?pvs=21)

[Graphs](https://app.notion.com/p/Graphs-31672ba532a14e02865a75b7736937e0?pvs=21)

[Dictionary](https://app.notion.com/p/Dictionary-3d24b9b00d84489b9e53458c666be7d6?pvs=21)

[Tuple](https://app.notion.com/p/Tuple-96374962fb3a4b28a991dc608cecd59a?pvs=21)

[Set](https://app.notion.com/p/Set-238333bdb9174572b6ed98b9f7519636?pvs=21)

# Algorithms:

## Common Tools/Strategies (Algorithmic Toolbox/Design):

### **Greedy Algorithm:**

- **Safety Choice Heuristic:** First choice that is consistent with optimal solution or when the greedy algorithm yields the same result as Dynamic programming (Safety choice is commonly sorting)
    - Start with a Greedy choice
    - Prove that it is safe
    - Repeat for subproblems
- **Properties:**
1. **Greedy Choice Property:** A globally optimal solution can be obtained by making locally optimal choices at each step (focusing only on the present/current step when choosing next steps) → **Bottom-up Optimality Inheritance**
2. **No Need for Backtracking:** Once a choice is made, it is never reconsidered.
3. **Subproblem dependence:** The subproblems in a greedy algorithm are not independent because the solution to a subproblem affects the future subproblems optimality ⇒ **Submodular functions (Submodularity): limitations of the greedy approach**

if for every S,T⊆Ω such that S and T are arbitrary sets of greedy choices **(Special case: S is just a permutation of T)** (There is only one special set that starts with the safety choice, Sopt)

we have that:

[https://wikimedia.org/api/rest_v1/media/math/render/svg/f21068db00908ee3727f8f8f64990b2a68ea7c09](https://wikimedia.org/api/rest_v1/media/math/render/svg/f21068db00908ee3727f8f8f64990b2a68ea7c09)

.Suppose one wants to find a set S which maximizes f. The greedy algorithm building up a set by incrementally adding the ‘’choice’’ element which increases f the most at each step, produces a set that is at least:

[https://wikimedia.org/api/rest_v1/media/math/render/svg/80e68143eac3b3c1ce6906a7f2646793bc940fde](https://wikimedia.org/api/rest_v1/media/math/render/svg/80e68143eac3b3c1ce6906a7f2646793bc940fde)

That is, greedy performs within a constant factor of

[https://wikimedia.org/api/rest_v1/media/math/render/svg/91728e8230b87f795fbfc68ec7c8775e4430b169](https://wikimedia.org/api/rest_v1/media/math/render/svg/91728e8230b87f795fbfc68ec7c8775e4430b169)

as good as the optimal solution

1. **Subproblem Structure-Preservation:** The problem can be solved by dividing it into subproblems of the same type or category, just with different (smaller) input size (this is not to be confused with Overlapping Subproblems).

→ Greedy algorithms are inefficient in solving problems that exhibit emergence property (complexity, non-linearity) because they never have a top-down/mountain-view perspective of the problem.

→ Greedy algorithms are very efficient in solving problems that exhibit reductionist property (simplicity, linearity)

### Divide-and-Conquer:

- **Master Theorem:**

$$
if \space\ T(n) = aT([n/b]) + O(n^d) \space\ then:\\ T(n) = O(n^d) \space if \space d > log_b(a)\\T(n) = O(n^dlog(n)) \space if \space d = log_b(a)\\T(n) = O(n^{\\log_b(a)}) \space if \space d < log_b(a)\\
$$

- a: the number of subproblems in the first generation (a^i in the ith generation)
- b: the reduction factor of the problem size
- d: power of the amount of work done in the first generation

Proof: Levels - Recursion Tree - Subproblems - Work ⇒ Geometric Series case analysis

- **Properties:**
1. **Divisible into Subproblems:** The problem can be divided into smaller subproblems of the same type.
2. **Polynomial subproblems:** The number of subproblems is small enough to be evaluated in polynomial time (in order to avoid infinite regress).
3. **Independent Subproblems (Matroid):** The subproblems are independent of each other, and solving them does not affect other subproblems. ⇒ **Modular functions (Modularity)**
4. **Subproblem Structure-Preservation:** The problem can be solved by dividing it into subproblems of the same type or category, just with different (smaller) input size (this is not to be confused with Overlapping Subproblems).
5. **Recombining Solutions:** The solutions of subproblems can be combined efficiently to solve the original problem. (bottom-up approach)

Example of Divide-and-Conquer algorithms: Binary Search, Ternary Search, k-ary Search, Branch-and-Bound, Merge sort, Quick sort…etc

### Dynamic Programming:

- **Properties:**
1. **Overlapping Subproblems**: The problem can be broken down into subproblems, and solutions to these subproblems are reused multiple times. (**Strong Dependence**)
2. **Polynomial subproblems:** The number of subproblems is small enough to be evaluated in polynomial time (in order to avoid infinite regress).
3. **Exhaustive Backtracking:** All past choices are reconsidered exhaustively, thanks to the accumulative form of the Bellman equation. DP evaluates all subproblems possible in a particular order to ensure that all subproblems are evaluated only once thanks to memoization. **(Subproblems space filtration-reduction heuristics are usually used to ease out load)**
4. **Optimal Substructure:** An optimal solution to the problem contains optimal solutions to its subproblems. (Bellman equation) → **Top-down Optimality Inheritance ⇒ Messengers-Deceivers analogy (Hypothetical-Counterfactual process to obtain the Bellman equation)**
5. **Memoization or Tabulation:** Techniques are used to store and retrieve solutions to subproblems to avoid redundant computations. This is implemented in a **bottom-up approach** by solving pillar subproblems first, storing their solutions and reusing those solutions in bigger subproblems till the whole pool of subproblems is covered.
- **Implementation Steps:**
1. Finding an appropriate subproblem or subproblem statement (What parameter that affects the optimality of the solution is chosen and recursed upon) of which there are many (some statements are simpler than others implementation-wise)
2. Given that the problem/object is recursible (it can be written recursively) → Write the problem recursively = subproblem + isolated component ⇒ property optimality(problem) = property optimality(subproblem) + property(isolated component)
3. Assume that the optimal solution to the problem exists, apply optimality inheritance recursively to smaller and smaller instances. **(Cut-and-Paste technique ⇒ Proof by contradiction: Assume one has a globally optimal solution S* to the problem with k subproblems, that is attained by having k-1 globally optimal solutions to k-1 subproblems and one non-globally optimal (say locally optimal solution or non-optimal) solution to the kth subproblem. It is possible to replace or ‘’cut’’ the non-optimal solution with an optimal solution to the kth subproblem, but doing so will improve the globally optimal solution to the problem at hand, hence the contradictions)** → **Bellman equation of the problem (Topological Sorting of DAG or Stack)**
4. Solve all the required subproblems (Exhaustive Backtracking) in the right order of requirement and store their solutions in a table or a matrix for later use (Memoization-Tabulation)
5. Build up the matrix/table from basic subproblems to the final problem.

**→ Dynamic Programming is global optimization, Greedy Algorithm is local optimization**

**→ Optimality Inheritance: Dynamic Programming is Top-Down (Mountain view), Greedy Algorithm is Bottom-up (Messengers-Deceivers analogy: Top-down starts from global solution as a messenger guiding you to the right optimal solutions to subproblems, Bottom-up, unless in present of safety choice heuristic, is usually accompanied by deceivers who only seek their local and shortsighted interests in guiding you to the greedy choices with short-term optimality only)**

→ **Dynamic Programming is efficient for both emergentist and reductionist problems, Greedy algorithms are only efficient for reductionist problems because their bottom-up approach can’t predict ‘’what emerges’’.**  

**→ Dynamic Programming, Divide-and-Conquer and Greedy Algorithm can be implemented either recursively or iteratively.**

**→Dynamic Programming is based on the recursive leap of faith of a foundationalist nature (Recursive base case as the foundation and the only faith-free iteration). Moreover, the idea behind Bellman equation is thinking in the hypothetical ‘’if that was the case, then this should be the case’’**

---

---

Recall on Recursions:

- Top-down definition: Recursion is a method of solving a computational problem where the solution depends on solutions to smaller instances of the same problem → Domino effect analogy
- Bottom-up definition (Linear Algebra definition): Recursion is a method of using the simplest input size/instance to solve the whole problem. This assumes that this simplest input (also known as Recursive Base Case) spans all other possible inputs in that they necessarily backtrack to it → Problem as a spanned vector space, Recursive base case as the eigenvector.

**Implementation:** 

1. Find the appropriate Recursive Base Case (appropriate property/parameter should change with each iteration otherwise infinite loop or maximum recursive depth error)
2. Visualize and Examine examples
3. Generalize the pattern in the form of Recursion Equation (Recursive Leap of Faith)
4. Program = Recursive Base Case + Generalized Recursive Pattern

**Programming-wise:**

→ Make sure the recursive base case is applied on the right variable/parameter ( should change every iteration )

→ Calling a function recursively doesn’t overwrite its state variables/values (no vicious circle), but it modifies them incrementally in stairs ⇒ **Recursive Leap of Faith**

---

---