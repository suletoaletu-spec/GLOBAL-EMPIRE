# Contributing to GLOBAL-EMPIRE

Thank you for your interest in contributing! This document provides guidelines and instructions for contributing.

## Code of Conduct

Please read and adhere to our [CODE_OF_CONDUCT.md](CODE_OF_CONDUCT.md).

## Getting Started

1. Fork the repository
2. Clone your fork: `git clone https://github.com/YOUR_USERNAME/GLOBAL-EMPIRE.git`
3. Create a feature branch: `git checkout -b feature/amazing-feature`
4. Make your changes
5. Commit your changes: `git commit -m 'Add amazing feature'`
6. Push to the branch: `git push origin feature/amazing-feature`
7. Open a Pull Request

## Development Setup

```bash
# Clone the repository
git clone https://github.com/suletoaletu-spec/GLOBAL-EMPIRE.git
cd GLOBAL-EMPIRE

# Build the project
mkdir build && cd build
cmake ..
cmake --build .

# Run tests
ctest
```

## Coding Standards

### C++ Style Guide

- Use 4 spaces for indentation (no tabs)
- Class names: `PascalCase` (e.g., `AIAgent`)
- Function names: `camelCase` (e.g., `assistUser`)
- Variable names: `camelCase` (e.g., `totalEarnings`)
- Constants: `UPPER_SNAKE_CASE` (e.g., `PLATFORM_COMMISSION`)
- Use meaningful names
- Maximum line length: 100 characters

### Best Practices

- Always validate input parameters
- Use const references for large objects: `const string&`
- Implement virtual destructors for base classes
- Use smart pointers when appropriate
- Avoid `using namespace std;` in headers
- Add comments for complex logic
- Write self-documenting code

### Example

```cpp
class Order {
private:
    string orderId;
    double totalAmount;
    
public:
    Order(const string& id, double amount) 
        : orderId(id), totalAmount(amount) {}
    
    virtual ~Order() = default;
    
    void processPayment(double amount) {
        if (amount <= 0) {
            throw invalid_argument("Amount must be positive");
        }
        // Process payment
    }
};
```

## Commit Messages

Follow conventional commits:

```
type(scope): subject

body

footer
```

### Types
- `feat`: A new feature
- `fix`: A bug fix
- `docs`: Documentation changes
- `style`: Code style changes (formatting, missing semicolons, etc.)
- `refactor`: Code refactoring
- `test`: Adding tests
- `chore`: Maintenance tasks

### Examples

```
feat(seller): add seller rating system
fix(logistics): resolve delivery agent assignment bug
docs: update API documentation
```

## Pull Request Process

1. Update documentation for any new features
2. Add/update tests for your changes
3. Ensure all tests pass: `cmake --build . && ctest`
4. Update README.md if needed
5. Follow the PR template
6. Link any related issues

## Testing

- Write tests for new features
- Ensure all existing tests pass
- Test on multiple platforms if possible
- Include both positive and negative test cases

## Documentation

- Update README.md for user-facing changes
- Update relevant docs in `docs/` folder
- Add inline comments for complex logic
- Document public APIs

## Questions?

Feel free to:
- Open an issue for discussion
- Ask in GitHub discussions
- Contact the maintainers

## Recognition

Contributors will be recognized in the README.md.

Thank you for contributing! 🎉
