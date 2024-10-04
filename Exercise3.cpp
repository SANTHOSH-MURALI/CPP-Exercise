#include <iostream>
#include <cstring>

using namespace std;

// Matrix dimensions
int N, M;
// Directions for 4-connected neighbors
int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// DFS to explore a group
void dfs(int** matrix, bool** visited, int x, int y, int& groupSum) {
    // Mark the current cell as visited
    visited[x][y] = true;
    groupSum += matrix[x][y];

    // Explore all 4-connected neighbors
    for (int i = 0; i < 4; i++) {
        int newX = x + directions[i][0];
        int newY = y + directions[i][1];

        // Check bounds and if the neighbor is part of the group
        if (newX >= 0 && newX < N && newY >= 0 && newY < M && 
            !visited[newX][newY] && matrix[newX][newY] > 0) {
            dfs(matrix, visited, newX, newY, groupSum);
        }
    }
}

// Function to find groups and their member counts
int* findGroups(int** matrix, int& totalGroups, int& maxGroupMembers) {
    // Allocate dynamic memory for visited matrix
    bool** visited = new bool*[N];
    for (int i = 0; i < N; i++) {
        visited[i] = new bool[M];
        // Mark all as unvisited
        for(int j=0;j<M;j++){
            visited[i][j]=false;
        }
    }

    // Result array to store group sizes
    int* groupSizes = new int[N * M]; // Max possible groups is N * M
    totalGroups = 0;
    maxGroupMembers = 0;

    // Traverse the matrix to find groups
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (matrix[i][j] > 0 && !visited[i][j]) {
                int groupSum = 0;
                dfs(matrix, visited, i, j, groupSum);
                groupSizes[totalGroups++] = groupSum;
                if (groupSum > maxGroupMembers) {
                    maxGroupMembers = groupSum;
                }
            }
        }
    }

    // Free visited matrix memory
    for (int i = 0; i < N; i++) {
        delete[] visited[i];
    }
    delete[] visited;

    return groupSizes;
}

// Function to find the leader group
int findLeaderGroup(int* groupSizes, int totalGroups) {
    int leaderGroup = groupSizes[0];
    for (int i = 1; i < totalGroups; i++) {
        if (groupSizes[i] > leaderGroup) {
            leaderGroup = groupSizes[i];
        }
    }
    return leaderGroup;
}

// Main function
int main() {
    // Input the matrix dimensions
    cout << "Enter matrix dimensions (N M): ";
    cin >> N >> M;

    // Dynamically allocate the matrix
    int** matrix = new int*[N];
    for (int i = 0; i < N; i++) {
        matrix[i] = new int[M];
    }

    // Input the matrix elements
    cout << "Enter matrix elements: " << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> matrix[i][j];
        }
    }

    // Find groups and member counts
    int totalGroups, maxGroupMembers;
    int* groupSizes = findGroups(matrix, totalGroups, maxGroupMembers);

    // Output the group member counts
    cout << "Groups and their member counts: ";
    for (int i = 0; i < totalGroups; i++) {
        cout << groupSizes[i] << " ";
    }
    cout << endl;

    // Find and output the leader group
    int leaderGroup = findLeaderGroup(groupSizes, totalGroups);
    cout << "Leader group: " << leaderGroup << endl;

    // Free dynamically allocated memory
    delete[] groupSizes;
    for (int i = 0; i < N; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
