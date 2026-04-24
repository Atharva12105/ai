#include <iostream>          // Used for input and output (cin, cout)
#include <queue>             // Used for priority_queue
#include <set>               // Used to store visited states
#include <vector>            // Used for 2D puzzle board
using namespace std;         // So we don't write std:: again and again

// Structure to store each puzzle state
struct State
{
    vector<vector<int>> board;   // Current 3x3 puzzle board
    int x, y;                    // Position of blank tile (0)
    int g, h, f;                // g = moves so far, h = heuristic, f = g+h

    // Comparator for priority queue
    bool operator<(const State &other) const
    {
        return f > other.f;     // Smaller f gets higher priority
    }
};

// Goal state of puzzle
vector<vector<int>> goal =
{
    {1,2,3},
    {4,5,6},
    {7,8,0}
};

// Heuristic function = count misplaced tiles
int heuristic(vector<vector<int>> board)
{
    int count = 0;             // Count wrong tiles

    for(int i=0;i<3;i++)      // Traverse rows
    {
        for(int j=0;j<3;j++)  // Traverse columns
        {
            // If tile is not blank and not in correct place
            if(board[i][j] != 0 && board[i][j] != goal[i][j])
                count++;      // Increase heuristic
        }
    }

    return count;             // Return misplaced tiles count
}

// Function to print board
void printBoard(vector<vector<int>> board)
{
    for(int i=0;i<3;i++)      // Rows
    {
        for(int j=0;j<3;j++)  // Columns
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Convert board into string for visited set
string boardToString(vector<vector<int>> board)
{
    string s = "";

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            s += char(board[i][j] + '0'); // Convert number to character
        }
    }

    return s;
}

// A* Algorithm function
void solvePuzzle(vector<vector<int>> start, int x, int y)
{
    priority_queue<State> pq;  // Priority queue for best state
    set<string> visited;       // Store visited states

    int h = heuristic(start);  // Find heuristic of start board

    // Push initial state
    pq.push({start, x, y, 0, h, h});

    // Movement arrays (up, down, left, right)
    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};

    while(!pq.empty())         // Until queue becomes empty
    {
        State current = pq.top(); // Take best state
        pq.pop();

        // If goal state found
        if(current.board == goal)
        {
            cout << "Goal Reached!\n";
            printBoard(current.board);
            return;
        }

        string key = boardToString(current.board); // Convert board to string

        if(visited.count(key)) // If already visited
            continue;

        visited.insert(key);   // Mark visited

        // Try all 4 directions
        for(int i=0;i<4;i++)
        {
            int nx = current.x + dx[i]; // New row
            int ny = current.y + dy[i]; // New column

            // Check valid move
            if(nx>=0 && nx<3 && ny>=0 && ny<3)
            {
                State next = current; // Copy current state

                // Swap blank tile with adjacent tile
                swap(next.board[current.x][current.y],
                     next.board[nx][ny]);

                next.x = nx;          // Update blank row
                next.y = ny;          // Update blank column

                next.g = current.g + 1; // Increase move cost
                next.h = heuristic(next.board); // New heuristic
                next.f = next.g + next.h; // Total cost

                pq.push(next);       // Push new state into queue
            }
        }
    }

    cout << "No Solution Found";
}

// Main function
int main()
{
    vector<vector<int>> start(3, vector<int>(3)); // Create 3x3 board

    int x, y; // Blank tile position

    cout << "Enter initial puzzle state:\n";

    for(int i=0;i<3;i++)      // Input rows
    {
        for(int j=0;j<3;j++)  // Input columns
        {
            cin >> start[i][j];

            if(start[i][j] == 0) // Find blank tile
            {
                x = i;
                y = j;
            }
        }
    }

    solvePuzzle(start, x, y); // Call A* function

    return 0;
}