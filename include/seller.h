#ifndef SELLER_H
#define SELLER_H

#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

class Seller {
private:
    string country;
    string sellerId;
    bool verified;
    vector<string> products;
    bool isLive;
    
public:
    Seller(const string& loc, const string& id);
    virtual ~Seller() = default;
    
    void verifyIdentity(const string& verificationCode);
    void postProduct(const string& item);
    void goLive();
    void goOffline();
    
    bool isVerified() const;
    bool getIsLive() const;
    const vector<string>& getProducts() const;
    string getCountry() const;
};

#endif
