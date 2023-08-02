#include <stdio.h>
#include <stdbool.h>

#define MAX_N 10 // Maximum girlfriends

bool visited[MAX_N];
int path[MAX_N];
int gfCount;

// Function to find all possible ways to meet N girlfriends.
void findWays(int N, int daysLeft) {
    if (daysLeft == 0) {

        for (int i = 0; i < gfCount; i++) {
            printf("%d ", path[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (!visited[i] && i <= daysLeft) {

            visited[i] = true;
            path[gfCount] = i;
            gfCount++;
            findWays(N, daysLeft - i);
            gfCount--;
            visited[i] = false;
        }
    }
}

int main() {
    int N;
    printf("Enter the number of days left for joining Google: ");
    scanf("%d", &N);

    if (N <= 0) {
        printf("Invalid input. The number of days must be greater than 0.\n");
        return 1;
    }

    if (N > MAX_N) {
        printf("The number of girlfriends cannot be more than %d.\n", MAX_N);
        return 1;
    }

    gfCount = 0; // Initialize the girlfriend count.

    printf("All possible ways Anoop can meet his girlfriends within %d days:\n", N);
    findWays(N, N);

    return 0;
}
