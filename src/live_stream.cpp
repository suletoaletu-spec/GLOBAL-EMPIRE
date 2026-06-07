#include "live_stream.h"
#include <iostream>

using namespace std;

LiveStream::LiveStream() : totalRevenue(0.0), totalTransactions(0) {}

void LiveStream::sendGift(double amount, const string& giftName) {
    if (amount <= 0) throw invalid_argument("Gift amount must be positive");
    if (giftName.empty()) throw invalid_argument("Gift name cannot be empty");
    
    totalRevenue += amount;
    totalTransactions++;
    cout << "🎁 Gift '" << giftName << "' Sent! +$" 
         << fixed << setprecision(2) << amount << "\n";
}

void LiveStream::buyNow(const string& product, double price) {
    if (product.empty()) throw invalid_argument("Product name cannot be empty");
    if (price <= 0) throw invalid_argument("Price must be positive");
    
    totalRevenue += price;
    totalTransactions++;
    cout << "⚡ BUY DIRECT: " << product << " for $" 
         << fixed << setprecision(2) << price << " — Order confirmed!\n";
}

double LiveStream::getTotalRevenue() const { 
    return totalRevenue; 
}

int LiveStream::getTotalTransactions() const { 
    return totalTransactions; 
}
