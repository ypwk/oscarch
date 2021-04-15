#include <iostream>
#include <vector>
#include <fstream>
#include <entity/Coordinate.h>
#include <algorithms/InsertionSortIntegers.h>
#include <algorithms/InsertionSortGeneric.h>
#include <algorithms/InsertionSortGenericWithComparator.h>
#include <comparator/CoordinateYXComparator.h>
#include "utilities/ArrayUtilities.h"

using namespace std;

void insertionSortExample(vector<int> unsortedIntArray, vector<Coordinate> unsortedCoordinates);

void insertionSortExampleFromFile();

int main() {

    vector<int> unsortedIntArray{42, 1, 6, 56, 54, 0, 7, 1};
    vector<Coordinate> unsortedCoordinates{Coordinate(3, 3), Coordinate(3, 1), Coordinate(2, 1),
                                           Coordinate(3, 0), Coordinate(2, 3)};

    //-------------------------------------

    insertionSortExample(unsortedIntArray, unsortedCoordinates);
    insertionSortExampleFromFile();

    return 0;
}

/*
 * Method that illustrates how to sort integers (read from a text file) using insertion sort.
 */
void insertionSortExampleFromFile() {

    string filePath = "../data/numbers.txt";

    fstream numbersFile;
    numbersFile.open(filePath, ios::in);

    //check if the file is open
    if (!numbersFile.is_open()) {
        cout << "Could not find/open input file" << endl;
        return;
    }

    //-------------------------------------

    vector<int> unsortedArray;

    //read the numbers line by line
    string line;
    while (getline(numbersFile, line)) {
        unsortedArray.push_back(stoi(line));
    }
    numbersFile.close();

    //-------------------------------------

    cout << "Size: " << unsortedArray.size() << endl;
    cout << "Unsorted array: " << endl;
    ArrayUtilities<int>::printArray(unsortedArray);

    //sort the numbers
    vector<int> sortedArray = InsertionSortIntegers(unsortedArray).sort();

    cout << "Sorted int array: " <<endl;
    ArrayUtilities<int>::printArray(sortedArray);
}

/*
 * Method that illustrates how to sort integers and coordinates with the different implementations of insertion sort.
 */
void insertionSortExample(vector<int> unsortedIntArray, vector<Coordinate> unsortedCoordinates) {

    //Sorting an integer array with insertion sort

    cout << "Unsorted int array: ";
    ArrayUtilities<int>::printArray(unsortedIntArray);

    vector<int> sortedIntArray = InsertionSortIntegers(unsortedIntArray).sort();

    cout << "Sorted int array: ";
    ArrayUtilities<int>::printArray(sortedIntArray);

    //--------------------------------------------------

    //Sorting an array of coordinates with in insertion sort.
    //The sorting is first by the x component of the coordinates and then by the y component
    //In other words, (x1, y1) goes before (x2, y2) if (x1 < x2) or (x1 == x2 && y1 < y2)
    //This order is defined by the < operator defined in the Coordinate class

    cout << "Unsorted coordinates: ";
    ArrayUtilities<Coordinate>::printArray(unsortedCoordinates);

    vector<Coordinate> sortedCoordinates = InsertionSortGeneric<Coordinate>(unsortedCoordinates).sort();

    cout << "Sorted coordinates (first by x, and then by y): ";
    ArrayUtilities<Coordinate>::printArray(sortedCoordinates);


    //--------------------------------------------------

    //Sorting an array of coordinates with in insertion sort.
    //In this case, the order of coordinates is different:
    //The sorting is first by the y of the coordinates and then by the x part
    //(x1, y1) goes before (x2, y2) if (y1 < y2) or (y1 == y2 && x1 < x2)
    //This order is implemented in CoordinateYXComparator

    InsertionSortGenericWithComparator<Coordinate> algorithm = InsertionSortGenericWithComparator<Coordinate>(
            unsortedCoordinates);
    Comparator<Coordinate> *comparator2 = new CoordinateYXComparator();
    vector<Coordinate> sortedCoordinates2 = algorithm.sort(comparator2);

    cout << "Sorted coordinates (first by y, and then by x): ";
    ArrayUtilities<Coordinate>::printArray(sortedCoordinates2);

}

