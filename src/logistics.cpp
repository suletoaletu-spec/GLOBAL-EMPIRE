#include "logistics.h"
#include <iostream>

using namespace std;

LogisticsJobs::LogisticsJobs() {}

void LogisticsJobs::registerForJob(const string& person) {
    if (person.empty()) throw invalid_argument("Person name cannot be empty");
    
    deliveryAgents.push_back(person);
    cout << "💼 JOB SECURED: " << person << " — Ready to deliver and earn!\n";
}

void LogisticsJobs::moveGoods(const string& item, const string& destination) {
    if (item.empty() || destination.empty()) 
        throw invalid_argument("Item and destination cannot be empty");
    
    shipments.push_back({item, destination});
    cout << "🚚 Moving & Delivering: " << item << " → " << destination << "\n";
}

int LogisticsJobs::getDeliveryAgentCount() const { 
    return deliveryAgents.size(); 
}

int LogisticsJobs::getShipmentCount() const { 
    return shipments.size(); 
}

const vector<string>& LogisticsJobs::getAgents() const { 
    return deliveryAgents; 
}
