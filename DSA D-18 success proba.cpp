#include <iostream>
#include <climits>
using namespace std;

int sum(int freq[], int low, int high) {
    int sum = 0;
    for (int k = low; k <= high; k++)
        sum += freq[k];
    return sum;
}

int buildOptimalBST(int keys[], int freq[], int n, int root[][10]) {
    int cost[10][10];  // Cost matrix

    for (int i = 0; i < n; i++) {
        cost[i][i] = freq[i];
        root[i][i] = i;
    }

    for (int length = 2; length <= n; length++) {
        for (int i = 0; i <= n - length; i++) {
            int j = i + length - 1;
            cost[i][j] = INT_MAX;

            for (int r = i; r <= j; r++) {
                int c = ((r > i) ? cost[i][r - 1] : 0) +
                        ((r < j) ? cost[r + 1][j] : 0) +
                        sum(freq, i, j);

                if (c < cost[i][j]) {
                    cost[i][j] = c;
                    root[i][j] = r;
                }
            }
        }
    }
    return cost[0][n - 1];
}

// Preorder traversal from root matrix
void printPreorder(int keys[], int root[][10], int i, int j) {
    if (i > j)
        return;
    int r = root[i][j];
    cout << keys[r] << " ";
    printPreorder(keys, root, i, r - 1);
    printPreorder(keys, root, r + 1, j);
}

int main() {
    int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    int n = 3;

    int root[10][10];
    int cost = buildOptimalBST(keys, freq, n, root);

    cout << "Cost of Optimal BST is: " << cost << endl;
    cout << "Preorder traversal of the OBST: ";
    printPreorder(keys, root, 0, n - 1);
    cout << endl;

    return 0;
}

