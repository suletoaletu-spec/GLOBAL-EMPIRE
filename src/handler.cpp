#include "handler.h"
#include <iostream>

using namespace std;

Handler::Handler() : isRunning(true), operatingCount(0) {}

void Handler::manageAll() {
    if (!isRunning) throw runtime_error("Handler is not running");
    operatingCount++;
    cout << "🔧 Handler Running Smoothly — System Stability Maintained! (Operations: " 
         << operatingCount << ")\n";
}

void Handler::start() {
    isRunning = true;
    operatingCount = 0;
    cout << "✅ Handler Started\n";
}

void Handler::stop() {
    isRunning = false;
    cout << "⏹️ Handler Stopped\n";
}

bool Handler::getStatus() const { 
    return isRunning; 
}
