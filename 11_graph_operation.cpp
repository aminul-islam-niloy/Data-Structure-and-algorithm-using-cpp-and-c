#include <bits/stdc++.h>
using namespace std;

int main()
{
    int numCities, choice, startCity;
    string cityName;

    cout << "Enter the number of cities: ";
    cin >> numCities;
    vector<string> cities(numCities);
    vector<vector<int>> adjacencyMatrix(numCities, vector<int>(numCities, 0));

    for (int i = 0; i < numCities; i++)
    {
        cout << "Enter the name of city " << i + 1 << ": ";
        cin >> cities[i];
    }

    cout << "Enter the number of edges: ";
    int numEdges;
    cin >> numEdges;
    for (int i = 0; i < numEdges; i++)
    {
        int from, to;
        cout << "Enter edge " << i + 1 << " (from to): ";
        cin >> from >> to;
        if (from >= 0 && from < numCities && to >= 0 && to < numCities)
        {
            adjacencyMatrix[from][to] = 1;
        }
    }

    while (true)
    {
        cout << "\nGraph Operations Menu:\n";
        cout << "1. Print Cities\n";
        cout << "2. Perform DFS Traversal\n";
        cout << "3. Perform BFS Traversal\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Cities: ";
            for (int i = 0; i < numCities; i++)
            {
                cout << cities[i] << " ";
            }
            cout << endl;
            break;
        case 2:
            cout << "Enter the starting city index: ";
            cin >> startCity;
            if (startCity >= 0 && startCity < numCities)
            {
                vector<bool> visited(numCities, false);
                cout << "DFS traversal from city " << cities[startCity] << ": ";
                stack<int> st;
                st.push(startCity);
                visited[startCity] = true;

                while (!st.empty())
                {
                    int v = st.top();
                    st.pop();
                    cout << cities[v] << " ";

                    for (int i = 0; i < numCities; i++)
                    {
                        if (adjacencyMatrix[v][i] == 1 && !visited[i])
                        {
                            st.push(i);
                            visited[i] = true;
                        }
                    }
                }
                cout << endl;
            }
            else
            {
                cout << "Invalid starting city index." << endl;
            }
            break;
        case 3:
            cout << "Enter the starting city index: ";
            cin >> startCity;
            if (startCity >= 0 && startCity < numCities)
            {
                vector<bool> visited(numCities, false);
                cout << "BFS traversal from city " << cities[startCity] << ": ";
                queue<int> q;
                visited[startCity] = true;
                q.push(startCity);

                while (!q.empty())
                {
                    int v = q.front();
                    q.pop();
                    cout << cities[v] << " ";

                    for (int i = 0; i < numCities; i++)
                    {
                        if (adjacencyMatrix[v][i] == 1 && !visited[i])
                        {
                            visited[i] = true;
                            q.push(i);
                        }
                    }
                }
                cout << endl;
            }
            else
            {
                cout << "Invalid starting city index." << endl;
            }
            break;
        case 4:
            cout << "Exiting program. Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice. ." << endl;
        }
    }

    return 0;
}
