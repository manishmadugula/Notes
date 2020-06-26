# Interesting Insights

## If 2 nodes like each other.
- Say if we are having a study where, we find who are more likely to have on average more sexual partner men or women, we can use graph theory, 
  - Average male sex partners = Total number of relationship/Number of men i.e Average male sex partners = Edge in the graph/Number of men
  - Similarly, Average female sex partner = Edge in the graph/Number of women.
  - So depending on the number of women/men ratio in population our answer depends. Not some social stigma.
  - Same logic applies when talking about minority students on average study with non minority rather than other way around. It is because they are minority.

## If 2 nodes don't like each other. i.e can't go with each other
- This is where graph Coloring algorithms comes into picture. We need to assign different color to adjacent nodes. Adjacent nodes are nodes which don't like each other.
- ### Some Theorems
  - For any graph G, with n nodes and max degree d, we can color the graph, with atmost d+1 colors. We don't need any more than that. (This upper bound case comes when all nodes are connected to each other).
  - It is important to understand the value of ordering in which we traverse the graph to assign colors.
  - A basic greedy solution i.e just order in some random way and start with any node and assign lowest possible color to it won't work for checking if it is a bipartite graph.


## Matching Problem.
- Solution TMA (Stable Marriage problem).
