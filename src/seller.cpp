#include "seller.h"
#include <iostream>

using namespace std;

Seller::Seller(const string& loc, const string& id) 
    : country(loc), sellerId(id), verified(false), isLive(false) {
    if (loc.empty() || id.empty()) 
        throw invalid_argument("Country and Seller ID cannot be empty");
}

void Seller::verifyIdentity(const string& verificationCode) {
    if (verificationCode.empty()) 
        throw invalid_argument("Verification code required");
    verified = true;
    cout << "✅ Seller " << sellerId << " from " << country 
         << " verified — All products are 100% genuine!\n";
}

void Seller::postProduct(const string& item) {
    if (!verified) throw runtime_error("Seller not verified. Cannot post products.");
    if (item.empty()) throw invalid_argument("Product name cannot be empty");
    
    products.push_back(item);
    cout << "📢 Posted: " << item << " — Trusted Worldwide!\n";
}

void Seller::goLive() {
    if (!verified) throw runtime_error("Seller not verified. Cannot go live.");
    isLive = true;
    cout << "🎥 LIVE STREAM STARTED — Seller " << sellerId 
         << " is now live! Promote, interact, and sell!\n";
}

void Seller::goOffline() {
    isLive = false;
    cout << "⏹️ LIVE STREAM ENDED — Seller " << sellerId << " is now offline.\n";
}

bool Seller::isVerified() const { 
    return verified; 
}

bool Seller::getIsLive() const { 
    return isLive; 
}

const vector<string>& Seller::getProducts() const { 
    return products; 
}

string Seller::getCountry() const { 
    return country; 
}
