#ifndef AI_AGENT_H
#define AI_AGENT_H

#include <string>
#include <stdexcept>

using namespace std;

class AIAgent {
private:
    bool isActive;
    
public:
    AIAgent();
    virtual ~AIAgent() = default;
    
    void assistUser();
    void processOrder(const string& orderId);
    bool getStatus() const;
    void deactivate();
};

#endif
