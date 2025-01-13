// // #include <iostream>
// // #include <vector>
// // #include <iomanip>
// // #include <limits>

// // using namespace std;

// #include "Booking_Seating.hpp" 

// class FlightReservationSystem {
// private:
//     vector<vector<bool>> seats;
//     int rows;
//     int cols;

// public:
//     FlightReservationSystem(int rows, int cols) : rows(rows), cols(cols) {
//         seats.resize(rows, vector<bool>(cols, false));
//     }

//     void displaySeats() {
//         cout << "\nSeat Map (O = Available, X = Booked):\n";
//         cout << "       ";
//         for (int c = 0; c < cols; ++c) {
//             cout << setw(2) << c + 1 << " ";
//         }
//         cout << endl;

//         for (int r = 0; r < rows; ++r) {
//             cout << "Row " << setw(2) << r + 1 << " ";
//             for (int c = 0; c < cols; ++c) {
//                 cout << (seats[r][c] ? " X " : " O ");
//             }
//             cout << endl;
//         }
//     }

//     void bookSeats(vector<pair<int, int>> seatSelections) {
//         bool allAvailable = true;

//         for (const auto& seat : seatSelections) {
//             int row = seat.first;
//             int col = seat.second;

//             if (row < 1 || row > rows || col < 1 || col > cols || seats[row - 1][col - 1]) {
//                 allAvailable = false;
//                 cout << "Seat (Row " << row << ", Col " << col << ") is either invalid or already booked.\n";
//             }
//         }

//         if (allAvailable) {
//             for (const auto& seat : seatSelections) {
//                 seats[seat.first - 1][seat.second - 1] = true;
//             }
//             cout << "All selected seats have been successfully booked!\n";
//         } else {
//             cout << "Some seats could not be booked. Please try again.\n";
//         }
//     }
// };

// int booking() 
// {
//     int rows = 30;
//     int cols = 6;
//     FlightReservationSystem system(rows, cols);

//     int choice;
//     do {
//         cout << "\n--- Flight Ticket Reservation System ---\n";
//         cout << "1. Display Available Seats\n";
//         cout << "2. Book Seats\n";
//         cout << "3. Exit\n";
//         cout << "Enter your choice: ";
//         cin >> choice;

//         if (cin.fail()) {
//             cin.clear();
//             cin.ignore(numeric_limits<streamsize>::max(), '\n');
//             cout << "Invalid input. Please enter a number.\n";
//             continue;
//         }

//         switch (choice) {
//         case 1:
//             system.displaySeats();
//             break;
//         case 2: {
//             int numSeats;
//             cout << "Enter the number of seats to book: ";
//             cin >> numSeats;

//             if (cin.fail() || numSeats <= 0) {
//                 cin.clear();
//                 cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                 cout << "Invalid input. Please enter a positive integer.\n";
//                 break;
//             }

//             vector<pair<int, int>> seatSelections;
//             for (int i = 0; i < numSeats; ++i) {
//                 int row, col;
//                 cout << "Enter row and column for seat " << i + 1 << " (e.g., 1 2): ";
//                 cin >> row >> col;

//                 if (cin.fail()) {
//                     cin.clear();
//                     cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                     cout << "Invalid input. Please enter valid row and column numbers.\n";
//                     --i; // Retry the current seat input
//                     continue;
//                 }

//                 seatSelections.emplace_back(row, col);
//             }

//             system.bookSeats(seatSelections);
//             break;
//         }
//         case 3:
//             cout << "Exiting the system. Thank you!\n";
//             break;
//         default:
//             cout << "Invalid choice. Please try again.\n";
//         }
//     } while (choice != 3);

//     return 0;
// }
