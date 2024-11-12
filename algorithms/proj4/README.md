Project 04: Path Finding
========================

This project implements a [Dijkstra's Algorithm] to perform rudimentary path
finding on a 2D tile-based map.

[Dijkstra's Algorithm]: https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm


Input
-----

    TILES_N
    TILE_NAME_0	TILE_COST_0
    ...
    TILE_NAME_N-1	TILE_COST_N-1

    MAP_ROWS MAP_COLUMNS
    TILE_0_0    ...
    ...

    TRAVELER_START_ROW TRAVELER_START_COL
    TRAVELER_END_ROW   TRAVELER_END_COL

Output
------

    Cost
    [(ROW_0, COL_0), ...]

Writeup:

Contributions:
David:
My contributions to the project included reading in the files and setting them up in the data structures we aggread on. From there we both worked on how to implement the actual algorithm, I wrote some helper functions as well to try and make things easier. We both worked to figure out the structure of how the algorithm should be implemented. While Liam did a bit more on the research side I worked on the specific implementation in our code.

Liam:
I spent most of the time studying how Dijkstras algorithm was typically implemented. I suggested the use of a priority queue, and implemented that, and I also helped with the debugging with David in person. I also made all of the writeup and tested the code against our randomly generated maps.

Table (5 tests per row):
|N    |Average Elapsed Time (seconds)|Memory Usage (bytes)|
|-----|------------------------------|--------------------|
|10   |0.474                         |84,116              |
|20   |0.486                         |88,484              |
|50   |0.568                         |117,268             |
|100  |0.874                         |208,292             |
|200  |2.14                          |574,436             |
|500  |11.216                        |3,123,108           |
|1000 |44.556                        |12,164,068          |


How did you represent the graph?
    We stored the graph as an adjacency matrix 
    except the array was flatenned due to the rectangular properties of the map.
    The visited nodes were stored as {distance, index} pairs.
What is complexity of your implementation of Dijkstra's Algorithm?
    The complexity of our algorithm is O(E+Vlog(V))
    where V is the number of verticies, and E is the number of edges.
    We used a priority queue for storing the frontier, 
    and then used vectors for storing other things like our graph, marked, and path.
How well does your implementation scale?
    The implementation does seem to scale exponentially unfortunately.There was a huge increase in runtime and memory usage after 100 items.

