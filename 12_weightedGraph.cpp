#include <iostream>
using namespace std;

#define INF 99999
#define MAX 10

int graph[MAX][MAX];
int numCities;

void initializeGraph() {
    for (int i = 0; i < numCities; i++) {
        for (int j = 0; j < numCities; j++) {
            if (i == j) {
                graph[i][j] = 0;
            } else {
                graph[i][j] = INF;
            }
        }
    }
}

void addEdge(int from, int to, int weight) {
    graph[from][to] = weight;
}

void floydWarshall() {
    for (int k = 0; k < numCities; k++) {
        for (int i = 0; i < numCities; i++) {
            for (int j = 0; j < numCities; j++) {
                if (graph[i][k] + graph[k][j] < graph[i][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
}

void printShortestPath(int from, int to) {
    cout << "Shortest path from City " << from << " to City " << to << ": ";
    if (graph[from][to] == INF) {
        cout << "No path exists." << endl;
        return;
    }

    cout << from << " -> ";
    while (from != to) {
        for (int i = 0; i < numCities; i++) {
            if (graph[from][to] == graph[from][i] + graph[i][to]) {
                cout << i << " -> ";
                from = i;
                break;
            }
        }
    }
    cout << to << endl;
}

int main() {
    int numEdges, from, to, weight;

    cout << "Enter the number of cities: ";
    cin >> numCities;
    initializeGraph();

    cout << "Enter the number of edges: ";
    cin >> numEdges;
    for (int i = 0; i < numEdges; i++) {
        cout << "Enter edge " << i + 1 << " (from to weight): ";
        cin >> from >> to >> weight;
        addEdge(from, to, weight);
    }

    floydWarshall();

    while (true) {
        cout << "\nShortest Path Menu:\n";
        cout << "1. Print Shortest Path\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter source and destination cities: ";
                cin >> from >> to;
                printShortestPath(from, to);
                break;
            case 2:
                cout << "Exiting program. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. " << endl;
        }
    }

    return 0;
}
