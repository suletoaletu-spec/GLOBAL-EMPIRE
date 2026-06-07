# API Reference

## Overview

This document describes the public API of the GLOBAL-EMPIRE system.

## AIAgent Class

### Methods

#### `void assistUser()`
Provides 24/7 user assistance.

**Throws**: `runtime_error` if AI Agent is not active

**Example**:
```cpp
AIAgent ai;
ai.assistUser();
```

---

#### `void processOrder(const string& orderId)`
Processes a customer order.

**Parameters**:
- `orderId` (string): Unique order identifier

**Throws**: 
- `runtime_error` if AI Agent is not active
- `invalid_argument` if orderId is empty

**Example**:
```cpp
AIAgent ai;
ai.processOrder("ORD_2025_001");
```

---

#### `bool getStatus() const`
Returns the operational status of the AI Agent.

**Returns**: `true` if active, `false` otherwise

---

#### `void deactivate()`
Deactivates the AI Agent.

---

## Seller Class

### Constructor

#### `Seller(const string& country, const string& sellerId)`
Creates a new Seller instance.

**Parameters**:
- `country` (string): Seller's country
- `sellerId` (string): Unique seller identifier

**Throws**: `invalid_argument` if country or sellerId is empty

**Example**:
```cpp
Seller seller("Nigeria", "SELLER_NG_001");
```

---

### Methods

#### `void verifyIdentity(const string& verificationCode)`
Verifies seller identity.

**Parameters**:
- `verificationCode` (string): Verification code

**Throws**: `invalid_argument` if verificationCode is empty

**Example**:
```cpp
seller.verifyIdentity("VER_CODE_123");
```

---

#### `void postProduct(const string& item)`
Lists a product for sale.

**Parameters**:
- `item` (string): Product name

**Throws**:
- `runtime_error` if seller is not verified
- `invalid_argument` if item is empty

**Example**:
```cpp
seller.postProduct("Premium Handmade Goods");
```

---

#### `void goLive()`
Starts a live stream.

**Throws**: `runtime_error` if seller is not verified

**Example**:
```cpp
seller.goLive();
```

---

#### `void goOffline()`
Ends the live stream.

**Example**:
```cpp
seller.goOffline();
```

---

#### `bool isVerified() const`
Returns verification status.

**Returns**: `true` if verified, `false` otherwise

---

#### `bool getIsLive() const`
Returns live streaming status.

**Returns**: `true` if live, `false` otherwise

---

#### `const vector<string>& getProducts() const`
Returns all listed products.

**Returns**: Vector of product names

---

#### `string getCountry() const`
Returns the seller's country.

**Returns**: Country name

---

## LiveStream Class

### Methods

#### `void sendGift(double amount, const string& giftName)`
Processes a gift transaction.

**Parameters**:
- `amount` (double): Gift amount in currency
- `giftName` (string): Gift/package name

**Throws**:
- `invalid_argument` if amount <= 0
- `invalid_argument` if giftName is empty

**Example**:
```cpp
LiveStream live;
live.sendGift(50.00, "Premium Package");
```

---

#### `void buyNow(const string& product, double price)`
Processes a direct purchase.

**Parameters**:
- `product` (string): Product name
- `price` (double): Purchase price

**Throws**:
- `invalid_argument` if product is empty
- `invalid_argument` if price <= 0

**Example**:
```cpp
live.buyNow("Premium Handmade Goods", 99.99);
```

---

#### `double getTotalRevenue() const`
Returns total platform revenue.

**Returns**: Revenue amount (after commission)

---

#### `int getTotalTransactions() const`
Returns total number of transactions.

**Returns**: Transaction count

---

## Handler Class

### Methods

#### `void manageAll()`
Manages all system operations.

**Throws**: `runtime_error` if Handler is not running

---

#### `void start()`
Starts the Handler.

**Example**:
```cpp
Handler handler;
handler.start();
```

---

#### `void stop()`
Stops the Handler.

---

#### `bool getStatus() const`
Returns operational status.

**Returns**: `true` if running, `false` otherwise

---

## LogisticsJobs Class

### Methods

#### `void registerForJob(const string& person)`
Registers a delivery agent.

**Parameters**:
- `person` (string): Agent name

**Throws**: `invalid_argument` if person is empty

**Example**:
```cpp
LogisticsJobs logistics;
logistics.registerForJob("John — Abu Dhabi");
```

---

#### `void moveGoods(const string& item, const string& destination)`
Tracks a shipment.

**Parameters**:
- `item` (string): Item name
- `destination` (string): Delivery destination

**Throws**:
- `invalid_argument` if item is empty
- `invalid_argument` if destination is empty

**Example**:
```cpp
logistics.moveGoods("Premium Goods", "Lagos");
```

---

#### `int getDeliveryAgentCount() const`
Returns number of registered agents.

**Returns**: Agent count

---

#### `int getShipmentCount() const`
Returns number of tracked shipments.

**Returns**: Shipment count

---

#### `const vector<string>& getAgents() const`
Returns all registered agents.

**Returns**: Vector of agent names

---

## Error Handling

All methods use exceptions for error handling:

```cpp
try {
    AIAgent ai;
    ai.processOrder("");  // Throws invalid_argument
} catch (const invalid_argument& e) {
    cerr << "Error: " << e.what() << endl;
} catch (const runtime_error& e) {
    cerr << "Runtime Error: " << e.what() << endl;
} catch (const exception& e) {
    cerr << "Unexpected Error: " << e.what() << endl;
}
```

---

For more examples and usage patterns, see the source code and documentation.
