#include "doctest.h"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Test graph addition") {
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 + g2;
    CHECK(g3.printGraph() == "[0, 2, 1]\n[2, 0, 3]\n[1, 3, 0]");

    g1 += g2;
    CHECK(g1.printGraph() == "[0, 2, 1]\n[2, 0, 3]\n[1, 3, 0]");
}

TEST_CASE("Test graph subtraction") {
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {4, 5, 6},
        {7, 8, 9},
        {1, 2, 3}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}};
    g2.loadGraph(graph2);
    ariel::Graph g3 = g1 - g2;
    CHECK(g3.printGraph() == "[3, 4, 5]\n[6, 7, 8]\n[0, 1, 2]");

    g1 -= g2;
    CHECK(g1.printGraph() == "[3, 4, 5]\n[6, 7, 8]\n[0, 1, 2]");
}

TEST_CASE("Test unary minus") {
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    g1.loadGraph(graph);
    ariel::Graph g2 = -g1;
    CHECK(g2.printGraph() == "[-1, -2, -3]\n[-4, -5, -6]\n[-7, -8, -9]");
}

TEST_CASE("Test multiplication by a scalar") {
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    g1.loadGraph(graph);
    ariel::Graph g2 = g1 * 2;
    CHECK(g2.printGraph() == "[2, 4, 6]\n[8, 10, 12]\n[14, 16, 18]");

    g1 *= 3;
    CHECK(g1.printGraph() == "[3, 6, 9]\n[12, 15, 18]\n[21, 24, 27]");
}

TEST_CASE("Test division by a scalar") {
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {2, 4, 6},
        {8, 10, 12},
        {14, 16, 18}};
    g1.loadGraph(graph);
    ariel::Graph g2 = g1 / 2;
    CHECK(g2.printGraph() == "[1, 2, 3]\n[4, 5, 6]\n[7, 8, 9]");

    g1 /= 2;
    CHECK(g1.printGraph() == "[1, 2, 3]\n[4, 5, 6]\n[7, 8, 9]");
}

TEST_CASE("Test element-wise graph multiplication") {
    ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);
    ariel::Graph g2;
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(graph2);
    ariel::Graph g3 = g1 * g2;
    vector<vector<int>> expectedGraph = {
        {0, 1, 0},
        {1, 0, 2},
        {0, 2, 0}};
    CHECK(g3.printGraph() == "[0, 1, 0]\n[1, 0, 2]\n[0, 2, 0]");
}

TEST_CASE("Test graph equality operators") {
   ariel::Graph g1;
    vector<vector<int>> graph1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    g1.loadGraph(graph1);

    ariel::Graph g2;
    g2.loadGraph(graph1);

    ariel::Graph g3;
    vector<vector<int>> graph3 = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };
    g3.loadGraph(graph3);

    CHECK(g1 == g2);
    CHECK(g1 != g3);
    CHECK(g3 <= g1);
    CHECK(g1 >= g3);
}

TEST_CASE("Test graph increment and decrement operators") {
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    g1.loadGraph(graph);

    ariel::Graph g2 = ++g1;
    CHECK(g2.printGraph() == "[2, 3, 4]\n[5, 6, 7]\n[8, 9, 10]");
    CHECK(g1.printGraph() == "[2, 3, 4]\n[5, 6, 7]\n[8, 9, 10]");

    ariel::Graph g3 = g1++;
    CHECK(g3.printGraph() == "[2, 3, 4]\n[5, 6, 7]\n[8, 9, 10]");
    CHECK(g1.printGraph() == "[3, 4, 5]\n[6, 7, 8]\n[9, 10, 11]");

    ariel::Graph g4 = --g1;
    CHECK(g4.printGraph() == "[2, 3, 4]\n[5, 6, 7]\n[8, 9, 10]");
    CHECK(g1.printGraph() == "[2, 3, 4]\n[5, 6, 7]\n[8, 9, 10]");

    ariel::Graph g5 = g1--;
    CHECK(g5.printGraph() == "[2, 3, 4]\n[5, 6, 7]\n[8, 9, 10]");
    CHECK(g1.printGraph() == "[1, 2, 3]\n[4, 5, 6]\n[7, 8, 9]");
}

TEST_CASE("Test friend multiplication by scalar") {
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    g1.loadGraph(graph);
    ariel::Graph g2 = 2 * g1;
    CHECK(g2.printGraph() == "[2, 4, 6]\n[8, 10, 12]\n[14, 16, 18]");
}

TEST_CASE("Invalid operations") {
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1, 1},
        {1, 0, 2, 1},
        {1, 2, 0, 1}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g5;
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g5.loadGraph(graph2);
    CHECK_THROWS(g5 * g1);
    CHECK_THROWS(g1 * g2);

    // Addition of two graphs with different dimensions
    ariel::Graph g6;
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g6.loadGraph(graph3);
    CHECK_THROWS(g1 + g6);
}

