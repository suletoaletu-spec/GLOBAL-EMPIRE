#ifndef LIVE_STREAM_H
#define LIVE_STREAM_H

#include <string>
#include <stdexcept>
#include <iomanip>

using namespace std;

class LiveStream {
private:
    double totalRevenue;
    int totalTransactions;
    
public:
    LiveStream();
    virtual ~LiveStream() = default;
    
    void sendGift(double amount, const string& giftName);
    void buyNow(const string& product, double price);
    
    double getTotalRevenue() const;
    int getTotalTransactions() const;
};

#endif
