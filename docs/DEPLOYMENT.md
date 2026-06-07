# Deployment Guide

## Prerequisites

- C++11 or later compiler
- CMake 3.10 or later (recommended)
- Linux, macOS, or Windows system

## Local Development

### 1. Clone the Repository

```bash
git clone https://github.com/suletoaletu-spec/GLOBAL-EMPIRE.git
cd GLOBAL-EMPIRE
```

### 2. Build the Project

#### Using CMake

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

#### Using Make

```bash
make
```

#### Manual Compilation

```bash
g++ -std=c++11 -O2 -Wall -Wextra -o empire Main Ui/Components/U
```

### 3. Run the Application

```bash
./empire
```

## Production Deployment

### 1. Optimize Build

```bash
mkdir -p build-release
cd build-release
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build . --config Release
```

### 2. Strip Executable

```bash
strip empire
```

### 3. Create Distribution

```bash
mkdir -p dist/bin
cp empire dist/bin/
cp ../README.md dist/
cd dist && tar -czf empire-linux-x64.tar.gz .
```

## Platform-Specific Instructions

### Linux

```bash
# Debian/Ubuntu
sudo apt-get install build-essential cmake

# Fedora/RHEL
sudo dnf install gcc-c++ cmake

# Build
cmake --build build --config Release

# Install
sudo make -C build install
```

### macOS

```bash
# Install Xcode Command Line Tools
xcode-select --install

# Install CMake
brew install cmake

# Build
cmake --build build --config Release
```

### Windows

```bash
# Install Visual Studio or MinGW
# Then build using CMake
cmake -G "Visual Studio 16 2019" ..
cmake --build . --config Release
```

## Docker Deployment

### Dockerfile

```dockerfile
FROM gcc:11-bullseye

WORKDIR /app

# Copy source files
COPY . .

# Install CMake
RUN apt-get update && apt-get install -y cmake

# Build
RUN mkdir build && cd build && cmake .. && cmake --build .

# Run
CMD ["./build/empire"]
```

### Build Docker Image

```bash
docker build -t global-empire:latest .
```

### Run Container

```bash
docker run -it global-empire:latest
```

## Configuration

Edit `include/config.h` before building:

```cpp
#define PLATFORM_COMMISSION 0.15
#define STARTUP_CAPITAL 10000.00
#define MAX_AGENTS 1000
#define MAX_PRODUCTS 10000
```

## Performance Tuning

### Compile Flags

```bash
# Optimization
-O3              # Maximum optimization
-march=native    # Native CPU instructions
-flto            # Link-time optimization

# Debug
-g               # Debug symbols
-O0              # No optimization
```

### Example Release Build

```bash
g++ -std=c++11 -O3 -march=native -flto -Wall -Wextra \
    -o empire Main Ui/Components/U
```

## Testing

### Run Tests

```bash
cmake --build build --target test
```

### Manual Testing

```bash
# Test basic functionality
./empire

# Test with output redirection
./empire > output.log 2>&1

# Test with different configurations
echo "Testing seller verification..."
./empire
```

## Monitoring

### Log Output

```bash
./empire 2>&1 | tee empire.log
```

### Performance Profiling

```bash
g++ -std=c++11 -pg -o empire Main Ui/Components/U
./empire
gprof empire gmon.out > profile.txt
```

## Troubleshooting

### Build Issues

#### C++ Standard Error

```bash
# Ensure C++11 is available
g++ --version
cmake -DCMAKE_CXX_STANDARD=11 ..
```

#### Missing Headers

```bash
# Check include paths
g++ -I./include -I./Ui/Components -std=c++11 -c Main
```

### Runtime Issues

#### Segmentation Fault

```bash
# Run with gdb
gdb ./empire
run
backtrace
```

#### Memory Issues

```bash
# Run with valgrind
valgrind --leak-check=full ./empire
```

## CI/CD Integration

### GitHub Actions

Create `.github/workflows/build.yml`:

```yaml
name: Build

on: [push, pull_request]

jobs:
  build:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v2
      - name: Build
        run: |
          mkdir build
          cd build
          cmake ..
          cmake --build .
      - name: Test
        run: ./build/empire
```

## Backup and Recovery

```bash
# Backup binary
cp empire empire.backup

# Backup source
tar -czf source-backup.tar.gz .
```

## Version Management

```bash
# Tag release
git tag -a v1.0.0 -m "Release version 1.0.0"
git push origin v1.0.0

# Create release
github-cli release create v1.0.0 ./empire
```

## Rollback Procedures

```bash
# Restore previous version
cp empire.backup empire

# Verify
./empire
```

## Support

For deployment issues, please:
1. Check this guide
2. Review build logs
3. Open a GitHub issue
4. Contact maintainers

---

For additional help, see [README.md](../README.md) and [ARCHITECTURE.md](ARCHITECTURE.md).
