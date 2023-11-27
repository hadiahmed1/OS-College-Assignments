#include<stdio.h>

// Function to allocate memory using First Fit
void firstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++) {
        allocation[i] = -1; // Initialize all slots as unallocated
    }
    // Traverse all processes and allocate memory using the First Fit method
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                // Allocate the process to the first fit block
                allocation[i] = j;
                // Reduce available memory in this block
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }
    // Display the allocation result
    printf("First Fit Allocation:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d -> Block %d\n", i + 1, allocation[i] + 1);
    }
}

// Function to allocate memory using Best Fit
void bestFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    for (int i = 0; i < n; i++) {
        allocation[i] = -1; // Initialize all slots as unallocated
    }
    // Traverse all processes and allocate memory using the Best Fit method
    for (int i = 0; i < n; i++) {
        // Find the best fit block for the current process
        int bestFitIndex = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestFitIndex == -1 || blockSize[j] < blockSize[bestFitIndex]) {
                    bestFitIndex = j;
                }
            }
        }
        // Allocate the process to the best fit block
        if (bestFitIndex != -1) {
            allocation[i] = bestFitIndex;
            blockSize[bestFitIndex] -= processSize[i];
        }
    }
    // Display the allocation result
    printf("Best Fit Allocation:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d -> Block %d\n", i + 1, allocation[i] + 1);
    }
}
// Function to allocate memory using Worst Fit
void worstFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n]; 
    for (int i = 0; i < n; i++) {
        allocation[i] = -1; // Initialize all slots as unallocated
    }
    // Traverse all processes and allocate memory using the Worst Fit method
    for (int i = 0; i < n; i++) {
        // Find the worst fit block for the current process
        int worstFitIndex = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (worstFitIndex == -1 || blockSize[j] > blockSize[worstFitIndex]) {
                    worstFitIndex = j;
                }
            }
        }
        // Allocate the process to the worst fit block
        if (worstFitIndex != -1) {
            allocation[i] = worstFitIndex;
            blockSize[worstFitIndex] -= processSize[i];
        }
    }
    // Display the allocation result
    printf("Worst Fit Allocation:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d -> Block %d\n", i + 1, allocation[i] + 1);
    }
}

// Driver program
int main() {
    // Number of memory blocks
    int m = 5;
    // Size of each memory block
    int blockSize[] = {100, 500, 200, 300, 600};
    // Number of processes
    int n = 4;
    // Size of each process
    int processSize[] = {212, 417, 112, 426};
    // Memory allocation using First Fit
    firstFit(blockSize, m, processSize, n);
    // Reset blockSize array to its original values
    int resetBlockSize[] = {100, 500, 200, 300, 600};
    // Memory allocation using Best Fit
    bestFit(resetBlockSize, m, processSize, n);
    // Reset blockSize array to its original values
    int resetBlockSize2[] = {100, 500, 200, 300, 600};
    // Memory allocation using Worst Fit
    worstFit(resetBlockSize2, m, processSize, n);
    return 0;
}
