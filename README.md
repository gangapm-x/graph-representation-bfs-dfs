# Graph Representation - BFS and DFS

## Problem

Consider a small social network with the following connections:

A-B, A-C, B-D, B-E, C-F, E-F

The graph is implemented using:

1. Adjacency Matrix
2. Adjacency List

BFS and DFS are performed starting from vertex A.

## Vertices

A, B, C, D, E, F

## Edges

A-B
A-C
B-D
B-E
C-F
E-F

## BFS

Starting vertex: A

BFS traversal:

A B C D E F

## DFS

Starting vertex: A

DFS traversal:

A B D E F C

## Comparison

| Feature | Adjacency Matrix | Adjacency List |
|---|---|---|
| Space | O(V²) | O(V+E) |
| Edge checking | O(1) | O(degree) |
| Traversal | O(V²) | O(V+E) |
| Suitable for | Dense graphs | Sparse graphs |
| Memory usage | Higher | Lower |

## Conclusion

For a sparse social network, adjacency list is more suitable because it stores only existing edges and requires O(V+E) space.

It is more memory efficient than an adjacency matrix, which requires O(V²) space.
