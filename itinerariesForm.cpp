#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Flight {
    string destination;
    double price;
};

struct Hotel {
    string name;
    int nights;
    double pricePerNight;
};

struct Itinerary {
    string name;
    vector<Flight> flights;
    vector<Hotel> hotels;
    double totalCost;
};

void addFlight(Itinerary &itinerary) {
    Flight flight;
    cout << "أدخل وجهة الرحلة: ";
    cin >> flight.destination;
    cout << "أدخل سعر الرحلة: ";
    cin >> flight.price;

    itinerary.flights.push_back(flight);
    itinerary.totalCost += flight.price;
}

void addHotel(Itinerary &itinerary) {
    Hotel hotel;
    cout << "أدخل اسم الفندق: ";
    cin >> hotel.name;
    cout << "أدخل عدد الليالي: ";
    cin >> hotel.nights;
    cout << "أدخل سعر الليلة الواحدة: ";
    cin >> hotel.pricePerNight;

    double hotelCost = hotel.nights * hotel.pricePerNight;
    itinerary.hotels.push_back(hotel);
    itinerary.totalCost += hotelCost;
}

void showItinerary(const Itinerary &itinerary) {
    cout << "=========================" << endl;
    cout << "اسم الـ Itinerary: " << itinerary.name << endl;
    cout << "رحلات: " << endl;
    for (const auto& flight : itinerary.flights) {
        cout << "  إلى: " << flight.destination << ", السعر: " << flight.price << endl;
    }
    cout << "فنادق: " << endl;
    for (const auto& hotel : itinerary.hotels) {
        cout << "  فندق: " << hotel.name << ", ليالي: " << hotel.nights
             << ", سعر/ليلة: " << hotel.pricePerNight << endl;
    }
    cout << "إجمالي التكلفة: " << itinerary.totalCost << " جنيه" << endl;
    cout << "=========================" << endl;
}

int main() {
    Itinerary itinerary;
    int choice;

    cout << "=============================" << endl;
    cout << "    صفحة إدارة Itineraries    " << endl;
    cout << "=============================" << endl;

    cout << "أدخل اسم الـ Itinerary: ";
    cin >> itinerary.name;

    do {
        cout << "\nاختر عملية:\n";
        cout << "1. إضافة رحلة\n";
        cout << "2. إضافة فندق\n";
        cout << "3. عرض الـ Itinerary\n";
        cout << "4. خروج\n";
        cout << "اختيارك: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addFlight(itinerary);
                break;
            case 2:
                addHotel(itinerary);
                break;
            case 3:
                showItinerary(itinerary);
                break;
            case 4:
                cout << "شكراً لاستخدامك النظام!" << endl;
                break;
            default:
                cout << "اختيار غير صحيح!" << endl;
        }
    } while (choice != 4);

    return 0;
}
