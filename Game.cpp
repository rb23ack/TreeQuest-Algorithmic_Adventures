#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include "bst.c" // Including C functions for BST operations
#include "mergesort.c" // Including C functions for Merge Sort

using namespace std;
using namespace chrono;

class TreeGame {
public:
    TreeGame() : score(0) {
        start = high_resolution_clock::now(); // Timer start
    }

    // Starting the game and displaying challenges
    void startGame() {
        cout << "Welcome to the Tree Data Structure Game!" << endl;

        // Level 1: Binary Search Challenge
        runBinarySearchChallenge();

        // Level 2: Merge Sort Challenge
        runMergeSortChallenge();

        // Game Over: Show score
        endGame();
    }

private:
    int score;
    high_resolution_clock::time_point start; // Timer for challenges

    // Run Binary Search Challenge
    void runBinarySearchChallenge() {
        cout << "\nLevel 1: Binary Search Challenge" << endl;

        // Create a binary search tree
        struct Node* root = NULL;
        vector<int> values = {10, 20, 5, 15, 30, 25, 40};
        for (int val : values) {
            root = insert(root, val);
        }

        cout << "In-order Traversal of Tree: ";
        inorder(root);
        cout << endl;

        int target = 25;
        struct Node* result = binarySearch(root, target);
        if (result != NULL) {
            cout << "Success! Found the value " << target << "." << endl;
            score += 10;
        } else {
            cout << "Oops! Value not found!" << endl;
        }
    }

    // Run Merge Sort Challenge
    void runMergeSortChallenge() {
        cout << "\nLevel 2: Merge Sort Challenge" << endl;

        vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
        cout << "Array Before Merge Sort: ";
        for (int val : arr) cout << val << " ";
        cout << endl;

        mergeSort(arr.data(), 0, arr.size() - 1);

        cout << "Array After Merge Sort: ";
        for (int val : arr) cout << val << " ";
        cout << endl;

        score += 10; // Add points for solving Merge Sort challenge
    }

    // End the game and display score
    void endGame() {
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<seconds>(end - start);
        cout << "\nGame Over! Your total score: " << score << endl;
        cout << "Time taken: " << duration.count() << " seconds" << endl;

        // Save score to leaderboard
        saveScore();
    }

    // Save score to leaderboard
    void saveScore() {
        ofstream leaderboard("leaderboard.txt", ios::app);
        leaderboard << "Score: " << score << " | Time: " << chrono::duration_cast<seconds>(high_resolution_clock::now() - start).count() << " seconds" << endl;
        leaderboard.close();
    }
};
 
int main() {
    TreeGame game;
    game.startGame();    
    return 0;
}      
