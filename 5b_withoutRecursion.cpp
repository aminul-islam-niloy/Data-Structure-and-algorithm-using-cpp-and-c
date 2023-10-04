#include <iostream>
#include <stack>

using namespace std;

void moveDisk(stack<int> &source, stack<int> &destination)
{
    int disk = source.top();
    source.pop();
    destination.push(disk);
    cout << "Move disk " << disk << " from source to destination" << endl;
}

void solveTowerOfHanoi(int numDisks, stack<int> &source, stack<int> &auxiliary, stack<int> &destination)
{
    int totalMoves = (1 << numDisks) - 1;
    if (numDisks % 2 == 0)
    {
        swap(auxiliary, destination);
    }

    for (int i = 1; i <= totalMoves; i++)
    {
        if (i % 3 == 1)
        {
            if (!source.empty() && (destination.empty() || source.top() < destination.top()))
            {
                moveDisk(source, destination);
            }
            else
            {
                moveDisk(destination, source);
            }
        }
        else if (i % 3 == 2)
        {
            if (!source.empty() && (auxiliary.empty() || source.top() < auxiliary.top()))
            {
                moveDisk(source, auxiliary);
            }
            else
            {
                moveDisk(auxiliary, source);
            }
        }
        else if (i % 3 == 0)
        {
            if (!auxiliary.empty() && (destination.empty() || auxiliary.top() < destination.top()))
            {
                moveDisk(auxiliary, destination);
            }
            else
            {
                moveDisk(destination, auxiliary);
            }
        }
    }
}

int main()
{
    int numDisks;
    cout << "Enter the number of disks: ";
    cin >> numDisks;

    stack<int> source, auxiliary, destination;
    for (int i = numDisks; i >= 1; i--)
    {
        source.push(i);
    }

    solveTowerOfHanoi(numDisks, source, auxiliary, destination);

    return 0;
}
