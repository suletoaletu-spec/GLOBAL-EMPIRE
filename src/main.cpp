#include <iostream>
#include <iomanip>
#include "ai_agent.h"
#include "seller.h"
#include "live_stream.h"
#include "handler.h"
#include "logistics.h"

using namespace std;

int main() {
    try {
        cout << "=== WELCOME TO GLOBAL EMPIRE SYSTEM ===\n\n";
        
        // Initialize system components
        AIAgent myAI;
        Handler bossHandler;
        LogisticsJobs systemLogistics;
        LiveStream liveFeature;
        
        // Create sellers from different countries
        Seller sellerNigeria("Nigeria", "SELLER_NG_001");
        Seller sellerUAE("UAE", "SELLER_AE_001");
        
        // Verify sellers
        sellerNigeria.verifyIdentity("VER_CODE_123");
        sellerUAE.verifyIdentity("VER_CODE_456");
        
        // Post products
        sellerNigeria.postProduct("Premium Handmade Goods");
        sellerNigeria.postProduct("Artisan Crafts");
        sellerUAE.postProduct("Luxury Electronics");
        
        // Start live stream
        sellerNigeria.goLive();
        
        // Process transactions
        liveFeature.sendGift(50.00, "Premium Package");
        liveFeature.buyNow("Premium Handmade Goods", 99.99);
        liveFeature.buyNow("Artisan Crafts", 75.50);
        
        // AI assistance
        myAI.assistUser();
        myAI.processOrder("ORD_2025_001");
        
        // System management
        bossHandler.manageAll();
        
        // Logistics operations
        systemLogistics.registerForJob("John — Abu Dhabi");
        systemLogistics.registerForJob("Sarah — Lagos");
        systemLogistics.moveGoods("Premium Handmade Goods", "Customer Worldwide");
        systemLogistics.moveGoods("Luxury Electronics", "International Hub");
        
        // End live stream
        sellerNigeria.goOffline();
        
        // Summary
        cout << "\n=== SYSTEM SUMMARY ===\n";
        cout << "Total Revenue: $" << fixed << setprecision(2) 
             << liveFeature.getTotalRevenue() << "\n";
        cout << "Total Transactions: " << liveFeature.getTotalTransactions() << "\n";
        cout << "Active Delivery Agents: " << systemLogistics.getDeliveryAgentCount() << "\n";
        cout << "Shipments Processed: " << systemLogistics.getShipmentCount() << "\n";
        cout << "System Status: " << (bossHandler.getStatus() ? "Running" : "Stopped") << "\n";
        cout << "\n=== SYSTEM OPERATIONAL — GLOBAL EMPIRE RUNNING SUCCESSFULLY! ===\n";
        
        return 0;
        
    } catch (const exception& e) {
        cerr << "ERROR: " << e.what() << endl;
        return 1;
    }
}
