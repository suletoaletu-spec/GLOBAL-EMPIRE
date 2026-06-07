#ifndef HANDLER_H
#define HANDLER_H

#include <string>
#include <stdexcept>

using namespace std;

class Handler {
private:
    bool isRunning;
    int operatingCount;
    
public:
    Handler();
    virtual ~Handler() = default;
    
    void manageAll();
    void start();
    void stop();
    bool getStatus() const;
};

#endif
