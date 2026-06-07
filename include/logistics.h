#ifndef LOGISTICS_H
#define LOGISTICS_H

#include <string>
#include <vector>
#include <utility>
#include <stdexcept>

using namespace std;

class LogisticsJobs {
private:
    vector<string> deliveryAgents;
    vector<pair<string, string>> shipments;
    
public:
    LogisticsJobs();
    virtual ~LogisticsJobs() = default;
    
    void registerForJob(const string& person);
    void moveGoods(const string& item, const string& destination);
    
    int getDeliveryAgentCount() const;
    int getShipmentCount() const;
    const vector<string>& getAgents() const;
};

#endif
