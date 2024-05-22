/*
 * @ID - 6412  
 * @Email - yuvalbentzur1996@gmail.com
 */

#pragma once

#include "Graph.hpp"
#include <string>

namespace ariel {

    class Algorithms {
    public:
        /**
         * @brief Check if the graph is connected.
         * 
         * @param g The graph object.
         * @return true if the graph is connected, false otherwise.
         */
        static bool isConnected(const Graph& g);

        /**
         * @brief Find the shortest path between two vertices in the graph.
         * 
         * @param g The graph object.
         * @param start The starting vertex.
         * @param end The ending vertex.
         * @return The shortest path between the two vertices as a string,
         *         or "-1" if no path exists.
         */
        static std::string shortestPath(const Graph& g, int start, int end);

        /**
         * @brief Check if the graph contains a cycle.
         * 
         * @param g The graph object.
         * @return true if the graph contains a cycle, false otherwise.
         */
        static bool isContainsCycle(const Graph& g);

        /**
         * @brief Check if the graph is bipartite and return the partitioning.
         * 
         * @param g The graph object.
         * @return A string indicating the bipartitioning of the graph,
         *         or "0" if the graph is not bipartite.
         */
        static std::string isBipartite(const Graph& g);

         /**
         * @brief Find a negative cycle in the graph.
         * 
         * @param g The graph object.
         * @return A string indicating the negative cycle found, or
         *         "No negative cycle found." if no negative cycle exists.
         */
         static std::string negativeCycle(const Graph& g);
       

    private:
        // Utility function for isContainsCycle
        static std::string isContainsCycleUtil(const Graph& g, std::size_t currVertex, std::vector<bool>& visited, int parent);

        // Utility function for isBipartite
        static bool isBipartiteUtil(const Graph& g, std::size_t currVertex, std::vector<int>& color);
    };

} // namespace ariel
