#!/bin/bash
# Qt Exam System Build Script

echo "============================================"
echo "🎨 Qt Exam System - Build Script"
echo "============================================"
echo ""

# Check if Qt is installed
if ! command -v qmake &> /dev/null; then
    echo "❌ Qt not found! Installing Qt5..."
    sudo apt-get update -qq
    sudo apt-get install -y -qq qtbase5-dev qtbase5-dev-tools qttools5-dev-tools
fi

if ! command -v qmake &> /dev/null; then
    echo "❌ Failed to install Qt. Please install manually:"
    echo "   sudo apt-get install qtbase5-dev qtbase5-dev-tools"
    exit 1
fi

echo "✅ Qt found!"
qmake --version
echo ""

# Create build directory
mkdir -p build-qt
cd build-qt

# Generate Makefiles
echo "🔨 Generating Makefiles..."
qmake ..

# Build
echo "🔨 Building..."
make -j$(nproc)

if [ $? -eq 0 ]; then
    echo ""
    echo "============================================"
    echo "✅ Build successful!"
    echo ""
    echo "🚀 Run: ./build-qt/ExamSystemQt"
    echo ""
    echo "Or run from project root:"
    echo "   ./build-qt/ExamSystemQt"
    echo "============================================"
else
    echo ""
    echo "❌ Build failed!"
    echo ""
    echo "Common issues:"
    echo "1. Missing Qt development files"
    echo "   sudo apt-get install qtbase5-dev"
    echo ""
    echo "2. Try cleaning and rebuilding:"
    echo "   rm -rf build-qt && ./build_qt.sh"
fi
