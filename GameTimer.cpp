#include <iostream>
#include <chrono> // For time tracking

using namespace std;
using namespace chrono;

int main() {
    // Start the timer
    auto start = high_resolution_clock::now();

    // End the timer
    auto end = high_resolution_clock::now();
    
    // Calculate the duration
    auto duration = duration_cast<seconds>(end - start);
    
    // Display the time spent
    cout << "Time taken for the challenge: " << duration.count() << " seconds" << endl;

    return 0;
}   
